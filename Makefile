postfix: postfix.o 
	g++ -o postfix postfix.o

postfix.o: postfix.cpp linkedStack.h node.h
	g++ -c postfix.cpp

clean:
	rm *.o postfix