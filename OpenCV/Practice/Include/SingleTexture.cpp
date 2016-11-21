#include "stdafx.h"
#include "SingleTexture.h"

#include "SystemFunc.h"

CSingleTexture::CSingleTexture(void)
	:m_pTexInfo(NULL)
{
}


CSingleTexture::~CSingleTexture(void)
{
	Release();
}

const TEX_INFO* CSingleTexture::GetTexture( const TCHAR* pStateKey /*= NULL*/,const int& iCnt /*=0*/ )
{
	return m_pTexInfo;
}

const HRESULT CSingleTexture::InsertTexture( const int iAlpha, const int iRed,const int iGreen,const int iBlue, const TCHAR* pFileName,const TCHAR* pStateKey /*= NULL*/,const int& iCnt /*=0*/)
{
	m_pTexInfo = new TEX_INFO;
	ZeroMemory(m_pTexInfo,sizeof(TEX_INFO));

	if (FAILED(D3DXGetImageInfoFromFile(pFileName,&m_pTexInfo->ImgInfo)))
	{
		return E_FAIL;
	}

	if(FAILED(D3DXCreateTextureFromFileEx(GetDevice(),
		pFileName,
		m_pTexInfo->ImgInfo.Width,m_pTexInfo->ImgInfo.Height,
		m_pTexInfo->ImgInfo.MipLevels,0, m_pTexInfo->ImgInfo.Format,D3DPOOL_MANAGED, D3DX_DEFAULT,D3DX_DEFAULT,
		D3DCOLOR_ARGB(iAlpha,iRed,iGreen,iBlue),
		&m_pTexInfo->ImgInfo, NULL,&m_pTexInfo->pTexture)))
	{
		return E_FAIL;
	}

	return S_OK;
}

void CSingleTexture::Release( void )
{
	if(m_pTexInfo)
	{
		m_pTexInfo->pTexture->Release();
		delete m_pTexInfo;
		m_pTexInfo = NULL;
	}
}
