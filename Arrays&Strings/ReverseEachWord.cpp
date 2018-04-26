#include <iostream>
using namespace std;

void reverse(char *,char *);

void reverseWord(char *s)
{
    char *word = s;
    char *temp = s;
    while(*temp)
    {
        temp++;
        if(*temp == '\0')
        {
            reverse(word,temp-1);
        }
        else if(*temp == ' ')
        {
            reverse(word,temp-1);
            word = temp+1;
        }
    }
    reverse(s,temp-1);
}
void reverse(char *begin,char *end)
{
    char temp;
    while(begin < end)
    {
        temp = *begin;
        *begin++ = *end;
        *end-- = temp;
    }
}
int main()
{
    char s[] = "India is my country";
    reverseWord(s);
    cout<<s;
    getchar();
    return 0;
}