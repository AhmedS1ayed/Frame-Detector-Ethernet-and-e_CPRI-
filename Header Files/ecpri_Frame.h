#pragma once

#include"Basic_Frame.h"
class ecpri_Frame : public Basic_Frame
{
    
    public:
    //Default Constructor
    ecpri_Frame()
    {

    };
    //Full Frame Constructor
    ecpri_Frame(string s , string d , string t , string cr) : Basic_Frame(s , d , t ,cr)
    {

    };

};