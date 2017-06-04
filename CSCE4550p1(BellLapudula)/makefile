default: securesystem
securesystem: RefMon.o SecureSystem.o	
	g++ -g -Wall -o securesystem Refmon.o SecureSystem.o
Refmon.o: Refmon.cpp Refmon.h Subject.h Object.h
	g++ -g -Wall -c Refmon.cpp
SecureSystem.o: SecureSystem.cpp Refmon.h Subject.h Object.h
	g++ -g -Wall -c SecureSystem.cpp
clean: 
	$(RM) count *.o *~
