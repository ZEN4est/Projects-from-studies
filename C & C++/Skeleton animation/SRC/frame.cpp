#include "frame.h"

double angle(Point a, Point b, Point c)
{
    double x1 = a.x - b.x;
    double x2 = c.x - b.x;
    double y1 = a.y - b.y;
    double y2 = c.y - b.y;
    double angle1 = atan2(y1,x1);
    double angle2 = atan2(y2,x2);
    double angle = angle1 - angle2;
    return angle;
}



double distance_p(Point a, Point b)
{
	double x = a.x - b.x;
	double y = a.y - b.y;
	double distance = sqrt(pow(x,2) + pow(y,2));
	return distance;
}

double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
}

Frame::Frame()
{
    leftLeg = Point(0,0);
    rightLeg = Point(0,0);
    leftHip = Point(0,0);
    rightHip = Point(0,0);
    lowerSpine = Point(0,0);
    mediumSpine = Point(0,0);
    neck = Point(0,0);
    leftArm = Point(0,0);
    rightArm = Point(0,0);
    leftElbow = Point(0,0);
    rightElbow = Point(0,0);
    leftHand = Point(0, 0);
    rightHand = Point(0, 0);
    leftFoot = Point(0, 0);
    rightFoot = Point(0, 0);
    head = Point(0, 0);
}


void Frame::rotateNode(Point &node, Point &center, double angle)
{
	double x = node.x - center.x;
	double y = node.y - center.y;
	double x1 = x*cos(angle) - y*sin(angle);
	double y1 = x*sin(angle) + y*cos(angle);
    
	node.x = x1 + center.x;
	node.y = y1 + center.y;
}

void Frame::rotateNeck(double angle)
{
    rotateNode(head, neck, (angle - angleNeck) * M_PI / 100);
    angleNeck = angle;
}

void Frame::rotateLeftElbow(double angle)
{
    rotateNode(leftHand, leftElbow, (angle - angleLeftElbow) * M_PI / 100);
    angleLeftElbow = angle;
}

void Frame::rotateLeftArm(double angle)
{
    rotateNode(leftHand, leftArm, (angle - angleLeftArm) * M_PI / 100);
    rotateNode(leftElbow, leftArm, (angle - angleLeftArm) * M_PI / 100);
    angleLeftArm = angle;
}

void Frame::rotateRightElbow(double angle)
{
    rotateNode(rightHand, rightElbow, (angle - angleRightElbow) * M_PI / 100);
    angleRightElbow = angle;
}

void Frame::rotateRightArm(double angle)
{
    rotateNode(rightHand, rightArm, (angle - angleRightArm) * M_PI / 100);
    rotateNode(rightElbow, rightArm, (angle - angleRightArm) * M_PI / 100);
    angleRightArm = angle;
}

void Frame::rotateLowerSpineLeft(double angle)
{
    rotateNode(leftHip, lowerSpine, (angle - angleLowerSpineLeft) * M_PI / 100);
    rotateNode(leftLeg, lowerSpine, (angle - angleLowerSpineLeft) * M_PI / 100);
    rotateNode(leftFoot, lowerSpine, (angle - angleLowerSpineLeft) * M_PI / 100);
    angleLowerSpineLeft = angle;
}

void Frame::rotateLowerSpineRight(double angle)
{
    rotateNode(rightHip, lowerSpine, (angle - angleLowerSpineRight) * M_PI / 100);
    rotateNode(rightLeg, lowerSpine, (angle - angleLowerSpineRight) * M_PI / 100);
    rotateNode(rightFoot, lowerSpine, (angle - angleLowerSpineRight) * M_PI / 100);
    angleLowerSpineRight = angle;
}

void Frame::rotateMediumSpine(double angle)
{
    rotateNode(neck, mediumSpine, (angle - angleMediumSpine) * M_PI / 100);
    rotateNode(leftArm, mediumSpine, (angle - angleMediumSpine) * M_PI / 100);
    rotateNode(rightArm, mediumSpine, (angle - angleMediumSpine) * M_PI / 100);
    rotateNode(leftElbow, mediumSpine, (angle - angleMediumSpine) * M_PI / 100);
    rotateNode(rightElbow, mediumSpine, (angle - angleMediumSpine) * M_PI / 100);
    rotateNode(leftHand, mediumSpine, (angle - angleMediumSpine) * M_PI / 100);
    rotateNode(rightHand, mediumSpine, (angle - angleMediumSpine) * M_PI / 100);
    rotateNode(head, mediumSpine, (angle - angleMediumSpine) * M_PI / 100);
    angleMediumSpine = angle;
}

void Frame::rotateLeftLeg(double angle)
{
	rotateNode(leftLeg, leftHip, (angle - angleLeftHip) * M_PI / 100);
    rotateNode(leftFoot, leftHip, (angle - angleLeftHip) * M_PI / 100);
    angleLeftHip = angle;
}

void Frame::rotateLeftKnee(double angle)
{
    rotateNode(leftFoot, leftLeg, (angle - angleLeftLeg) * M_PI / 100);
    angleLeftLeg = angle;
}

void Frame::rotateRightKnee(double angle)
{
    rotateNode(rightFoot, rightLeg, (angle - angleRightLeg) * M_PI / 100);
    angleRightLeg = angle;
}

void Frame::rotateRightLeg(double angle)
{
    rotateNode(rightLeg, rightHip, (angle - angleRightHip) * M_PI / 100);
    rotateNode(rightFoot, rightHip, (angle - angleRightHip) * M_PI / 100);
    angleRightHip = angle;
}

void Frame::rotateRightHip(double angle)
{
    rotateNode(rightHip, lowerSpine, (angle - angleRightHip) * M_PI / 100);
    

    rotateNode(rightLeg, lowerSpine, (angle - angleRightHip) * M_PI / 100);
    rotateNode(rightFoot, lowerSpine, (angle - angleRightHip) * M_PI / 100);

    angleRightHip = angle;
}

void Frame::rotateLeftHip(double angle)
{
    rotateNode(leftHip, lowerSpine, (angle - angleLeftHip) * M_PI / 100);
    rotateNode(leftLeg, lowerSpine, (angle - angleLeftHip) * M_PI / 100);
    rotateNode(leftFoot, lowerSpine, (angle - angleLeftHip) * M_PI / 100);

    angleLeftHip = angle;
}

void Frame::setFrame(Point LeftLeg, Point RightLeg, Point leftHip, Point rightHip, Point lowerSpine, Point mediumSpine, Point upperSpine, Point leftArm, Point rightArm, Point leftElbow, Point rightElbow, Point leftHand, Point rightHand, Point leftFoot, Point rightFoot, Point Head) {
    this->head = Head;
    this->neck = upperSpine;

    this->leftHand = leftHand;
    this->leftElbow = leftElbow;
    this->leftArm = leftArm;

    this->rightHand = rightHand;
    this->rightElbow = rightElbow;
    this->rightArm = rightArm;

    this->mediumSpine = mediumSpine;
    this->lowerSpine = lowerSpine;

    this->leftHip = leftHip;
    this->leftLeg = LeftLeg;
    this->leftFoot = leftFoot;

    this->rightHip = rightHip;
    this->rightLeg = RightLeg;
    this->rightFoot = rightFoot;
}

Frame::Frame(Point leftLeg, Point rightLeg, Point leftHip, Point rightHip, Point lowerSpine, Point mediumSpine, Point neck, Point leftArm, Point rightArm, Point leftElbow, Point rightElbow, Point leftHand, Point rightHand, Point leftFoot, Point rightFoot, Point head)

{
    this->leftLeg = leftLeg;
    this->rightLeg = rightLeg;
    this->leftHip = leftHip;
    this->rightHip = rightHip;
    this->lowerSpine = lowerSpine;
    this->mediumSpine = mediumSpine;
    this->neck = neck;
    this->leftArm = leftArm;
    this->rightArm = rightArm;
    this->leftElbow = leftElbow;
    this->rightElbow = rightElbow;
    this->leftFoot = leftFoot;
    this->rightFoot = rightFoot;
    this->rightHand = rightHand;
    this->leftHand = leftHand;
    this->head = head;
}

Frame::~Frame()
{
}

Point Frame::getLeftLeg()
{
    return leftLeg;
}

Point Frame::getRightLeg()
{
    return rightLeg;
}

Point Frame::getLeftHip()
{
    return leftHip;
}

Point Frame::getRightHip()
{
    return rightHip;
}

Point Frame::getLowerSpine()
{
    return lowerSpine;
}

Point Frame::getMediumSpine()
{
    return mediumSpine;
}

Point Frame::getNeck()
{
    return neck;
}

Point Frame::getLeftArm()
{
    return leftArm;
}

Point Frame::getRightArm()
{
    return rightArm;
}

Point Frame::getLeftElbow()
{
    return leftElbow;
}

Point Frame::getRightElbow()
{
    return rightElbow;
}

Point Frame::getLeftHand()
{
    return leftHand;
}

Point Frame::getRightHand()
{
    return rightHand;
}

Point Frame::getLeftFoot()
{
    return leftFoot;
}

Point Frame::getRightFoot()
{
    return rightFoot;
}
Point Frame::getHead()
{
    return head;
}

void Frame::setLeftLeg(Point leftLeg)
{
    this->leftLeg = leftLeg;
}

void Frame::setRightLeg(Point rightLeg)
{
    this->rightLeg = rightLeg;
}

void Frame::setLeftHip(Point leftHip)
{
    this->leftHip = leftHip;
}

void Frame::setRightHip(Point rightHip)
{
    this->rightHip = rightHip;
}

void Frame::setLowerSpine(Point lowerSpine)
{
    this->lowerSpine = lowerSpine;
}

void Frame::setMediumSpine(Point mediumSpine)
{
    this->mediumSpine = mediumSpine;
}

void Frame::setNeck(Point neck)
{
    this->neck = neck;
}

void Frame::setLeftArm(Point leftArm)
{
    this->leftArm = leftArm;
}

void Frame::setRightArm(Point rightArm)
{
    this->rightArm = rightArm;
}

void Frame::setLeftElbow(Point leftElbow)
{
    this->leftElbow = leftElbow;
}

void Frame::setRightElbow(Point rightElbow)
{
    this->rightElbow = rightElbow;
}

void Frame::setLeftHand(Point leftHand)
{
    this->leftHand = leftHand;
}

void Frame::setRightHand(Point rightHand)
{
    this->rightHand = rightHand;
}

void Frame::setLeftFoot(Point leftFoot)
{
    this->leftFoot = leftFoot;
}

void Frame::setRightFoot(Point rightFoot)
{
    this->rightFoot = rightFoot;
}
void Frame::setHead(Point head)
{
    this->head = head;
}