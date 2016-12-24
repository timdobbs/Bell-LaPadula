#include "object.h"

#include <string>

using namespace std;

Object::Object(string newName){
	name = newName;
	value = 0;
}

string Object::getName(){
	return name;
}

int Object::getValue(){
	return value;
}

void Object::setValue(int n){
	value = n;
}

