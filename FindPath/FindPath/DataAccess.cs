using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using ESRI.ArcGIS.ADF.BaseClasses;
using ESRI.ArcGIS.ADF.CATIDs;
using ESRI.ArcGIS.Framework;
using ESRI.ArcGIS.ArcMapUI;
using System.Windows.Forms;
using ESRI.ArcGIS.Controls;
using ESRI.ArcGIS.Carto;
using ESRI.ArcGIS.Geodatabase;
using ESRI.ArcGIS.esriSystem;
using ESRI.ArcGIS.GISClient;
using ESRI.ArcGIS.DataSourcesRaster;
using ESRI.ArcGIS.Server;
using ESRI.ArcGIS.DataSourcesFile;
using ESRI.ArcGIS.DataSourcesGDB;
using ESRI.ArcGIS.Display;
using ESRI.ArcGIS.Geometry;
using ESRI.ArcGIS.Output;
using ESRI.ArcGIS.SystemUI;
namespace FindPath.DataAccess
{
	class DataAccess{
		static public void AddShapefileLayer(AxMapControl ax)
		{
			//获取数据文件目录
			string pPath = System.IO.Directory.GetCurrentDirectory()+"\\Data\\";
			//添加到axmapcontrol中
			ax.AddShapeFile(pPath, "njnod");
			ax.AddShapeFile(pPath, "njarc");
			IFeatureLayer lyr = ax.Map.Layer[0] as IFeatureLayer;
			ax.ActiveView.Extent = ((IGeoDataset)lyr).Extent;
			ax.ActiveView.PartialRefresh(esriViewDrawPhase.esriViewGeography, lyr, ax.ActiveView.Extent);

		}
		static public void AddMapService( AxMapControl ax)
		{
            try
            {
				IMapServerRESTLayer mapServerRESTLayer = new MapServerRESTLayerClass();

				//世界影像地图
				//mapServerRESTLayer.Connect("http://services.arcgisonline.com/ArcGIS/rest/services/World_Imagery/MapServer");

				//世界交通地图服务
				mapServerRESTLayer.Connect("http://services.arcgisonline.com/ArcGIS/rest/services/ESRI_StreetMap_World_2D/MapServer");

				////OSM，但链接不成功
				//mapServerRESTLayer.Connect("http://ows.mundialis.de/services/service?TOPO-REST");
				ax.AddLayer(mapServerRESTLayer as ILayer);
            }
            catch
            {
				ax.DrawText(ax.Extent, "链接地图服务失败");
            }

         }

		//添加百度地图或高德地图，需要申请Key
		public ESRI.ArcGIS.Carto.ILayer AddServiceLayer(string url, string serviceName)
		{
			//create a new ArcGIS Server connection factory 
			ESRI.ArcGIS.GISClient.IAGSServerConnectionFactory2 connectionFactory;
			connectionFactory = (ESRI.ArcGIS.GISClient.IAGSServerConnectionFactory2)new ESRI.ArcGIS.GISClient.AGSServerConnectionFactory();
			//create a property set to hold connection properties 
			IPropertySet connectionProps;
			connectionProps = new PropertySet();
			//specify the URL for the server 
			connectionProps.SetProperty("url", url);
			//define username and password for the connection 
			connectionProps.SetProperty("user", "giser");
			connectionProps.SetProperty("password", "123456");
			//open the server connection, pass in the property set, get a connection object back 
			ESRI.ArcGIS.GISClient.IAGSServerConnection gisServer;
			gisServer = connectionFactory.Open(connectionProps, 0);

			//get an enum of all server object names from the server (GIS services, i.e.) 
			ESRI.ArcGIS.GISClient.IAGSEnumServerObjectName soNames = gisServer.ServerObjectNames;
			ESRI.ArcGIS.GISClient.IAGSServerObjectName3 soName;
			//loop thru all services, find a map service called I3_Imagery_Prime_World_2D (high res imagery for the world) 
			soName = (ESRI.ArcGIS.GISClient.IAGSServerObjectName3)soNames.Next();
			do
			{
				if ((soName.Type == "MapServer") && (soName.Name == serviceName))
				{
					break; //found it 
				}
				//keep searching the services ... 
				soName = (ESRI.ArcGIS.GISClient.IAGSServerObjectName3)soNames.Next();
			} while (soName != null);
			//if the desired service was found ... 
			ILayer serviceLayer = null;
			if (soName != null)
			{
				//create a layer factory to make a new MapServerLayer from the server object name 
				ILayerFactory msLayerFactory;
				msLayerFactory = new MapServerLayerFactory();
				//create an enum of layers using the name object (will contain only a single layer) 
				IEnumLayer enumLyrs = msLayerFactory.Create(soName);
				//get the layer from the enum, store it in a MapServerLayer variable 
				IMapServerLayer mapServerLayer;
				mapServerLayer = (IMapServerLayer)enumLyrs.Next();
				//make sure the layer is not empty (Nothing), then add it to the map 
				if (mapServerLayer != null)
				{
					serviceLayer = ((ILayer)mapServerLayer);
				}
			}
			return serviceLayer;
		}

		public IMapServer GetMapServer(string agsUrl, string serviceName)
		{
			IMapServer mapserver = null;

			//Set connection propertyset. sample URL: http://host:port/arcgis/services. 
			IPropertySet propertySet = new PropertySetClass();
			propertySet.SetProperty("url", agsUrl);

			//Open an AGS connection. 
			Type factoryType = Type.GetTypeFromProgID("esriGISClient.AGSServerConnectionFactory");
			IAGSServerConnectionFactory agsFactory = (IAGSServerConnectionFactory)Activator.CreateInstance(factoryType);
			IAGSServerConnection agsConnection = agsFactory.Open(propertySet, 0);

			//Get the image server. 
			IAGSEnumServerObjectName agsServerObjectNames = agsConnection.ServerObjectNames;
			agsServerObjectNames.Reset();
			IAGSServerObjectName agsServerObjectName = agsServerObjectNames.Next();
			while (agsServerObjectName != null)
			{
				if ((agsServerObjectName.Name.ToLower() == serviceName.ToLower()) && (agsServerObjectName.Type == "MapServer"))
				{
					IName pName = (IName)agsServerObjectName;
					IAGSServerObject agsServerObject = (IAGSServerObject)pName.Open();
					mapserver = (IMapServer)agsServerObject;
					break;
				}
				agsServerObjectName = agsServerObjectNames.Next();
			}

			//Return the image server object. 
			return mapserver;
		}

		public IServerObjectAdmin ConnectAGS(string host, string username, string password)
		{
			IServerObjectAdmin m_ServerObjectAdmin = null;
			try
			{
				IPropertySet propertySet = new PropertySetClass();
				propertySet.SetProperty("url", host);
				propertySet.SetProperty("ConnectionMode", esriAGSConnectionMode.esriAGSConnectionModeAdmin);
				propertySet.SetProperty("ServerType", esriAGSServerType.esriAGSServerTypeDiscovery);
				propertySet.SetProperty("user", username);
				propertySet.SetProperty("password", password);
				propertySet.SetProperty("ALLOWINSECURETOKENURL", true);
				IAGSServerConnectionName3 connectName = new AGSServerConnectionNameClass() as IAGSServerConnectionName3;
				connectName.ConnectionProperties = propertySet;
				IAGSServerConnectionAdmin agsAdmin = ((IName)connectName).Open() as IAGSServerConnectionAdmin;

				m_ServerObjectAdmin = agsAdmin.ServerObjectAdmin;
			}

			catch (Exception exc)
			{
				Console.WriteLine("连接失败：{ 0}.Message: { 1}", host, exc.Message);
				return null;
			}
			return m_ServerObjectAdmin;
		}
	};
}

