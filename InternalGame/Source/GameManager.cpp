#include <GameManager.h>


void GameManager::Update()
{
	if (isInitialized()) {
		Dot dot1("dot", 20, 20, 20, 20, GraphicManager::GetInstance().LoadTexture("../../Media/dot.bmp"));
		ObjectManager::GetInstance().AddObject(&dot1);
	}
}

void GameManager::Destroy()
{
	
}


