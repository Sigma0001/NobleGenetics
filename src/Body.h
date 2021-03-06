#pragma once
#include "ofVec2f.h"
class Shape;

class CBody
{
public:

	enum ActorType
	{
		PLAYER

	};

	ActorType type;

	ofVec2f velocity;
	ofVec2f acceleration;
	ofVec2f   position;
	Shape *shape;
	float restitution;
	ofVec2f   force;
	float iMass;
	float staticFriction;
	float dynamicFriction;

	CBody(float x, float y);
	void update();
	void draw();
	void setShape(Shape *shape);
	//void boundsCollision();

	bool destroy;

	
	void applyForce(const ofVec2f& f);
	void applyImpulse(const ofVec2f& impulse);

	void setType(ActorType t);
	ActorType getType();




};

