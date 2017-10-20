#include "Shape.h"
#include "ofGraphics.h"
#include "Body.h"

Circle::Circle(float radius)
{
	this->radius = radius;

}
void Circle::draw()
{
	ofSetColor(0, 255, 0);
	ofNoFill();
	ofDrawCircle(body->position.x, body->position.y, radius);

}
Shape::ShapeType Circle::getType()
{
	return Shape::CIRCLE;
}

void REKT::draw()
{
	ofSetColor(0, 255, 0);
	ofNoFill();
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofDrawRectangle(body->position.x, body->position.y, width, height);

}

REKT::REKT(float width, float heigth)
{
	this->width = width;
	this->height = heigth;
}

Shape::ShapeType REKT::getType()
{
	return Shape::REKT;
	
}
