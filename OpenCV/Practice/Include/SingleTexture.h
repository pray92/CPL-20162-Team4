#pragma once
#include "texture.h"

class CSingleTexture :
	public CTexture
{
private:
	TEX_INFO*	m_pTexInfo;

public:
	virtual const TEX_INFO*	GetTexture(const TCHAR* pStateKey = NULL,
		const int& iCnt =0);
public:
	virtual const HRESULT	InsertTexture(const int iAlpha, const int iRed,const int iGreen,const int iBlue,const TCHAR* pFileName,
		const TCHAR* pStateKey = NULL,const int& iCnt =0);
	virtual void Release(void);
public:
	CSingleTexture(void);
	virtual ~CSingleTexture(void);
};

