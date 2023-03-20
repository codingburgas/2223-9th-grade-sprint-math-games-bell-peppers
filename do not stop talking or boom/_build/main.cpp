#include "raylib.h"

int main() {

	InitWindow(1600, 1000, "Bombs");

	Texture2D menu = LoadTexture("../resources/menu.png");

	SetWindowIcon(LoadImage("../resources/menu.png"));

	while (!WindowShouldClose()) {

		BeginDrawing();

		DrawTexture(menu, 0, 0, WHITE);

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && GetMouseX() >= 94 && GetMouseX() <= 219 && GetMouseY() >= 365 && GetMouseY() <= 430) {
			UnloadTexture(menu);
		}
		else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && GetMouseX() >= 94 && GetMouseX() <= 209 && GetMouseY() >= 550 && GetMouseY() <= 605) {
			UnloadTexture(menu);
		}
		else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && GetMouseX() >= 94 && GetMouseX() <= 209 && GetMouseY() >= 755 && GetMouseY() <= 810) {
			return 0;
		}

		EndDrawing();
	}
	CloseWindow();
}