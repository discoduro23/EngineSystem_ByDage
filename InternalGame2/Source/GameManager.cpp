//GAME2

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
		std::string backgroundPath = "../../Media/SusJump/background.png";
		std::string pixelFontPath = "../../Media/SusJump/fonts/PIXEL.TTF";
		std::string playerFolderPath = "../../Media/SusJump/player/AmongusBody/";
		std::string playerHeadFolderPath = "../../Media/SusJump/player/Head/";
		std::string worldFolderPath = "../../Media/SusJump/world/";
		std::string particlePlayerPath = "../../Media/SusJump/particles/playerParticle.png";

#endif
#if (!_DEBUG)
		std::string backgroundPath = "./Media/background.png";
		std::string pixelFontPath = "./Media/fonts/PIXEL.TTF";
		std::string playerFolderPath = "./Media/player/AmongusBody/";
		std::string playerHeadFolderPath = "./Media/player/Head/";
		std::string worldFolderPath = "./Media/world/";
		std::string particlePlayerPath = "./Media/particles/playerParticle.png";
		
#endif

		//Set the background
		grM->SetBGTexture(grM->LoadTexture(backgroundPath));

		//Set fonts
		grM->loadFont(pixelFontPath, "pixel_40", 40);
		grM->loadFont(pixelFontPath, "pixel_60", 60);
		grM->loadFont(pixelFontPath, "pixel_20", 20);
		grM->loadFont(pixelFontPath, "pixel_15", 15);


		//Make the Player
		player = new Player("knight", nullptr, grM->LoadTexture(particlePlayerPath), grM->LoadTexture(particlePlayerPath),
			grM->GetWidth() / 2 - 130, grM->GetHeight() / 2, 50, 50, 0, true);
		grM->LoadTexturesFromPath(playerFolderPath, player);
		player->SetTexture("Body0");
		oM->AddObject(player);

		//Make the Player Head
		Head* head = new Head("head", player->GetX(), player->GetY(), player->GetWidth()/1.2, player->GetHeight()/1.5, nullptr, 0, false);
		grM->LoadTexturesFromPath(playerHeadFolderPath, head);
		head->SetTexture("amoHead0");
		oM->AddObject(head);
		player->SetHead(head);

		//Create the platforms
		for (int i = 0; i < 5; i++) {
			platforms.push_back(new Platform("platform"+i, 100 + (rand() % (grM->GetWidth() - 200 )), grM->GetHeight() * i / 5, 100, 25, nullptr, 0, true));
			grM->LoadTexturesFromPath(worldFolderPath, platforms[i]);
			platforms[i]->SetTexture("Platform");
			oM->AddObject(platforms[i]);
		}
		
		
		
		
		
		//Sounds
		//sM->LoadSound(goblinDrumPath, "GoblinDrum");

		//Music By Dream Protocol in pixabay
		/*sM->LoadMusic(bgMusicPath, "bgMusic");
		sM->PlayMusic("bgMusic", -1);
		sM->SetMusicVolume("bgMusic", 50);*/

		//create text
		Text* Fps = new Text("FPS", "FPS:", { 255,255,255 }, 30, grM->GetHeight() - 50, "pixel_15");
		grM->AddText(Fps);

		Text* FpsValue = new Text("FPSValue", "0", { 255,255,255 }, 75, grM->GetHeight() - 50, "pixel_15");
		grM->AddText(FpsValue);
		
		Text* Meters = new Text("Meters", "Meters:", { 255,255,255 }, 30, grM->GetHeight() - 70, "pixel_15");
		grM->AddText(Meters);

		//Set the timer

		
		
	}

	// if player is moving up, platforms move down
	if (player->GetIsOnMaxHeight() == true) {
		for (auto& platform : platforms) {
			//set velocity of platforms to velocity
			platform->SetVelY(-1000 * player->GetVelY() *tM->GetDeltaTime());

			meters += -1 * player->GetVelY() * tM->GetDeltaTime()/100;
			
			//convert meters to string with 2 float zeros
			std::string metersString = std::to_string(meters);
			metersString = metersString.substr(0, metersString.find(".") + 3);
			
			grM->ChangeWText("Meters", "Meters: " + metersString);
			
		}
	}
	// if player is moving down, platforms dont move
	else {
		for (auto& platform : platforms) {
			//set velocity of platforms to velocity
			platform->SetVelY(0);
		}
	}

	//Update texts
	grM->ChangeWText("FPSValue", std::to_string(tM->GetFPS()));

	//if player is dead reset game
	if (player->GetIsDead() == true) {
		meters = 0;
		std::string metersString = std::to_string(meters);
		metersString = metersString.substr(0, metersString.find(".") + 3);

		grM->ChangeWText("Meters", "Meters: " + metersString);
	}
		

	//Check collisions between foreach platform with player
	for (auto& platform : platforms) {
		if (PhysicsManager::GetInstance().CheckCollision(player->GetRect(), platform->GetRect()) && player->GetVelY() > 0 &&
			player->GetY() + player->GetHeight() < platform->GetY() + platform->GetHeight()) {
			player->AddVelY();
			
		}
	}

	//Save and load (K to Save, L to load)
	if (InputManager::GetInstance().GetKey(SDL_SCANCODE_K))
		SaveGameState();

	if (InputManager::GetInstance().GetKey(SDL_SCANCODE_L))
		LoadGameState();
}

void GameManager::Destroy()
{
}

void GameManager::SaveGameState()
{
	std::vector<std::string> saveData;
	
	saveData.push_back(std::to_string(meters));
	saveData.push_back(std::to_string(player->GetX()));
	saveData.push_back(std::to_string(player->GetY()));
	
	//save all platforms positions
	for (auto& platform : platforms) {
		saveData.push_back(std::to_string(platform->GetX()));
		saveData.push_back(std::to_string(platform->GetY()));
	}

	SaveManager::GetInstance().storeFile(saveData, "Game2");
}

void GameManager::LoadGameState()
{

	std::vector<std::string> saveData = SaveManager::GetInstance().readFile("Game2");
	
	meters = (std::stof(saveData[0]));
	player->SetX(std::stof(saveData[1]));
	player->SetY(std::stof(saveData[2]));
	
	//load all platforms positions
	for (int i = 0; i < platforms.size(); i++) {
		platforms[i]->SetX(std::stof(saveData[3 + i * 2]));
		platforms[i]->SetY(std::stof(saveData[4 + i * 2]));
	}
	
	std::string metersString = std::to_string(meters);
	metersString = metersString.substr(0, metersString.find(".") + 3);

	grM->ChangeWText("Meters", "Meters: " + metersString);

}
