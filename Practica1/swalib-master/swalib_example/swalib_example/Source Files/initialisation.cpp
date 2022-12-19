#include "../Header Files/initialisation.h"


void C_Initialisation::loadTextures()
{
	this->texbkg = CORE_LoadPNG("data/circle-bkg-128.png", true);
	this->texsmallball = CORE_LoadPNG("data/tyrian_ball.png", false);
}

void C_Initialisation::gameStateinitialise(Ball* balls, unsigned int u_nBalls, int i_scrWidth, int i_scrHeight, int i_maxSpeed)
{

	for (int i = 0; i < u_nBalls; i++) {
		balls[i].pos = vec2(CORE_FRand(0.0, i_scrWidth), CORE_FRand(0.0, i_scrHeight));
		balls[i].vel = vec2(CORE_FRand(-i_maxSpeed, +i_maxSpeed), CORE_FRand(-i_maxSpeed, +i_maxSpeed));
		balls[i].radius = 16.f;

		balls[i].gfx = this->texsmallball;
	}
}

void C_Initialisation::renderInitialise(int i_scrWidth, int i_scrHeight)
{
	glViewport(0, 0, i_scrWidth, i_scrHeight); // Sets up clipping.
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);	// Specifies clear values for the color buffers.
	glMatrixMode(GL_PROJECTION);	// Specifies projection matrix is the current matrix.
	glLoadIdentity();	// Replaces the current matrix with the identity matrix.
	glOrtho(0.0, i_scrWidth, 0.0, i_scrHeight, 0.0, 1.0);	// Multiplies the current matrix by an orthographic matrix.
	glEnable(GL_TEXTURE_2D);	// Enabling two-dimensional texturing.
	// NOTA: Mirar diferencias comentando las 2 siguientes funciones.
	glEnable(GL_BLEND);	// Blend the incoming RGBA color values with the values in the color buffers.
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);	// Blend func. for alpha color.
}

void C_Initialisation::initialiseGame(Ball* balls, unsigned int u_nBalls, int i_scrWidth, int i_scrHeight, int i_maxSpeed)
{
	FONT_Init();

	loadTextures();
	gameStateinitialise(balls, u_nBalls, i_scrWidth, i_scrHeight, i_maxSpeed);
	renderInitialise(i_scrWidth, i_scrHeight);
}