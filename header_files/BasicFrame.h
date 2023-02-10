#pragma once
#include<iostream>
#include<string>
#include "../configuration_files/basic_frame_config.h"
using namespace std;

/*
    BasicFrame class to process the basic frame and extract the source , destination , type and crc
*/
class BasicFrame
{

    private:
    string frame;
    string source;
    string dest;
    string type;
    string crc;

    public :
    //Default Constructor
    BasicFrame(){};
    //Full Frame Constructor
    BasicFrame(string input) : frame(input)
    {
    }
    //pre-determined frame constructor used for optimization in Ecpri_Frame
    BasicFrame(string frame ,string source , string dest , string type ,string crc) 
                : frame(frame),source(source) , dest(dest) , type(type) , crc(crc)
    {
    }

//---------------------------------------
    // Setters and Getters :
    void setFrame(string input)
    {
        frame=input;
    }
    string getFrame()
    {
        return frame;
    }
    void setSource(string input)
    {
        source=input;
    }
    string getSource()
    {
        return source;
    }
    void setDestination(string input)
    {
        dest=input;
    }
    string getDestination()
    {
        return dest;
    }
    void setType(string input)
    {
        type=input;
    }
    string getType()
    {
        return type;
    }
    virtual void setCRC(string input)
    {
        crc=input;
    }
    string getCRC()
    {
        return crc;
    }

//----------------------------------------------------
    //Processing The Frame :
    virtual void processFrame()
    {
        source = procesSource();
        dest = processDest();
        type = processType();
        crc = processCRC();
    }
    string procesSource()
    {

        string temp;
        temp = frame.substr(SOURCE_ADDRESS_INDEX,ETHERNET_SOURCE_ADDRESS_SIZE);   
        return temp;
    }
    string processDest()
    {
        string temp;
        temp = frame.substr(DESTINATION_ADDRESS_INDEX,ETHERNET_DESTINATION_ADDRESS_SIZE);
        return temp;
    }
    string processType()
    {
        string temp;
        temp = frame.substr(ETHERNET_TYPE_INDEX,ETHERNET_TYPE_SIZE);   
        return temp;
    }
    string processCRC()
    {
        string temp;
        temp = frame.substr(frame.size()-ETHERNET_CRC_SiZE,ETHERNET_CRC_SiZE);   
        return temp;
    }

    // Determine Frame_type
    string getFrameType()
    {
        if(type=="AEFE")
            return "e-CPRI";
        else
            return "Ethernet";
    }


//----------------------------------------------------
    //Printers :
    virtual string print()
    {
        string temp="";
        temp += printCrc();
        temp += printDest();
        temp += printSource();
        temp += printType();
        return temp;
        }
    string printSource()
    {
        return "Source Address: " + source + "\n";
    }
    string printDest()
    {
        return "Destination Address: " + dest + "\n";
    }
    string printType()
    {
        return "Type: " + type + "\n";
    }
    string printCrc()
    {
        return "CRC: " + crc + "\n";
    }
};