#include "Instruction.h"

#include <string>

using namespace std;


Instruction::Instruction(string a, string b, string c, int d){
	rw = a;
	subj = b;
	obj = c;
	val = d;
}

string Instruction::getReadOrWrite(){
	return rw;
}

string Instruction::getSubject(){
	return subj;
}

string Instruction::getObject(){
	return obj;
}

int Instruction::getValue(){
	return val;
}

void Instruction::passToRef(ReferenceMonitor& refMon){
	refMon.setInstructionRW(getReadOrWrite());
	refMon.setInstructionSubject(getSubject());
	refMon.setInstructionObject(getObject());
	refMon.setInstructionValue(getValue());
}
