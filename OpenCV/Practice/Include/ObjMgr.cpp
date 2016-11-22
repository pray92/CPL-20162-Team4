#include "stdafx.h"
#include "ObjMgr.h"

#include "Obj.h"

CObjMgr::CObjMgr(void)
{
}


CObjMgr::~CObjMgr(void)
{
	Release();
}

void CObjMgr::InsertObject(shared_ptr<CObj> pObject, TYPE eType)
{
	pObject->Initialize();
	m_vecObject[eType].push_back(pObject);
}

SCENE CObjMgr::Progress()
{
	for (auto i = 0; i < TYPE_END; ++i)
	{
		for (auto iterObj = m_vecObject[i].begin();
			iterObj != m_vecObject[i].end(); ++iterObj)
		{
			(*iterObj)->Progress();
		}
	}

	return SCENE_NONPASS;
}

void CObjMgr::Render()
{
	sort(m_vecObject[TYPE_TURTLE].begin(), m_vecObject[TYPE_TURTLE].end(), RenderingSort());
	for (auto i = 0; i < TYPE_END; ++i)
	{
		for (auto iterObj = m_vecObject[i].begin();
			iterObj != m_vecObject[i].end(); ++iterObj)
		{
			(*iterObj)->Render();
		}
	}
}

void CObjMgr::Release(void)
{
	for (auto i = 0; i < TYPE_END; ++i)
		m_vecObject[i].clear();
}