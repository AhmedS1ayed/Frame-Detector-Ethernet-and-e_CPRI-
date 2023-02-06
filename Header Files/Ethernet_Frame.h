#pragma once

#include"Basic_Frame.h"
class Ethernet_Frame : public Basic_Frame
{
    string data;
    
    public :
    Ethernet_Frame()
    {

    };
    Ethernet_Frame(string s , string d , string t , string cr) : Basic_Frame(s , d , t ,cr)
    {
        
    };

};