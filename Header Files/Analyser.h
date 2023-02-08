#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "Scanner.h"
#include "BasicFrame.h"
#include "Emitter.h"
using namespace std;


class Analyser
{
    private:
    vector<string> inputData;
    string outputData;
    string packet;
    Scanner scanner;
    Emitter emitter;

    //TODO: add destructor !!
    public:
    Analyser()
    {
        outputData = "";
    }

    void analyse(string inputFile){
        //get the input data
        this->inputData = scanner.scanFile(inputFile);
        //loop through the input data and process each packet
        for (size_t i = 0; i < inputData.size(); i++)
        {
            packet = inputData[i];
            BasicFrame* frame = new BasicFrame(packet);
            //call thq process_Frame function to process the packet
            frame->processFrame();
            //check the frame type if it is e-CPRI or Ethernet and do ecpri processing
            frame = checkFrameType(frame);
            
            if(frame == nullptr) 
                return;
            //add the output to the outputData string
            outputData += "Packet #" + to_string(i) + ": \n" + packet + "\n";
            outputData += frame->print() + "\n";
            delete(frame);
            outputData += "*******************************************************************************************************************************************************\n";
        }
            cout << outputData << endl;
            emitter.emit(outputData);
    }

    BasicFrame* checkFrameType(BasicFrame* input)
    {
        string temp = input->getFrameType();
        if(temp == "e-CPRI")
        {
            EcpriFrame* newframe = new EcpriFrame(input->getFrame(),input->getSource(),input->getDestination(),input->getType(),input->getCRC());
            delete(input);
            newframe->processFrameFull();
            return newframe;
        }
        else if(temp == "Ethernet")
        {
            return input;
        }
        else
        {
            return nullptr;
        }
    }
    ~Analyser()
    {

    }


};