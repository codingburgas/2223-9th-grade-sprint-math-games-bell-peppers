#pragma once
#include "raylib.h"

struct Button {
public: 
	Button(Rectangle rect);

	bool isClicked();

private:
	Rectangle rect;
};