#ifndef PSFF_HPP          //Check if library was declared already
#define PSFF_HPP
//Include Standard Libraries
#include <fstream>
#include <string>
#ifdef BDL
#include "BitsDebugging.hpp"
#endif //BDL
//Declare the namespace
namespace PSFF {
/**
 * Initializes a file with a specified node.
 * @param initialNode The name of the node to initialize the file with
 * @param filename The path to the file to initialize
 * @param shouldOverwrite Whether to overwrite the file if it already exists with a different node
 * @return true if initialization was successful, false otherwise
 */
	inline bool initializeFile(const std::string& initialNode,
								const std::string& filename,
								 const bool shouldOverwrite) 
	{
		std::string firstLine; 																//String to store the first line of the file
		if(initialNode=="") 																//Check for empty initial node
		{
			#ifdef BDL
			BDL::linearDebugMessage("Empty initial node.Please provide node name",true);
			#endif //BDL
			return false;
		}
		std::ifstream file(	filename); //Open the file for reading
		if (file.fail()) 			   //Check if file opened succesfuly
		{
			#ifdef BDL
			BDL::linearDebugMessage("File could not be opened",true);
			#endif //BDL
			return false;
		}
		else { 
			std::getline(file, firstLine);   //Read first line of the file
			if (initialNode.find(firstLine)!=NULL) //Check if the file has the declared file name
			{
				#ifdef BDL
				BDL::linearDebugMessage("File already initialized.Enjoy",false);
				#endif //BDL
				file.close();
				return true;
			}
			else {
				if (!shouldOverwrite) { 		  //Should the program overwrite contents
					#ifdef BDL
					BDL::linearDebugMessage("File opened but wrong default node is already declared ",false);
					#endif //BDL
					file.close();
					return false;
				}
				else
				{	
					#ifdef BDL
					BDL::linearDebugMessage("File opened but wrong default node is already declared.Overwriting",false);
					#endif //BDL
					file.close(); 				  //Close the file before opening it for writing
					std::ofstream file(filename); //Open file for writing
					if(!file.fail()) 			  //Check for failure
					{
					file <<"[" + initialNode + "]\n";
					#ifdef BDL
					BDL::linearDebugMessage("File opened and overwritten",false);
					#endif //BDL
					}
					file.close();
					return true;
					}
					else
					{
					#ifdef BDL
					BDL::linearDebugMessage("File could not be opened",true);
					#endif //BDL
					return false;
				}
			}
		}
		void writeToFile(){
			
		}
	}
}
#endif                    //PSFF_HPP
