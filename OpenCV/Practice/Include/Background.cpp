#include "stdafx.h"
#include "Background.h"

#include "TextureMgr.h"

bool CBackground::m_bTextCalled = false;

HRESULT CBackground::Initialize(void)
{
	if (!m_bTextCalled)
	{
		if (FAILED(GET_SINGLE(CTextureMgr)->InsertTexture(255, 255, 255, 255, L"./Background/tree.png", L"Tree", TEXTTYPE_SINGLE)))
		{
			MessageBox(NULL, L"나무 배경 사진 불러오기 실패", L"Message", MB_OK);
			return E_FAIL;
		}

		if (FAILED(GET_SINGLE(CTextureMgr)->InsertTexture(255, 0, 0, 0, L"./Background/sky.jpg", L"Sky", TEXTTYPE_SINGLE)))
		{
			MessageBox(NULL, L"하늘 배경 사진 불러오기 실패", L"Message", MB_OK);
			return E_FAIL;
		}

		if (FAILED(GET_SINGLE(CTextureMgr)->InsertTexture(255, 0, 0, 0, L"./Background/ground.png", L"Ground", TEXTTYPE_SINGLE)))
		{
			MessageBox(NULL, L"해변 배경 사진 불러오기 실패", L"Message", MB_OK);
			return E_FAIL;
		}


		m_bTextCalled = true;
	}

	m_vPos = D3DXVECTOR3(0.f, 0.f, 0.f);
	m_vCenter = D3DXVECTOR3(0.f, 0.f, 0.f);

	return S_OK;
}

SCENE CBackground::Progress(void)
{
	return SCENE_NONPASS;
}

void CBackground::Render(void)
{
	if (m_iID == 0)				//sky 출력
	{
		m_rcFrame = { 0, 0, 1200, 300 };
		const TEX_INFO* pTexInfo = GET_SINGLE(CTextureMgr)->GetTexture(L"Sky");
		if (pTexInfo == NULL)
			return;

		//위치
		D3DXMATRIX matTrans;
		D3DXMatrixIdentity(&matTrans);
		D3DXMatrixTranslation(&matTrans, m_vPos.x, m_vPos.y, m_vPos.z);

		GetSprite()->SetTransform(&matTrans);
		GetSprite()->Draw(pTexInfo->pTexture, &m_rcFrame, &m_vCenter,
			NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
	}
	if (m_iID == 1)				//ground 출력
	{
		m_rcFrame = { 0, 0, 1200, 500 };
		const TEX_INFO* pTexInfo = GET_SINGLE(CTextureMgr)->GetTexture(L"Ground");
		if (pTexInfo == NULL)
			return;

		//위치
		D3DXMATRIX matTrans;
		D3DXMatrixIdentity(&matTrans);
		D3DXMatrixTranslation(&matTrans, m_vPos.x, m_vPos.y + 300.f, m_vPos.z);

		GetSprite()->SetTransform(&matTrans);
		GetSprite()->Draw(pTexInfo->pTexture, &m_rcFrame, &m_vCenter,
			NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
	}
	if(m_iID == 2)				//tree 출력
	{
		m_rcFrame = { 0, 0, 777, 300 };
		const TEX_INFO* pTexInfo = GET_SINGLE(CTextureMgr)->GetTexture(L"Tree");
		if (pTexInfo == NULL)
			return;

		//위치
		D3DXMATRIX matTrans;
		D3DXMatrixIdentity(&matTrans);
		D3DXMatrixTranslation(&matTrans, m_vPos.x, m_vPos.y, m_vPos.z);


		GetSprite()->SetTransform(&matTrans);
		GetSprite()->Draw(pTexInfo->pTexture, &m_rcFrame, &m_vCenter,
			NULL, D3DCOLOR_ARGB(255, 255, 255, 255));

		//그림이 짧아 두번 출력
		D3DXMatrixIdentity(&matTrans);
		D3DXMatrixTranslation(&matTrans, m_vPos.x + 777, m_vPos.y, m_vPos.z);
		GetSprite()->SetTransform(&matTrans);
		GetSprite()->Draw(pTexInfo->pTexture, &m_rcFrame, &m_vCenter,
			NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
	}
}

void CBackground::Release(void)
{
}

CBackground::CBackground()
{
}

CBackground::CBackground(int _iID)
	:CObj(_iID)
{
}

CBackground::~CBackground()
{
}
