#include "gameManager.h"

Texture2D menu;
Font font;
Vector2 position = { 0, 0 };
Music music;
Rectangle frameRec;
Image icon = LoadImage("../resources/icon.png");
Rectangle play = { 30, 355, 150, 82 };
Rectangle info = { 30, 555, 150, 75 };
Rectangle quit = { 28, 790, 150, 74 };
Rectangle exit = { 4, 10, 210, 65 };
Rectangle back = { 20, 5, 155, 50 };
Rectangle maze = { 590, 852, 20, 20 };
Rectangle finish = { 708, 693, 20, 20 };
Rectangle up = { 741, 905, 10, 10 };
Rectangle left = { 741, 922, 10, 10 };
Rectangle right = { 741, 941, 10, 10 };
Rectangle down = { 741, 960, 10, 10 };
Rectangle box = { 505, 683, 250, 200 };
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
char arr1[2] = { '\0' };
char arr2[2] = { '\0' };
char arr3[2] = { '\0' };
char arr4[2] = { '\0' };
char arr5[2] = { '\0' };
char arr6[2] = { '\0' };
Rectangle write1 = { 1175, 879, 15, 25 };
Rectangle write2 = { 1175, 919, 15, 25 };
Rectangle write3 = { 1291, 879, 15, 25 };
Rectangle write4 = { 1291, 919, 15, 25 };
Rectangle write5 = { 1407, 879, 15, 25 };
Rectangle write6 = { 1407, 919, 15, 25 };
char correct1 = '1', correct2 = '6', correct3 = '5', correct4 = '3', correct5 = '4', correct6 = '7';
time_t start, end, diff, timeLeft = 0;
bool correct = false;
int modules = 3;

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
}

bool ShouldClose() {
	return WindowShouldClose() || shouldClose;
}

void Close() {
	shouldClose = true;
}

void CheckNumber(char num[],Rectangle box, char correct, int& strikes) {
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

		if(strikes == 1) {
			DrawTextEx(font, "X ", { 1212, 385 }, 80, 1, RED);
		}
		else if (strikes == 2) {
			currentFrame = 4;
		}

		
		CheckNumber(arr1, write1, correct1, strikes);

		CheckNumber(arr2, write2, correct2, strikes);

		CheckNumber(arr3, write3, correct3, strikes);

		CheckNumber(arr4, write4, correct4, strikes);

		CheckNumber(arr5, write5, correct5, strikes);

		CheckNumber(arr6, write6, correct6, strikes);

		DrawRectangleRec(maze, RED);

		button oneButton = { one };

		button twoButton = { two };

		button threeButton = { three };

		button fourButton = { four };

		button fiveButton = { five };

		button sixButton = { six };

		button sevenButton = { seven };

		button eightButton = { eight };

		button nineButton = { nine };

		button zeroButton = { zero };

		button upButton = { up };

		button leftButton = { left };

		button rightButton = { right };

		button downButton = { down };

		if (fiveButton.isClicked()){
			modules--;
		}
		else if (oneButton.isClicked() || twoButton.isClicked() || threeButton.isClicked() || fourButton.isClicked() || sixButton.isClicked() || sevenButton.isClicked() || eightButton.isClicked() || nineButton.isClicked() || zeroButton.isClicked())
		{
			strikes++;
		}

		if(upButton.isClicked()) {

			(float)maze.y = (float)maze.y - 105;

			if (!CheckCollisionRecs(box, maze)) {
				(float)maze.y = (float)maze.y + 58;
			}
			
		}
		else if (leftButton.isClicked()) {

			(float)maze.x = (float)maze.x - 58;

			if (!CheckCollisionRecs(box, maze)) {
				(float)maze.y = (float)maze.y + 58;
			}
		}
		else if (rightButton.isClicked()) {

			(float)maze.x = (float)maze.x + 58;

			if (!CheckCollisionRecs(box, maze)) {
				(float)maze.y = (float)maze.y - 58;
			}
		}
		else if (downButton.isClicked()) {

			(float)maze.y = (float)maze.y + 105;

			if (!CheckCollisionRecs(box, maze)) {
				(float)maze.y = (float)maze.y - 58;
			}
		}
		if (CheckCollisionRecs(maze, finish)) {
			currentFrame = 3;
		}
		/*DrawRectangleRec(write2, RED);*/
		DrawText(arr1, 1178, 879, 28, WHITE);
		DrawText(arr2, 1179, 921, 28, WHITE);
		DrawText(arr3, 1292, 879, 28, WHITE);
		DrawText(arr4, 1292, 921, 28, WHITE);
		DrawText(arr5, 1404, 879, 28, WHITE);
		DrawText(arr6, 1409, 921, 28, WHITE);
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

		if (timeLeft == -1) {
			currentFrame = 4;
		}

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