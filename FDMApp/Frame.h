#include<wx/wx.h>
#include<osgViewer/Viewer>
#include "MeshGenerator.h"
class OsgViewFrame : public wxFrame
{
public:
    OsgViewFrame(wxFrame *frame, const wxString& title, const wxPoint& pos,
        const wxSize& size, long style = wxDEFAULT_FRAME_STYLE);

    void SetViewer(osgViewer::Viewer *viewer);
    void OnIdle(wxIdleEvent& event);

private:
    osg::ref_ptr<osgViewer::Viewer> _viewer;

    DECLARE_EVENT_TABLE()
};