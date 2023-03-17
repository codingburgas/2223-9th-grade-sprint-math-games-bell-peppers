#include "raylib.h"

int main() {

	InitWindow(1600, 1000, "Bombs");

	Texture2D menu = LoadTexture("../resources/menu.png");

	while (!WindowShouldClose()) {


		BeginDrawing();
		
		DrawTexture(menu, 0, 0, WHITE);
		
		EndDrawing();
	}
	CloseWindow();
}