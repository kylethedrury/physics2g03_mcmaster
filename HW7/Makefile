testlookup: testlookup.o interp.o
	c++ -o testlookup testlookup.o interp.o

testlookup.o: testlookup.cpp
	c++ -c testlookup.cpp

testinterp: testinterp.o interp.o	
	c++ -o testinterp testinterp.o interp.o

testinterp.o: testinterp.cpp
	c++ -c testinterp.cpp

interp.o: interp.cpp interp.h
	c++ -c interp.cpp interp.h


