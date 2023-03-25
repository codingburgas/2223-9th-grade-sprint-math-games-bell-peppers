#pragma once
#include "raylib.h"

struct button {
public: 
	button(Rectangle rect);

	bool isClicked();

private:
	Rectangle rect;
};