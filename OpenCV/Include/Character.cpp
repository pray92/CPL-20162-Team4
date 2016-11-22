#include "stdafx.h"
#include "Character.h"
#include "TextureMgr.h"

#include "SystemFunc.h"

bool CCharacter::m_bTextCalled = false;

HRESULT CCharacter::Initialize(void)
{
	if (!m_bTextCalled)
	{
		_finddatai64_t c_file;
		intptr_t hFile;
		char* path = "./CharacterImage/*.png";
		hFile = _findfirsti64(path, &c_file);
		int iCnt = 0;
		do {
			++iCnt;
		} while (_findnexti64(hFile, &c_file) == 0);
		_findclose(hFile);

		if (FAILED(GET_SINGLE(CTextureMgr)->InsertTexture(255, 255, 255, 255, L"./CharacterImage/%dsaved.png", L"", TEXTTYPE_MULTI, L"Turtle", iCnt)))
		{
			MessageBox(NULL, L"거북이 사진 불러오기 실패", L"Message", MB_OK);
			return E_FAIL;
		}
		m_bTextCalled = true;
	}

	m_vPos = D3DXVECTOR3(rand() % WINSIZEX, rand() % WINSIZEY, 0.f);
	m_vDestination = D3DXVECTOR3(rand() % WINSIZEX, rand() % WINSIZEY, 0.f);	// Set destination
	m_vDirection = GetUnitVec(m_vPos, m_vDestination);							// Unit vector of the m_vPos
	m_vCenter = D3DXVECTOR3(142.f, 142.f, 0.f);

	m_vStartPos = m_vPos;
	movingSpeed = 0;
	maxSpeed = (rand() % 20) / 10 + 0.5;
	acceleration = maxSpeed / 250;

	m_iFrame = 0;
	m_dwTime = GetTickCount();

	return S_OK;
}

SCENE CCharacter::Progress(void)
{
	if (GetDMagnitude(m_vStartPos, m_vPos) < (GetDMagnitude(m_vStartPos, m_vDestination) / 3))
	{
		// Accelerate
		movingSpeed += acceleration;
	}
	else if (GetDMagnitude(m_vStartPos, m_vPos) < (GetDMagnitude(m_vStartPos, m_vDestination) * 2 / 3))
	{
		//
		movingSpeed = maxSpeed;
	}
	else
	{
		// Deaccelerate
		if ((movingSpeed -= acceleration) < 0.1)
			movingSpeed = 0.1;
	}

	// Move character position to the destination
	m_vPos.x += m_vDirection.x * movingSpeed;
	m_vPos.y += m_vDirection.y * movingSpeed;
	m_vPos.z += m_vDirection.z * movingSpeed;

	// Set next position
	if (GetDMagnitude(m_vPos, m_vDestination) < 10)
	{
		m_vStartPos = m_vDestination;
		m_vDestination = D3DXVECTOR3(rand() % WINSIZEX, rand() % WINSIZEY, 0.f);

		m_vDirection = GetUnitVec(m_vPos, m_vDestination);

		movingSpeed = 0;
		maxSpeed = (rand() % 20) / 10 + 0.5;
	}

	Frame();

	return SCENE_NONPASS;
}

void CCharacter::Render(void)
{
	const TEX_INFO* pTexInfo = GET_SINGLE(CTextureMgr)->GetTexture(L"", L"Turtle", m_iID);
	if (pTexInfo == NULL)
		return;

	//월드
	D3DXMATRIX matWorld;
	D3DXMatrixIdentity(&matWorld);
	//크기
	D3DXMATRIX matScale;
	D3DXMatrixIdentity(&matScale);

	if (m_vDestination.x - m_vPos.x < 0)
	{
		D3DXMatrixScaling(&matScale, -1.f, 1.f, 1.f);
	}
	else
	{
		D3DXMatrixScaling(&matScale, 1.f, 1.f, 1.f);
	}

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

	rcFrame = { 283 * m_iFrame, 0, 283 * m_iFrame + 283, 283 };

	return rcFrame;
}

D3DXVECTOR3 CCharacter::GetUnitVec(const D3DXVECTOR3 m_vPos1, const D3DXVECTOR3 m_vPos2)
{
	int vectorLength;
	D3DXVECTOR3 m_vUnit = m_vPos2 - m_vPos1;

	vectorLength = sqrt(pow(m_vUnit.x, 2) + pow(m_vUnit.y, 2) + pow(m_vUnit.z, 2));

	m_vUnit.x = m_vUnit.x / vectorLength;
	m_vUnit.y = m_vUnit.y / vectorLength;
	m_vUnit.z = m_vUnit.z / vectorLength;

	return  m_vUnit;
}

float CCharacter::GetDMagnitude(const D3DXVECTOR3 m_vPos1, const D3DXVECTOR3 m_vPos2)
{
	float length;

	length = pow(m_vPos2.x - m_vPos1.x, 2) + pow(m_vPos2.y - m_vPos1.y, 2) + pow(m_vPos2.z - m_vPos1.z, 2);

	return length;
}

CCharacter::CCharacter()
{
}

CCharacter::CCharacter(int _iID)
	:m_iID(_iID)
{
}

CCharacter::~CCharacter()
{
}
