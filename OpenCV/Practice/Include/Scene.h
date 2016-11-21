#pragma once

class CScene
{
public:
	virtual HRESULT Initialize(void) PURE;
	virtual SCENE Progress(void) PURE;
	virtual void Render(void) PURE;
	virtual void Release(void) PURE;
public:
	CScene();
	virtual ~CScene();
};

