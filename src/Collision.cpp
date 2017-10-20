#include "Collision.h"
#include "ofMain.h"


void circleToCircle(Contact *c, CBody *a, CBody *b)
{
	Circle *cA = reinterpret_cast<Circle *> (a->shape);
	Circle *cB = reinterpret_cast<Circle *> (b->shape);

	ofVec2f normal = b->position - a->position;

	float dist_sqr = normal.lengthSquared();
	float radius = cA->radius + cB->radius;

	if (dist_sqr >= radius*radius)
	{
		c->collission_count = 0;
		return;
	}

	float distance = std::sqrt(dist_sqr);
	c->collission_count = 1;

	if (distance == 0.0f)
	{
		c->collisionDeep = cA->radius;
		c->normal = ofVec2f(1, 0);
		c->cPoints[0] = a->position;
	}
	else 
	{
		c->collisionDeep = radius - distance;
		c->normal = normal/distance;
		c->cPoints[0] = c->normal * cA->radius + a->position;
	}
}

void AABBvsAABB(Contact *c, CBody *a, CBody *b)
{
	REKT * box_a = reinterpret_cast<REKT*>(a->shape);
	REKT * box_b = reinterpret_cast<REKT*>(b->shape);

	ofVec2f n = box_b->body->position - box_a->body->position;

	float a_extent = box_a->width / 2;
	float b_extent = box_b->width / 2;

	float x_overlap = a_extent + b_extent - abs(n.x);

	if (x_overlap > 0)
	{
		float a_extent = box_a->height/2;
		float b_extent = box_b->height / 2;

		float y_overlap = a_extent + b_extent - abs(n.y);

		if (y_overlap > 0)
		{
			c->collission_count = 1;

			ofVec2f fixNormal;
			n.normalize();
			n.x = floor(n.x);
			n.y = floor(n.y);

			if (x_overlap < y_overlap)
			{
				if (n.x < 0)
					fixNormal = ofVec2f(1, 0);
				
				else
					fixNormal = ofVec2f(-1, 0);
				c->normal = n*fixNormal;
				c->cPoints[0] = box_a->body->position - fixNormal*box_a->width / 2;
				c->collisionDeep = x_overlap;
				return;
			}
			else 
			{
				if (n.y < 0)
					fixNormal = ofVec2f(0, 1);
				else
					fixNormal = ofVec2f(0, -2);
				c->cPoints[0] = box_a->body->position - fixNormal*box_a->height / 2;
				c->normal = n.getNormalized()*fixNormal;
				c->collisionDeep = y_overlap;
				return;
			}
		}
	}
	c->collission_count = 0;
}

void AABBvsCircle(Contact *c, CBody *a, CBody *b)
{
	REKT*aabb_a = reinterpret_cast<REKT*>(a->shape);
	Circle*circle_b = reinterpret_cast<Circle*>(b->shape);

	ofVec2f n = circle_b->body->position - aabb_a->body->position;

	ofVec2f closest = n;

	float x_extent = aabb_a->width/2;
	float y_extent = aabb_a->height/2;

	closest.x = ofClamp(n.x, -x_extent, x_extent);
	closest.y = ofClamp(n.y, -y_extent, y_extent);

	c->cPoints[0] = aabb_a->body->position + closest;
	bool inside = false;

	if(n == closest)
	{
		inside = true;

	if (abs(n.x) > abs(n.y))
	{
		if (closest.x > 0)
			closest.x = x_extent;
		else
			closest.x = -x_extent;	
	}

	else
	{
		if (closest.y > 0)
			closest.y = y_extent;
		else
			closest.y = -y_extent;
	}
	}

	ofVec2f normal = n - closest;

	float d = normal.lengthSquared();
	float r = circle_b->radius;

	if (d >= r*r && !inside)
	{
		c->collission_count = 0;
		return;
	}

	d = sqrt(d);

	if (inside)
	{
		c->normal = -normal.getNormalized();
		c->collisionDeep = r - d;
		c->collission_count = 1;
	}
	else
	{
		c->normal = normal.getNormalized();
		c->collisionDeep = r - d;
		c->collission_count = 1;
	}

}