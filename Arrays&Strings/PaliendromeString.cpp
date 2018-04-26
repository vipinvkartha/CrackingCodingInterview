#include <iostream>
using namespace std;

int getIndex(char a)
{
    int index = -1;
    if(('a' <= a) && (a <='z'))
    {
        index =  a - 'a';
    }
    else if(('A' <=  a) && (a <= 'Z'))
    {
        index = a - 'A';
    }
    return index;
}
void count_freq(const string &str,int *freq)
{
    int val;
    for(const char& c : str)
    {
        val = getIndex(c);
        if(-1 != val)
        {
            freq[val]++;
        }
    }
}
bool check_paliendrome(const string & str)
{
    int freq[26]  = {0};
    count_freq(str,freq);
    bool odd = false;
    for(int i = 0;i< 26;i ++)
    {
        if((freq[i] %2) && odd)
            return false;
        else if((freq[i] %2) && !odd)
            odd = true;
    }
    return true;
}

int main()
{
    string test = " he llea";
    if(check_paliendrome(test))
        cout<<"YES\n";
    else
        cout<<"NO\n";
    getchar();
    return 0;
}