#include "Encoder.h"
#include <fstream>
#include <sstream>

Encoder::Encoder(string filename)
{
	this->filename = filename;
    loadText();
}

void Encoder::loadText()
{
    ifstream inputFile(filename);
    stringstream sstream;
    sstream << inputFile.rdbuf();
    inputText = sstream.str();
}

string Encoder::getInputText()
{
    return inputText;
}


