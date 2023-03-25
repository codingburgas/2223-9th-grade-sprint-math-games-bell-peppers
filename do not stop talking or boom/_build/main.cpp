#include "gameManager.h"

int main() {

	Initialize();

	while (!ShouldClose()) {

		Update();
		
	}
	CloseWindow();
}