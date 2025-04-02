
beep: beep.o
	ld -macos_version_min 14.0.0 -o beep beep.o -lSystem -syslibroot `xcrun -sdk macosx --show-sdk-path` -e _start -arch arm64 

beep.o: beep.s
	as -o beep.o beep.s
