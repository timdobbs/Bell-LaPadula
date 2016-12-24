#ifndef Object_H
#define Object_H

#include <string>


class Object{

	std::string name;
	int value;        
	

public:

	Object(std::string);
	std::string getName();
	void setValue(int);
	int getValue();
	
};

#endif