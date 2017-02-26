#include <stdlib.h>
#include <libgte.h>
#include <libgpu.h>
#include <libgs.h>
#include "constants.h"

void initialize();
void display();

GsOT orderingTable[2];
short currentBuffer;

int main() {

	initialize();

	while(1) {
		FntPrint("DamajaUK 2017 Presents\n\n\n\n\n\nPlaystation demo\n\n(c) 2017");
		display();
	}
	return 0;
}

void initialize() {
	initializeScreen();
	initializeDebugFont();
}

void display() {
	currentBuffer = GsGetActiveBuff();
	FntFlush(-1);
	GsClearOt(0, 0, &orderingTable[currentBuffer]);
	DrawSync(0);
	VSync(0);
	GsSwapDispBuff();
	GsSortClear(32, 32, 255, &orderingTable[currentBuffer]);
	GsDrawOt(&orderingTable[currentBuffer]);
}
