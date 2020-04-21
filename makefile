miniproject: base.o extras.o main.o
	gcc -o miniproject base.o extras.o main.o

base.o: base.h base.c
	gcc -c -o base.o base.c

extras.o: extras.h extras.c
	gcc -c -o extras.o extras.c

main.o: base.h extras.h record.h main.c
	gcc -c -o main.o main.c

clean:
	rm -f *.o
cleanx:
	rm -f *.o miniproject.exe miniproject

