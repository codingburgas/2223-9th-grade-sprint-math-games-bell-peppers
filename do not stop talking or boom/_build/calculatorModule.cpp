#include "calculatorModule.h"

CalculatorModule::CalculatorModule(Rectangle rect) {

	this->rect = rect;
}

//Update the frames
bool CalculatorModule::Update() {

	DrawNumbers();

	if (!isActive || IsCompleted()) {

		return true;
	}

	char key = GetCharPressed();
	
	if ((key >= 48) && (key <= 57)) {
		//Check if the pressed key is correct
		if (IsCorrect(key - '0', currentIndex)) {

			currentIndex++;
		}
		else {

			return false;
		}
	}

	return true;
}

//Draw the correct numbers
void CalculatorModule::DrawNumbers() {

	for (int i = 0; i < currentIndex; i++) {

		std::string number = std::to_string(correct[i]);

		DrawText(number.c_str(), (int)numbers[i].x, (int)numbers[i].y, 28, WHITE);
	}
	
}

//Set the module active
void CalculatorModule::SetActive(bool active) {

	this->isActive = active;
}

//Make the module active
bool CalculatorModule::GetActive() {

	return isActive;
}

//Check if the number is correct
bool CalculatorModule::IsCorrect(int number, int index) {

	return number == correct[index];
}

//Check if the module is finished
bool CalculatorModule::IsCompleted() {
	return currentIndex == 6;
}