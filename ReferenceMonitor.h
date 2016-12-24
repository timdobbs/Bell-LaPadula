#ifndef ReferenceMonitor_H
#define ReferenceMonitor_H

#include "Instruction.h"
#include "subject.h"
#include "object.h"

#include <iostream>
#include <string>
#include <map>
#include <vector>

const int LOW = 1;
const int MEDIUM = 2;
const int HIGH = 3;


class ReferenceMonitor{

	//these variables hold the values passed by the instruction object
	std::string instructionRW;
	std::string instructionSubject;
	std::string instructionObject;
	int instructionValue;

	//vectors that hold ONLY the names of the subjects and objects respectively. For instruction validation purposes
	std::vector<std::string> subjectNames;
	std::vector<std::string> objectNames;

	//Maps that will contain subjects/object pointers(keys) associated with a security level(values).
	std::map<Subject*, int> subjects;
	std::map<Object*, int> objects;

public:	
	
	void createSubject(std::string, int);
	void createObject(std::string, int);
	void executeRead();
	void executeWrite();
	void printState();

	//setters
	void setInstructionRW(std::string);
	void setInstructionSubject(std::string);
	void setInstructionObject(std::string);
	void setInstructionValue(int);

	//gets security level for subjects and objects respectively
	int getSubjectLevel();
	int getObjectLevel();

	//getters
	std::string getInstructionRW();
	std::string getInstructionSubject();
	std::string getInstructionObject();
	int getInstructionValue();
	
	//parses the instruction object and calls executeRead() or executeWrite() if valid.
	void handleInstruction();
	

};

#endif