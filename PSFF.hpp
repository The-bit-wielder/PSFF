#ifndef PSFF_HPP //Check if library was declared already
#define PSFF_HPP
#endif //PSFF_HPP
//Include Standard Libraries
#include <fstream>
#include <string>
//Dont forget to include BDL
//Declare the namespace
namespace PSFF {
	//Function to initialize the file 
	bool initializeFile(const std::string& initialNode,const std::string& filename,const bool& shouldOverwrite) {
		std::string firstLine; //String to store the first line of the file
		filename = filename.empty() ? "file.psff" : filename;// Check for empty file name and assing a default filename
		if(initialNode=="") //Check for empty initial node
		{
			//BDL
			return false;
		}
		std::ifstream file(filename); //Open the file for reading
		if (file.fail()) //Check if file opened succesfuly
		{
			//BDL
			return false;
		}
		else { 
			std::getline(file, firstLine);//Read first line of the file
			if (initialNode == firstLine) //Check if the file has the declared file name
			{
				//BDL
				file.close();
				return true;
			}
			else {
				if (!shouldOverwrite) { //Should the program overwrite contents
					//BDL
					file.close();
					return false;
				}
				else
				{
					//BDL
					std::ofstream file(filename); //Open file for writing
					if(!file.fail()) //Check for failure
					{
					file <<"[" + initialNode + "]\n";
					//BDL
					file.close();
					return true;
					}
					else
					{
					//BDL
					return false;
					}
				}
			}
		}
	}
}
