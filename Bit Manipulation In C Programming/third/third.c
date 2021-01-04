#include <stdio.h>
#include <stdlib.h>

unsigned short nthBitCheck(unsigned x, int n) // returns the binary value at nth bit
{
    unsigned short returnV = 0;
    returnV = x >> n;
    unsigned short one = 1;
    returnV = returnV & one;
    return returnV;
}

int main(int argc, char* argv[])
{
    int input = 0;
    int check = 0;
    input = atoi(argv[1]);
    unsigned short num = (unsigned short) input;
    for(int i = 0; i < 8; i++)
    {
        if((nthBitCheck(num, i)) ^ (nthBitCheck(num, 15 - i)))
        {
	    check = 1;
	    break;
        }
    }
    if(check == 1){
      printf("Not-Palindrome\n");
    }else{
      printf("Is-Palindrome\n");
    }
    return 0;
}
