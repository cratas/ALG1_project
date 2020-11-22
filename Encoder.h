#pragma once
#include <iostream>

using namespace std;

class Encoder
{
private:
	string filename;
	string inputText;

public:
	Encoder(string filename);
	void loadText();
	string getInputText();
	
};
