#pragma once

#include <fstream>
#include <iostream>

class QuitFile
{
public:
	QuitFile() : file{} {
		std::cout << "QuitFile created!" << std::endl;
		file.open ("quit.txt");
		file << "quit"; 		
	}

	~QuitFile() {
		file.close();
	}	
private:
	std::ofstream file;
};
