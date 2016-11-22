#pragma once
#include "Define.h"
#include "SystemFunc.h"
#include "Character.h"

struct RenderingSort
{
	bool operator()(shared_ptr<CCharacter> a, shared_ptr<CCharacter> b)
	{
		return a->GetPos().y < b->GetPos().y;
	}
};

class CObjMgr
{
	DECLARE_SINGLETON(CObjMgr)
private:
	vector<shared_ptr<CCharacter>> m_vecObject;
public:
	void InsertObject(shared_ptr<CCharacter> pObject, TYPE eType = TYPE_TURTLE);
	SCENE Progress(void);
	void Render(void);
	void Release(void);
private:
	CObjMgr();
public:
	~CObjMgr();
};

