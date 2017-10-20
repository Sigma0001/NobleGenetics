#include "Contact.h"
#include "Collision.h"

#define EPSILON 0.0001f

Contact::Contact(CBody *a, CBody *b)
{
	this->body_A = a;
	this->body_B = b;
	collission_count = 0;
}

void Contact::positionalCorrection()
{
	const float k_slop = 0.2f;
	const float percent = 0.8f;

	ofVec2f correction = (std::max(collisionDeep - k_slop, 0.0f) / (body_A -> iMass + body_B -> iMass))*normal*percent;

	body_A->position -= correction * body_A->iMass;
	body_B->position += correction * body_B->iMass;
}

void Contact::solve()
{
	//circleToCircle(this, body_A, body_B);
	if (body_A->shape->getType() == Shape::CIRCLE && body_B->shape->getType() == Shape::CIRCLE)
	{
		circleToCircle(this, body_A, body_B);
	}
	else if (body_A->shape->getType() == Shape::REKT && body_B->shape->getType() == Shape::REKT)
	{
		AABBvsAABB(this, body_A, body_B);
	}
	else if (body_A->shape->getType() == Shape::REKT && body_B->shape->getType() == Shape::CIRCLE)
	{
		AABBvsCircle(this, body_A, body_B);
	}
	else if (body_A->shape->getType() == Shape::CIRCLE && body_B->shape->getType() == Shape::REKT)
	{
		AABBvsCircle(this, body_A, body_B);
		this->normal = -this->normal;
	}
	//cout << "Cuerpo A: " << body_A->shape->getType() << endl;
	//cout << "Cuerpo B: " << body_B->shape->getType() << endl;
}

bool epsilonEqual(float a, float b)
{
	return std::abs(a - b) <= EPSILON;
}

void Contact::applyImpulse()
{
	if (epsilonEqual(body_A->iMass + body_B->iMass, 0))
	{
		infiniteMassCorrection();
		return;
	}
	ofVec2f rv = body_B->velocity - body_A->velocity;

	float velAlongNormal = rv.dot(normal);

	if (velAlongNormal > 0)
		return;

	float e = min(body_A->restitution, body_B->restitution);

	float invMassSum = body_A->iMass + body_B->iMass;

	float j = -((1 + e)*velAlongNormal);
	j /= invMassSum;

	ofVec2f impulse = j*normal;

	body_A->applyImpulse(-impulse*body_A->iMass);
	body_B->applyImpulse(impulse*body_B->iMass);


	rv = body_B->velocity - body_A->velocity;

	ofVec2f tangent = rv - (normal * rv.dot(normal));
	tangent.normalize();

	float jt = -rv.dot(tangent);
	jt /= invMassSum;

	ofVec2f frictionImpulse;

	float mu = min(body_A->staticFriction, body_B->staticFriction);
	if (abs(jt) < j * mu)
	{
		frictionImpulse = jt * tangent;
	} 
	else 
	{
		float dynamicFriction = min(body_A->dynamicFriction, body_B->dynamicFriction);
		frictionImpulse = -j * tangent * dynamicFriction;
	}

	body_A->applyImpulse(-body_A->iMass* frictionImpulse);

	body_B->applyImpulse(body_B->iMass* frictionImpulse);
}

	void Contact::infiniteMassCorrection()
	{
		body_A->velocity.set(0,0);
	    body_B->velocity.set(0,0);
	}