//Tim Dobbs
//CSCE 4550 Fall 2016
//Project 1

#include "ReferenceMonitor.h"
#include "Instruction.h"


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int numWords(string const& s);               //used to for initial file parsing


int main(int argc, char **argv){

	

	ReferenceMonitor refMon;

	refMon.createSubject("adam", LOW);
	refMon.createSubject("james", MEDIUM);
	refMon.createSubject("tim", HIGH);
	refMon.createSubject("sara", LOW);
	refMon.createSubject("kristy", MEDIUM);
	refMon.createSubject("liz", HIGH);

	refMon.createObject("aobj", LOW);
	refMon.createObject("jobj", MEDIUM);
	refMon.createObject("tobj", HIGH);
	refMon.createObject("sobj", LOW);
	refMon.createObject("kobj", MEDIUM);
	refMon.createObject("lobj", HIGH);

	

	string command;                     
	ifstream commandFile(argv[1]);


	while(getline(commandFile, command)){                      //store each line of file in "command" variable

		
		if(numWords(command) < 3 || numWords(command) > 4){
			cout << "Bad Instruction : " << command << endl;
		}
		else{

			string readOrWrite;                                //first 4 variables to be used in instruction object
			string subject;
			string object;
			int value;
			int numberOfWords = numWords(command);             //use of user defined function

			istringstream stream(command);                     //store each line of file in stream 
			stream >> readOrWrite;

			//Parse each line of file
			switch (numberOfWords){
				case 3:	

					if(readOrWrite.compare("read") == 0 && (stream >> subject >> object)){
							Instruction instr(readOrWrite, subject, object, 0);
							instr.passToRef(refMon);
							refMon.handleInstruction();
							
							
					}
					else{
							cout << "Bad Instruction : " << stream.str() << endl;
					}
					break;

				case 4: 
					
					if(readOrWrite.compare("write") == 0 && (stream >> subject >> object >> value)){
							Instruction instr(readOrWrite, subject, object, value);
						 	instr.passToRef(refMon);
						 	refMon.handleInstruction();
					}
					else{
						cout << "Bad Instruction : " << stream.str() << endl; 
					}
					break;
				    
					
				default:
						cout << "Bad Instruction : " << stream.str() << endl;
			}

		}
	
	}
	

	commandFile.close();

return 0;
}



int numWords(string const& s){
	if(s.empty()) return 0;

	int words = 1;

	for(int i = 0; i < s.length(); i++){
		if(s[i] == ' '){
			words++;
		}
	}

	return words;
}

