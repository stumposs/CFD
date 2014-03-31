#include "OsgApp.h"
#include "GraphicsWindowWx.h"
#include "MeshGenerator.h"
IMPLEMENT_APP(wxOsgApp);

bool wxOsgApp::OnInit()
{
	MeshGenerator *mesh = new MeshGenerator();
	mesh->CreateQuad();

    if (argc<2)
    {
        std::cout << wxString(argv[0]).mb_str() <<": requires filename argument." << std::endl;
        return false;
    }

    int width = 800;
    int height = 600;

    // Create the main frame window

    OsgViewFrame *frame = new OsgViewFrame(NULL, wxT("Computational Fluid Dynamics Application"),
        wxDefaultPosition, wxSize(width, height));

    // create osg canvas
    //    - initialize

    int attributes[7];
    attributes[0] = int(WX_GL_DOUBLEBUFFER);
    attributes[1] = WX_GL_RGBA;
    attributes[2] = WX_GL_DEPTH_SIZE; //number of bits for z-buffer (typically 0, 16, or 32)
    attributes[3] = 8;
    attributes[4] = WX_GL_STENCIL_SIZE; //specifies number of bits for stencil buffer
    attributes[5] = 8;
    attributes[6] = 0;

    OSGCanvas *canvas = new OSGCanvas(frame, wxID_ANY, wxDefaultPosition,
        wxSize(width, height), wxSUNKEN_BORDER, wxT("osgviewerWX"), attributes);

    GraphicsWindowWX* gw = new GraphicsWindowWX(canvas);

    canvas->SetGraphicsWindow(gw);

    osgViewer::Viewer *viewer = new osgViewer::Viewer;
    viewer->getCamera()->setGraphicsContext(gw);
    viewer->getCamera()->setViewport(0,0,width,height);
    viewer->addEventHandler(new osgViewer::StatsHandler);
    viewer->setThreadingModel(osgViewer::Viewer::SingleThreaded);

    // load the scene.
    //wxString fname(argv[1]);
	wxString fname("data/Cessna.osgt");
    osg::ref_ptr<osg::Node> loadedModel = osgDB::readNodeFile(std::string(fname.mb_str()));
    if (!loadedModel)
    {
		wxString fname2(argv[1]);
		loadedModel = osgDB::readNodeFile(std::string(fname2.mb_str()));
		if(!loadedModel)
		{
        std::cout << argv[0] <<": No data loaded." << std::endl;
        return false;
		}
    }
	viewer->setSceneData(mesh->GetRoot().get());
    //viewer->setSceneData(loadedModel.get());
    viewer->setCameraManipulator(new osgGA::TrackballManipulator);
    frame->SetViewer(viewer);

    /* Show the frame */
    frame->Show(true);

    return true;
}