#include "Shape.h"
#include "Body.h"
#include "Player.h"

void Player::init(float x, float y, float r)
{
	CBody *b = new CBody(x, y);
	Shape *shape = new Circle(r);
	b->iMass = 1;
	b->setShape(shape);
	this->body = b;
	this->body->setType(CBody::PLAYER);
	dead = false;

	this->body->dynamicFriction = 7.0f;
	this->body->staticFriction = 7.0f;

	hp = 10;
}

void Player::onHit()
{
	hp -= 10;

	//cout << "Le Pego" << endl;
	if (hp <= 0 && !dead)
	{
		Kill();
		//	cout << "Se Petateo" << endl;
	}
}

void Player::Kill()
{
	dead = true;
	body->destroy = true;
}
