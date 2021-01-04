#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned short twoN(unsigned short x) // help to find the 2 raise to x for the convertToDecimal process
{
    unsigned short returnV = 1;
    returnV = returnV << x;
    return returnV;
}

void getNthBit(unsigned x, int n) // returns the binary value at nth bit
{
    unsigned short returnV = 0;
    returnV = x >> n;
    unsigned short one = 1;
    returnV = returnV & one;
    printf("%u\n", returnV);
    //return returnV;
}

unsigned short  nthBitCheck(unsigned x, int n) // returns the binary value at nth bit
{
    unsigned short returnV = 0;
    returnV = x >> n;
    unsigned short one = 1;
    returnV = returnV & one;
    return returnV;
}

unsigned short comp(unsigned short x, int n) // setting nth term to it's complement or flip
{
    unsigned short nthPower = 0;
    nthPower = twoN(n);
    unsigned short returnV = 0;
    returnV = x ^ nthPower;
    printf("%u\n", returnV);
    return returnV;
}

unsigned short set(unsigned short x, int n, int v)
{
    unsigned short checkSame = nthBitCheck(x, n);
    //printf("Start: %d %d\n", checkSame, v);
    if(!(checkSame ^  v))
    {
        printf("%u\n", x);
        return x;
    }else{
        //printf("Hello");
        unsigned short temp = 0;
        temp = twoN(n);
        unsigned short returnV = 0;
        returnV = x ^ temp;
        printf("%u\n", returnV);
        return returnV;
    }
}

int main(int argc, char* argv[])
{
    FILE* textR = fopen(argv[1], "r"); // reading the file input
    //int arr[16]; //making an array to store binary value of an input in the heap
    if(textR == NULL){
      return 0;
    }
    int x = 0;
    fscanf(textR, "%d\n", &x);
    // reading the number in the input file and storing it in the num variable
    // converting the num into binary
    //printf("\n");
    unsigned short num = 0;
    num = (unsigned short)x;
// start of the get method
/*
    char inputG[4];
    inputG[3] = '\0';
    int firstV = 0;
    int secondV = 0;
    fscanf(textR, "%s\t%d\t%d\n", inputG, &firstV, &secondV); // get    0   0
*/

// end of the get method
// start of the comp method

    char inputC[5];
    inputC[4] = '\0';
    int firstV = 0;
    int secondV = 0;
    while((fscanf(textR, "%s\t%d\t%d\n", inputC, &firstV, &secondV)) != EOF) // comp   0   0
    {
        if(strcmp(inputC, "get") == 0) // comparison of the strings
        {
            getNthBit(num, firstV);
        }
        if(strcmp(inputC, "comp") == 0)
        {
            //printf("%u\n", num);
            num = comp(num, firstV);
        }
        if(strcmp(inputC, "set") == 0)
        {
            //printf("Num: %u\n", num);
            num = set(num, firstV, secondV);
        }

    }

// end of the comp method
// start of the set method


// end of the set method

    //free(arr);
    /*
    FILE* textR = fopen("temp1.txt", "r");
    unsigned short num;
    fscanf(textR, "%u\n", &num);
    printf("Num: %u\n", num);
    char inputG[100];
    for(int i = 0; i < 100; i++)
    {
        inputG[i] = '\0';
    }
    int firstG = 0;
    int secondG = 0;
    fscanf(textR, "%s\t", inputG);
    fscanf(textR, "%d\t", &firstG);
    printf("%s %d\n", inputG, firstG);
    //fscanf(textR, "%d\n", &secondG);
    printf("%s %d\n", inputG, firstG);
    */
    fclose(textR);
    return 0;
}
