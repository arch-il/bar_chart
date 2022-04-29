all:
	@g++ src/main.cpp src/chart.cpp -I inc/ -g --std=c++17 -o bin/chart

run: all
	@./bin/chart