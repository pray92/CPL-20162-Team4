#pragma once
#include "Define.h"
#include "SystemFunc.h"
#include "Obj.h"
#include "Character.h"

struct RenderingSort
{
	bool operator()(shared_ptr<CObj> a, shared_ptr<CObj> b)
	{
		return a->GetPos().y < b->GetPos().y;
	}
};

class CObjMgr
{
	DECLARE_SINGLETON(CObjMgr)
private:
	vector<shared_ptr<CObj>> m_vecObject[TYPE_END];
public:
	void InsertObject(shared_ptr<CObj> pObject, TYPE eType = TYPE_TURTLE);
	SCENE Progress(void);
	void Render(void);
	void Release(void);
private:
	CObjMgr();
public:
	~CObjMgr();
};

