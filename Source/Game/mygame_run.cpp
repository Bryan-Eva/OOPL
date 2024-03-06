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
// �o��class���C�����C�����檫��A�D�n���C���{�����b�o��
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

void CGameStateRun::OnMove()							// ���ʹC������
{
	
}

void CGameStateRun::OnInit()  								// �C������Ȥιϧγ]�w
{
	background.LoadBitmapByString({
		"Resources/home_page/background.bmp",
		"Resources/menu/background.bmp",
		"Resources/map/map1.bmp",
		"Resources/map/block1.bmp"
		});
	background.SetTopLeft(0, 0);

	button[0].LoadBitmapByString({ "Resources/home_page/button_play.bmp" });
	button[0].SetTopLeft(553, 530);
	button[1].LoadBitmapByString({ "Resources/home_page/button_setting.bmp" });
	button[1].SetTopLeft(100, 890);
	button[2].LoadBitmapByString({ "Resources/menu/button_back.bmp" });
	button[2].SetTopLeft(90, 800);

	window[0].LoadBitmapByString({ "Resources/window/setting/background.bmp" });
	window[0].SetTopLeft(70, 167);
	/*
	for (int i = 0; i < 4; i++) {
		window[i].SetTopLeft(182, 167);	//(0,0) ()
	}
	*/
	
}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (nChar == VK_RIGHT) {
		page_phase ++;
	}
	if (nChar == VK_LEFT) {
		page_phase --;
	}
	if (nChar == VK_SPACE) {
		if (call_window == false) {call_window = true;}
		if (call_window == true) { call_window = false; }
		
	}

	
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	
}

void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // �B�z�ƹ����ʧ@
{
	if (nFlags == VK_LBUTTON) {

	}
	
}

void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
{
}

void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
{
}

void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // �B�z�ƹ����ʧ@
{
}

void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
{
}

void CGameStateRun::OnShow()
{
	
	
	if (call_window) {
		show_window();
	}
	else {
		show_page();
	}

	ShowWindowCoordinate();
	
}

void CGameStateRun::show_page() {
	if (page_phase == 0) {	//home page
		background.SetFrameIndexOfBitmap(0);
		background.ShowBitmap();
		button[0].ShowBitmap();	//button_play
		button[1].ShowBitmap();	//button_setting
	}
	if (page_phase == 1) {	//menu
		background.SetFrameIndexOfBitmap(1);
		background.ShowBitmap();
		button[2].ShowBitmap();	//back
	}
	if (page_phase == 2) {	//map1
		background.SetFrameIndexOfBitmap(2);
		background.ShowBitmap();
		window[0].ShowBitmap();
	}
}

void CGameStateRun::show_window() {
	if (window_phase == 0) {
		window[0].ShowBitmap();
	}
}

void CGameStateRun::ShowWindowCoordinate() {
	// �y���ন�r��
	string text;
	stringstream ss;
	// �ŧi��ܤ�r�u��
	CDC* pDC = CDDraw::GetBackCDC();
	// Window ���U��API
	POINT pt;							// �y��
	HWND hWnd = GetForegroundWindow();	// �ŧi�è��o��e�������y�`
	BOOL bReturn = GetCursorPos(&pt);	// ���o��e���ЦbScreen�W���y��(�Y�Lreturn false)
	ScreenToClient(hWnd, &pt);			// �N���oScreen���y���ন��e�����y�`���y��
	if (bReturn != 0) {
		ss << pt.x << ", " << pt.y;
		text = ss.str();
		CTextDraw::Print(pDC, 5, 5, text);
	}
	CDDraw::ReleaseBackCDC();
}

