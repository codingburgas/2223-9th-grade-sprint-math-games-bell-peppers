#include "raylib.h"

int main() {

	InitWindow(1600, 1000, "Bombs");

	Texture2D menu = LoadTexture("../resources/menu.png");

	while (!WindowShouldClose()) {


		BeginDrawing();

		DrawTexture(menu, 0, 0, WHITE);

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && GetMouseX() >= 94 && GetMouseX() <= 209 && GetMouseY() >= 745 && GetMouseY() <= 800) {
			return 0;
		}

		EndDrawing();
	}
	CloseWindow();
}