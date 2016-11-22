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
			MessageBox(NULL, L"���� ��� ���� �ҷ����� ����", L"Message", MB_OK);
			return E_FAIL;
		}

		if (FAILED(GET_SINGLE(CTextureMgr)->InsertTexture(255, 0, 0, 0, L"./Background/sky.jpg", L"Sky", TEXTTYPE_SINGLE)))
		{
			MessageBox(NULL, L"�ϴ� ��� ���� �ҷ����� ����", L"Message", MB_OK);
			return E_FAIL;
		}

		if (FAILED(GET_SINGLE(CTextureMgr)->InsertTexture(255, 0, 0, 0, L"./Background/ground.png", L"Ground", TEXTTYPE_SINGLE)))
		{
			MessageBox(NULL, L"�غ� ��� ���� �ҷ����� ����", L"Message", MB_OK);
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
	if (m_iID == 0)				//sky ���
	{
		m_rcFrame = { 0, 0, 1200, 300 };
		const TEX_INFO* pTexInfo = GET_SINGLE(CTextureMgr)->GetTexture(L"Sky");
		if (pTexInfo == NULL)
			return;

		//��ġ
		D3DXMATRIX matTrans;
		D3DXMatrixIdentity(&matTrans);
		D3DXMatrixTranslation(&matTrans, m_vPos.x, m_vPos.y, m_vPos.z);

		GetSprite()->SetTransform(&matTrans);
		GetSprite()->Draw(pTexInfo->pTexture, &m_rcFrame, &m_vCenter,
			NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
	}
	if (m_iID == 1)				//ground ���
	{
		m_rcFrame = { 0, 0, 1200, 500 };
		const TEX_INFO* pTexInfo = GET_SINGLE(CTextureMgr)->GetTexture(L"Ground");
		if (pTexInfo == NULL)
			return;

		//��ġ
		D3DXMATRIX matTrans;
		D3DXMatrixIdentity(&matTrans);
		D3DXMatrixTranslation(&matTrans, m_vPos.x, m_vPos.y + 300.f, m_vPos.z);

		GetSprite()->SetTransform(&matTrans);
		GetSprite()->Draw(pTexInfo->pTexture, &m_rcFrame, &m_vCenter,
			NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
	}
	if(m_iID == 2)				//tree ���
	{
		m_rcFrame = { 0, 0, 777, 300 };
		const TEX_INFO* pTexInfo = GET_SINGLE(CTextureMgr)->GetTexture(L"Tree");
		if (pTexInfo == NULL)
			return;

		//��ġ
		D3DXMATRIX matTrans;
		D3DXMatrixIdentity(&matTrans);
		D3DXMatrixTranslation(&matTrans, m_vPos.x, m_vPos.y, m_vPos.z);


		GetSprite()->SetTransform(&matTrans);
		GetSprite()->Draw(pTexInfo->pTexture, &m_rcFrame, &m_vCenter,
			NULL, D3DCOLOR_ARGB(255, 255, 255, 255));

		//�׸��� ª�� �ι� ���
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
