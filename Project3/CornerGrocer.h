/*
 * CornerGrocer.h
 *
 *  Created on: Aug 11, 2023
 *      Author: connor
 */
#include <map>
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#pragma once
#ifndef CORNERGROCER_H_
#define CORNERGROCER_H_
using namespace std;

class CornerGrocer
{
	//these are all the functions and variables
	public:
		CornerGrocer();
		int makeMenu();
		void makeFile();
		void takeFile();
		void play();
		void printGroceryMap();
		void printGrocery();
		void searchItem();
		CornerGrocer(string inputFile, string outputFile);
		void getMenu(int chosen);
		void setInputFile(string mainFile);
		void setOutputFile(string mainFile);
		void printHisto();

	private:
		string inputFile;
		string outputFile;
		map<string, int> cornerGrocerMap;
};





#endif /* CORNERGROCER_H_ */
