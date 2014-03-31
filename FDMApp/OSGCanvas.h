#include<wx/wx.h>
#include "wx/glcanvas.h"
#include <osgViewer/Viewer>

class OSGCanvas : public wxGLCanvas
{
public:
    OSGCanvas(wxWindow *parent, wxWindowID id = wxID_ANY,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize, long style = 0,
        const wxString& name = wxT("TestGLCanvas"),
        int *attributes = 0);

    virtual ~OSGCanvas();

    void SetGraphicsWindow(osgViewer::GraphicsWindow *gw)   { _graphics_window = gw; }

    void OnPaint(wxPaintEvent& event);
    void OnSize(wxSizeEvent& event);
    void OnEraseBackground(wxEraseEvent& event);

    void OnChar(wxKeyEvent &event);
    void OnKeyUp(wxKeyEvent &event);

    void OnMouseEnter(wxMouseEvent &event);
    void OnMouseDown(wxMouseEvent &event);
    void OnMouseUp(wxMouseEvent &event);
    void OnMouseMotion(wxMouseEvent &event);
    void OnMouseWheel(wxMouseEvent &event);

    void UseCursor(bool value);

private:
    DECLARE_EVENT_TABLE()

    osg::ref_ptr<osgViewer::GraphicsWindow> _graphics_window;

    wxCursor _oldCursor;
};

