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
    int FancyStrLen= len*(len+1)/2-1;
    char FancyStr[FancyStrLen];
    for (int i = 0; i < len && k < FancyStrLen; i++) 
    {
        for (int j = 0; j <= i && k < FancyStrLen; j++) 
        {
            FancyStr[k++] = Str[i];
        }
    }
    //printf("%s",FancyStr); 

}   