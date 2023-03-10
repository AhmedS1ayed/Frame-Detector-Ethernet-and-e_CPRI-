#pragma once


#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

/*
    Scanner class to read the input file and return the data as a string
*/
class Scanner 
{
    private: 
    string inputFile;
    

    public:
    Scanner()
    {
        inputFile = "";
    }

    vector<string> scanFile(string inputFile)
    {
        string line;
        ifstream file;
        vector<string> inputData;
        this->inputFile = inputFile;
        file.open(this->inputFile);
        if(!file.is_open())
        {
            cout<<"Error opening file"<<endl;
            exit(1);
        }
        while(getline(file,line))
        {
            inputData.push_back(line);
        }
        file.close();
        return inputData;
    }

};
