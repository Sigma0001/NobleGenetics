#include "Actor.h"
#include "Shape.h"
#include "ofGraphics.h"

Actor::Actor()
{
	img = NULL;
}

void Actor::draw()
{
	if (img != NULL)
	{
		ofRectMode(OF_RECTMODE_CENTER);
		img->draw(body->position.x, body->position.y, width, height);
	}
}

void Actor::setImage(ofImage *image)
{
	img = image;
	float r = body->shape->radius;

	width = r * 2;
	height = r * 2;
}
void Actor::setImageWall(ofImage *image)
{
	img = image;
	
	width = body->shape->width;
	height = body->shape->height;
}
