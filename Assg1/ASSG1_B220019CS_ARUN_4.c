#include<stdio.h>
#define STRLENGTH 200

void main()
{

    char Str[STRLENGTH];
    scanf("%[^\n]", Str); 
    int i,j,len=0,k=0;
    while(Str[len]!='\0')
    {
             len++;
    }
    int FancyStrLenMax= len*(len+1)/2-1;
    char FancyStr[FancyStrLenMax];
    /*for (int i = 0; i < len && k < FancyStrLenMax; i++) 
    {
        for (int j = 0; j <= i && k < FancyStrLenMax; j++) 
        {
            FancyStr[k++] = Str[i];
        }
    } */
    int n=0;
    while (Str[n] != '\0') {
        for (int i = 0; i <= n; i++) {
            FancyStr[k++] = Str[n];
        }
        n++;
    }
    FancyStr[k] = '\0';
    

    int freq[256]={0}, FancyStrLen=0;
    while(FancyStr[FancyStrLen]!='\0')
    {
             FancyStrLen++;
    }

    for (int i = 0; i < FancyStrLen; i++) {
        char tempChar = FancyStr[i];
        freq[(int)tempChar]++;
    }
    
    char FreqChar = FancyStr[0];
    int MaxFreq = freq[FancyStr[0]];

    for (int i = 1; i < FancyStrLen; i++) {
        char tempChar = FancyStr[i];
        if (freq[tempChar] > MaxFreq) {
            FreqChar = tempChar;
            MaxFreq = freq[tempChar];
        }
    }
    printf("%c",FreqChar);

}   