#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "Scanner.h"
#include "BasicFrame.h"
using namespace std;


class Analyser
{
    private:
    vector<string> inputData;
    string packet;
    Scanner scanner;

    public:
    Analyser()
    {
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
            (*frame).processFrame();
            //check the frame type if it is e-CPRI or Ethernet and do ecpri processing
            frame = checkFrameType(frame);
            
            if(frame == nullptr) 
                return;

            //print the frame
            cout <<"Packet #"<<i<<": " << endl;
            cout << packet << endl;
            frame->Print();
            delete(frame);
            cout << "*******************************************************************************************************************************************************" << endl;
        }
    }

    BasicFrame* checkFrameType(BasicFrame* input)
    {
        string temp = input->getFrameType();
        if(temp == "e-CPRI")
        {
            EcpriFrame* newframe = new EcpriFrame(input->getFrame(),input->getSource(),input->getDestination(),input->getType(),input->getCRC());
            (*newframe).processFrameFull();
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


};