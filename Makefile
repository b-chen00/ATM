output: ATM.o Account.o
	g++ ATM.o Account.o

ATM.o: ATM.cpp
	g++ -c ATM.cpp

Account.o: Account.cpp Account.h
	g++ -c Account.cpp

run: output
	./a.exe
