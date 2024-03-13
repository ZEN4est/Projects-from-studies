#pragma once
#include <wx/gdicmn.h>

class Point {
public:
	double x;
	double y;
    Point(): x(0.0), y(0.0) {}
    Point(double x, double y): x(x), y(y) {}
    operator wxPoint() const { return wxPoint(x, y); }
};

double angle(Point a, Point b, Point c);

class Frame
{
    private:
        Point leftLeg;
        Point rightLeg;
        Point leftHip;
        Point rightHip;
        Point lowerSpine;
        Point mediumSpine;
        Point neck;
        Point leftArm;
        Point rightArm;
        Point leftElbow;
        Point rightElbow;
        Point leftHand;
        Point rightHand;
        Point leftFoot;
        Point rightFoot;
        Point head;

        double angleLeftLeg = 0.0;
        double angleRightLeg = 0.0;
        double angleLeftHip = 0.0;
        double angleRightHip = 0.0;
        double angleLowerSpineLeft = 0.0;
        double angleLowerSpineRight = 0.0;
        double angleMediumSpine = 0.0;
        double angleNeck = 0.0;
        double angleLeftArm = 0.0;
        double angleRightArm = 0.0;
        double angleLeftElbow = 0.0;
        double angleRightElbow = 0.0;
       

    public:
        Frame();
        Frame(Point LeftLeg,Point RightLeg, Point leftHip, Point rightHip, Point lowerSpine, Point mediumSpine, Point upperSpine, Point leftArm, Point rightArm, Point leftElbow, Point rightElbow, Point leftHand, Point rightHand, Point leftFoot, Point rightFoot, Point Head);
        ~Frame();
        Point getLeftLeg();
        Point getRightLeg();
        Point getLeftHip();
        Point getRightHip();
        Point getLowerSpine();
        Point getMediumSpine();
        Point getNeck();
        Point getLeftArm();
        Point getRightArm();
        Point getLeftElbow();
        Point getRightElbow();
        Point getLeftHand();
        Point getRightHand();
        Point getLeftFoot();
        Point getRightFoot();
        Point getHead();
        void setLeftLeg(Point LeftLeg);
        void setRightLeg(Point RightLeg);
        void setLeftHip(Point leftHip);
        void setRightHip(Point rightHip);
        void setLowerSpine(Point lowerSpine);
        void setMediumSpine(Point mediumSpine);
        void setNeck(Point upperSpine);
        void setLeftArm(Point leftArm);
        void setRightArm(Point rightArm);
        void setLeftElbow(Point leftElbow);
        void setRightElbow(Point rightElbow);
        void setLeftHand(Point leftHand);
        void setRightHand(Point rightHand);
        void setLeftFoot(Point leftFoot);
        void setRightFoot(Point rightFoot);

        void setHead(Point head);
        void setFrame(Point LeftLeg, Point RightLeg, Point leftHip, Point rightHip, Point lowerSpine, Point mediumSpine, Point upperSpine, Point leftArm, Point rightArm, Point leftElbow, Point rightElbow, Point leftHand, Point rightHand, Point leftFoot, Point rightFoot, Point Head);
        static void rotateNode(Point &node, Point &center, double angle);
        void rotateLeftKnee(double angle);
        void rotateRightKnee(double angle);
        void rotateLeftLeg(double angle);
        void rotateRightLeg(double angle);
        void rotateLowerSpineLeft(double angle);
        void rotateLowerSpineRight(double angle);
        void rotateMediumSpine(double angle);
        void rotateNeck(double angle);
        void rotateLeftArm(double angle);
        void rotateRightArm(double angle);
        void rotateLeftElbow(double angle);
        void rotateRightElbow(double angle);
        void rotateRightHip(double angle);
        void rotateLeftHip(double angle);
};


