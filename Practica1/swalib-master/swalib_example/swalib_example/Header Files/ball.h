#pragma once

#include "../../../common/stdafx.h"
#include "../../../common/core.h"
#include "../../../common/vector2d.h"

class Ball
{
public:
	vec2   pos;	// Position.
	vec2   vel;	// Velocity.
	GLuint gfx;	// OpenGL for id. for visualization purposes. 
	float  radius;	// Radius.

	Ball() :
		pos(0.0f),
		vel(0.0f),
		gfx(0),
		radius(0.0f)
	{}
};

