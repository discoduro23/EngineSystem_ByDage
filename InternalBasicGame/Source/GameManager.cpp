//BASIC GAME

#include <GameManager.h>
void GameManager::Update()
{
	GraphicManager* grM = GraphicManager::GetInstancePtr();
	
	//All inside isInit will be executed only once and at start
	if (isInit) {
		
		//Load Zone!
#if _DEBUG
		std::string dotPath = "../../Media/images/Dot/dot.bmp";
		std::string dotARROWPath = "../../Media/images/Dot/dotARROW.bmp";
		std::string dotWASDPath = "../../Media/images/Dot/dotWASD.bmp";
		
#endif
#if (!_DEBUG)
		std::string dotPath = "./Media/images/Dot/dot.bmp";
		std::string dotARROWPath = "./Media/images/Dot/dotARROW.bmp";
		std::string dotWASDPath = "./Media/images/Dot/dotWASD.bmp";
#endif

		Dot* dot1 = new Dot("dot1", 20, 20, 20, 20, grM->LoadTexture(dotARROWPath), 0);
		Dot* dot2 = new Dot("dot2", 50, 40, 20, 20, grM->LoadTexture(dotWASDPath), 1);
		Dot* dot3 = new Dot("dot3", 100, 60, 20, 20, grM->LoadTexture(dotPath));

		ObjectManager::GetInstance().AddObject(dot1);
		ObjectManager::GetInstance().AddObject(dot2);
		ObjectManager::GetInstance().AddObject(dot3);
	}
	
}



