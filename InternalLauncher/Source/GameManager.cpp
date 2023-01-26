//GAME

#include <GameManager.h>


void GameManager::Update()
{


	//All inside isInit will be executed only once and at start
	if (isInit) {
		grM = GraphicManager::GetInstancePtr();
		tM = TimeManager::GetInstancePtr();
		oM = ObjectManager::GetInstancePtr();
		sM = SoundManager::GetInstancePtr();
		
#if (_DEBUG)
		std::string backgroundPath = "../../Media/Launcher/images/launcher.jpg";
		std::string buttonPath = "../../Media/Launcher/images/Buttons";
		std::string pixelFontPath = "../../Media/Launcher/fonts/PIXEL.TTF";
		std::string bgMusicPath = "../../Media/Launcher/sounds/feedthemachine.mp3";
		std::string logoPath = "../../Media/Launcher/images/3dLogo";
		
#endif
#if (!_DEBUG)
		std::string backgroundPath = "./Media/images/launcher.jpg";
		std::string buttonPath = "./Media/images/Buttons";
		std::string pixelFontPath = "./Media/fonts/PIXEL.TTF";
		std::string bgMusicPath = "./Media/sounds/feedthemachine.mp3";
		std::string logoPath = "./Media/images/3dLogo";
#endif


		//Set the background
		grM->SetBGTexture(grM->LoadTexture(backgroundPath));

		//Set fonts
		grM->loadFont(pixelFontPath, "pixel_40", 40);
		
		//Music By Dream Protocol in pixabay
		sM->LoadMusic(bgMusicPath, "bgMusic");
		sM->PlayMusic("bgMusic", -1);
		sM->SetMusicVolume("bgMusic", 50);

		HideAndWhere = new Button("HideAndWhere", grM->GetWidth() / 4 - 130, grM->GetHeight() / 2 - 70, 200, 200);
		grM->LoadTexturesFromPath(buttonPath, HideAndWhere);
		HideAndWhere->SetTexture("GameHide");
		HideAndWhere->setTextureName("GameHideSelect", "GameHide");

		SusJump = new Button("SusJump", (grM->GetWidth() / 4) * 3 - 100, grM->GetHeight() / 2 - 70, 200, 200);
		grM->LoadTexturesFromPath(buttonPath, SusJump);
		SusJump->SetTexture("GameSusJump");
		SusJump->setTextureName("GameSusJumpSelect", "GameSusJump");

		//"Add object" section
		oM->AddObject(HideAndWhere);
		oM->AddObject(SusJump);
		
		//create text
		Text* BaseText = new Text("BaseTxt", "Launcher", { 255,255,255 }, grM->GetWidth()/2-120, grM->GetHeight()/6, "pixel_40");
		grM->AddText(BaseText);

		//create logo
		Logo* logo = new Logo("Logo", grM->GetWidth() / 2 - 100, grM->GetHeight() / 2 + 50, 200, 200);
		grM->LoadTexturesFromPath(logoPath, logo);
		oM->AddObject(logo);
		
	}
	
}

void GameManager::Destroy()
{
}
