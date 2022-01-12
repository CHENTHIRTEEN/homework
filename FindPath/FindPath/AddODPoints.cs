using System;
using System.Drawing;
using System.Runtime.InteropServices;
using ESRI.ArcGIS.ADF.BaseClasses;
using ESRI.ArcGIS.ADF.CATIDs;
using ESRI.ArcGIS.Framework;
using ESRI.ArcGIS.ArcMapUI;
using System.Windows.Forms;
using ESRI.ArcGIS.Controls;
using ESRI.ArcGIS.Carto;
using ESRI.ArcGIS.Geometry;
using ESRI.ArcGIS.Display;
using System.Collections.Generic;
using ESRI.ArcGIS.Geodatabase;
using FindPath.Route;
using FindPath.Framwork;

namespace FindPath.Tools
{
    /// <summary>
    /// Summary description for AddODPoints.
    /// </summary>
    [Guid("671118b8-9d11-4a4d-935e-b5085cba543d")]
    [ClassInterface(ClassInterfaceType.None)]
    [ProgId("FindPath.AddODPoints")]
    public sealed class AddODPoints : BaseTool
    {

        private IHookHelper m_HookHelper = new HookHelperClass();
        bool isFirstClick = false;
        IPoint fPt, tPt;

        #region COM Registration Function(s)
        [ComRegisterFunction()]
        [ComVisible(false)]
        static void RegisterFunction(Type registerType)
        {
            // Required for ArcGIS Component Category Registrar support
            ArcGISCategoryRegistration(registerType);

            //
            // TODO: Add any COM registration code here
            //
        }

        [ComUnregisterFunction()]
        [ComVisible(false)]
        static void UnregisterFunction(Type registerType)
        {
            // Required for ArcGIS Component Category Registrar support
            ArcGISCategoryUnregistration(registerType);

            //
            // TODO: Add any COM unregistration code here
            //
        }

        #region ArcGIS Component Category Registrar generated code
        /// <summary>
        /// Required method for ArcGIS Component Category registration -
        /// Do not modify the contents of this method with the code editor.
        /// </summary>
        private static void ArcGISCategoryRegistration(Type registerType)
        {
            string regKey = string.Format("HKEY_CLASSES_ROOT\\CLSID\\{{{0}}}", registerType.GUID);
            MxCommands.Register(regKey);

        }
        /// <summary>
        /// Required method for ArcGIS Component Category unregistration -
        /// Do not modify the contents of this method with the code editor.
        /// </summary>
        private static void ArcGISCategoryUnregistration(Type registerType)
        {
            string regKey = string.Format("HKEY_CLASSES_ROOT\\CLSID\\{{{0}}}", registerType.GUID);
            MxCommands.Unregister(regKey);

        }

        #endregion
        #endregion

        private IApplication m_application;
        public AddODPoints()
        {
            //
            // TODO: Define values for the public properties
            //
            base.m_category = ""; //localizable text 
            base.m_caption = "";  //localizable text 
            base.m_message = "";  //localizable text
            base.m_toolTip = "";  //localizable text
            base.m_name = "";   //unique id, non-localizable (e.g. "MyCategory_ArcMapTool")
            try
            {
                //
                // TODO: change resource name if necessary
                //
                string bitmapResourceName = GetType().Name + ".bmp";
                base.m_bitmap = new Bitmap(GetType(), bitmapResourceName);
                base.m_cursor = new System.Windows.Forms.Cursor(GetType(), GetType().Name + ".cur");
            }
            catch (Exception ex)
            {
                System.Diagnostics.Trace.WriteLine(ex.Message, "Invalid Bitmap");
            }
        }

        #region Overridden Class Methods

        /// <summary>
        /// Occurs when this tool is created
        /// </summary>
        /// <param name="hook">Instance of the application</param>
        public override void OnCreate(object hook)
        {
            m_application = hook as IApplication;

            //Disable if it is not ArcMap
            if (hook is IMxApplication)
                base.m_enabled = true;
            else
                base.m_enabled = false;

            m_HookHelper.Hook = hook;
            // TODO:  Add other initialization code
        }

        /// <summary>
        /// Occurs when this tool is clicked
        /// </summary>
        public override void OnClick()
        {
            // TODO: Add AddODPoints.OnClick implementation
        }

        public override void OnMouseDown(int Button, int Shift, int X, int Y)
        {
            // TODO:  Add AddODPoints.OnMouseDown implementation
            isFirstClick = !isFirstClick;

            IActiveView activeView = m_HookHelper.ActiveView;
            IGraphicsContainer pGraphicsContainer = activeView.GraphicsContainer;

            IPoint pt = activeView.ScreenDisplay.DisplayTransformation.ToMapPoint(X, Y);

            IMarkerElement pMarkerElement;
            ISimpleMarkerSymbol pSimpleMarkerSymbol = new SimpleMarkerSymbolClass();
            IRgbColor pRgbColor = new RgbColorClass();

            if (isFirstClick == true)
            {
                pRgbColor.Red = 255;
                pGraphicsContainer.DeleteAllElements();//第一次点击前清除上一次的起始点
                fPt = pt;
            }
            else
            {
                pRgbColor.Green = 255;
                tPt = pt;
            }

            pSimpleMarkerSymbol.Color = pRgbColor;
            pSimpleMarkerSymbol.Style = esriSimpleMarkerStyle.esriSMSCircle;
            pMarkerElement = new MarkerElementClass();
            pMarkerElement.Symbol = pSimpleMarkerSymbol;
            pMarkerElement.Symbol.Size = 4;
            pMarkerElement.Symbol = pSimpleMarkerSymbol;
            IElement pElement = pMarkerElement as IElement;
            pElement.Geometry = pt;

            pGraphicsContainer.AddElement((IElement)pMarkerElement, 0);         
            activeView.Refresh();
        }

        public override void OnMouseMove(int Button, int Shift, int X, int Y)
        {
            // TODO:  Add AddODPoints.OnMouseMove implementation
        }

        public override void OnMouseUp(int Button, int Shift, int X, int Y)
        {
            // TODO:  Add AddODPoints.OnMouseUp implementation
            IActiveView activeView = m_HookHelper.ActiveView;
            IntPtr pHandle = new IntPtr(m_HookHelper.ActiveView.ScreenDisplay.hWnd);
            AxMapControl ax = System.Windows.Forms.Form.FromHandle(pHandle) as AxMapControl;//加载

            if (isFirstClick == false)//说明第二次选择点弹起
            {
                IFeatureLayer nodeLyr = activeView.FocusMap.Layer[1] as IFeatureLayer;
                int fID, tID;               
                IPoint fPoint = getNearestPoint(fPt, nodeLyr, 0.005,out fID);//0.05度作为搜索半径
                 ax.FlashShape(fPoint);
                IPoint tPoint = getNearestPoint(tPt, nodeLyr, 0.005,out tID);
                ax.FlashShape(tPoint);
                MainForm frm = Form.FromHandle(pHandle).FindForm() as MainForm;
                frm.FindPath(fID, tID);
            }

        }
        //获取最近点
        private IPoint getNearestPoint(IPoint pPoint, IFeatureLayer pFeatureLayer, double pRadius, out int NodeID)
        {
            ITopologicalOperator pTop = pPoint as ITopologicalOperator;
            IGeometry pGeometry = pTop.Buffer(pRadius);  //建立缓冲区
            ISpatialFilter pSpatialFilter = new SpatialFilterClass();  //空间查询模块
            pSpatialFilter.Geometry = pGeometry;  //查询内容
            pSpatialFilter.SpatialRel = esriSpatialRelEnum.esriSpatialRelIntersects;  //求交
            IFeatureCursor pFeatureCursor = pFeatureLayer.FeatureClass.Search(pSpatialFilter, false);
            IFeature pFeature = pFeatureCursor.NextFeature();
            int index = pFeatureLayer.FeatureClass.Fields.FindField("NodeID");
            NodeID = Convert.ToInt32(pFeature.get_Value(index));
            return pFeature.Shape as IPoint;
            #endregion
        }
    }
}
