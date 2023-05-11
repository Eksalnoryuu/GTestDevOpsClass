#include "calculator.h"
#include <iostream>
#include <unistd.h>
int main ()
{  
    while(true)
    {

        std::cout << Add(4,5) << std::endl;
        sleep(1);
    }
    return 0;

}