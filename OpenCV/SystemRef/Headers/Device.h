#pragma once
#define SYSTEM_EXPORT
#include "SystemDef.h"

EXTERN class SYSTEM_DLL CDevice
{
	DECLARE_SINGLETON(CDevice);
private:
	//��ġ�� ������ ���� , ����̽� ��ü ����
	LPDIRECT3D9		m_p3D;

	// ��ġ�� ��ǥ�ϴ� ��ü
	LPDIRECT3DDEVICE9 m_pDevice;

	LPD3DXSPRITE	m_pSprite;
	//��Ʈ ��¿� ��ü
	LPD3DXFONT		m_pFont;
	//���� ��¿� ��ü
	LPD3DXLINE		m_pLine;

public:
	LPD3DXSPRITE GetSprite() { return m_pSprite; }
	LPDIRECT3DDEVICE9 GetDevice() { return m_pDevice; }
	LPD3DXFONT GetFont() { return m_pFont; }
	LPD3DXLINE GetLine() { return m_pLine; }

	HRESULT	 InitDevice(BOOL isFullScreen, HWND hWnd, const int& iWinCX, const int& iWinCY);
	void	 Release(void);
public:
	void	Render_Begin(void);
	void	Render_End();
public:
	CDevice(void);
	~CDevice(void);
};

