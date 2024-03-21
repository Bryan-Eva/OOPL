#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "mygame.h"
#include "sstream"

using namespace game_framework;

/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
/////////////////////////////////////////////////////////////////////////////

CGameStateRun::CGameStateRun(CGame *g) : CGameState(g)
{

}

CGameStateRun::~CGameStateRun()
{
}

void CGameStateRun::OnBeginState()
{
}

void CGameStateRun::OnMove()							// 移動遊戲元素
{	
	fireman.IsMoving();
	watergirl.IsMoving();

}

void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
{
	/*
	background[3]: home, menu, map
	window[4]: setting, paused, die, pass
	*/
	scene.loadScene();

	/*
	home: (0)play  (1)setting
	menu: (2)stage1, 2, 3, 4 (3)back 
	map: (4)paused
	window-
	settig: (5)muic (6)effect (7)end
	paused: (8)end (9)resume (10)retry
	die: (11)menu (12)retry (13)skip 
	pass: (14)continue
	*/
	button.loadButton();
	
	/*
	map_box.LoadBitmapByString({ "Resources/object/box.bmp" }, RGB(0, 255, 0));
	map_button[0].LoadBitmapByString({ "Resources/object/button_blue_1.bmp", "Resources/object/button_blue_2.bmp" , "Resources/object/button_blue_3.bmp" }, RGB(0, 255, 0));	//blue purple red
	map_button[1].LoadBitmapByString({ "Resources/object/button_purple_1.bmp", "Resources/object/button_purple_2.bmp" , "Resources/object/button_purple_3.bmp" }, RGB(0, 255, 0));
	map_button[2].LoadBitmapByString({ "Resources/object/button_red_1.bmp", "Resources/object/button_red_2.bmp" , "Resources/object/button_red_3.bmp" }, RGB(0, 255, 0));
	map_controller[0].LoadBitmapByString({ "Resources/object/controller_yellow_1.bmp", "Resources/object/controller_yellow_2.bmp" }, RGB(0, 255, 0));	//yellow blue green red white
	map_controller[1].LoadBitmapByString({ "Resources/object/controller_blue_1.bmp", "Resources/object/controller_blue_2.bmp" }, RGB(255, 0, 0));
	map_controller[2].LoadBitmapByString({ "Resources/object/controller_green_1.bmp", "Resources/object/controller_green_2.bmp" }, RGB(0, 255, 0));
	map_controller[3].LoadBitmapByString({ "Resources/object/controller_red_1.bmp", "Resources/object/controller_red_2.bmp" }, RGB(0, 255, 0));
	map_controller[4].LoadBitmapByString({ "Resources/object/controller_white_1.bmp", "Resources/object/controller_white_2.bmp" }, RGB(0, 255, 0));
	map_diamond[0].LoadBitmapByString({"Resources/object/diamond_red.bmp"}, RGB(0, 255, 0));	//red blue white
	map_diamond[1].LoadBitmapByString({ "Resources/object/diamond_blue.bmp" }, RGB(0, 255, 0));
	map_diamond[2].LoadBitmapByString({ "Resources/object/diamond_white.bmp" }, RGB(0, 255, 0));
	map_door[0].LoadBitmapByString({ "Resources/object/door_fire_1.bmp", "Resources/object/door_fire_2.bmp" });	//fire water
	map_door[1].LoadBitmapByString({ "Resources/object/door_water_1.bmp", "Resources/object/door_water_2.bmp" });
	map_pole[0].LoadBitmapByString({ "Resources/object/pole_M1_yellow_1.bmp", "Resources/object/pole_M1_yellow_2.bmp" });
	map_pole[1].LoadBitmapByString({"Resources/object/pole_M1_purple_1.bmp", "Resources/object/pole_M1_purple_2.bmp" });
	*/
	object.generateObject();

	fireman.character.LoadBitmapByString({"Resources/characters/fireman_front_1.bmp"}, RGB(0, 255, 0));
	fireman.character.SetTopLeft(38, 877);
	watergirl.character.LoadBitmapByString({ "Resources/characters/watergirl_front_1.bmp" }, RGB(0, 255, 0));
	watergirl.character.SetTopLeft(38, 737);

	map.generateMap();
}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	fireman.IsButtonDown(nChar);
	watergirl.IsButtonDown(nChar);
	
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	fireman.IsButtonUp(nChar);
	watergirl.IsButtonUp(nChar);
}

void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
	if (nFlags == VK_LBUTTON) {
		TestOverlap(point.x, point.y);	//點左半phase-- 右半phase++
		//IsMouseOverlap(point.x, point.y);
	}
	
}

void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
}

void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
	
}

void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
}

void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
}

void CGameStateRun::OnShow()
{		
	scene.showScene(page_phase);

	//Map1
	if (page_phase == 6) {
		map.showMap(page_phase - 5);
		object.showObject(page_phase - 5);

		fireman.character.ShowBitmap();		//(38, 877)
		watergirl.character.ShowBitmap();	//(38, 737)
	}

	//Map2
	if (page_phase == 7) {
		map.showMap(page_phase - 5);
		object.showObject(page_phase - 5);

		fireman.character.ShowBitmap();		//(1200, 70)
		watergirl.character.ShowBitmap();	//(70, 460)
	}

	//Map3
	if (page_phase == 8) {
		map.showMap(page_phase - 5);
		//object.showObject(page_phase - 5);

		fireman.character.ShowBitmap();		//(1020, 745)
		watergirl.character.ShowBitmap();	//(905, 745)
	}

	//Map4
	if (page_phase == 9) {
		map.showMap(page_phase - 5);
		object.showObject(page_phase - 5);

		fireman.character.ShowBitmap();		//(50, 875)
		watergirl.character.ShowBitmap();	//(1285, 875)
	}

	//Map5
	if (page_phase == 10) {
		map.showMap(page_phase - 5);
		//object.showObject(page_phase - 5);

		fireman.character.ShowBitmap();		//(130, 875)
		watergirl.character.ShowBitmap();	//(1140, 41)
	}
	
	button.showButton(page_phase);
	//map.generateMap(page_phase - 5);	//6~10
	
	ShowWindowCoordinate();
}


void CGameStateRun::ShowWindowCoordinate() {
	// 座標轉成字串
	string text;
	stringstream ss;
	// 宣告顯示文字工具
	CDC* pDC = CDDraw::GetBackCDC();
	// Window 底下的API
	POINT pt;							// 座標
	HWND hWnd = GetForegroundWindow();	// 宣告並取得當前視窗的句柄
	BOOL bReturn = GetCursorPos(&pt);	// 取得當前鼠標在Screen上的座標(若無return false)
	ScreenToClient(hWnd, &pt);			// 將取得Screen的座標轉成當前視窗句柄的座標
	if (bReturn != 0) {
		ss << pt.x << ", " << pt.y;
		text = ss.str();
		CTextDraw::Print(pDC, 5, 5, text);
	}
	CDDraw::ReleaseBackCDC();
}



void CGameStateRun::IsMouseOverlap(int mouse_x, int mouse_y) {
/*
// playButton at Home Page
	if ((mouse_x >= button[0].GetLeft() && mouse_x <= button[0].GetLeft() + 300) && (mouse_y >= button[0].GetTop() && mouse_y <= button[0].GetTop() + 120) && page_phase == 0) {
		background.SetFrameIndexOfBitmap(2);
		page_phase = 2;
	}
	// settingButton at Home Page
	if ((mouse_x >= button[1].GetLeft() && mouse_x <= button[1].GetLeft() + 110) && (mouse_y >= button[1].GetTop() && mouse_y <= button[1].GetTop() + 110) && page_phase == 0) {
		button[7].SetTopLeft(560, 700);
		window_phase = 0;
		call_window = true;
	}

	// backButton at Stage Menu
	if ((mouse_x >= button[3].GetLeft() && mouse_x <= button[3].GetLeft() + 340) && (mouse_y >= button[3].GetTop() && mouse_y <= button[3].GetTop() + 150) && page_phase == 1) {
		background.SetFrameIndexOfBitmap(0);
		page_phase = 0;
	}

	// backButton at Setting Menu
	if ((mouse_x >= button[7].GetLeft() && mouse_x <= button[7].GetLeft() + 340) && (mouse_y >= button[7].GetTop() && mouse_y <= button[7].GetTop() + 150) && call_window == true && window_phase == 0) {
		call_window = false;
		page_phase = 0;
	}
	// settingButton at Map
	if ((mouse_x >= button[4].GetLeft() && mouse_x <= button[4].GetLeft() + 35) && (mouse_y >= button[4].GetTop() && mouse_y <= button[4].GetTop() + 40) && page_phase >= 2) {
		button[8].SetTopLeft(290,560);		//end
		button[9].SetTopLeft(820,560);		//resume
		button[10].SetTopLeft(560,690);	//retry
		window_phase = 1;
		call_window = true;
	}

	// backButton at Paused Menu
	if ((mouse_x >= button[8].GetLeft() && mouse_x <= button[8].GetLeft() + 300) && (mouse_y >= button[8].GetTop() && mouse_y <= button[8].GetTop() + 125) && call_window == true && window_phase == 1) {
		call_window = false;
		page_phase = 1;		//menu
	}

	// resumeButton at Paused Menu
	if ((mouse_x >= button[9].GetLeft() && mouse_x <= button[9].GetLeft() + 300) && (mouse_y >= button[8].GetTop() && mouse_y <= button[8].GetTop() + 125) && call_window == true && window_phase == 1) {
		call_window = false;
		page_phase = 2;		//map1 (可能要改 或偵測回哪張地圖
	}

	// skipButton at Paused Menu  (retry)
	if ((mouse_x >= button[10].GetLeft() && mouse_x <= button[10].GetLeft() + 300) && (mouse_y >= button[10].GetTop() && mouse_y <= button[10].GetTop() + 125) && call_window == true && window_phase == 1) {
		call_window = false;
		page_phase = 1;		//menu (將retry換成skip測試
	}

	// musicButton at Setting Menu
	if ((mouse_x >= button[5].GetLeft() && mouse_x <= button[5].GetLeft() + 145) && (mouse_y >= button[5].GetTop() && mouse_y <= button[5].GetTop() + 110) && call_window == true && window_phase == 0) {
		//button[5].SetFrameIndexOfBitmap(0);
		button[5].SetFrameIndexOfBitmap(1);

	}

	// effectButton at Setting Menu
	if ((mouse_x >= button[6].GetLeft() && mouse_x <= button[6].GetLeft() + 110) && (mouse_y >= button[6].GetTop() && mouse_y <= button[6].GetTop() + 125) && call_window == true && window_phase == 0) {
		//button[6].SetFrameIndexOfBitmap(0);
		button[6].SetFrameIndexOfBitmap(1);

	}

	// stageButton at Stage Menu
	if ((mouse_x >= button[2].GetLeft() && mouse_x <= button[2].GetLeft() + 130) && (mouse_y >= button[2].GetTop() && mouse_y <= button[2].GetTop() + 140) && page_phase == 1) {
		if (mouse_y >= 830 && mouse_y <= 1000) {
			page_phase = 2;		//map1
		}
		if (mouse_y >= 630 && mouse_y <= 820) {
			page_phase = 3;		//map2
		}
		if (mouse_y >= 430 && mouse_y <= 620) {
			page_phase = 4;		//map3
		}
		if (mouse_y >= 230 && mouse_y <= 420) {
			page_phase = 5;		//map4
		}
		if (mouse_y >= 30 && mouse_y <= 220) {
			page_phase = 6;		//map5
		}
		background.SetFrameIndexOfBitmap(1);	//menu

	}
*/
}

void CGameStateRun::TestOverlap(int mouse_x, int mouse_y) {
	if (mouse_x <= 400) {
		page_phase--;
	}
	if (mouse_x >= 400) {
		page_phase++;
	}
}