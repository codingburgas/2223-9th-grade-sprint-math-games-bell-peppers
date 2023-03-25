#include "button.h"

button::button(Rectangle rect) {
	this->rect = rect;
}

bool button::isClicked() {
	return IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(),this->rect);
}
