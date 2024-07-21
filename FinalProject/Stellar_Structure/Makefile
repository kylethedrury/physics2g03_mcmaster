SS: SS.o SS_math.cpp SS_math.h 
	c++ -o SS SS.o SS_math.h SS_math.o -ltrapfpe -lpgplot -lcpgplot -lX11 -lm 

SS.o: SS_math.cpp SS_math.h SS_math.o
	c++ -c -O0 -g -Wall SS.cpp SS_math.o -ltrapfpe -lpgplot -lcpgplot -lX11 -lm 

SS_math.o: SS_math.cpp SS_math.h
	c++ -c -O0 -g SS_math.cpp SS_math.h -ltrapfpe -lpgplot -lcpgplot -lX11 -lm 
