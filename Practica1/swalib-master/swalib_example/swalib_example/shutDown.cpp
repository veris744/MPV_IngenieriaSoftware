#include "shutDown.h"

void C_ShutDown::shutdown(C_Initialisation init)
{
	CORE_UnloadPNG(init.texbkg);
	CORE_UnloadPNG(init.texsmallball);
	FONT_End();
}