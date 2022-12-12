#include "SaveManager.h"

std::vector<std::string> SaveManager::readFile(std::string gameName)
{
#if _DEBUG
	std::string savePath = "../../Media/Data/" + gameName + ".MDyG";
#endif
#if (!_DEBUG)
	std::string savePath = "./Media/Data/" + gameName + ".MDyG";
#endif


	FILE* file = fopen(savePath.c_str(), "r");
	if (file == nullptr) {
		std::cerr << "Error: file is null" << std::endl;
		return std::vector<std::string>();
	}

	char* str = new char[100];
	std::vector<std::string> linea;
	size_t pos = 0;
	while (fgets(str, 100, file) != NULL) {
		
		//char* to string
		std::string str2(str);
		//erase the last character
		str2.erase(str2.size() - 1);
		//add the string to the vector
		linea.push_back(str2);

	}
	fclose(file);
	
	//Free memory
	delete[] str;
	
	return linea;	
}

void SaveManager::storeFile(std::vector<std::string> data, std::string gameName){
	
#if _DEBUG
	std::string savePath = "../../Media/Data/" + gameName + ".MDyG";
#endif
#if (!_DEBUG)
	std::string savePath = "./Media/Data/" + gameName + ".MDyG";
#endif


	FILE* file = fopen(savePath.c_str(), "w");
	if (file == nullptr) {
		std::cerr << "Error: file is null" << std::endl;
		return;
	}
	
	//recorer un vector de strings y escribirlos en el fichero
	for (int i = 0; i < data.size(); i++) {
		fputs(data[i].append("\n").c_str(), file);
	}	
	fclose(file);
	
	//Free memory
	data.clear();
	
}

