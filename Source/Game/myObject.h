#pragma once

#ifndef MYOBJECT_H

#define MYOBJECT_H
#include "../Library/gameutil.h"

class Object {
public:
	int object[29][40];

	game_framework::CMovingBitmap objectResource1[29][40];
	game_framework::CMovingBitmap objectResource2[29][40];
	game_framework::CMovingBitmap objectResource4[29][40];


	void generateObject();
	void showObject(int map_stage);

};
#endif // !MYOBJECT_H