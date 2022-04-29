all:
	@g++ src/main.cpp src/chart.cpp -I inc/ -g --std=c++17 -o bin/chart.exe

run: all
	@./bin/chart.exe