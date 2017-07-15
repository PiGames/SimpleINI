/*
	The MIT License

	Copyright (c) 2017 PiGames ( https://github.com/PiGames )

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in
	all copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
	THE SOFTWARE.
*/

#include <iostream>

// Uncomment to use filesystem header for saving.
//#define USE_CPP_17
#include "INIFile.hpp"

int main()
{
	pi::INIFile iniFile;

	if ( !iniFile.Open( "SampleFile.ini" ) ) {
		std::cout << "Cannot open file\n";
		std::cin.get();
		return -1;
	}

	iniFile.Parse();

	std::cout << "Player name: " << iniFile.GetValue( "PLAYER_DATA", "name" ) << "\n";
	std::cout << "Player score: " << iniFile.GetValue( "PLAYER_DATA", "score" ) << "\n";
	// Enable bools printing ('false' instead '0' and 'true' instead '1')
	std::cout << std::boolalpha << "Does player visit tavern?: " << iniFile.GetValue( "VISITED_PLACES", "tavern" ) << "\n";
	std::cout << "Player X position: " << iniFile.GetValue( "PLAYER_DATA", "positionX" ) << "\n";
	std::cout << "Player Y position: " << iniFile.GetValue( "PLAYER_DATA", "positionY" ) << "\n";

	std::cin.get();
	return 0;
}