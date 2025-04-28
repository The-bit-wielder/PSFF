#ifndef PSFF_HPP
#define PSFF_HPP
#endif
#include <fstream>
#include <string>
const char delimiter = ' ';

namespace PSFF {
	void initializeFile(std::string initialNode, std::string filename, bool shouldOverwrite) {
		std::string firstLine;
		if (filename.empty())
		{
			filename = "file.psff";
			//bdl
		}
		std::ifstream file(filename);
		if (file.fail())
		{
			//bdl
		}
		else {
			std::getline(file, firstLine,delimiter);
			if (initialNode == firstLine) 
			{
				//bdl
			}
			else {
				if (!shouldOverwrite) {
					//bdl
				}
				else
				{
					//bdl
					std::ofstream file(filename);
					file <<"[" + initialNode + "]\n";
				}
			}
		}
	}
}