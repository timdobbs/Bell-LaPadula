#ifndef Instruction_H
#define Instruction_H

#include "ReferenceMonitor.h"

#include <string>

class ReferenceMonitor;    //compiler complains unless this is included

//Instance of this class will be passed to reference monitor for final parsing and execution
class Instruction{

	std::string rw;        //read or write value
	std::string subj;	   //subject value	
	std::string obj;       //object value
	int val;               //value of "value" from instruction

public:

	Instruction(std::string, std::string, std::string, int);
	void passToRef(ReferenceMonitor&);							//this method passes the instance to the reference monitor
	std::string getReadOrWrite();
	std::string getSubject();
	std::string getObject();
	int getValue();
};

#endif