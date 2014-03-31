#include "MainFrame.h"
BEGIN_EVENT_TABLE(MainFrame, wxFrame)
	EVT_MENU(wxID_EXIT, MainFrame::OnExit)
	EVT_MENU(wxID_ABOUT, MainFrame::OnAbout)
	EVT_MENU(ID_Help, MainFrame::OnHelp)
END_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
: wxFrame(NULL, wxID_ANY, title, pos, size)
{
	wxMenu *menuFile = new wxMenu;
	
	menuFile->Append(wxID_EXIT);
	wxMenu *menuHelp = new wxMenu;
	//menuHelp->Append(wxID_ABOUT);
	menuHelp->Append(ID_Help, "&Help",
	"CFD");
	wxMenuBar *menuBar = new wxMenuBar;
	menuBar->Append( menuFile, "&File" );
	menuBar->Append( menuHelp, "&Help" );
	SetMenuBar( menuBar );

}


MainFrame::~MainFrame(void)
{
}

void MainFrame::OnExit(wxCommandEvent& event)
{
	Close( true );
}
void MainFrame::OnHelp(wxCommandEvent& event)
{
wxMessageBox( "Computational Fluid Dynamics",
"Collect fluid flow parameters to solve the Reynolds Averaged Navier Stokes equations", wxOK | wxICON_INFORMATION );
}
void MainFrame::OnAbout(wxCommandEvent& event)
{
wxMessageBox( "CFD!",
"TODO: Document", wxOK | wxICON_INFORMATION );
}
