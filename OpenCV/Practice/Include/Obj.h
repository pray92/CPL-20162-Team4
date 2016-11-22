#pragma once
class CObj
{
protected:
	int			m_iID;
protected:
	D3DXVECTOR3		m_vPos;
	D3DXVECTOR3		m_vCenter;
public:
	D3DXVECTOR3 GetPos() const { return m_vPos; };
public:
	virtual HRESULT Initialize(void) PURE;
	virtual SCENE Progress(void) PURE;
	virtual void Render(void) PURE;
	virtual void Release(void) PURE;
public:
	CObj();
	CObj(int _iID);
	virtual ~CObj();
};

