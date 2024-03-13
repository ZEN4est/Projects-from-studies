#include <wx/wx.h>
#include "GUIMainFrame.h"

class MyApp : public wxApp {

public:

	virtual bool OnInit();
	virtual int OnExit() { return 0; }

};

IMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
	SetProcessDPIAware();
	GUIMainFrame* mainFrame = new GUIMainFrame(NULL);
	mainFrame->Show(true);
	mainFrame->Draw();
	SetTopWindow(mainFrame);

	return true;
}