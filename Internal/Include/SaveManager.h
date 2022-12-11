#pragma once
#include <SDL.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include "Singleton.h"
#include <vector>

#pragma warning(disable : 4996)


/**
Save Manager class
*/
class SaveManager :public Singleton<SaveManager> {
	/*****************************************************************************/
	friend class Singleton<SaveManager>;
	/*****************************************************************************/
private:

	// Private constructor to avoid more than one instance
	SaveManager() {};

	//data to store
	int totalData = 0;
	
	//Data to store
	std::vector<int> mSaveData = std::vector<int>();

	//storagePath
	std::string mStoragePath;
	/*****************************************************************************/

public:
	//set storage path
	void SetStoragePath(std::string path) { mStoragePath = path; }
	
	// Set the Save data
	void SetSaveData(int index, int data);

	// Get the Save data
	int GetSaveData(int index);

	// Save the Save data
	bool SaveSaveData();

	// Close the Save manager
	void Close();
};