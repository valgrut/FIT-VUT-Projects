/*
 * Jmeno:     Jiri Peska
 * Login:     xpeska05
 * Fakulta:   FIT VUT Brno
 * Priklad:   1
 * Datum:     24.4.2019
 * Prekladac: gcc version 8.3.0 (Debian 8.3.0-2)
 */

#include <stdexcept>
#include <iostream>
#include <string>
#include <fstream>
#include <deque>

#define PRINT_N 10

using namespace std;

unsigned int get_option_n(int argc, char *argv[]);
istream *get_input(fstream *file, int argc, char *argv[]);

int main(int argc, char *argv[]) 
{	
	ios::sync_with_stdio(false);
	unsigned int lines = get_option_n(argc, argv);
	if(lines == 0)
	{
		cerr << "Invalidni argument pro -n, jsou dovolena pouze cisla > 0." << endl;
		return 1;
	}
	string str;
	deque<string> buffer;

	fstream soubor;
	istream *input = get_input(&soubor, argc, argv);
	if(input == NULL)
	{
		cerr << "Nepovedlo se nacist vstupni zdroj." << endl;
		return 1;
	}

	while(getline(*input, str)) 
	{	
		buffer.push_back(str);
		if(buffer.size() > lines)
		{
			buffer.pop_front();
		}
	}
	
	for(string line : buffer) 
	{
		cout << line << endl;
	}

	return 0;
}

unsigned int get_option_n(int argc, char *argv[])
{
	if(argc <= 1 || argc > 4)
	{
		return PRINT_N;
	}

	string option(argv[1]);
	if(option == "-n")
	{
		string num_of_lines(argv[2]);
		int lines = 0;
		try
		{
			lines = stoi(num_of_lines);
		} 
		catch(const std::invalid_argument& ia)
		{
			//cerr << "Invalid argument provided for -n option." << endl;
			return 0;
		}

		return lines;
	}

	return PRINT_N;
}

istream *get_input(fstream *soubor, int argc, char *argv[]) 
{
	if(argc == 1) 
	{
		return &cin;
	}
	
	//soubor
	if(argc == 2) 
	{
		if(argv[1][0] != '-') 
		{
			(*soubor).open(argv[1], ios::in);
			return soubor;	
		}
		
		string option(argv[1]);
		if(option == "-n") 
		{
			return NULL;
		}
			
	}

	//-n x
	if(argc == 3) 
	{
		string option(argv[1]);
		if(option == "-n") 
		{
			return &cin;
		}	
	}

	//-n x soubor
	if(argc == 4) 
	{
		string option(argv[1]);
		if(option == "-n") 
		{
			(*soubor).open(argv[3], ios::in);
			return soubor;
		}
	}

	return &cin;
}


