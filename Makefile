all:	web

web:	main.o 
	g++ -o web main.o

main.o: main.cc Node.h Web.h
	g++ -c main.cc
	
clean:
	rm -f *.o web
