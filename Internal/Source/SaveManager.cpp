#include "SaveManager.h"

void SaveManager::Close()
{

}


int SaveManager::readFile()
{
	FILE* file = fopen("../../Media/Data/save.MDyG", "r");
	if (file == nullptr) {
		std::cerr << "Error: el puntero file es nullptr" << std::endl;
		return 0;
	}

	char* str = new char[100];
	int linea = 0;
	size_t pos = 0;
	
	while (fgets(str, 100, file) != NULL) {
		
		//char* to int
		linea = atoi(str);

	}
	fclose(file);
	return linea;	
}

void SaveManager::storeFile(int score){
	
	FILE* file = fopen("../../Media/Data/save.MDyG", "w");
	if (file == nullptr) {
		std::cerr << "Error: el puntero file es nullptr" << std::endl;
		return;
	}
	
	
	fprintf(file, "%d", score);
	
	fclose(file);

}

