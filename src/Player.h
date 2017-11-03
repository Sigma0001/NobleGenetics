#pragma once
#include "Actor.h"

class Player : public Actor
{
public:
	bool dead;
	int hp;

	void init(float x, float y, float r);
	void onHit();
	void Kill();
};