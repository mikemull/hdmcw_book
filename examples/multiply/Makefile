
multiply: multiply.o
	ld -macos_version_min 26.0.0 -o multiply multiply.o -lSystem -syslibroot `xcrun -sdk macosx --show-sdk-path` -e _main -arch arm64 

multiply.o: multiply.s
	as -o multiply.o multiply.s
