#pragma once
#include <SDL.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
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

	SDL_sem* DataLock = nullptr;

	
	/*****************************************************************************/

public:

	int readFile();
	
	void storeFile(int);

	// Close the Save manager
	void Close();
};