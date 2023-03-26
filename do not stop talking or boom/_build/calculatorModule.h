#pragma once

#include <iostream>
#include <string>

#include "raylib.h"

struct CalculatorModule {

public:
	CalculatorModule(Rectangle rect);

	bool Update();

	void DrawNumbers();

	void SetActive(bool active);

	bool GetActive();
	
	bool IsCorrect(int number, int index);

	bool IsCompleted();

private:
	Rectangle rect;

	Rectangle numbers[6] = {
		{ 1175, 879, 15, 25 },
		{ 1175, 919, 15, 25 },
		{ 1291, 879, 15, 25 },
		{ 1291, 919, 15, 25 },
		{ 1407, 879, 15, 25 },
		{ 1407, 919, 15, 25 }
	};

	int correct[6] = { 3, 6, 5, 3, 4, 7 };
	int currentIndex = 0;

	bool isActive = false;
};
