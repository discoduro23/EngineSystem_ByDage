#include "SaveManager.h"

void SaveManager::SetSaveData(int index, int data)
{
	mSaveData[index] = data;
}

int SaveManager::GetSaveData(int index)
{
	//Open data file
	std::string path = mStoragePath + "data.dat";
	FILE* file = fopen(path.c_str(), "r");
	if (file != NULL)
	{
		//Read data
		for (int i = 0; i < mSaveData.size(); ++i)
		{
			fscanf(file, "%d", &mSaveData[i]);
		}

		//Close file handler
		fclose(file);
	}
	return 0;
}

bool SaveManager::SaveSaveData()
{
	//Open data file
	std::string path = mStoragePath + "data.dat";
	FILE* file = fopen(path.c_str(), "w");
	if (file != NULL)
	{
		//Save data
		for (int i = 0; i < mSaveData.size(); ++i)
		{
			fprintf(file, "%d", mSaveData[i]);
		}

		//Close file handler
		fclose(file);
	}
	else
	{
		printf("Error: Unable to save file! %s\n", SDL_GetError());
		return false;
	}
	return true;
}

void SaveManager::Close()
{
}
