
all: securesystem

securesystem: systemsecure.o subject.o object.o Instruction.o ReferenceMonitor.o 
	g++ systemsecure.o subject.o object.o Instruction.o ReferenceMonitor.o -o securesystem

systemsecure.o: systemsecure.cpp
	g++ -c -Wall systemsecure.cpp 

subject.o: subject.cpp
	g++ -c -Wall subject.cpp

object.o: object.cpp
	g++ -c -Wall object.cpp

Instruction.o: Instruction.cpp
	g++ -c -Wall Instruction.cpp

ReferenceMonitor.o: ReferenceMonitor.cpp
	g++ -c -Wall ReferenceMonitor.cpp

clean:
	rm *.o 




