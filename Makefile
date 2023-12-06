all:
	rm -rf build
	mkdir build
	g++ 'cpp/main.cpp' 'cpp/bwtUtil.cpp' 'cpp/mtfUtil.cpp' -o 'build/main.exe'