#include"./Header Files/Basic_Frame.h"
#include"./Header Files/ecpri_Frame.h"
#include"./Header Files/Ethernet_Frame.h"
#include "./Header Files/Scanner.h"

int main()
{
    Scanner scanner("input_packets");
    string inputData = scanner.scanFile();
    cout << inputData << endl;
    Basic_Frame a("0","0","0","0","0","0");
    a.Print();
    return 0;
}