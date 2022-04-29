/*
	Simple program for creating bar chart
*/

#include <iostream>

#include "chart.h"

int main()
{
	std::cout << "Welcome to simple bar chart by arch-il\n\n";
	
	bool run{true};
	while (run)
	{
		std::cout << "bar height: ";
		int start_height{};
		std::cin >> start_height;
		
		Chart chart(start_height);

		std::cout << "number of inputs: ";
		int num{};
		std::cin >> num;
		for (int index{1}; index <= num; index++)
		{
			std::cout << "input number(" << index << '/' << num << "): ";
			int temp{};
			std::cin >> temp;
			chart.add_value(temp);
		}

		std::cout << "sorted(y/N): ";
		char sorted{};
		std::cin >> sorted;

		chart.display_chart(sorted == 'y');

		std::cout << "repeat?(y/N): ";
		char repeat{};
		std::cin >> repeat;
		run = (repeat == 'y');
	}
	return 0;
}