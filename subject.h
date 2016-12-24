#ifndef Subject_H
#define Subject_H


#include <string>


class Subject{
	std::string name;
	int temp;					
	

public:
	
	Subject(std::string);
	void setName(std::string);
	std::string getName();
	void setTemp(int);
	int getTemp();
	
};


#endif