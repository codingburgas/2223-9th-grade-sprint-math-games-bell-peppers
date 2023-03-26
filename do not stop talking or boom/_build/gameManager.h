#pragma once

#include "button.h"
#include "calculatorModule.h"

#include "raylib.h"

#include <ctime>

void Initialize();

bool ShouldClose();

void Update();

void Close();

void CheckNumber(char num[], Rectangle box, char correct, int& strikes, int& done);