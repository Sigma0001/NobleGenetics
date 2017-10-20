#pragma once
#include "Body.h"
#include "ofVec2f.h"

class Contact {
public:
	CBody * body_A;
	CBody * body_B;


	ofVec2f normal;
	ofVec2f cPoints[2];
	float collisionDeep;
	int collission_count;
	void positionalCorrection();

	Contact(CBody*a, CBody*b);
	void solve();
	void applyImpulse();
	void infiniteMassCorrection();
};