#include "calculatorModule.h"

CalculatorModule::CalculatorModule(Rectangle rect) {

	this->rect = rect;
}

bool CalculatorModule::Update() {

	DrawNumbers();

	if (!isActive || IsCompleted()) {

		return true;
	}

	char key = GetCharPressed();
	
	if ((key >= 48) && (key <= 57)) {

		if (IsCorrect(key - '0', currentIndex)) {

			currentIndex++;
		}
		else {

			return false;
		}
	}

	return true;
}

void CalculatorModule::DrawNumbers() {

	for (int i = 0; i < currentIndex; i++) {

		std::string number = std::to_string(correct[i]);

		DrawText(number.c_str(), (int)numbers[i].x, (int)numbers[i].y, 28, WHITE);
	}
	
}

void CalculatorModule::SetActive(bool active) {

	this->isActive = active;
}

bool CalculatorModule::GetActive() {

	return isActive;
}

bool CalculatorModule::IsCorrect(int number, int index) {

	return number == correct[index];
}

bool CalculatorModule::IsCompleted() {
	return currentIndex == 6;
}