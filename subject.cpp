#include "subject.h"

#include <string>


using namespace std;

Subject::Subject(string newName){
	name = newName;
	temp = 0;
}

void Subject::setName(string newName){
	name = newName;
}

string Subject::getName(){
	return name;
}

void Subject::setTemp(int n){
	temp = n;
}

int Subject::getTemp(){
	return temp;
}



