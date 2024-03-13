#include "GUIMainFrame.h"

GUIMainFrame::GUIMainFrame( wxWindow* parent ):MainFrame( parent )
{

}

void GUIMainFrame::m_panel2OnSize(wxSizeEvent& event) {
	Draw();
}


void GUIMainFrame::m_slider_leftShoulderOnScroll( wxScrollEvent& event )
{
	szkieletor.rotateLeftArm(m_slider_leftShoulder->GetValue());
	Draw();
}

void GUIMainFrame::m_slider_leftElbowOnScroll( wxScrollEvent& event )
{
	szkieletor.rotateLeftElbow(m_slider_leftElbow->GetValue());
	Draw();
}

void GUIMainFrame::m_slider_leftHipOnScroll( wxScrollEvent& event )
{
	szkieletor.rotateLeftHip(m_slider_leftHip->GetValue());
	Draw();
}

void GUIMainFrame::m_slider_leftLegOnScroll(wxScrollEvent& event)
{
	szkieletor.rotateLeftLeg(m_slider_leftLeg->GetValue());
	Draw();
}

void GUIMainFrame::m_slider_leftKneeOnScroll( wxScrollEvent& event )
{
	szkieletor.rotateLeftKnee(m_slider_LeftKnee->GetValue());
	Draw();
}

void GUIMainFrame::m_slider_neckOnScroll( wxScrollEvent& event )
{
	szkieletor.rotateNeck(m_slider_Neck->GetValue());
	Draw();
}

void GUIMainFrame::m_slider_rightShoulderOnScroll( wxScrollEvent& event )
{
	szkieletor.rotateRightArm(m_slider_rightShoulder->GetValue());
	Draw();
}

void GUIMainFrame::m_slider_rightElbowOnScroll( wxScrollEvent& event )
{
	szkieletor.rotateRightElbow(m_slider_rightElbow->GetValue());
	Draw();
}

void GUIMainFrame::m_slider_rightHipOnScroll( wxScrollEvent& event )
{
	szkieletor.rotateRightHip(m_slider_rightHip->GetValue());
	Draw();
}

void GUIMainFrame::m_slider_rightLegOnScroll(wxScrollEvent& event)
{
	szkieletor.rotateRightLeg(m_slider_rightLeg->GetValue());
	Draw();
}

void GUIMainFrame::m_slider_rightKneeOnScroll( wxScrollEvent& event )
{
	szkieletor.rotateRightKnee(m_slider_RightKnee->GetValue());
	Draw();
}

void GUIMainFrame::m_slider_spineOnScroll( wxScrollEvent& event )
{
	szkieletor.rotateMediumSpine(m_slider_Spine->GetValue());
	Draw();
}

void GUIMainFrame::m_slider_endOfSpineOnScroll( wxScrollEvent& event )
{
	
}


void GUIMainFrame::Draw() {
	std::unique_ptr<wxClientDC> clientDC(new wxClientDC(m_panel2));
	bitmapBuffer = wxBitmap(m_panel2->GetSize());
	std::unique_ptr<wxBufferedDC> DC(new wxBufferedDC(clientDC.get(), bitmapBuffer));

	DC->SetDeviceOrigin(m_panel2->GetSize().x / 2, m_panel2->GetSize().y / 2-60);

	DC->SetBackground(*wxWHITE_BRUSH);
	DC->Clear();
	DC->SetBrush(*wxBLACK_BRUSH);
	//DC->SetPen(*wxBLACK_PEN);
	DC->DrawLine(szkieletor.getNeck(), szkieletor.getHead());//neck
	DC->DrawCircle(szkieletor.getNeck(), 3); //neck joint
	DC->DrawLine(szkieletor.getNeck(), szkieletor.getRightArm());//right shoulder
	DC->DrawCircle(szkieletor.getRightArm(), 3); //right shoulder joint
	DC->DrawLine(szkieletor.getRightArm(), szkieletor.getRightElbow());//right arm
	DC->DrawCircle(szkieletor.getRightElbow(), 3); //right elbow
	DC->DrawLine(szkieletor.getRightElbow(), szkieletor.getRightHand());//right forearm
	DC->DrawLine(szkieletor.getNeck(), szkieletor.getLeftArm());//left shoulder
	DC->DrawCircle(szkieletor.getLeftArm(), 3); //left shoulder joint
	DC->DrawLine(szkieletor.getLeftArm(), szkieletor.getLeftElbow());//left arm
	DC->DrawCircle(szkieletor.getLeftElbow(), 3); //left elbow
	DC->DrawLine(szkieletor.getLeftElbow(), szkieletor.getLeftHand());//left forearm
	DC->DrawLine(szkieletor.getNeck(), szkieletor.getMediumSpine());//spine
	DC->DrawCircle(szkieletor.getMediumSpine(), 3); //spine joint
	DC->DrawLine(szkieletor.getMediumSpine(), szkieletor.getLowerSpine());//endofspine
	DC->DrawCircle(szkieletor.getLowerSpine(), 3);//endofspine
	DC->DrawLine(szkieletor.getLowerSpine(), szkieletor.getRightHip());//right hip
	DC->DrawCircle(szkieletor.getRightHip(), 3);//right hip joint
	DC->DrawLine(szkieletor.getRightHip(), szkieletor.getRightLeg()); //right leg
	DC->DrawCircle(szkieletor.getRightLeg(), 3);//right leg joint
	DC->DrawLine(szkieletor.getRightLeg(), szkieletor.getRightFoot());//right calf
	DC->DrawLine(szkieletor.getLowerSpine(), szkieletor.getLeftHip());//left hip
	DC->DrawCircle(szkieletor.getLeftHip(), 3);//left hip joint
	DC->DrawLine(szkieletor.getLeftHip(), szkieletor.getLeftLeg()); //left leg
	DC->DrawCircle(szkieletor.getLeftLeg(), 3);//left leg joint
	DC->DrawLine(szkieletor.getLeftLeg(), szkieletor.getLeftFoot());//left calf


}

