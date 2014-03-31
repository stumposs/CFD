#pragma once
#include <wx/wx.h>
#include "Frame.h"

class MainFrame:public wxFrame
{
public:
	MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
	~MainFrame(void);
		enum{  
		ID_Help = 1
	};
		
	void OnExit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	void OnHelp(wxCommandEvent& event);

	DECLARE_EVENT_TABLE()
private:
	OsgViewFrame *_osgViewer;

};

