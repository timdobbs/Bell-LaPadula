#include "ReferenceMonitor.h"
#include "Instruction.h"

#include <iostream>
#include <string>
#include <map>                
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

//create instance of "subject" class and store with associated security level in map container
void ReferenceMonitor::createSubject(string name, int level){
	subjectNames.push_back(name);                               //append subject name to subjectNames vector

	Subject *subj = new Subject(name);
	subjects.insert(pair<Subject*, int>(subj, level));			//store names only for parsing purposes

}

//create instance of "object" class and store with associated security level in map container
void ReferenceMonitor::createObject(string name, int level){	
	objectNames.push_back(name);								//append object name to objectNames vector

	Object *obj = new Object(name);
	objects.insert(pair<Object*, int>(obj, level));				//store names only for parsing purposes

}

void ReferenceMonitor::printState(){

	cout << "+---------------------The current state is--------------------+" << endl;
	cout << setw(8) << left << "Subject" << "|";
	for (map<Subject*, int>::iterator it = subjects.begin(); it != subjects.end(); ++it){
		cout << setw(8) << right << it->first->getName() << "|";
	}

	cout << endl;

	cout << setw(8) << left << "Value" << "|";
	for (map<Subject*, int>::iterator it = subjects.begin(); it != subjects.end(); ++it){
		cout << setw(8) << right << it->first->getTemp() << "|";
	}

	cout << endl;
	cout << "+-------------------------------------------------------------+" << endl;

	

	cout << setw(8) << left << "Object" << "|";
	for (map<Object*, int>::iterator it = objects.begin(); it != objects.end(); ++it){
		
		cout << setw(8) << right << it->first->getName() << "|";
	}

	cout << endl;

	cout << setw(8) << left << "Value" << "|";
	for (map<Object*, int>::iterator it = objects.begin(); it != objects.end(); ++it){
		cout << setw(8) << right << it->first->getValue() << "|";
	}

	cout << endl;
	cout << "+-------------------------------------------------------------+" << endl;

}

int ReferenceMonitor::getSubjectLevel(){
	string subject = getInstructionSubject();
	int level;

	for (map<Subject*, int>::iterator it = subjects.begin(); it != subjects.end(); ++it){
		if(subject.compare(it->first->getName()) == 0){
			level = it->second;
		}
	}

	return level;

}

int ReferenceMonitor::getObjectLevel(){
	string object = getInstructionObject();
	int level;

	for (map<Object*, int>::iterator it = objects.begin(); it != objects.end(); ++it){
		if(object.compare(it->first->getName()) == 0){
			level = it->second;
		}
	}

	return level;
	
}

void ReferenceMonitor::executeRead(){
	string readorwrite = getInstructionRW();
	string subject = getInstructionSubject();
	string object = getInstructionObject();
	int val = getInstructionValue();

	int subjectLevel = getSubjectLevel();
	
	int objectLevel = getObjectLevel();
	int objectValue;


	if(subjectLevel >= objectLevel){
		for (map<Object*, int>::iterator it = objects.begin(); it != objects.end(); ++it){
			if(object.compare(it->first->getName()) == 0){
				objectValue = it->first->getValue();
			}
		}

		for (map<Subject*, int>::iterator it = subjects.begin(); it != subjects.end(); ++it){
			if(subject.compare(it->first->getName()) == 0){
				it->first->setTemp(objectValue);
			}
		}

		cout << "Access Granted : " << subject << " reads " << object << endl;
		printState();
	}
	else{

		cout << "Access Denied : " << readorwrite << " " << subject << " " << object << endl;
	}

}

void ReferenceMonitor::executeWrite(){
	string readorwrite = getInstructionRW();
	string subject = getInstructionSubject();
	string object = getInstructionObject();
	int val = getInstructionValue();

	int subjectLevel = getSubjectLevel();
	int subjectValue;

	int objectLevel = getObjectLevel();
	int objectValue;

	if(subjectLevel <= objectLevel){

		for (map<Object*, int>::iterator it = objects.begin(); it != objects.end(); ++it){
			if(object.compare(it->first->getName()) == 0){
				it->first->setValue(val);
			}
		}

		cout << "Access Granted : " << subject << " writes value " << val << " to " << object << endl;
		printState();
	}
	else{

		cout << "Access Denied : " << readorwrite << " " << subject << " " << object << " " << val << endl;
	}

}


//the rest of the methods handle the values passed in the instruction object
void ReferenceMonitor::setInstructionRW(string s){
	instructionRW = s;
}

void ReferenceMonitor::setInstructionSubject(string s){
	instructionSubject = s;
}

void ReferenceMonitor::setInstructionObject(string s){
	instructionObject = s;
}

void ReferenceMonitor::setInstructionValue(int n){
	instructionValue = n;
}
string ReferenceMonitor::getInstructionRW(){
	return instructionRW;
}

string ReferenceMonitor::getInstructionSubject(){
	return instructionSubject;
}

string ReferenceMonitor::getInstructionObject(){
	return instructionObject;
}

int ReferenceMonitor::getInstructionValue(){
	return instructionValue;
}

//final parsing and calls to execute read/write if valid
void ReferenceMonitor::handleInstruction(){

	string readorwrite = getInstructionRW();
	string subject = getInstructionSubject();
	string object = getInstructionObject();
	int val = getInstructionValue();

	//check if the passed in subject and object values from instruction object are valid
		if(readorwrite.compare("read") == 0){
			if(!(find(subjectNames.begin(), subjectNames.end(), subject) != subjectNames.end()) ||
				!(find(objectNames.begin(), objectNames.end(), object) != objectNames.end())){
		 			
		 			cout << "Bad Instruction : " << readorwrite << " " << subject << " " << object << endl;
			}
		 	else{
				
				executeRead();
			}

		 }
			

		if(readorwrite.compare("write") == 0){
			if(!(find(subjectNames.begin(), subjectNames.end(), subject) != subjectNames.end()) ||
				!(find(objectNames.begin(), objectNames.end(), object) != objectNames.end())){
		 			
		 			cout << "Bad Instruction : " << readorwrite << " " << subject << " " << object << " " << val << endl;
			}
		 	else{
				
				executeWrite();
			}
			
		}
}



