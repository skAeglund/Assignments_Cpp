#include <iostream>
#pragma once

namespace input
{
	int number()
	{
		int number = 0;
		do
		{
			std::cout << "Enter a number: ";
			std::cin >> number;
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		} while (std::cin.fail());

		return number;
	}
}