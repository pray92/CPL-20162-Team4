#pragma once
#include "Obj.h"

class CCharacter
	:public CObj
{
private:
	static bool m_bTextCalled;
private:
	D3DXVECTOR3		m_vStartPos;
	D3DXVECTOR3		m_vDestination;
private:
	D3DXVECTOR3		m_vDirection;
	float			movingSpeed;
	float			maxSpeed;
	float			acceleration;
private:
	int				m_iFrame;
	DWORD			m_dwTime;
public:
	virtual HRESULT Initialize(void);
	virtual SCENE Progress(void);
	virtual void Render(void);
	virtual void Release(void);
private:
	RECT Frame();
	D3DXVECTOR3 GetUnitVec(const D3DXVECTOR3, const D3DXVECTOR3);
	float GetDMagnitude(const D3DXVECTOR3, const D3DXVECTOR3);		// Return length square between two points
public:
	CCharacter();
	CCharacter(int _iID);
	~CCharacter();
};
