#pragma once

class CCharacter
{
private:
	static bool m_bTextCalled;
private:
	D3DXVECTOR3		m_vPos;
	D3DXVECTOR3		m_vCenter;
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
public:
	CCharacter();
	~CCharacter();
};

