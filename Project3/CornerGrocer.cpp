/*
 * CornerGrocer.cpp
 *
 *  Created on: Aug 11, 2023
 *      Author: connor
 */
#include "CornerGrocer.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <map>
using namespace std;
//This is the constuctor
CornerGrocer::CornerGrocer()
{
	setInputFile("CS210_Project_Three_Input_File.txt");
	setOutputFile("frequency.dat");
	takeFile();
	makeFile();
}

CornerGrocer::CornerGrocer(string inputFile, string outputFile)
{
	setInputFile(string inputFile);
	setOutputFile(string outputFile);
	takeFile();
	makeFile();
}
//opens the file, checks if the file is open, then goes through the grocery map and saves the data
void CornerGrocer::makeFile()
{
	ofstream outFS;
	outFS.open(outputFile);
	if (!outFS.is_open())
	{
		cout << "Couldn't open file" << endl;
	}
	for (auto i = cornerGrocerMap.begin(); i != cornerGrocerMap.end(); i++)
	{
		outFS << i->first << " " << i->second << endl;
	}
	outFS.close();
}
// sets output file
void CornerGrocer::setOutputFile(string mainFile)
{
	outputFile = mainFile;
}
// sets input file
void CornerGrocer::setInputFile(string mainFile)
{
	inputFile = mainFile;
}
//opens file and checks if file is opening correctly
void CornerGrocer::takeFile()
{
	ifstream inFS;
	inFS.open(inputFile);
	if(!inFS.is_open())
	{
		cout << "Couldn't open file" << endl;
	}
	string temporary;
	map<string, int> temporaryMapping;
	while (!inFS.fail())
	{
		inFS >> temporary;
		if (temporaryMapping.count(temporary))
		{
			temporaryMapping[temporary] += 1;
		}
		else
		{
			temporaryMapping.insert(std::pair<std::string, int>(temporary, 1));
		}
	}
	cornerGrocerMap = temporaryMapping;
	inFS.close();
}
// This asks the user for an item, then it sees if its a valid item, then if there is an item in the list it prints it out and tells the user how much of the item there is
void CornerGrocer::searchItem()
{
	string data;
	bool input;
	while (!input)
	{
		cout << "Please enter an item you want to find";
		cin >> data;
		try
		{
			for(char a : data)
			{
				if(!isalpha(a))
				{
					throw invalid_argument("input isn't valid");
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			input = true;
			if (cornerGrocerMap.find(data) != cornerGrocerMap.end())
			{
				cout << "The amount of " << data << " is " << cornerGrocerMap[data] << endl;
			}
			else
			{
				cout << "There isn't any " << data << endl;
			}
		}
		catch (const invalid_arguent& e)
		{
			cout << "Error " << e.what() << std::endl;
		}
	}
}
// this gives all the data in the grocery map
void CornerGrocer::printGroceryMap()
{
	for (auto t = cornerGrocerMap.begin(); t != cornerGrocerMap.end(); t++)
	{
		cout << t->first << " " << t->second << endl;
	}
}
//this prints out options for the user
void CornerGrocer::printGrocery()
{
	cout << "\33[1m\33[4mMain Menu:\33[0m" << endl;
	cout << "\33[33m1. Search for item.\33" << endl;
	cout << "\33[32m2. Show items and amounts for items.\33" << endl;
	cout << "\33[31m3. Show all grocery items in histogram\033" << endl;
	cout << "\33[34m4. exit the program\33" << endl;
	cout << "[0m";
	int choose = makeMenu();
	getMenu(choose);
}
//this runs the program
void CornerGrocer::play()
{
	while(true)
	{
		printGrocery();
	}
}
//This prints the corner grocer
void CornerGrocer::printHisto()
{
	for (auto p = cornerGrocerMap.begin(); p != cornerGrocerMap.end(); p++)
	{
		cout << p->first << " ";
		int temporary = p->second;
		for (int l = 0; l < temporary; l++)
		{
			cout << "*";
		}
		cout << endl;
	}
}

//This gets the options
void CornerGrocer::getMenu(int chosen)
{
	system("cls");
	if (chosen == 1)
	{
		searchItem();
	}
	else if (chosen == 2)
	{
		printGroceryMap();
	}
	else if (chosen == 3)
	{
		printHisto();
	}
	else if (chosen == 4)
	{
		exit(0);
	}

	system("pause");
	system("cls");
}
//This makes sure that the option that the user gave is valid. If it is valid then the program keeps running and sends back the option
int CornerGrocer::makeMenu()
{
	int option;
	while (true)
	{
		cout << "Choose a option for the menu:";
		cin >> option;
		try
		{
			if (option <1 || option >4)
			{
				throw std::out_of_range("invalid input");
				option = 0;
			}
			else
			{
				break;
			}
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what() << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	return option;
}



