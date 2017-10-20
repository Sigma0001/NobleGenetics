#include "Body.h"
#include "ofGraphics.h"
#include "ofMath.h"
#include "ofVec2f.h"
#include "ofApp.h"
#include "Shape.h"
#include "ofAppRunner.h"

CBody::CBody(float x, float y)
{
	position.set(x, y);//set ya tiene x Y y
	//this->velocity.set(0, 0);
	acceleration.set(0, 6);//0.0005);
	restitution = 0.2;
	iMass = 1;
	staticFriction = 0.2f;
	dynamicFriction = 0.1f;
}


void CBody::update()
{
	applyForce(acceleration);
	velocity += force*iMass*DT;
	position += velocity*DT;
	force.set(0, 0);
	//velocity += acceleration*(DT / 2.0f);
	//boundsCollision();
}
void CBody::draw()
{
	this->shape->draw();
}
void CBody::setShape(Shape* r)
{
	
	this->shape = r;
	r->body = this;
	//linkea body y shape, para que el tipo de shape sea inconsecuente a asignar un body

}
//void CBody::boundsCollision()
//{
//	
//	if (position.x > ofGetWidth())
//	{
//		position.x = ofGetWidth();
//		velocity.x *= -0.8;
//	}
//	else if (position.x < 0)
//	{
//		velocity.x *= -0.8;
//		position.x = 0;
//	}
//	if (position.y > ofGetHeight())
//	{
//		velocity.y *= -0.8;
//		position.y = ofGetHeight();
//	}
//	
//}

void CBody::applyForce(const ofVec2f& f)
{
	force += f;
}

void CBody::applyImpulse(const ofVec2f& impulse)
{
	velocity += impulse;
}