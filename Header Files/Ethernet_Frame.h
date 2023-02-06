#pragma once

#include"Basic_Frame.h"
class Ethernet_Frame : public Basic_Frame
{
    string data;
    
    public :
    Ethernet_Frame(Basic_Frame frame)
    {

    };
    Ethernet_Frame(string p , string sf , string s , string d , string t , string cr) : Basic_Frame(p ,sf ,s , d , t ,cr)
    {

    };

};