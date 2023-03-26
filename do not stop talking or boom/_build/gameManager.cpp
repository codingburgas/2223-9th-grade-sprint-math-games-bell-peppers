#include "gameManager.h"

Texture2D menu;
Font font;
Vector2 position = { 0, 0 };
Music music;
Sound soundWin;
Sound soundLose;
Rectangle frameRec;
Image icon = LoadImage("../resources/icon.png");
Rectangle play = { 30, 355, 150, 82 };
Rectangle info = { 30, 555, 150, 75 };
Rectangle quit = { 28, 790, 150, 74 };
Rectangle exitRect = { 4, 10, 210, 65 };
Rectangle back = { 20, 5, 155, 50 };
Rectangle maze = { 590, 852, 20, 20 };
Rectangle finish = { 708, 693, 20, 20 };
Rectangle up = { 741, 905, 10, 10 };
Rectangle left = { 741, 922, 10, 10 };
Rectangle right = { 741, 941, 10, 10 };
Rectangle down = { 741, 960, 10, 10 };
Rectangle box = { 505, 683, 255, 205 };
Rectangle one = { 487, 438, 46, 38 };
Rectangle two = { 545, 438, 46, 38 };
Rectangle three = { 606, 438, 46, 38 };
Rectangle four = { 665, 438, 46, 38 };
Rectangle five = { 728, 438, 46, 38 };
Rectangle six = { 487, 480, 46, 46 };
Rectangle seven = { 545, 480, 46, 46 };
Rectangle eight = { 606, 480, 46, 46 };
Rectangle nine = { 665, 480, 46, 46 };
Rectangle zero = { 728, 480, 46, 46 };

int currentFrame = 0, strikes = 0;
bool shouldClose = false;
const int timer = 300;

Rectangle calculatorModuleRect = { 1062, 645, 440, 340 };
CalculatorModule calculatorModule = { calculatorModuleRect };
Button calculatorModuleButton = { calculatorModuleRect };

time_t start, end, diff, timeLeft = 0;
int done = 0;
int where = 0;
bool firstModule = false, secondModule = false, thirdModule = false;

void Initialize() {
	InitWindow(1920, 1080, "Bombs");
	SetWindowIcon(icon);
	SetTargetFPS(60);
	ToggleFullscreen();
	InitAudioDevice();
	menu = LoadTexture("../resources/menu.png");
	frameRec = { 0, 0, (float)menu.width / 5, (float)menu.height };
	font = LoadFont("../resources/font.ttf");
	music = LoadMusicStream("../resources/music.mp3");
	soundWin = LoadSound("../resources/win.mp3");
	soundLose = LoadSound("../resources/lose.mp3");
}

bool ShouldClose() {
	return WindowShouldClose() || shouldClose;
}

void Close() {
	shouldClose = true;
}

void CheckNumber(char num[], Rectangle box, char correct, int& strikes, int& done) {
	int write = false;
	if (CheckCollisionPointRec(GetMousePosition(), box)) {
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
			if ((key >= 48) && (key <= 57))
			{
				if ((char)key == correct) {
					num[0] = (char)key;
					num[1] = '\0';
					done++;
				}
				else {
					strikes++;
					return;
				}
			}
			key = GetCharPressed();
		}
	}
}
void Update() {

	UpdateMusicStream(music);

	PlayMusicStream(music);

	SetMusicVolume(music, (float)0.1);

	frameRec.x = (float)currentFrame * (float)menu.width / 5;

	BeginDrawing();

	ClearBackground(WHITE);

	DrawTextureRec(menu, frameRec, position, WHITE);

	if (currentFrame == 0) {

		start = time(0);

		maze = { 590, 852, 20, 20 };

		Button playButton = { play };

		Button infoButton = { info };

		Button quitButton = { quit };

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

		if (strikes == 1) {
			DrawTextEx(font, "X ", { 1212, 385 }, 80, 1, RED);
		}
		else if (strikes == 2) {
			currentFrame = 4;
		}

		if (calculatorModuleButton.isClicked()) {
			bool isActive = calculatorModule.GetActive();
			calculatorModule.SetActive(!isActive);
		}

		if (!calculatorModule.Update()) {
			strikes++;
		}

		DrawRectangleRec(maze, RED);

		Button oneButton = { one };

		Button twoButton = { two };

		Button threeButton = { three };

		Button fourButton = { four };

		Button fiveButton = { five };

		Button sixButton = { six };

		Button sevenButton = { seven };

		Button eightButton = { eight };

		Button nineButton = { nine };

		Button zeroButton = { zero };

		Button upButton = { up };

		Button leftButton = { left };

		Button rightButton = { right };

		Button downButton = { down };
		DrawCircle(850, 210, 18, BLACK);
		if (fiveButton.isClicked() && !firstModule) {
			firstModule = true;
		}
		if (firstModule) {
			DrawCircle(850, 210, 15, GREEN);
			DrawTextEx(font, "5", { 470,345 }, 80, 1, WHITE);
		}
		else if (oneButton.isClicked() || twoButton.isClicked() || threeButton.isClicked() || fourButton.isClicked() || sixButton.isClicked() || sevenButton.isClicked() || eightButton.isClicked() || nineButton.isClicked() || zeroButton.isClicked())
		{
			strikes++;
		}
		DrawCircle(850, 650, 18, BLACK);
		if ((!CheckCollisionRecs(maze, finish))) {
			if (upButton.isClicked()) {


				if (where < 2 && CheckCollisionRecs(box, maze)) {
					(float)maze.y = (float)maze.y - 105;
					where++;
					if (where == 2) {
						(float)maze.y = (float)maze.y + 58;
					}
				}

			}
			else if (leftButton.isClicked()) {

				(float)maze.x = (float)maze.x - 58;

				if (!CheckCollisionRecs(box, maze)) {

					(float)maze.x = (float)maze.x + 58;
				}
			}
			else if (rightButton.isClicked()) {

				(float)maze.x = (float)maze.x + 58;

				if (!CheckCollisionRecs(box, maze)) {

					(float)maze.x = (float)maze.x - 58;
				}
			}
			else if (downButton.isClicked()) {

				if (where > 0 && CheckCollisionRecs(box, maze)) {
					(float)maze.y = (float)maze.y + 105;
					where--;
					if (where == 0) {
						(float)maze.y = (float)maze.y - 58;
					}
				}
			}
		}
		else {
			secondModule = true;
			DrawCircle(850, 650, 15, GREEN);
		}
		
		DrawCircle(1485, 660, 18, BLACK);
		thirdModule = calculatorModule.IsCompleted();

		if (thirdModule) {

			DrawCircle(1485, 660, 15, GREEN);
		}

		DrawTextEx(font, TextFormat("%i:%02i", timeLeft / 60, timeLeft % 60), { 1135, 183 }, 180, 1, WHITE);

		end = time(0);

		diff = end - start;

		timeLeft = timer - diff;

		if (timeLeft == -1) {
			currentFrame = 4;
			StopMusicStream(music);
			SetSoundVolume(soundLose, 0.1);
			PlaySound(soundLose);
			
		}

		Button exitButton = { exitRect };

		if (currentFrame == 4)
		{
			StopMusicStream(music);
			SetSoundVolume(soundLose, 0.1);
			PlaySound(soundLose);
		}

		if (exitButton.isClicked()) {
			currentFrame = 0;
		}

		if (firstModule && secondModule && thirdModule) {
			StopMusicStream(music);
			SetSoundVolume(soundWin, 0.1);
			PlaySound(soundWin);

			currentFrame = 3;
		}
	}

	else if (currentFrame == 2) {
		Button backButton = { back };
		if (backButton.isClicked()) {

			currentFrame = 0;
		}
	}


	EndDrawing();

}