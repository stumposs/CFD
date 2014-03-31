#include "wx/defs.h"
#include "wx/app.h"
#include "wx/cursor.h"
#include "wx/glcanvas.h"
#include "Frame.h"

#include <osgViewer/ViewerEventHandlers>
#include <string>
#include <osgGA/TrackballManipulator>
#include <osgDB/ReadFile>
#include <wx/image.h>
#include <wx/menu.h>
#include <iostream>



class wxOsgApp : public wxApp
{
public:
    bool OnInit();
};
