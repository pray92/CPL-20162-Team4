#include "stdafx.h"
#include "Character.h"
#include "TextureMgr.h"

#include "SystemFunc.h"

bool CCharacter::m_bTextCalled = false;

HRESULT CCharacter::Initialize(void)
{
	if (!m_bTextCalled)
	{
		if (FAILED(GET_SINGLE(CTextureMgr)->InsertTexture(255, 255, 0, 255,
			L"turtle.png", L"Turtle", TEXTTYPE_SINGLE)))
		{
			MessageBox(NULL, L"거북이 사진 불러오기 실패", L"Message", MB_OK);
			return E_FAIL;
		}
		m_bTextCalled = true;
	}

	m_vPos = D3DXVECTOR3(rand() % WINSIZEX, rand() % WINSIZEY, 0.f);
	m_vCenter = D3DXVECTOR3( 142.f, 142.f, 0.f);

	m_iFrame = 0;
	m_dwTime = GetTickCount();

	return S_OK;
}

SCENE CCharacter::Progress(void)
{
	Frame();
	return SCENE_NONPASS;
}

void CCharacter::Render(void)
{
	const TEX_INFO* pTexInfo = GET_SINGLE(CTextureMgr)->GetTexture(L"Turtle");
	if (pTexInfo == NULL)
		return;

	//월드
	D3DXMATRIX matWorld;
	D3DXMatrixIdentity(&matWorld);
	//크기
	D3DXMATRIX matScale;
	D3DXMatrixIdentity(&matScale);
	D3DXMatrixTranslation(&matScale, 1.f, 1.f, 1.f);
	//위치
	D3DXMATRIX matTrans;
	D3DXMatrixIdentity(&matTrans);
	D3DXMatrixTranslation(&matTrans, m_vPos.x, m_vPos.y, m_vPos.z);

	matWorld = matScale * matTrans;

	GetSprite()->SetTransform(&matWorld);
	GetSprite()->Draw(pTexInfo->pTexture, &Frame(), &m_vCenter,
		NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
}

void CCharacter::Release(void)
{
}

RECT CCharacter::Frame()
{
	RECT rcFrame;
	if (GetTickCount() > m_dwTime + 500)
	{
		++m_iFrame; 
		m_dwTime = GetTickCount();
	}
	if (m_iFrame > 4)
		m_iFrame = 0;

	rcFrame = { 283 * m_iFrame, 0, 283 * m_iFrame + 283, 283};

	return rcFrame;
}

CCharacter::CCharacter()
{
}


CCharacter::~CCharacter()
{
}
