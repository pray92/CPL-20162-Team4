#include "stdafx.h"
#include "ObjMgr.h"

#include "Character.h"

CObjMgr::CObjMgr(void)
{
}


CObjMgr::~CObjMgr(void)
{
	Release();
}

void CObjMgr::InsertObject(shared_ptr<CCharacter> pObject, TYPE eType)
{
	pObject->Initialize();
	m_vecObject.push_back(pObject);
}

SCENE CObjMgr::Progress()
{
	for (auto iterObj = m_vecObject.begin();
		iterObj != m_vecObject.end(); ++iterObj)
	{
		(*iterObj)->Progress();
	}

	return SCENE_NONPASS;
}

void CObjMgr::Render()
{
	sort(m_vecObject.begin(), m_vecObject.end(), RenderingSort());
	for (auto iterObj = m_vecObject.begin();
		iterObj != m_vecObject.end(); ++iterObj)
	{
		(*iterObj)->Render();
	}
}

void CObjMgr::Release(void)
{
	m_vecObject.clear();
}