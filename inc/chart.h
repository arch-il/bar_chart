#pragma once
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Chart
{
private:
	std::vector<int> values;
	std::vector<std::string> chart;
	int start_height;
	int height, width; // size of chart 
	int max; // maximum number possible on chart

	void get_max_limit(int num); // find next round number
	int get_len_of_int(int num); // get length of int
public:
	Chart(int start_height = 10);
	void add_value(int num); // add value to variables
	void display_chart(); // create and display chart on the screen
};