#pragma once

#include "../../../common/font.h"
#include "../../../common/stdafx.h"
#include "../../../common/core.h"
#include "../../../common/vector2d.h"
#include "ball.h"

class C_Initialisation
{
public:
	void initialiseGame(Ball* balls, unsigned int u_nBalls, int i_scrWidth, int i_scrHeight, int i_maxSpeed);
	GLuint texbkg;
	GLuint texsmallball;

	C_Initialisation() :
		texbkg(NULL),
		texsmallball(NULL)
	{}


private: 
	void loadTextures();
	void gameStateinitialise(Ball* balls, unsigned int u_nBalls, int i_scrWidth, int i_scrHeight, int i_maxSpeed);
	void renderInitialise(int i_scrWidth, int i_scrHeight);

};

