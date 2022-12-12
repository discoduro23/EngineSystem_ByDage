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
		std::string backgroundPath = "../../Media/images/launcher.jpg";
		std::string buttonPath = "../../Media/images/Buttons";
		std::string pixelFontPath = "../../Media/fonts/PIXEL.TTF";
		std::string bgMusicPath = "../../Media/sounds/feedthemachine.mp3";
		
#endif
#if (!_DEBUG)
		std::string backgroundPath = "./Media/images/launcher.jpg";
		std::string buttonPath = "./Media/images/Buttons";
		std::string pixelFontPath = "./Media/fonts/PIXEL.TTF";
		std::string bgMusicPath = "./Media/sounds/feedthemachine.mp3";
#endif


		//Set the background
		grM->SetBGTexture(grM->LoadTexture(backgroundPath));

		//Set fonts
		grM->loadFont(pixelFontPath, "pixel_40", 40);
		
		//Music By Dream Protocol in pixabay
		sM->LoadMusic(bgMusicPath, "bgMusic");
		sM->PlayMusic("bgMusic", -1);
		sM->SetMusicVolume("bgMusic", 50);

		button = new Button("button", grM->GetWidth() / 4 - 130, grM->GetHeight() / 2 - 70, 200, 200);
		grM->LoadTexturesFromPath(buttonPath, button);
		button->SetTexture("GameHide");

		//"Add object" section
		oM->AddObject(button);
		
		//create text
		Text* BaseText = new Text("BaseTxt", "Launcher", { 255,255,255 }, grM->GetWidth()/2-120, grM->GetHeight()/6, "pixel_40");
		grM->AddText(BaseText);

	}
	
}

void GameManager::Destroy()
{
}
