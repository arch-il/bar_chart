#include "chart.h"

//* simple pow function I created
//! DO NOT USE IT IS NOT FULLY FUNCTIONAL
int pow(int num, int pow);

Chart::Chart(int start_height)
:
start_height(start_height),
height(start_height),
width(1),
max(1)
{
	// create left bar
	for (int index{0}; index < this->height; index++)
		chart.push_back("|");

	// TODO: constructor
}

// add value to variables
void Chart::add_value(int num)
{
	values.push_back(num);
}

// create and display chart on the screen
void Chart::display_chart()
{
	// if there is no chart
	if (values.size() == 0)
		return;

	// sort values for better visual
	sort(values.begin(), values.end(), [](int a, int b) { return a > b; });
	get_max_limit(values[0]);

	// fill chart up with empty space
	this->width = (values.size() * 2) + 1;
	for (int index{0}; index < this->height; index++)
		for (int _index2{0}; _index2 < this->width; _index2++)
			chart[index] += ' ';

	// add pilars
	for (int index{0}; index < static_cast<int>(values.size()); index++)
	{
		int num_of_squares{values[index] * this->start_height / this->max};
		for (int index2{0}; index2 < num_of_squares; index2++)
		{
			chart[this->height - index2 - 1][(index + 1) * 2] = '#';
		}
	}
	
	// create down bar
	this->height++;
	chart.push_back("|");
	for (int index{0}; index < this->width; index++)
		chart[this->height - 1] += '_';

	// empty out space below bar for numbers
	for (int index{0}; index < get_len_of_int(values[0]); index++)
	{
		this->height++;
		chart.push_back("");
		for (int _index2{0}; _index2 < this->width; _index2++)
			chart[this->height - 1] += ' ';
	}

	// write numbers below bar
	for (int index{0}; index < static_cast<int>(values.size()); index++)
	{
		int len_of_num{get_len_of_int(values[index])};
		for (int index2{len_of_num}; index2 > 0; index2--)
			chart[this->height - index2][(index + 1) * 2] = '0' + (values[index] % pow(10, index2) / pow(10, index2 - 1));
	}

	// empty out space left of bar for numbers
	for (int index{0}; index < height; index++)
		for (int index2{0}; index2 < get_len_of_int(this->max) + 1; index2++)
			chart[index] = " " + chart[index];

	// write numbers left of bar
	for (int index{this->start_height}; index >= 0; index--)
	{
		int num{this->max * index / this->start_height};
		for (int index2{0}; index2 < get_len_of_int(num); index2++)
		{
			chart[this->start_height - index][index2] = std::to_string(num)[index2];
		}
	}

	// print chart
	for (int index{0}; index < this->height; index++)
		std::cout << chart[index] << '\n';
}

// find next round number
void Chart::get_max_limit(int num)
{
	int len{get_len_of_int(num) - 1};
	this->max = (num / pow(10, len) + 1) * pow(10, len);
}

// get length of int
int Chart::get_len_of_int(int num)
{
	int len{0};
	for (int temp{num}; temp; len++, temp/=10);
	return len;
}

//* simple pow function I created
//! DO NOT USE IT IS NOT FULLY FUNCTIONAL
int pow(int num, int pow)
{
	int result{1};
	for (int index = 0; index < pow; index++)
		result *= num;
	return result;
}