#include <iostream>
#include <string>
using namespace std;
bool OneEditReplace(string s1,string s2);
bool OneEditInsert(string s1,string s2);
bool OneEditAway(string s1,string s2)
{
    if(s1.length() == s2.length())
        return OneEditReplace(s1,s2);
    else if(s1.length() + 1 == s2.length())
        return OneEditInsert(s1,s2);
    else if(s1.length() - 1 == s2.length())
        return OneEditInsert(s2,s1);
    else
        return false;
}
bool OneEditReplace(string s1,string s2)
{
    bool diff = false;
    for(int i = 0;i < s1.length();i++)
    {
        if((s1[i] != s2[i]))
        {
            if(diff)
                return false;
            else
                diff = true;
        }
    }
    return true;
}
bool OneEditInsert(string s1,string s2)
{
    int index1 = 0,index2 = 0;
    bool enter = false;
    while((index1 < s1.length()) && (index2 < s2.length()))
    {
        if(s1[index1] != s2[index2])
        {
            //if(index1 != index2)
            //    return false;
            if(enter)
                return false;
            else
            {
                index2++;
                enter = true;
            }
        }
        else
        {
            index1++;
            index2++;
        }
    }
    return true;
}
int main()
{
    string s1= "pplee";
    string s2 = "ple";
    if(OneEditAway(s1,s2))
        cout<<"YES\n";
    else
        cout<<"NO\n";
    getchar();
    return 0;
}