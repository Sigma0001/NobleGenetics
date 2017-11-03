#pragma once
//#include "Body.h" forward declaration, le prometemos que esto estara compilado


class CBody;
class Shape
{
public:
	enum ShapeType
	{
		CIRCLE,
		REKT
	};

	float radius;
	float width;
	float height;
	CBody *body;
	//Otra promesa de que habra un body
	virtual void draw() = 0;
	//virtual pura, para sobrecargar otras clases con comandos reales
	virtual ShapeType getType() = 0;
//
};

class  Circle : public Shape
{
public:
	float radius; 
	Circle(float radius);
	void draw();
	ShapeType getType();
};

class  REKT : public Shape
{
public:
	float width;
	float height;
	REKT(float width, float height);
	void draw();
	ShapeType getType();
};