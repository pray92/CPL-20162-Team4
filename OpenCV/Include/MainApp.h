#pragma once

class CMainApp
{
public:
	HRESULT Initialize(void);
	void Progress(void);
	void Render(void);
	void Release(void);
public:
	CMainApp();
	~CMainApp();
};

