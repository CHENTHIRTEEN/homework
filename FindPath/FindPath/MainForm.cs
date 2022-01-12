using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Windows.Forms;
using ESRI.ArcGIS.Controls;
using FindPath.DataAccess;
using FindPath.Route;
using ESRI.ArcGIS.Carto;
using ESRI.ArcGIS.SystemUI;
using FindPath.Tools;
using System.Collections;
using ESRI.ArcGIS.Geometry;
using ESRI.ArcGIS.Display;
using ESRI.ArcGIS.Geodatabase;

namespace FindPath.Framwork
{
    public partial class MainForm : Form
    {
        //SVF计算工具
        ICommand myODSelTool;//鼠标选点工具
        Network net = new Network();
        public MainForm()
        {
            InitializeComponent();
        }

        private void MainForm_Load(object sender, EventArgs e)
        {
           // DataAccess.DataAccess.AddMapService(axMapControl1);
            Thread t = new Thread(ThreadLoadGISData);
            t.Name = "MyNewThread1";
            t.IsBackground = true;
            t.Start();

            //鼠标选取起始点工具
            myODSelTool = new AddODPoints() as ICommand;
            myODSelTool.OnCreate(axMapControl1.Object);
        }

        private void axMapControl1_OnMouseDown(object sender, IMapControlEvents2_OnMouseDownEvent e)
        {
        }
         private void ThreadLoadMapService()
        {
            DataAccess.DataAccess.AddMapService(axMapControl1);
        }
        void ThreadLoadGISData()
        {
            DataAccess.DataAccess.AddShapefileLayer(axMapControl1);
        }

        private void 初始化道路网络ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //初始化网络
            axMapControl1.DrawText(axMapControl1.ActiveView.Extent, "正在执行初始化，请稍候...");
            net.InitNetWork(axMapControl1.Map.Layer[0] as IFeatureLayer, axMapControl1.Map.Layer[1] as IFeatureLayer);
            axMapControl1.Refresh();
        }
        public  void FindPath(int fID,int tID)
        {
            //求取路径
            axMapControl1.DrawText(axMapControl1.ActiveView.Extent, "正在获取最短路径，请稍候...");
            net.QueryRoute(fID, tID);
            axMapControl1.Refresh();
        }
        private void 选取起始点ToolStripMenuItem_Click(object sender, EventArgs e)
        {
                axMapControl1.CurrentTool = myODSelTool as ITool;            
        }

        private void 最短路径查询ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            axMapControl1.CurrentTool = myODSelTool as ITool;
        }

        private void MainForm_Load_1(object sender, EventArgs e)
        {
            axMapControl1.CurrentTool = myODSelTool as ITool;
        }
    }
}
