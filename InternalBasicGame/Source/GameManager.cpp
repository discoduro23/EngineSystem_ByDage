//BASIC GAME

#include <GameManager.h>
void GameManager::Update()
{
	GraphicManager* grM = GraphicManager::GetInstancePtr();
	
	//All inside isInit will be executed only once and at start
	if (isInit) {
		
		//Load Zone!
#if _DEBUG

		std::string backgroundPath = "../../Media/images/background.png";
		std::string dotPath = "../../Media/images/Dot/dot.bmp";
		std::string dotARROWPath = "../../Media/images/Dot/dotARROW.bmp";
		std::string dotWASDPath = "../../Media/images/Dot/dotWASD.bmp";
		std::string particleRedPath = "../../Media/images/Particle/red.bmp";
		std::string particleGreenPath = "../../Media/images/Particle/green.bmp";
		std::string particleBluePath = "../../Media/images/Particle/blue.bmp";
		std::string particleShimmerPath = "../../Media/images/Particle/shimmer.bmp";
		
#endif
#if (!_DEBUG)

		std::string backgroundPath = "./Media/images/background.png";
		std::string dotPath = "./Media/images/Dot/dot.bmp";
		std::string dotARROWPath = "./Media/images/Dot/dotARROW.bmp";
		std::string dotWASDPath = "./Media/images/Dot/dotWASD.bmp";
		std::string particleRedPath = "./Media/images/Particle/red.bmp";
		std::string particleGreenPath = "./Media/images/Particle/green.bmp";
		std::string particleBluePath = "./Media/images/Particle/blue.bmp";
		std::string particleShimmerPath = "./Media/images/Particle/shimmer.bmp";
#endif
		
		grM->SetBGTexture(grM->LoadTexture(backgroundPath));

		Dot* dot1 = new Dot("dot1", 20, 20, 20, 20, grM->LoadTexture(dotARROWPath), 0, true,
			grM->LoadTexture(particleRedPath), grM->LoadTexture(particleShimmerPath));
		Dot* dot2 = new Dot("dot2", 50, 40, 20, 20, grM->LoadTexture(dotWASDPath), 1, true, 
			grM->LoadTexture(particleBluePath), grM->LoadTexture(particleShimmerPath));
		Dot* dot3 = new Dot("dot3", 100, 60, 20, 20, grM->LoadTexture(dotPath), -1, true, 
			grM->LoadTexture(particleGreenPath), grM->LoadTexture(particleShimmerPath));

		ObjectManager::GetInstance().AddObject(dot1);
		ObjectManager::GetInstance().AddObject(dot2);
		ObjectManager::GetInstance().AddObject(dot3);
	}
	
	
}



