///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI.h"

///////////////////////////////////////////////////////////////////////////

MainFrame::MainFrame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer(wxVERTICAL);

	m_panel2 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	m_panel2->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNHIGHLIGHT));
	m_panel2->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNHIGHLIGHT));

	bSizer5->Add(m_panel2, 1, wxEXPAND | wxALL, 5);

	bSizer4->Add(bSizer5, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer(wxVERTICAL);

	m_staticText_leftShoulder = new wxStaticText(this, wxID_ANY, wxT("Left Shoulder"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText_leftShoulder->Wrap(-1);
	bSizer7->Add(m_staticText_leftShoulder, 0, wxALL, 5);

	m_slider_leftShoulder = new wxSlider(this, wxID_ANY, 0, -25, 25, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
	bSizer7->Add(m_slider_leftShoulder, 0, wxALL, 5);

	m_staticText_leftElbow = new wxStaticText(this, wxID_ANY, wxT("Left Elbow"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText_leftElbow->Wrap(-1);
	bSizer7->Add(m_staticText_leftElbow, 0, wxALL, 5);

	m_slider_leftElbow = new wxSlider(this, wxID_ANY, 0, -25, 25, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
	bSizer7->Add(m_slider_leftElbow, 0, wxALL, 5);

	m_staticText_leftHip = new wxStaticText(this, wxID_ANY, wxT("Left Hip"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText_leftHip->Wrap(-1);
	bSizer7->Add(m_staticText_leftHip, 0, wxALL, 5);

	m_slider_leftHip = new wxSlider(this, wxID_ANY, 0, -25, 25, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
	bSizer7->Add(m_slider_leftHip, 0, wxALL, 5);

	m_staticText_LeftLeg = new wxStaticText(this, wxID_ANY, wxT("Left Leg"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText_LeftLeg->Wrap(-1);
	bSizer7->Add(m_staticText_LeftLeg, 0, wxALL, 5);

	m_slider_leftLeg = new wxSlider(this, wxID_ANY, 0, -25, 25, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
	bSizer7->Add(m_slider_leftLeg, 0, wxALL, 5);

	m_staticText_leftKnee = new wxStaticText(this, wxID_ANY, wxT("Left Knee"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText_leftKnee->Wrap(-1);
	bSizer7->Add(m_staticText_leftKnee, 0, wxALL, 5);

	m_slider_LeftKnee = new wxSlider(this, wxID_ANY, 0, -25, 25, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
	bSizer7->Add(m_slider_LeftKnee, 0, wxALL, 5);

	m_staticText_neck = new wxStaticText(this, wxID_ANY, wxT("Neck"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText_neck->Wrap(-1);
	bSizer7->Add(m_staticText_neck, 0, wxALL, 5);

	m_slider_Neck = new wxSlider(this, wxID_ANY, 0, -25, 25, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
	bSizer7->Add(m_slider_Neck, 0, wxALL, 5);

	bSizer6->Add(bSizer7, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer(wxVERTICAL);

	m_staticText_rightShoulder = new wxStaticText(this, wxID_ANY, wxT("Right Shoulder"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText_rightShoulder->Wrap(-1);
	bSizer9->Add(m_staticText_rightShoulder, 0, wxALL, 5);

	m_slider_rightShoulder = new wxSlider(this, wxID_ANY, 0, -25, 25, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
	bSizer9->Add(m_slider_rightShoulder, 0, wxALL, 5);

	m_staticText_rightElbow = new wxStaticText(this, wxID_ANY, wxT("Right Elbow"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText_rightElbow->Wrap(-1);
	bSizer9->Add(m_staticText_rightElbow, 0, wxALL, 5);

	m_slider_rightElbow = new wxSlider(this, wxID_ANY, 0, -25, 25, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
	bSizer9->Add(m_slider_rightElbow, 0, wxALL, 5);

	m_staticText_rightHip = new wxStaticText(this, wxID_ANY, wxT("Right Hip"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText_rightHip->Wrap(-1);
	bSizer9->Add(m_staticText_rightHip, 0, wxALL, 5);

	m_slider_rightHip = new wxSlider(this, wxID_ANY, 0, -25, 25, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
	bSizer9->Add(m_slider_rightHip, 0, wxALL, 5);

	m_staticText_RightLeg = new wxStaticText(this, wxID_ANY, wxT("Right Leg"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText_RightLeg->Wrap(-1);
	bSizer9->Add(m_staticText_RightLeg, 0, wxALL, 5);

	m_slider_rightLeg = new wxSlider(this, wxID_ANY, 0, -25, 25, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
	bSizer9->Add(m_slider_rightLeg, 0, wxALL, 5);

	m_staticText_rightKnee = new wxStaticText(this, wxID_ANY, wxT("Right Knee"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText_rightKnee->Wrap(-1);
	bSizer9->Add(m_staticText_rightKnee, 0, wxALL, 5);

	m_slider_RightKnee = new wxSlider(this, wxID_ANY, 0, -25, 25, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
	bSizer9->Add(m_slider_RightKnee, 0, wxALL, 5);

	m_staticText_spine = new wxStaticText(this, wxID_ANY, wxT("Spine"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText_spine->Wrap(-1);
	bSizer9->Add(m_staticText_spine, 0, wxALL, 5);

	m_slider_Spine = new wxSlider(this, wxID_ANY, 0, -25, 25, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
	bSizer9->Add(m_slider_Spine, 0, wxALL, 5);


	bSizer6->Add(bSizer9, 1, wxEXPAND, 5);


	bSizer4->Add(bSizer6, 0, wxEXPAND, 5);


	this->SetSizer(bSizer4);
	this->Layout();

	this->Centre(wxBOTH);

	// Connect Events
	m_panel2->Connect(wxEVT_SIZE, wxSizeEventHandler(MainFrame::m_panel2OnSize), NULL, this);
	m_slider_leftShoulder->Connect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MainFrame::m_slider_leftShoulderOnScroll), NULL, this);
	m_slider_leftShoulder->Connect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MainFrame::m_slider_leftShoulderOnScroll), NULL, this);
	m_slider_leftShoulder->Connect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MainFrame::m_slider_leftShoulderOnScroll), NULL, this);
	m_slider_leftShoulder->Connect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MainFrame::m_slider_leftShoulderOnScroll), NULL, this);
	m_slider_leftShoulder->Connect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MainFrame::m_slider_leftShoulderOnScroll), NULL, this);
	m_slider_leftShoulder->Connect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MainFrame::m_slider_leftShoulderOnScroll), NULL, this);
	m_slider_leftShoulder->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MainFrame::m_slider_leftShoulderOnScroll), NULL, this);
	m_slider_leftShoulder->Connect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MainFrame::m_slider_leftShoulderOnScroll), NULL, this);
	m_slider_leftShoulder->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MainFrame::m_slider_leftShoulderOnScroll), NULL, this);
	m_slider_leftElbow->Connect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MainFrame::m_slider_leftElbowOnScroll), NULL, this);
	m_slider_leftElbow->Connect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MainFrame::m_slider_leftElbowOnScroll), NULL, this);
	m_slider_leftElbow->Connect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MainFrame::m_slider_leftElbowOnScroll), NULL, this);
	m_slider_leftElbow->Connect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MainFrame::m_slider_leftElbowOnScroll), NULL, this);
	m_slider_leftElbow->Connect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MainFrame::m_slider_leftElbowOnScroll), NULL, this);
	m_slider_leftElbow->Connect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MainFrame::m_slider_leftElbowOnScroll), NULL, this);
	m_slider_leftElbow->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MainFrame::m_slider_leftElbowOnScroll), NULL, this);
	m_slider_leftElbow->Connect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MainFrame::m_slider_leftElbowOnScroll), NULL, this);
	m_slider_leftElbow->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MainFrame::m_slider_leftElbowOnScroll), NULL, this);
	m_slider_leftHip->Connect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MainFrame::m_slider_leftHipOnScroll), NULL, this);
	m_slider_leftHip->Connect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MainFrame::m_slider_leftHipOnScroll), NULL, this);
	m_slider_leftHip->Connect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MainFrame::m_slider_leftHipOnScroll), NULL, this);
	m_slider_leftHip->Connect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MainFrame::m_slider_leftHipOnScroll), NULL, this);
	m_slider_leftHip->Connect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MainFrame::m_slider_leftHipOnScroll), NULL, this);
	m_slider_leftHip->Connect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MainFrame::m_slider_leftHipOnScroll), NULL, this);
	m_slider_leftHip->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MainFrame::m_slider_leftHipOnScroll), NULL, this);
	m_slider_leftHip->Connect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MainFrame::m_slider_leftHipOnScroll), NULL, this);
	m_slider_leftHip->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MainFrame::m_slider_leftHipOnScroll), NULL, this);
	m_slider_leftLeg->Connect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MainFrame::m_slider_leftLegOnScroll), NULL, this);
	m_slider_leftLeg->Connect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MainFrame::m_slider_leftLegOnScroll), NULL, this);
	m_slider_leftLeg->Connect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MainFrame::m_slider_leftLegOnScroll), NULL, this);
	m_slider_leftLeg->Connect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MainFrame::m_slider_leftLegOnScroll), NULL, this);
	m_slider_leftLeg->Connect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MainFrame::m_slider_leftLegOnScroll), NULL, this);
	m_slider_leftLeg->Connect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MainFrame::m_slider_leftLegOnScroll), NULL, this);
	m_slider_leftLeg->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MainFrame::m_slider_leftLegOnScroll), NULL, this);
	m_slider_leftLeg->Connect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MainFrame::m_slider_leftLegOnScroll), NULL, this);
	m_slider_leftLeg->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MainFrame::m_slider_leftLegOnScroll), NULL, this);
	m_slider_LeftKnee->Connect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MainFrame::m_slider_leftKneeOnScroll), NULL, this);
	m_slider_LeftKnee->Connect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MainFrame::m_slider_leftKneeOnScroll), NULL, this);
	m_slider_LeftKnee->Connect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MainFrame::m_slider_leftKneeOnScroll), NULL, this);
	m_slider_LeftKnee->Connect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MainFrame::m_slider_leftKneeOnScroll), NULL, this);
	m_slider_LeftKnee->Connect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MainFrame::m_slider_leftKneeOnScroll), NULL, this);
	m_slider_LeftKnee->Connect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MainFrame::m_slider_leftKneeOnScroll), NULL, this);
	m_slider_LeftKnee->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MainFrame::m_slider_leftKneeOnScroll), NULL, this);
	m_slider_LeftKnee->Connect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MainFrame::m_slider_leftKneeOnScroll), NULL, this);
	m_slider_LeftKnee->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MainFrame::m_slider_leftKneeOnScroll), NULL, this);
	m_slider_Neck->Connect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MainFrame::m_slider_neckOnScroll), NULL, this);
	m_slider_Neck->Connect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MainFrame::m_slider_neckOnScroll), NULL, this);
	m_slider_Neck->Connect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MainFrame::m_slider_neckOnScroll), NULL, this);
	m_slider_Neck->Connect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MainFrame::m_slider_neckOnScroll), NULL, this);
	m_slider_Neck->Connect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MainFrame::m_slider_neckOnScroll), NULL, this);
	m_slider_Neck->Connect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MainFrame::m_slider_neckOnScroll), NULL, this);
	m_slider_Neck->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MainFrame::m_slider_neckOnScroll), NULL, this);
	m_slider_Neck->Connect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MainFrame::m_slider_neckOnScroll), NULL, this);
	m_slider_Neck->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MainFrame::m_slider_neckOnScroll), NULL, this);
	m_slider_rightShoulder->Connect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MainFrame::m_slider_rightShoulderOnScroll), NULL, this);
	m_slider_rightShoulder->Connect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MainFrame::m_slider_rightShoulderOnScroll), NULL, this);
	m_slider_rightShoulder->Connect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MainFrame::m_slider_rightShoulderOnScroll), NULL, this);
	m_slider_rightShoulder->Connect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MainFrame::m_slider_rightShoulderOnScroll), NULL, this);
	m_slider_rightShoulder->Connect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MainFrame::m_slider_rightShoulderOnScroll), NULL, this);
	m_slider_rightShoulder->Connect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MainFrame::m_slider_rightShoulderOnScroll), NULL, this);
	m_slider_rightShoulder->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MainFrame::m_slider_rightShoulderOnScroll), NULL, this);
	m_slider_rightShoulder->Connect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MainFrame::m_slider_rightShoulderOnScroll), NULL, this);
	m_slider_rightShoulder->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MainFrame::m_slider_rightShoulderOnScroll), NULL, this);
	m_slider_rightElbow->Connect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MainFrame::m_slider_rightElbowOnScroll), NULL, this);
	m_slider_rightElbow->Connect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MainFrame::m_slider_rightElbowOnScroll), NULL, this);
	m_slider_rightElbow->Connect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MainFrame::m_slider_rightElbowOnScroll), NULL, this);
	m_slider_rightElbow->Connect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MainFrame::m_slider_rightElbowOnScroll), NULL, this);
	m_slider_rightElbow->Connect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MainFrame::m_slider_rightElbowOnScroll), NULL, this);
	m_slider_rightElbow->Connect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MainFrame::m_slider_rightElbowOnScroll), NULL, this);
	m_slider_rightElbow->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MainFrame::m_slider_rightElbowOnScroll), NULL, this);
	m_slider_rightElbow->Connect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MainFrame::m_slider_rightElbowOnScroll), NULL, this);
	m_slider_rightElbow->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MainFrame::m_slider_rightElbowOnScroll), NULL, this);
	m_slider_rightHip->Connect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MainFrame::m_slider_rightHipOnScroll), NULL, this);
	m_slider_rightHip->Connect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MainFrame::m_slider_rightHipOnScroll), NULL, this);
	m_slider_rightHip->Connect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MainFrame::m_slider_rightHipOnScroll), NULL, this);
	m_slider_rightHip->Connect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MainFrame::m_slider_rightHipOnScroll), NULL, this);
	m_slider_rightHip->Connect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MainFrame::m_slider_rightHipOnScroll), NULL, this);
	m_slider_rightHip->Connect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MainFrame::m_slider_rightHipOnScroll), NULL, this);
	m_slider_rightHip->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MainFrame::m_slider_rightHipOnScroll), NULL, this);
	m_slider_rightHip->Connect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MainFrame::m_slider_rightHipOnScroll), NULL, this);
	m_slider_rightHip->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MainFrame::m_slider_rightHipOnScroll), NULL, this);
	m_slider_rightLeg->Connect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MainFrame::m_slider_rightLegOnScroll), NULL, this);
	m_slider_rightLeg->Connect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MainFrame::m_slider_rightLegOnScroll), NULL, this);
	m_slider_rightLeg->Connect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MainFrame::m_slider_rightLegOnScroll), NULL, this);
	m_slider_rightLeg->Connect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MainFrame::m_slider_rightLegOnScroll), NULL, this);
	m_slider_rightLeg->Connect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MainFrame::m_slider_rightLegOnScroll), NULL, this);
	m_slider_rightLeg->Connect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MainFrame::m_slider_rightLegOnScroll), NULL, this);
	m_slider_rightLeg->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MainFrame::m_slider_rightLegOnScroll), NULL, this);
	m_slider_rightLeg->Connect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MainFrame::m_slider_rightLegOnScroll), NULL, this);
	m_slider_rightLeg->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MainFrame::m_slider_rightLegOnScroll), NULL, this);
	m_slider_RightKnee->Connect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MainFrame::m_slider_rightKneeOnScroll), NULL, this);
	m_slider_RightKnee->Connect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MainFrame::m_slider_rightKneeOnScroll), NULL, this);
	m_slider_RightKnee->Connect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MainFrame::m_slider_rightKneeOnScroll), NULL, this);
	m_slider_RightKnee->Connect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MainFrame::m_slider_rightKneeOnScroll), NULL, this);
	m_slider_RightKnee->Connect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MainFrame::m_slider_rightKneeOnScroll), NULL, this);
	m_slider_RightKnee->Connect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MainFrame::m_slider_rightKneeOnScroll), NULL, this);
	m_slider_RightKnee->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MainFrame::m_slider_rightKneeOnScroll), NULL, this);
	m_slider_RightKnee->Connect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MainFrame::m_slider_rightKneeOnScroll), NULL, this);
	m_slider_RightKnee->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MainFrame::m_slider_rightKneeOnScroll), NULL, this);
	m_slider_Spine->Connect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MainFrame::m_slider_spineOnScroll), NULL, this);
	m_slider_Spine->Connect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MainFrame::m_slider_spineOnScroll), NULL, this);
	m_slider_Spine->Connect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MainFrame::m_slider_spineOnScroll), NULL, this);
	m_slider_Spine->Connect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MainFrame::m_slider_spineOnScroll), NULL, this);
	m_slider_Spine->Connect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MainFrame::m_slider_spineOnScroll), NULL, this);
	m_slider_Spine->Connect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MainFrame::m_slider_spineOnScroll), NULL, this);
	m_slider_Spine->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MainFrame::m_slider_spineOnScroll), NULL, this);
	m_slider_Spine->Connect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MainFrame::m_slider_spineOnScroll), NULL, this);
	m_slider_Spine->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MainFrame::m_slider_spineOnScroll), NULL, this);
}

MainFrame::~MainFrame()
{
	// Disconnect Events
	m_panel2->Disconnect(wxEVT_SIZE, wxSizeEventHandler(MainFrame::m_panel2OnSize), NULL, this);
	m_slider_leftShoulder->Disconnect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MainFrame::m_slider_leftShoulderOnScroll), NULL, this);
	m_slider_leftShoulder->Disconnect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MainFrame::m_slider_leftShoulderOnScroll), NULL, this);
	m_slider_leftShoulder->Disconnect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MainFrame::m_slider_leftShoulderOnScroll), NULL, this);
	m_slider_leftShoulder->Disconnect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MainFrame::m_slider_leftShoulderOnScroll), NULL, this);
	m_slider_leftShoulder->Disconnect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MainFrame::m_slider_leftShoulderOnScroll), NULL, this);
	m_slider_leftShoulder->Disconnect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MainFrame::m_slider_leftShoulderOnScroll), NULL, this);
	m_slider_leftShoulder->Disconnect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MainFrame::m_slider_leftShoulderOnScroll), NULL, this);
	m_slider_leftShoulder->Disconnect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MainFrame::m_slider_leftShoulderOnScroll), NULL, this);
	m_slider_leftShoulder->Disconnect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MainFrame::m_slider_leftShoulderOnScroll), NULL, this);
	m_slider_leftElbow->Disconnect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MainFrame::m_slider_leftElbowOnScroll), NULL, this);
	m_slider_leftElbow->Disconnect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MainFrame::m_slider_leftElbowOnScroll), NULL, this);
	m_slider_leftElbow->Disconnect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MainFrame::m_slider_leftElbowOnScroll), NULL, this);
	m_slider_leftElbow->Disconnect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MainFrame::m_slider_leftElbowOnScroll), NULL, this);
	m_slider_leftElbow->Disconnect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MainFrame::m_slider_leftElbowOnScroll), NULL, this);
	m_slider_leftElbow->Disconnect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MainFrame::m_slider_leftElbowOnScroll), NULL, this);
	m_slider_leftElbow->Disconnect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MainFrame::m_slider_leftElbowOnScroll), NULL, this);
	m_slider_leftElbow->Disconnect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MainFrame::m_slider_leftElbowOnScroll), NULL, this);
	m_slider_leftElbow->Disconnect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MainFrame::m_slider_leftElbowOnScroll), NULL, this);
	m_slider_leftHip->Disconnect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MainFrame::m_slider_leftHipOnScroll), NULL, this);
	m_slider_leftHip->Disconnect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MainFrame::m_slider_leftHipOnScroll), NULL, this);
	m_slider_leftHip->Disconnect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MainFrame::m_slider_leftHipOnScroll), NULL, this);
	m_slider_leftHip->Disconnect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MainFrame::m_slider_leftHipOnScroll), NULL, this);
	m_slider_leftHip->Disconnect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MainFrame::m_slider_leftHipOnScroll), NULL, this);
	m_slider_leftHip->Disconnect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MainFrame::m_slider_leftHipOnScroll), NULL, this);
	m_slider_leftHip->Disconnect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MainFrame::m_slider_leftHipOnScroll), NULL, this);
	m_slider_leftHip->Disconnect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MainFrame::m_slider_leftHipOnScroll), NULL, this);
	m_slider_leftHip->Disconnect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MainFrame::m_slider_leftHipOnScroll), NULL, this);
	m_slider_leftLeg->Disconnect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MainFrame::m_slider_leftLegOnScroll), NULL, this);
	m_slider_leftLeg->Disconnect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MainFrame::m_slider_leftLegOnScroll), NULL, this);
	m_slider_leftLeg->Disconnect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MainFrame::m_slider_leftLegOnScroll), NULL, this);
	m_slider_leftLeg->Disconnect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MainFrame::m_slider_leftLegOnScroll), NULL, this);
	m_slider_leftLeg->Disconnect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MainFrame::m_slider_leftLegOnScroll), NULL, this);
	m_slider_leftLeg->Disconnect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MainFrame::m_slider_leftLegOnScroll), NULL, this);
	m_slider_leftLeg->Disconnect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MainFrame::m_slider_leftLegOnScroll), NULL, this);
	m_slider_leftLeg->Disconnect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MainFrame::m_slider_leftLegOnScroll), NULL, this);
	m_slider_leftLeg->Disconnect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MainFrame::m_slider_leftLegOnScroll), NULL, this);
	m_slider_LeftKnee->Disconnect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MainFrame::m_slider_leftKneeOnScroll), NULL, this);
	m_slider_LeftKnee->Disconnect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MainFrame::m_slider_leftKneeOnScroll), NULL, this);
	m_slider_LeftKnee->Disconnect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MainFrame::m_slider_leftKneeOnScroll), NULL, this);
	m_slider_LeftKnee->Disconnect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MainFrame::m_slider_leftKneeOnScroll), NULL, this);
	m_slider_LeftKnee->Disconnect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MainFrame::m_slider_leftKneeOnScroll), NULL, this);
	m_slider_LeftKnee->Disconnect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MainFrame::m_slider_leftKneeOnScroll), NULL, this);
	m_slider_LeftKnee->Disconnect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MainFrame::m_slider_leftKneeOnScroll), NULL, this);
	m_slider_LeftKnee->Disconnect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MainFrame::m_slider_leftKneeOnScroll), NULL, this);
	m_slider_LeftKnee->Disconnect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MainFrame::m_slider_leftKneeOnScroll), NULL, this);
	m_slider_Neck->Disconnect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MainFrame::m_slider_neckOnScroll), NULL, this);
	m_slider_Neck->Disconnect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MainFrame::m_slider_neckOnScroll), NULL, this);
	m_slider_Neck->Disconnect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MainFrame::m_slider_neckOnScroll), NULL, this);
	m_slider_Neck->Disconnect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MainFrame::m_slider_neckOnScroll), NULL, this);
	m_slider_Neck->Disconnect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MainFrame::m_slider_neckOnScroll), NULL, this);
	m_slider_Neck->Disconnect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MainFrame::m_slider_neckOnScroll), NULL, this);
	m_slider_Neck->Disconnect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MainFrame::m_slider_neckOnScroll), NULL, this);
	m_slider_Neck->Disconnect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MainFrame::m_slider_neckOnScroll), NULL, this);
	m_slider_Neck->Disconnect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MainFrame::m_slider_neckOnScroll), NULL, this);
	m_slider_rightShoulder->Disconnect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MainFrame::m_slider_rightShoulderOnScroll), NULL, this);
	m_slider_rightShoulder->Disconnect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MainFrame::m_slider_rightShoulderOnScroll), NULL, this);
	m_slider_rightShoulder->Disconnect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MainFrame::m_slider_rightShoulderOnScroll), NULL, this);
	m_slider_rightShoulder->Disconnect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MainFrame::m_slider_rightShoulderOnScroll), NULL, this);
	m_slider_rightShoulder->Disconnect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MainFrame::m_slider_rightShoulderOnScroll), NULL, this);
	m_slider_rightShoulder->Disconnect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MainFrame::m_slider_rightShoulderOnScroll), NULL, this);
	m_slider_rightShoulder->Disconnect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MainFrame::m_slider_rightShoulderOnScroll), NULL, this);
	m_slider_rightShoulder->Disconnect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MainFrame::m_slider_rightShoulderOnScroll), NULL, this);
	m_slider_rightShoulder->Disconnect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MainFrame::m_slider_rightShoulderOnScroll), NULL, this);
	m_slider_rightElbow->Disconnect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MainFrame::m_slider_rightElbowOnScroll), NULL, this);
	m_slider_rightElbow->Disconnect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MainFrame::m_slider_rightElbowOnScroll), NULL, this);
	m_slider_rightElbow->Disconnect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MainFrame::m_slider_rightElbowOnScroll), NULL, this);
	m_slider_rightElbow->Disconnect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MainFrame::m_slider_rightElbowOnScroll), NULL, this);
	m_slider_rightElbow->Disconnect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MainFrame::m_slider_rightElbowOnScroll), NULL, this);
	m_slider_rightElbow->Disconnect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MainFrame::m_slider_rightElbowOnScroll), NULL, this);
	m_slider_rightElbow->Disconnect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MainFrame::m_slider_rightElbowOnScroll), NULL, this);
	m_slider_rightElbow->Disconnect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MainFrame::m_slider_rightElbowOnScroll), NULL, this);
	m_slider_rightElbow->Disconnect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MainFrame::m_slider_rightElbowOnScroll), NULL, this);
	m_slider_rightHip->Disconnect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MainFrame::m_slider_rightHipOnScroll), NULL, this);
	m_slider_rightHip->Disconnect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MainFrame::m_slider_rightHipOnScroll), NULL, this);
	m_slider_rightHip->Disconnect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MainFrame::m_slider_rightHipOnScroll), NULL, this);
	m_slider_rightHip->Disconnect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MainFrame::m_slider_rightHipOnScroll), NULL, this);
	m_slider_rightHip->Disconnect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MainFrame::m_slider_rightHipOnScroll), NULL, this);
	m_slider_rightHip->Disconnect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MainFrame::m_slider_rightHipOnScroll), NULL, this);
	m_slider_rightHip->Disconnect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MainFrame::m_slider_rightHipOnScroll), NULL, this);
	m_slider_rightHip->Disconnect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MainFrame::m_slider_rightHipOnScroll), NULL, this);
	m_slider_rightHip->Disconnect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MainFrame::m_slider_rightHipOnScroll), NULL, this);
	m_slider_rightLeg->Disconnect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MainFrame::m_slider_rightLegOnScroll), NULL, this);
	m_slider_rightLeg->Disconnect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MainFrame::m_slider_rightLegOnScroll), NULL, this);
	m_slider_rightLeg->Disconnect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MainFrame::m_slider_rightLegOnScroll), NULL, this);
	m_slider_rightLeg->Disconnect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MainFrame::m_slider_rightLegOnScroll), NULL, this);
	m_slider_rightLeg->Disconnect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MainFrame::m_slider_rightLegOnScroll), NULL, this);
	m_slider_rightLeg->Disconnect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MainFrame::m_slider_rightLegOnScroll), NULL, this);
	m_slider_rightLeg->Disconnect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MainFrame::m_slider_rightLegOnScroll), NULL, this);
	m_slider_rightLeg->Disconnect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MainFrame::m_slider_rightLegOnScroll), NULL, this);
	m_slider_rightLeg->Disconnect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MainFrame::m_slider_rightLegOnScroll), NULL, this);
	m_slider_RightKnee->Disconnect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MainFrame::m_slider_rightKneeOnScroll), NULL, this);
	m_slider_RightKnee->Disconnect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MainFrame::m_slider_rightKneeOnScroll), NULL, this);
	m_slider_RightKnee->Disconnect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MainFrame::m_slider_rightKneeOnScroll), NULL, this);
	m_slider_RightKnee->Disconnect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MainFrame::m_slider_rightKneeOnScroll), NULL, this);
	m_slider_RightKnee->Disconnect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MainFrame::m_slider_rightKneeOnScroll), NULL, this);
	m_slider_RightKnee->Disconnect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MainFrame::m_slider_rightKneeOnScroll), NULL, this);
	m_slider_RightKnee->Disconnect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MainFrame::m_slider_rightKneeOnScroll), NULL, this);
	m_slider_RightKnee->Disconnect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MainFrame::m_slider_rightKneeOnScroll), NULL, this);
	m_slider_RightKnee->Disconnect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MainFrame::m_slider_rightKneeOnScroll), NULL, this);
	m_slider_Spine->Disconnect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MainFrame::m_slider_spineOnScroll), NULL, this);
	m_slider_Spine->Disconnect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MainFrame::m_slider_spineOnScroll), NULL, this);
	m_slider_Spine->Disconnect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MainFrame::m_slider_spineOnScroll), NULL, this);
	m_slider_Spine->Disconnect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MainFrame::m_slider_spineOnScroll), NULL, this);
	m_slider_Spine->Disconnect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MainFrame::m_slider_spineOnScroll), NULL, this);
	m_slider_Spine->Disconnect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MainFrame::m_slider_spineOnScroll), NULL, this);
	m_slider_Spine->Disconnect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MainFrame::m_slider_spineOnScroll), NULL, this);
	m_slider_Spine->Disconnect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MainFrame::m_slider_spineOnScroll), NULL, this);
	m_slider_Spine->Disconnect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MainFrame::m_slider_spineOnScroll), NULL, this);

}
