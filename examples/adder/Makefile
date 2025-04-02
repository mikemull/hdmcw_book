
adder: adder.o
	ld -macos_version_min 14.0.0 -o adder adder.o -e _start -arch arm64 

adder.o: adder.s
	as -o adder.o adder.s
