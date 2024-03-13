///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/slider.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MainFrame
///////////////////////////////////////////////////////////////////////////////
class MainFrame : public wxFrame
{
private:

protected:
	wxPanel* m_panel2;
	wxStaticText* m_staticText_leftShoulder;
	wxSlider* m_slider_leftShoulder;
	wxStaticText* m_staticText_leftElbow;
	wxSlider* m_slider_leftElbow;
	wxStaticText* m_staticText_leftHip;
	wxSlider* m_slider_leftHip;
	wxStaticText* m_staticText_LeftLeg;
	wxSlider* m_slider_leftLeg;
	wxStaticText* m_staticText_leftKnee;
	wxSlider* m_slider_LeftKnee;
	wxStaticText* m_staticText_neck;
	wxSlider* m_slider_Neck;
	wxStaticText* m_staticText_rightShoulder;
	wxSlider* m_slider_rightShoulder;
	wxStaticText* m_staticText_rightElbow;
	wxSlider* m_slider_rightElbow;
	wxStaticText* m_staticText_rightHip;
	wxSlider* m_slider_rightHip;
	wxStaticText* m_staticText_RightLeg;
	wxSlider* m_slider_rightLeg;
	wxStaticText* m_staticText_rightKnee;
	wxSlider* m_slider_RightKnee;
	wxStaticText* m_staticText_spine;
	wxSlider* m_slider_Spine;

	// Virtual event handlers, override them in your derived class
	virtual void m_panel2OnSize(wxSizeEvent& event) { event.Skip(); }
	virtual void m_slider_leftShoulderOnScroll(wxScrollEvent& event) { event.Skip(); }
	virtual void m_slider_leftElbowOnScroll(wxScrollEvent& event) { event.Skip(); }
	virtual void m_slider_leftHipOnScroll(wxScrollEvent& event) { event.Skip(); }
	virtual void m_slider_leftLegOnScroll(wxScrollEvent& event) { event.Skip(); }
	virtual void m_slider_leftKneeOnScroll(wxScrollEvent& event) { event.Skip(); }
	virtual void m_slider_neckOnScroll(wxScrollEvent& event) { event.Skip(); }
	virtual void m_slider_rightShoulderOnScroll(wxScrollEvent& event) { event.Skip(); }
	virtual void m_slider_rightElbowOnScroll(wxScrollEvent& event) { event.Skip(); }
	virtual void m_slider_rightHipOnScroll(wxScrollEvent& event) { event.Skip(); }
	virtual void m_slider_rightLegOnScroll(wxScrollEvent& event) { event.Skip(); }
	virtual void m_slider_rightKneeOnScroll(wxScrollEvent& event) { event.Skip(); }
	virtual void m_slider_spineOnScroll(wxScrollEvent& event) { event.Skip(); }


public:

	MainFrame(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(800, 500), long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);

	~MainFrame();

};

