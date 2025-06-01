
random: random.o
	ld -o random random.o -e _start -arch arm64 

random2: random2.o
	ld -o random2 random2.o -e _start -arch arm64 

random.o: random.s
	as -o random.o random.s

random2.o: random2.s
	as -o random2.o random2.s
