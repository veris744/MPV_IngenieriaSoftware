#include "../Header Files/gameLogic.h"


void C_GameLogic::rebound(Ball* balls, int i, int i_collidingBall)
{
	balls[i].vel = balls[i].vel * -1.f;
	balls[i_collidingBall].vel = balls[i_collidingBall].vel * -1.f;
}

void C_GameLogic::reboundOnMargins(Ball* balls, int i, int i_width, int i_height)
{
	if ((balls[i].pos.x > i_width) || (balls[i].pos.x < 0)) {
		balls[i].vel.x *= -1.0;
	}
	if ((balls[i].pos.y > i_height) || (balls[i].pos.y < 0)) {
		balls[i].vel.y *= -1.0;
	}
}

int C_GameLogic::detectCollision(Ball* balls, int i, vec2 v_newpos, int i_nBalls)
{
	int colliding_ball = -1;
	for (int j = 0; j < i_nBalls; j++) {
		if (i != j) {
			float limit2 = (balls[i].radius + balls[j].radius) * (balls[i].radius + balls[j].radius);
			if (vlen2(v_newpos - balls[j].pos) <= limit2) {
				colliding_ball = j;
				break;
			}
		}
		return colliding_ball;
	}

}

void C_GameLogic::runBalls(Ball* balls, int i_nBalls, int i_width, int i_height)
{
	// Run balls
	for (int i = 0; i < i_nBalls; i++) {
		// New Pos.
		vec2 newpos = balls[i].pos + balls[i].vel;

		// Collision detection.
		int colliding_ball = detectCollision(balls, i, newpos, i_nBalls);


		if (colliding_ball == -1) {
			balls[i].pos = newpos;
		}
		else {
			// Rebound!
			rebound(balls, i, colliding_ball);
		}

		// Rebound on margins.
		reboundOnMargins(balls, i, i_width, i_height);
	}
}