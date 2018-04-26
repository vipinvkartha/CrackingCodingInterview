#include <iostream>
using namespace std;


void urlify(char *str , int len)
{
    int num_spaces = 0,index;
    for(int i = 0;i < len; i ++)
    {
        if(str[i] == ' ')
        {
            num_spaces++;
        }
    }
    int new_len = len + num_spaces*2;
    index = new_len - 1;
    //str[new_len] = '\0';
    for(int i = len - 1;i>=0;i--)
    {
        if(str[i]!=' ')
        {
            str[index--] = str[i];
        }
        else
        {
            str[index--] = '0';
            str[index--] = '2';
            str[index--] = '%';
        }
    }
}
int main()
{
    char str1[] = "i love my India";
    cout<<str1<<endl;
    urlify(str1,strlen(str1));
    cout<<str1<<endl;
    getchar();
    return 0;
}