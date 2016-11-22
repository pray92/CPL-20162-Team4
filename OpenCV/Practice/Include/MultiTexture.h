#pragma once

#include "texture.h"

class CMultiTexture :
	public CTexture
{
	map<const TCHAR*,vector<TEX_INFO*>>	m_pMapTexture;

public:
	virtual const TEX_INFO*	GetTexture(const TCHAR* pStateKey = NULL,const int& iCnt =0);
public:
	virtual const HRESULT	InsertTexture(const int iAlpha, const int iRed,const int iGreen,const int iBlue,const TCHAR* pFileName,const TCHAR* pStateKey = NULL,const int& iCnt =0) ;
	virtual void Release(void);
public:
	CMultiTexture(void);
	virtual ~CMultiTexture(void);
};
