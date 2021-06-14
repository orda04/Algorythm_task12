/*
**********  Second task on  Algorithm course                                         ****
**********  Filename >main.cpp                                               ****
**********  IDE > QT Creator 4.13.2||CodeBlocks 20.03 + GCC 10.2.0           ****
**********  Created by > "~ORDA~" , Anton Bondarenko                         ****
**********  Date 16.05.2021                                                  ****
*/

// DONE●  Написать функцию проверки, является ли число простым

#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;
int main()
{

        bool flag=true;
        int tsk4;
        printf("Please enter your number: ");
        scanf("%d",&tsk4);

    if (!(tsk4%2))
    {
        flag =false;
        printf("Your digit can be divided by: 2 \n do not need to do all other iterations...\n");
    }
    else
    {
       for (int i=3;i<=(sqrt(tsk4));i=i+2)
          {
         if (!(tsk4%i))
            {
             cout<<"\nwe are inside IF shit\n";
             printf("Your digit can be divided by: %d \n do not need to do all other iterations...\n",i);
             flag=false;
             break;
            }

          }
    if(flag)
     {
     printf("your digit can be divided only on 1 and digit itself\n");
     }


    }
return 1;
}
