all:
	mkdir build
	g++ 'cpp/main.cpp' 'cpp/bwtUtil.cpp' -o 'build/main.exe'