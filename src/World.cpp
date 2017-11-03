#include "World.h"
#include "Shape.h"
#include "Body.h"
#include "Contact.h"
#include"ofAppRunner.h"

World * World::_singleton = new World();

World* World::getInstance()
{
	return _singleton;
}

World::World()
{

}

void World::update()
{
	contacts.clear();

	for (int i = 0; i < bodies.size(); i++)
	{
		CBody * body_A = bodies[i];
		for (int j = i + 1; j < bodies.size(); j++)
		{
			CBody * body_B = bodies[j];
			Contact c(body_A, body_B);
			c.solve();

			if (c.collission_count)// > 0)
			{
				ofNotifyEvent(onCollide, c);
				contacts.push_back(c);
			}
		}
	}


	for (int j = 0; j < 24; j++)
	{
		for (auto &c : contacts)
		{
			c.applyImpulse();
		}
	}

	for (auto &c : contacts)
	{
		c.positionalCorrection();
	}

		for (auto &b : bodies)
		{
			b->update();
		}

}

void World::draw()
{
	for (auto &b : bodies) {
		b->draw();
	}

}

void World::addBody(CBody * body)
{
	bodies.push_back(body);
}

void World::addCircle(float x, float y, float radius)
{
	Circle *c = new Circle(radius);
	CBody *b = new CBody(x, y);
	b->setShape(c);
	bodies.push_back(b);
}

void World::addRectangle(float x, float y, float w, float h)
{
	Shape *r = new REKT(w, h);
	CBody * b = new CBody(x, y);
	b->setShape(r);
	bodies.push_back(b);
}


void World::addFloor()
{
	Shape * shape = new REKT(1024,20);
	CBody * body = new CBody(ofGetWidth() / 2, 530);
	body->iMass = 0;
	body->setShape(shape);
	bodies.push_back(body);
}

void World::addPlayer(float mX, float mY)
{
	Shape * shape = new REKT(20,20);
	CBody * body = new CBody(mX, mY);
	body->iMass = 0;
	body->setShape(shape);
	bodies.push_back(body);
}
