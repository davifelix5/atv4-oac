common = main.c dgemm.h
flags = -Wall -Wextra -std=c99 -fopenmp -lm -O3

all: cap2 cap3 cap4 cap5
	for n in 0 1 2 3 4; do \
		for c in 2 3 4 5; do \
			./cap$$c.out; \
		done \
	done > out.txt

cap2:
	gcc $(flags) -o cap2.out $(common) cap2.c

cap3:
	gcc $(flags) -mavx -o cap3.out $(common) cap3.c

cap4:
	gcc $(flags) -mavx -o cap4.out $(common) cap4.c

cap5:
	gcc $(flags) -mavx -o cap5.out $(common) cap5.c

clear:
	rm *.out