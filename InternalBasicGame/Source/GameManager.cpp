//BASIC GAME

#include <GameManager.h>
void GameManager::Update()
{
	GraphicManager* grM = GraphicManager::GetInstancePtr();
	
	//All inside isInit will be executed only once and at start
	if (isInit) {
		
		Dot* dot1 = new Dot("dot1", 20, 20, 20, 20,
			grM->LoadTexture("../../Media/images/Dot/dotARROW.bmp"), 0);
		Dot* dot2 = new Dot("dot2", 50, 40, 20, 20,
			grM->LoadTexture("../../Media/images/Dot/dotWASD.bmp"), 1);
		Dot* dot3 = new Dot("dot3", 100, 60, 20, 20,
			grM->LoadTexture("../../Media/images/Dot/dot.bmp"), 2);

		ObjectManager::GetInstance().AddObject(dot1);
		ObjectManager::GetInstance().AddObject(dot2);
		ObjectManager::GetInstance().AddObject(dot3);
	}
	
}

void GameManager::Destroy()
{	
}


