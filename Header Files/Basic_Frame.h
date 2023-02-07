#pragma once

#include<iostream>
#include<string>
#include "../Configration Files/Basic_Frame_config.h"
using namespace std;

class Basic_Frame
{

    string Frame;
    string source;
    string dest;
    string type;
    string crc;

    public :
    //Default Constructor
    Basic_Frame(){};
    //Full Frame Constructor
    Basic_Frame(string input)
    {
        this->Frame = input;
        process_Frame();
    }
    //pre-determined frame constructor
    Basic_Frame(string s , string d , string t ,string cr) : source(s) , dest(d) , type(t) , crc(cr)
    {

    }

//----------------------------------------------------
    // Setters and Getters :
    void set_source(string input)
    {
        source=input;
    }
    string get_source()
    {
        return source;
    }
    void set_destination(string input)
    {
        dest=input;
    }
    string get_destination()
    {
        return dest;
    }
    void set_type(string input)
    {
        type=input;
    }
    string get_type()
    {
        return type;
    }
    virtual void set_crc(string input)
    {
        crc=input;
    }
    string get_crc()
    {
        return crc;
    }

//----------------------------------------------------
    //Processing The Frame :
    virtual void process_Frame()
    {
        source = process_source();
        dest = process_dest();
        type = process_type();
        crc = process_crc();
    }
    string process_source()
    {

        string temp;
        temp = Frame.substr(SOURCE_ADDRESS_INDEX,ETHERNET_SOURCE_ADDRESS_SIZE);   
        return temp;
    }
    string process_dest()
    {
        string temp;
        temp = Frame.substr(DESTINATION_ADDRESS_INDEX,ETHERNET_DESTINATION_ADDRESS_SIZE);
        return temp;
    }
    string process_type()
    {
        string temp;
        temp = Frame.substr(ETHERNET_TYPE_INDEX,ETHERNET_TYPE_SIZE);   
        return temp;
    }
    string process_crc()
    {
        string temp;
        temp = Frame.substr(Frame.size()-ETHERNET_CRC_SiZE,ETHERNET_CRC_SiZE);   
        return temp;
    }

//----------------------------------------------------
    //Printers 
    virtual void Print()
    {
        Print_crc();
        Print_dst();
        Print_src();
        Print_type();
        cout << "*******************************************************************************************************************************************************" << endl;
    }
    void Print_src()
    {
        cout<<"Source Address: "<< source + "\n";
    }
    void Print_dst()
    {
        cout<<"Destination Address: "<< dest + "\n";
    }
    void Print_type()
    {
        cout<<"Type: "<< type + "\n";
    }
    void Print_crc()
    {
        cout<<"CRC: "<<crc + "\n";
    }
// Frame_type returns a pointer frame with its type
    Basic_Frame* Frame_type_object()
    {
        // if(Frame_type() == "e-CPRI")
        // {
        //     Basic_Frame* output = new ecpri_Frame(source,dest,type,crc);
        //     return output;
        // }
        // else if(Frame_type() == "Ethernet")
        // {
        //     Basic_Frame* output = new Ethernet_Frame(source,dest,type,crc);
        //     return output;
        // }
    }
    string Frame_type()
    {
        if(type=="AEFE")
            return "e-CPRI";
        else
            return "Ethernet";
    }

};