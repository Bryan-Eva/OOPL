#include "stdafx.h"
#include "../Game/myObject.h"
#include <fstream>

void Object::generateObject() {
	std::ifstream object1("Resources/objectContent/map1Object.txt");
	for (int i = 0; i < 29; i++) {
		for (int j = 0; j < 40; j++) {
			object1 >> this->object[i][j];
			if (this->object[i][j] == 1)
				this->objectResource1[i][j].LoadBitmapByString({ "Resources/object/1.bmp" }, RGB(0, 255, 0));
			if (this->object[i][j] == 2)
				this->objectResource1[i][j].LoadBitmapByString({ "Resources/object/2.bmp" }, RGB(0, 255, 0));
			if (this->object[i][j] == 3)
				this->objectResource1[i][j].LoadBitmapByString({ "Resources/object/3.bmp" }, RGB(0, 255, 0));
			if (this->object[i][j] == 4)
				this->objectResource1[i][j].LoadBitmapByString({ "Resources/object/4.bmp" }, RGB(0, 255, 0));
			if (this->object[i][j] == 5)
				this->objectResource1[i][j].LoadBitmapByString({ "Resources/object/5.bmp" }, RGB(0, 255, 0));
			if (this->object[i][j] == 6)
				this->objectResource1[i][j].LoadBitmapByString({ "Resources/object/6.bmp" }, RGB(0, 255, 0));
			if (this->object[i][j] == 7)
				this->objectResource1[i][j].LoadBitmapByString({ "Resources/object/7.bmp" }, RGB(255, 0, 0));
			if (this->object[i][j] == 8)
				this->objectResource1[i][j].LoadBitmapByString({ "Resources/object/8.bmp" }, RGB(255, 0, 0));
			if (this->object[i][j] == 9)
				this->objectResource1[i][j].LoadBitmapByString({ "Resources/object/9.bmp" }, RGB(255, 0, 0));
			else
				this->objectResource1[i][j].LoadBitmapByString({ "Resources/object/0.bmp" }, RGB(0, 255, 0));
			this->objectResource1[i][j].SetTopLeft(j * 35, i * 35);
		}
	}
	object1.close();

	std::ifstream object2("Resources/objectContent/map2Object.txt");
	for (int i = 0; i < 29; i++) {
		for (int j = 0; j < 40; j++) {
			object2 >> this->object[i][j];
			if (this->object[i][j] == 1)
				this->objectResource2[i][j].LoadBitmapByString({ "Resources/object/1.bmp" }, RGB(0, 255, 0));
			if (this->object[i][j] == 2)
				this->objectResource2[i][j].LoadBitmapByString({ "Resources/object/2.bmp" }, RGB(0, 255, 0));
			if (this->object[i][j] == 3)
				this->objectResource2[i][j].LoadBitmapByString({ "Resources/object/3.bmp" }, RGB(0, 255, 0));
			if (this->object[i][j] == 4)
				this->objectResource2[i][j].LoadBitmapByString({ "Resources/object/4.bmp" }, RGB(0, 255, 0));
			if (this->object[i][j] == 5)
				this->objectResource2[i][j].LoadBitmapByString({ "Resources/object/5.bmp" }, RGB(0, 255, 0));
			if (this->object[i][j] == 6)
				this->objectResource2[i][j].LoadBitmapByString({ "Resources/object/6.bmp" }, RGB(0, 255, 0));
			if (this->object[i][j] == 7)
				this->objectResource2[i][j].LoadBitmapByString({ "Resources/object/7.bmp" }, RGB(255, 0, 0));
			if (this->object[i][j] == 8)
				this->objectResource2[i][j].LoadBitmapByString({ "Resources/object/8.bmp" }, RGB(255, 0, 0));
			if (this->object[i][j] == 9)
				this->objectResource2[i][j].LoadBitmapByString({ "Resources/object/9.bmp" }, RGB(255, 0, 0));
			else
				this->objectResource2[i][j].LoadBitmapByString({ "Resources/object/0.bmp" }, RGB(0, 255, 0));
			this->objectResource2[i][j].SetTopLeft(j * 35, i * 35);
		}
	}
	object2.close();

	std::ifstream object4("Resources/objectContent/map4Object.txt");
	for (int i = 0; i < 29; i++) {
		for (int j = 0; j < 40; j++) {
			object4 >> this->object[i][j];
			if (this->object[i][j] == 1)
				this->objectResource4[i][j].LoadBitmapByString({ "Resources/object/1.bmp" }, RGB(0, 255, 0));
			if (this->object[i][j] == 2)
				this->objectResource4[i][j].LoadBitmapByString({ "Resources/object/2.bmp" }, RGB(0, 255, 0));
			if (this->object[i][j] == 3)
				this->objectResource4[i][j].LoadBitmapByString({ "Resources/object/3.bmp" }, RGB(0, 255, 0));
			if (this->object[i][j] == 4)
				this->objectResource4[i][j].LoadBitmapByString({ "Resources/object/4.bmp" }, RGB(0, 255, 0));
			if (this->object[i][j] == 5)
				this->objectResource4[i][j].LoadBitmapByString({ "Resources/object/5.bmp" }, RGB(0, 255, 0));
			if (this->object[i][j] == 6)
				this->objectResource4[i][j].LoadBitmapByString({ "Resources/object/6.bmp" }, RGB(0, 255, 0));
			if (this->object[i][j] == 7)
				this->objectResource4[i][j].LoadBitmapByString({ "Resources/object/7.bmp" }, RGB(255, 0, 0));
			if (this->object[i][j] == 8)
				this->objectResource4[i][j].LoadBitmapByString({ "Resources/object/8.bmp" }, RGB(255, 0, 0));
			if (this->object[i][j] == 9)
				this->objectResource4[i][j].LoadBitmapByString({ "Resources/object/9.bmp" }, RGB(255, 0, 0));
			else
				this->objectResource4[i][j].LoadBitmapByString({ "Resources/object/0.bmp" }, RGB(0, 255, 0));
			this->objectResource4[i][j].SetTopLeft(j * 35, i * 35);
		}
	}
	object4.close();

}

void Object::showObject(int map_stage) {
	switch (map_stage) {
	case 1: {
		for (int i = 0; i < 29; i++) {
			for (int j = 0; j < 40; j++) {
				this->objectResource1[i][j].ShowBitmap();
			}
		}
		break;
	}

	case 2: {
		for (int i = 0; i < 29; i++) {
			for (int j = 0; j < 40; j++) {
				this->objectResource2[i][j].ShowBitmap();
			}
		}
		break;
	}

	case 4: {
		for (int i = 0; i < 29; i++) {
			for (int j = 0; j < 40; j++) {
				this->objectResource4[i][j].ShowBitmap();
			}
		}
		break;
	}

	}
}


