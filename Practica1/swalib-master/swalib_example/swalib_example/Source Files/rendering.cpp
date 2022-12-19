#include "../Header Files/rendering.h"

void	C_Rendering::renderBackground(int i_width, int i_height, C_Initialisation init)
{
	for (int i = 0; i <= i_width / 128; i++) {
		for (int j = 0; j <= i_height / 128; j++) {
			CORE_RenderCenteredSprite(vec2(i * 128.f + 64.f, j * 128.f + 64.f), vec2(128.f, 128.f), init.texbkg);
		}
	}
}

void C_Rendering::renderBalls(Ball* balls, int i_nBalls)
{
	for (int i = 0; i < i_nBalls; i++) {
		CORE_RenderCenteredSprite(balls[i].pos, vec2(balls[i].radius * 2.f, balls[i].radius * 2.f), balls[i].gfx);
	}
}

void C_Rendering::render(Ball* balls, int i_nBalls, int i_width, int i_height, C_Initialisation init)
{
	glClear(GL_COLOR_BUFFER_BIT);

	renderBackground(i_width, i_height, init);

	renderBalls(balls, i_nBalls);

	// Text
	FONT_DrawString(vec2(i_width / 2 - 6 * 16, 16), "HELLO WORLD!");

	// Exchanges the front and back buffers
	SYS_Show();

	SYS_Pump();	// Process Windows messages.
	SYS_Sleep(17);	// To force 60 fps
}