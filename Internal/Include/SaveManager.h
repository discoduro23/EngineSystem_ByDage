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

	//vector of strings
	std::vector<std::string> _data;
	
	/*****************************************************************************/

public:

	std::vector<std::string> readFile(std::string gameName);
	
	void storeFile(std::vector<std::string> data, std::string gameName);

	// Close the Save manager
	void Close() {
		_data.clear();
	};
};