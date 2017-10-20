#pragma once

#include "Body.h"
#include "Shape.h"
#include "Contact.h"

void circleToCircle(Contact *c, CBody *a, CBody *b);
void AABBvsAABB(Contact *c, CBody *a, CBody *b);
void AABBvsCircle(Contact *c, CBody *a, CBody *b);