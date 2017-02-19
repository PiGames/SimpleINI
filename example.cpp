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

#include "INIparser.hpp"

int main()
{
	pi::INIFile iniFile;
	// In almost all methods pointer to error is additional argument (you don't need to use it)
	// ini_error_t is struct with std::string that contains information about error
	pi::ini_error_t error;

	// Checking if method failed, if yes then print error message.
	if ( !iniFile.LoadFromFile( "SampleFile.ini", &error ) )
		std::cout << "\n LOADING ERROR: " << error.what << "\n";

	// Same as above
	if ( !iniFile.Parse( &error ) )
		std::cout << "\n PARSE ERROR: " << error.what << "\n";



	std::cout << "Player name (string): " << iniFile.GetString( "PLAYER_DATA", "name" ) << "\n";
	std::cout << "Player score (int): " << iniFile.GetInt( "PLAYER_DATA", "score" ) << "\n";
	// Enable bools printing ('false' instead '0' and 'true' instead '1')
	std::cout << std::boolalpha << "Does player visit tavern? (bool): " << iniFile.GetBool( "VISITED_PLACES", "tavern" ) << "\n";
	std::cout << "Player X position (double): " << iniFile.GetDouble( "PLAYER_DATA", "positionX" ) << "\n";
	std::cout << "Player Y position (double): " << iniFile.GetDouble( "PLAYER_DATA", "positionY" ) << "\n";

	std::cin.get();
	return 0;
}