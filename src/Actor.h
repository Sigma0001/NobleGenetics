#pragma once
#include "Body.h"
#include "ofImage.h"

class Actor
{
public:
	CBody *body;
	float x, y;
	ofImage *img;
	float width ,height;

	void setImageWall(ofImage *image);

	Actor();
	void draw();
	void setImage(ofImage * image);
};