stat:stat.c
	gcc -o stat stat.c
run:stat
	./stat
clean:
	rm *~
	rm a.out
