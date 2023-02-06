#include"./Header Files/Basic_Frame.h"
#include"./Header Files/ecpri_Frame.h"
#include"./Header Files/Ethernet_Frame.h"
#include "./Header Files/Analyser.h"

int main()
{
    Analyser analyser;
    analyser.analyse("input_packets");
    
    // Basic_Frame a("0","0","0","0");
    // a.Print();
    return 0;
}