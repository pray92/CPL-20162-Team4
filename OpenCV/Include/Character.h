#pragma once

class CCharacter
{
private:
	static bool m_bTextCalled;
	int			m_iID;
private:
	D3DXVECTOR3		m_vPos;
	D3DXVECTOR3		m_vStartPos;
	D3DXVECTOR3		m_vDestination;
	D3DXVECTOR3		m_vCenter;

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
public:
	D3DXVECTOR3 GetPos() const { return m_vPos; };
private:
	RECT Frame();
	D3DXVECTOR3 GetUnitVec(const D3DXVECTOR3, const D3DXVECTOR3);
	float GetDMagnitude(const D3DXVECTOR3, const D3DXVECTOR3);		// Return length square between two points
public:
	CCharacter();
	CCharacter(int _iID);
	~CCharacter();
};
