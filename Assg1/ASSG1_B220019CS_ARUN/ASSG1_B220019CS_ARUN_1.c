#include<stdio.h>

#define MAX_LENGTH 100

void main()
{
    char ch, sentence[MAX_LENGTH];
    fgets(sentence, sizeof(sentence), stdin);
    //printf("%s",sentence);                          
    scanf("%c",&ch);
    if(ch >= 'A' && ch<= 'Z')
    {
        ch = ch +('a'-'A');
    }
    //printf("%c",ch);
    int i, len=0,count=0;
    while (sentence[len] != '\0') 
    {
        if(ch==sentence[len]||(ch-('a'-'A'))==sentence[len])
        {
            count++;
        }
        len++;
    }
    printf("%d",count);
    
    
}