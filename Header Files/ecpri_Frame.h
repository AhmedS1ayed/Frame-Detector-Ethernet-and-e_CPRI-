#pragma once

#include"Basic_Frame.h"
class ecpri_Frame : public Basic_Frame
{
    ecpri_Frame(Basic_Frame frame)
    {

    };
    ecpri_Frame(string p , string sf , string s , string d , string t , string cr) : Basic_Frame(p ,sf ,s , d , t ,cr)
    {

    };
};