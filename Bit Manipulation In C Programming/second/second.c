#include <stdio.h>
#include <stdlib.h>

unsigned short nthBit(unsigned x, int n) // returns the binary value at nth bit
{
    unsigned short returnV = 0; // 1 0 1
    returnV = x >> n;
    unsigned short one = 1;
    returnV = returnV & one;
    return returnV;
}

int main(int argc, char* argv[])
{
    int num = 0;
    num = atoi(argv[1]);
    unsigned short x = (unsigned short) num;
    int count = 0;
    int numOfPairs = 0;
    int check = 0;
    for(int i = 0; i < 16; i++)
    {
      if(!(nthBit(x, i) ^ 1)) // if true then increment check by 1
        {
	    count++;
            check++;
        }
        if(nthBit(x, i) ^ 1) // if 0 (above statement false) then set check to 0
        {
            check = 0;
        }
        if(check == 2)
        {
            numOfPairs++;  // if check is 2 then there is two consecutive 1 (pair) so increment numOfPairs by 1
            check = 0;  // set check to zero to look for other pairs in the same way
        }
    }
    if(count % 2 == 0)
    {
        printf("Even-Parity\t%d\n", numOfPairs);
    }else{
        printf("Odd-Parity\t%d\n", numOfPairs);
    }
    return 0;
}
