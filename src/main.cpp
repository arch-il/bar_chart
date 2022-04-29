/*
	Simple program for creating bar chart
*/

#include <iostream>

#include "chart.h"

int main()
{
	Chart chart(20);
	chart.add_value(39);
	chart.add_value(27);
	chart.add_value(12);
	chart.display_chart();
	return 0;
}