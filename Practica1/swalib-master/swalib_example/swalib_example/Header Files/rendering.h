#pragma once
#include "../../../common/stdafx.h"
#include "../../../common/core.h"
#include "../../../common/sys.h"
#include "initialisation.h"
#include "ball.h"

class C_Rendering
{
public:
	void render(Ball* balls, int i_nBalls, int i_width, int i_height, C_Initialisation init);
	C_Rendering() {};

private:
	void renderBackground(int i_width, int i_height, C_Initialisation init);
	void renderBalls(Ball* balls, int i_nBalls);

};

