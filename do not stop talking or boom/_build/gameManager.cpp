#include "gameManager.h"

Texture2D menu;
Font font;
Vector2 position = { 0, 0 };
Rectangle frameRec;
Rectangle play = { 30, 355, 150, 82 };
Rectangle info = { 30, 555, 150, 75 };
Rectangle quit = { 28, 790, 150, 74 };
Rectangle exit = { 4, 10, 210, 65 };
Rectangle back = { 20, 5, 155, 50 };
int currentFrame = 0, strikes = 0;
bool shouldClose = false;
const int timer = 300;
bool write = false;
char arr1[3] = { '\0' };
Rectangle num1 = { 1005, 683, 15, 25 };
time_t start, end, diff, timeLeft = 0;
bool correct = false;

void Initialize() {

	InitWindow(1920, 1080, "Bombs");
	SetTargetFPS(60);
	ToggleFullscreen();
	menu = LoadTexture("../resources/menu.png");
	frameRec = { 0, 0, (float)menu.width / 5, (float)menu.height };
	font = LoadFont("../resources/font.ttf");
}

bool ShouldClose() {
	return WindowShouldClose() || shouldClose;
}

void Close() {
	shouldClose = true;
}

void Update() {
	frameRec.x = (float)currentFrame * (float)menu.width / 5;
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

			key = GetCharPressed();
		}
	}
	BeginDrawing();

	ClearBackground(PURPLE);

	DrawTextureRec(menu, frameRec, position, WHITE);

	if (currentFrame == 0) {
		start = time(0);

		button playButton = { play };

		button infoButton = { info };

		button quitButton = { quit };

		if (playButton.isClicked()) {
			currentFrame = 1;
		}
		else if (infoButton.isClicked()) {
			currentFrame = 2;
		}
		else if (quitButton.isClicked()) {
			Close();
		}
	}
	else if (currentFrame == 1) {

		DrawTextEx(font, "X  X", { 1212, 385 }, 80, 1, RED);

		/*DrawRectangleRec(num1, LIGHTGRAY);*/

		DrawText(arr1, 1005, 687, 26, BLACK);
		if (IsKeyPressed(KEY_ENTER) && arr1[0] == '1') {
			correct = true;
		}
		if (correct) {
			DrawCircle(10, 10, 10, GREEN);
		}

		DrawTextEx(font, TextFormat("%i:%02i", timeLeft / 60, timeLeft % 60), { 1135, 183 }, 180, 1, WHITE);

		end = time(0);

		diff = end - start;

		timeLeft = timer - diff;

		button exitButton = { exit };

		if (exitButton.isClicked()) {
			currentFrame = 0;
		}
	}

	else if (currentFrame == 2) {
		button backButton = { back };
		if (backButton.isClicked()) {

			currentFrame = 0;
		}
	}
	EndDrawing();

}