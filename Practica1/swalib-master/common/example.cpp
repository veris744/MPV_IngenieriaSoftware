#include "stdafx.h"
#include "sys.h"
#include "core.h"
#include "font.h"
#include "vector2d.h"
#include "../swalib_example/swalib_example/Header Files/ball.h"
#include "../swalib_example/swalib_example/Header Files/initialisation.h"
#include "../swalib_example/swalib_example/Header Files/gameLogic.h"
#include "../swalib_example/swalib_example/Header Files/rendering.h"
#include "../swalib_example/swalib_example/Header Files/shutDown.h"
//#include "../swalib_example/swalib_example/initialisation.h"

//-----------------------------------------------------------------------------

const unsigned int NUM_BALLS = 10;	// Max. num balls.
Ball balls[NUM_BALLS];	// Array of balls.

const float MAX_BALL_SPEED = 8.f;	// Max vel. of ball. (pixels/?).

//-----------------------------------------------------------------------------
int Main(void)
{
	
	C_Initialisation initialisation;
	initialisation.initialiseGame(balls, NUM_BALLS, SCR_WIDTH, SCR_HEIGHT, MAX_BALL_SPEED);
  
	while (!SYS_GottaQuit()) {	// Controlling a request to terminate an application.
		

		// Run balls
		C_GameLogic gameLogic;
		gameLogic.runBalls(balls, NUM_BALLS, SCR_WIDTH, SCR_HEIGHT);
		 

		// Render
		C_Rendering rendering;
		rendering.render(balls, NUM_BALLS, SCR_WIDTH, SCR_HEIGHT, initialisation);
	}

	// End app.
	C_ShutDown shuttingDown;
	shuttingDown.shutdown(initialisation);
	

	return 0;
}
