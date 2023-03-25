#include "gameManager.h"

	Texture2D menu;
	Vector2 position = { 0, 0 };
	Rectangle frameRec;
	int currentFrame = 0;
	bool shouldClose = false;
	const int timer = 300;
	bool write = false;
	char arr1[2] = { '\0' };
	Rectangle num1 = { 1005, 683, 15, 25 };
	time_t start, end, diff, timeLeft = 0;

void Initialize() {

	InitWindow(1600, 1000, "Bombs");

	SetTargetFPS(60);
	menu = LoadTexture("../resources/menu.png");
	frameRec = { 0, 0, (float)menu.width / 3, (float)menu.height };
}

bool ShouldClose() {
	return WindowShouldClose() || shouldClose;
}

void Close() {
	shouldClose = true;
}

void Update() {
	frameRec.x = (float)currentFrame * (float)menu.width / 3;
	if (CheckCollisionPointRec(GetMousePosition(), num1)) {
		write = true;
	}
	else {
		write = false;
	}

	if (write)
	{

		int key = GetCharPressed();

		while (key > 0)
		{
			if ((key >= 32) && (key <= 125))
			{
				arr1[0] = (char)key;
				arr1[1] = '\0';
			}

			key = GetCharPressed();  // Check next character in the queue
		}
	}
	BeginDrawing();

	ClearBackground(PURPLE);

	DrawTextureRec(menu, frameRec, position, WHITE);

	if (currentFrame == 0) {
		start = time(0);

		DrawRectangle(94, 365, 125, 65, GREEN);

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && GetMouseX() >= 94 && GetMouseX() <= 219 && GetMouseY() >= 365 && GetMouseY() <= 430) {
			currentFrame = 1;
		}
		else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && GetMouseX() >= 94 && GetMouseX() <= 209 && GetMouseY() >= 550 && GetMouseY() <= 605) {
			currentFrame = 2;
		}
		else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && GetMouseX() >= 94 && GetMouseX() <= 209 && GetMouseY() >= 755 && GetMouseY() <= 810) {
			Close();
		}
	}
	else if (currentFrame == 1) {

		DrawRectangleRec(num1, LIGHTGRAY);

		DrawText(arr1, 1005, 683, 40, MAROON);

		DrawText(TextFormat("%i:%02i", timeLeft / 60, timeLeft % 60), 755, 336, 62, WHITE);

		end = time(0);

		diff = end - start;

		timeLeft = timer - diff;

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && GetMouseX() >= 16 && GetMouseX() <= 141 && GetMouseY() >= 10 && GetMouseY() <= 75) {
			currentFrame = 0;
		}
	}

	else if (currentFrame == 2) {
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {

			currentFrame = 0;
		}
	}
	EndDrawing();

}