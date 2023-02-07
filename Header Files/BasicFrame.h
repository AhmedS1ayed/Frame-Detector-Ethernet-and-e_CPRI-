#pragma once
#include<iostream>
#include<string>
#include "../Configration Files/Basic_Frame_config.h"
using namespace std;

class BasicFrame
{

    private:
    string Frame;
    string source;
    string dest;
    string type;
    string crc;

    public :
    //Default Constructor
    BasicFrame(){};
    //Full Frame Constructor
    BasicFrame(string input) : Frame(input)
    {
    }
    //pre-determined frame constructor used for optimization in Ecpri_Frame
    BasicFrame(string fr ,string s , string d , string t ,string cr) : Frame(fr),source(s) , dest(d) , type(t) , crc(cr)
    {
    }

//---------------------------------------
    // Setters and Getters :
    void setFrame(string input)
    {
        Frame=input;
    }
    string getFrame()
    {
        return Frame;
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
        temp = Frame.substr(SOURCE_ADDRESS_INDEX,ETHERNET_SOURCE_ADDRESS_SIZE);   
        return temp;
    }
    string processDest()
    {
        string temp;
        temp = Frame.substr(DESTINATION_ADDRESS_INDEX,ETHERNET_DESTINATION_ADDRESS_SIZE);
        return temp;
    }
    string processType()
    {
        string temp;
        temp = Frame.substr(ETHERNET_TYPE_INDEX,ETHERNET_TYPE_SIZE);   
        return temp;
    }
    string processCRC()
    {
        string temp;
        temp = Frame.substr(Frame.size()-ETHERNET_CRC_SiZE,ETHERNET_CRC_SiZE);   
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
    //Printers 
    virtual string Print()
    {
        string temp="";
        temp += Print_crc();
        temp += Print_dst();
        temp += Print_src();
        temp += Print_type();
        return temp;
        }
    string Print_src()
    {
        return "Source Address: " + source + "\n";
    }
    string Print_dst()
    {
        return "Destination Address: " + dest + "\n";
    }
    string Print_type()
    {
        return "Type: " + type + "\n";
    }
    string Print_crc()
    {
        return "CRC: " + crc + "\n";
    }


};