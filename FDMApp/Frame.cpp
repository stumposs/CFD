#include "Frame.h"

BEGIN_EVENT_TABLE(OsgViewFrame, wxFrame)
    EVT_IDLE(OsgViewFrame::OnIdle)
END_EVENT_TABLE()

/* My frame constructor */
OsgViewFrame::OsgViewFrame(wxFrame *frame, const wxString& title, const wxPoint& pos,
    const wxSize& size, long style)
    : wxFrame(frame, wxID_ANY, title, pos, size, style)
{

}

void OsgViewFrame::SetViewer(osgViewer::Viewer *viewer)
{
    _viewer = viewer;
}

void OsgViewFrame::OnIdle(wxIdleEvent &event)
{
    if (!_viewer->isRealized())
        return;

    _viewer->frame();

    event.RequestMore();
}