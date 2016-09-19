#ifndef _SYSTEMFUNC_H_
#define _SYSTEMFUNC_H_

#define SYSTEM_EXPORT
#include "SystemDef.h"

/* CDevice ³» °´Ã¼ */
EXTERN	SYSTEM_DLL HRESULT InitDevice(BOOL isFullScreen, HWND hWnd,
	const int& iWinCX,
	const int& iWinCY);

EXTERN	SYSTEM_DLL void System_Release();
EXTERN	SYSTEM_DLL void ReleaseDevice();
EXTERN	SYSTEM_DLL void Render_Begin();
EXTERN	SYSTEM_DLL void Render_End();


EXTERN	SYSTEM_DLL LPDIRECT3DDEVICE9 GetDevice();

EXTERN	SYSTEM_DLL LPD3DXLINE GetLine();
EXTERN	SYSTEM_DLL LPD3DXFONT Getfont();					//Changed by function overloading );
EXTERN	SYSTEM_DLL void Drawtext(const TCHAR* Message, long _lX, long _lY, long lSizeX = 640, long lSizeY = 480, DWORD Color = D3DCOLOR_ARGB(255, 255, 255, 255));
EXTERN	SYSTEM_DLL LPD3DXSPRITE GetSprite();

/* CInput ³» °´Ã¼ */
EXTERN	SYSTEM_DLL 	HRESULT CreateDevice(HWND hWnd);
EXTERN	SYSTEM_DLL 	HRESULT ReadData();
EXTERN	SYSTEM_DLL 	VOID FreeDirectInput();
EXTERN	SYSTEM_DLL 	void OnActivate(WPARAM wParam);
EXTERN	SYSTEM_DLL 	BOOL PushLeft();
EXTERN	SYSTEM_DLL 	BOOL PushRight();
EXTERN	SYSTEM_DLL 	BOOL PushMiddle();

EXTERN	SYSTEM_DLL 	POINT GetptMouse();
EXTERN	SYSTEM_DLL 	DIMOUSESTATE2 GetMouseState2();
EXTERN	SYSTEM_DLL  BYTE GetKeyBoardState(short nKey);

/* CTimeMgr ³» °´Ã¼ */
EXTERN	SYSTEM_DLL  void InitTimeMgr();
EXTERN	SYSTEM_DLL  void SetTime();
EXTERN	SYSTEM_DLL  float GetTime();
EXTERN SYSTEM_DLL float GetFps(void);

#endif
