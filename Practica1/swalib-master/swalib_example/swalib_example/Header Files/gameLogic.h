#pragma once
#include "ball.h"

class C_GameLogic
{
public:
	void runBalls(Ball* balls, int i_nBalls, int i_width, int i_height);
	C_GameLogic() {};

private:
	int detectCollision(Ball* balls, int i, vec2 v_newpos, int i_nBalls);
	void rebound(Ball* balls, int i, int i_collidingBall);
	void reboundOnMargins(Ball* balls, int i, int i_width, int i_height);


};

