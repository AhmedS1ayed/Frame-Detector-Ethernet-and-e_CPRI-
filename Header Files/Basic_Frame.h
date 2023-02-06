#pragma once

#include<iostream>
#include<string>
using namespace std;

class Basic_Frame
{

    string Frame;
    string preamble;
    string sfd;
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
        //TODO: how to handle the input strings
        Frame = input;
        process_Frame();
    }
    //pre-determined frame constructor
    Basic_Frame(string p ,string sf ,string s , string d , string t ,string cr) : preamble(p) , sfd(sf) , source(s) , dest(d) , type(t) , crc(cr)
    {

    }

//----------------------------------------------------
    // Setters and Getters :
    void set_preamble(string input)
    {
        preamble=input;
    }
    string get_preamble()
    {
        return preamble;
    }
    void set_sfd(string input)
    {
        sfd=input;
    }
    string get_sfd()
    {
        return sfd;
    }
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
    void set_crc(string input)
    {
        crc=input;
    }
    string get_crc()
    {
        return crc;
    }

//----------------------------------------------------
    //Processing The Frame :
    void process_Frame()
    {
        preamble = process_preamble();
        sfd = process_sfd();
        source = process_source();
        dest = process_dest();
        type = process_type();
        crc = process_crc();
    }
    string process_preamble()
    {

        return "00";
    }
    string process_sfd()
    {
        return "00";
    }
    string process_source()
    {
        
        return "00";
    }
    string process_dest()
    {
        return "00";
    }
    string process_type()
    {
        return "00";
    }
    string process_crc()
    {
        return "00";
    }

//----------------------------------------------------
    //Printers :
    // FIXME: May in another class 
    void Print()
    {
        Print_preamble();
        Print_sfd();
        Print_src();
        Print_dst();
        Print_type();
        Print_crc();
    }
    void Print_preamble()
    {
        cout<<preamble + "\n";
    }
    void Print_sfd()
    {
        cout<<sfd + "\n";
    }
    void Print_src()
    {
        cout<<source + "\n";
    }
    void Print_dst()
    {
        cout<<dest + "\n";
    }
    void Print_type()
    {
        cout<<type + "\n";
    }
    void Print_crc()
    {
        cout<<crc + "\n";
    }
};