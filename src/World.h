#pragma once
#include <vector>
#include "Body.h"
#include "Contact.h"
#include "ofEventUtils.h"

using namespace std;

class World
{
private:
		static World * _singleton;
		World();

public:
	static World* getInstance();
	vector <CBody*> bodies;
	vector <Contact> contacts;
	ofEvent<Contact> onCollide;

	void update();
	void draw();
	void addFloor();
	void addCircle(float x, float y, float radius);
	void addRectangle(float x, float y, float w, float h);

	void addPlayer(float mX, float mY);
};
