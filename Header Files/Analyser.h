#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "Scanner.h"
#include "Basic_Frame.h"
using namespace std;


class Analyser
{
    private:
    vector<string> inputData;
    string packet;

    public:
    Analyser()
    {
    }

    void analyse(string inputFile){
        //get the input data
        Scanner scanner(inputFile);
        this->inputData = scanner.scanFile();
        //loop through the input data
        for (size_t i = 0; i < inputData.size(); i++)
        {
            packet = inputData[i];
            Basic_Frame frame(packet);
            frame.Print();
        }

    }


};