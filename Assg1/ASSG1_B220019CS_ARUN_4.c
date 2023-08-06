#include<stdio.h>
#include<string.h>
#define STRLENGTH 200

void main()
{

    char Str[STRLENGTH];
    scanf("%[^\n]", Str); 
    //printf("%s", Str);
    int i,j,len=0,k=0;
    while(Str[len]!='\0')
    {
             len++;
    }
    int FancyStrLenMax= len*(len+1)/2-1;
    char FancyStr[FancyStrLenMax];
    for (int i = 0; i < len && k < FancyStrLenMax; i++) 
    {
        for (int j = 0; j <= i && k < FancyStrLenMax; j++) 
        {
            FancyStr[k++] = Str[i];
        }
    }
    //printf("%s",FancyStr); 

    int freq[256]={0}, FancyStrLen=0;
    while(FancyStr[FancyStrLen]!='\0')
    {
             FancyStrLen++;
    }

    /*for ( i = 0; i < FancyStrLen; i++)
    {
        for ( j = 0; j < 128; j++)
        {   
            if((char)j==FancyStr[j])
            {
                freq[j]++;
            }
        }
                                Did not work
    }

    for ( i = 0; i < 128; i++)
    {
        printf("%c    %d\n",(char)i,freq[i]);
    }
    
     for (int i = 0; i < FancyStrLen; i++) 
     {
        char ch = FancyStr[i];
        freq[ch]++;
     }

    /* for ( i = 0; i < 128; i++)
     {
        printf("%c    %d\n",(char)i,freq[i]);
     }
     printf("%s",FancyStr);

     char FreqChar = FancyStr[0],tempChar;
     int FrequencyChar = freq[FancyStr[0]];
     for ( i = 0; i < FancyStrLen; i++)
     {
        tempChar = FancyStr[i];
        if(freq[tempChar]>FrequencyChar)
        FreqChar=tempChar;
        FrequencyChar=freq[tempChar];
     }
     printf("%c",FreqChar);
     */

    for (int i = 0; i < FancyStrLen; i++) {
        char tempChar = FancyStr[i];
        freq[tempChar]++;
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