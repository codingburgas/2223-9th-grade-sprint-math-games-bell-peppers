#include "button.h"

Button::Button(Rectangle rect) {
	this->rect = rect;//confused
}

bool Button::isClicked() {
	return IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(),this->rect);
}
