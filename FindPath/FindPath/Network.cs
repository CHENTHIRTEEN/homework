using ESRI.ArcGIS.Carto;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Collections;
using ESRI.ArcGIS.Geodatabase;
using System.Windows.Forms;
using System.Diagnostics;

namespace FindPath.Route
{
	struct IterateNode//迭代的节点
	{
		public float dist;//当前距离
		public bool flag;//是否已经是最短路径节点
		public long pre;//前驱节点
	};

	class Network
	{
        const float MAX_DIS = 9999999.0F;//若两节点不相邻，用比较大的距离值表示无穷大
        long m_nodeCount;//节点数
		long m_arcCount;//弧段数
		IFeatureLayer m_arcLyr;//弧段层
		IFeatureLayer m_nodeLyr;//节点层

		float[,] m_Matrix;//二维指针，节点的邻接矩阵
        IterateNode[] m_Iterator;//迭代的节点向量变量
		ArrayList m_temRouteSeq = new ArrayList();//存储临时的最短路径序列,每次迭代增加一个当前最短路径结点
		ArrayList m_resRouteSeq = new ArrayList();//用于存储最终的结果序列

        private void AllocateMatrix()//分配权重矩阵空间
		{
            m_Matrix = new float[m_nodeCount, m_nodeCount];//邻接表n*n
            m_Iterator = new IterateNode[m_nodeCount];//迭代向量1*n
        }
		private void InitMatrix()//初始化邻接表矩阵和迭代向量
        {
            //初始化矩阵，主对角线为0，其它全部赋9999999.0，表示结点之间不存在通路
            for (int i = 0; i < m_nodeCount; i++)
            {
                for (int j = 0; j < m_nodeCount; j++)
                {
                    if (i == j)
                        m_Matrix[i,j] = 0.0f;//邻接矩阵对角线权重为0
                    else
                        m_Matrix[i,j] = MAX_DIS; //无穷大
                }
            }
        }
        private void InitIterator()
        {
            //初始化迭代向量，flag为false表示不是最短路径节点，不着色，距离赋9999999.0，用于最短距离对比
            for (int i = 0; i < m_nodeCount; i++)
            {
                m_Iterator[i].dist = MAX_DIS;
                m_Iterator[i].flag = false;
                m_Iterator[i].pre = -1;//前驱
            }
            m_temRouteSeq.Clear();//开始时这个可变数组是空的
            m_resRouteSeq.Clear();//开始时这个可变数组是空的
        }

        //通过路段ID值路段获取权重（路段长度），之后邻接矩阵赋值
		private void SetValueByArcID(long arcID)
        {
            //无向网络为对角矩阵
            long from;//弧段起点号
            long to;//弧段终点号
            float weight;//弧段权重

            string express1 = string.Format("ArcID = {0}", arcID);
            IQueryFilter queryFilter = new QueryFilterClass();
            queryFilter.WhereClause = express1;
            IFeatureClass featureClass = m_arcLyr.FeatureClass;
            IFeatureCursor featureCursor = featureClass.Search(queryFilter, false);
            IFeature feature = featureCursor.NextFeature();

            //获取节点图层的索引值
            int index1 = featureClass.Fields.FindField("从节点");
            int index2 = featureClass.Fields.FindField("到节点");
            int index3 = featureClass.Fields.FindField("实际长度");

            //获取字段值：from =从节点字段值   from =到节点字段值  from =从节点字段值
            from = Convert.ToInt64(feature.get_Value(index1));
            to = Convert.ToInt64(feature.get_Value(index2));
            weight = Convert.ToSingle(feature.get_Value(index3));

            //赋值，因为不考虑道路方向，邻接矩阵对称赋值
            m_Matrix[from - 1,to - 1] = weight;
            m_Matrix[to - 1,from - 1] = weight;
        }

        //初始化邻接矩阵，读取路网数据，将
        public void InitNetWork(IFeatureLayer arc, IFeatureLayer node)
        {
            m_arcLyr = arc;
            m_nodeLyr = node;
            IQueryFilter pQuery = new QueryFilterClass();
            m_arcCount = arc.FeatureClass.FeatureCount(pQuery);
            m_nodeCount = node.FeatureClass.FeatureCount(pQuery);

            AllocateMatrix();//分配空间
            InitMatrix();//以-999999赋初值

            //读取数据，给邻接表赋值
            IQueryFilter queryFilter = new QueryFilterClass();
            queryFilter.WhereClause = "";
            IFeatureCursor featureCursor = node.FeatureClass.Search(queryFilter, false);
            IFeature feature = featureCursor.NextFeature();

            //获取节点图层的索引值
            int index = node.FeatureClass.Fields.FindField("相邻线");
            while (feature != null)
            {
                string str = feature.get_Value(index).ToString();
                //按照逗号从字符串截取字符
                string[] strArr = str.Split(',');//字符串按照逗号截取
                for (int i = 0; i < strArr.Length-1; i++)//最后一个逗号不算，所以减1
                {
                    SetValueByArcID(Convert.ToInt64(strArr[i]));
                }
                feature = featureCursor.NextFeature();
            }
        }

        /*****************************************************************************
           作者：姓名学号
           日期：
           参数：
               输入： fNodeID:起始节点号； tNodeID:终点节点号
               输出：bool,查找成功为true，查找失败为false。

           功能：
              1:查找起点fNodeID到终点tNodeID的最短路径序列
              2:结果存储在 m_resRouteSeq可变长数组里
              3:并将resRouteSeq节点序列用MessageBox方式显示。
        *********************************************************************************/

        public bool QueryRoute(long fNodeID, long tNodeID)//查询最短路径
        {
            // dist数组存放路径权重
            float[] dist = new float[m_nodeCount];
            long[] pre = new long[m_nodeCount];
            // visited数组标示节点是否被访问过
            bool[] visited = new bool[m_nodeCount];
            int t = 0;
            // 初始化dist数组
            for (int i = 0; i < m_nodeCount; i++)
            {
                visited[i] = false;
                dist[i] = m_Matrix[fNodeID, i];
            }
            long[] path = new long[m_nodeCount];
            for(int i = 0; i < m_nodeCount; i++)
            {
                path[i] = 0;
            }
            m_temRouteSeq.Add(tNodeID);
            // 起点本身不需要被访问
            visited[0] = true;
            for(int i = 1; i < m_nodeCount; i++)
            {
                float min = MAX_DIS;
                for(int j = 0; j < m_nodeCount; j++)
                {
                    if(!visited[j] && dist[j] < min)
                    {
                        t = j;
                        min = dist[j];
                    }
                }
                visited[t] = true;
                for(int k = 0; k < m_nodeCount; k++)
                {
                    if(!visited[k] && min + m_Matrix[t, k] < dist[k])
                    {
                        dist[k] = min + m_Matrix[t, k];
                        pre[k] = t;
                    }
                }
            }
            long e = tNodeID;
            int s = 0;
            while(e != fNodeID)
            {
                s++;
                path[s] = pre[e];
                e = pre[e];
            }
            for (int i = s; i > s / 2; i--)
            {
                long temp = path[s - i];
                path[s - i] = path[i];
                path[i] = temp;
            }
            foreach(long i in path)
            {
                m_resRouteSeq.Add(i);
            }

            foreach (float i in m_resRouteSeq)
            {
                Console.WriteLine(i + " ");
            }
            return true;//路径查找成功
        }
    };

}
