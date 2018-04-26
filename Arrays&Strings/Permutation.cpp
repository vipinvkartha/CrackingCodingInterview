#include <vector>
#include <iostream>
#include <iostream>
#include <string>

using namespace std;


bool permutation_1(const string & str1, const string &str2)
{
    if(str1.length() != str2.length())
        return false;
    int count[256] = {0};
    for(int i = 0;i < str1.length();i++)
    {
        int val = str1[i];
        count[val]++;
    }
    for(int i = 0;i < str2.length();i++)
    {
        int val = str2[i];
        count[val]--;
        if(count[val] < 0)
            return false;
    }
    return true;
}
int main()
{
    if(permutation_1("test","estt"))
        cout<<"Yes\n";
    else
        cout<<"No\n";
    getchar();
    return 0;

}