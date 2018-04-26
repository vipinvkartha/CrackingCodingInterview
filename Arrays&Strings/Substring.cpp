#include <iostream>
#include <string>
#include<algorithm>

using namespace std;


int substring(string str , string sub)
{
    cout<<"Entered function\n";
    int len = str.length(),len1 = sub.length();
    transform(str.begin(),str.end(),str.begin(),::tolower);
    transform(sub.begin(),sub.end(),sub.begin(),::tolower);
  //  str.tolower();
   // sub.tolower();
    if(len1 > len)
        return -1;
    int count = 1;
    int j = 0;
    for(int i = 0;i < len;i ++)
    {
        if(str[i] == sub[j])
        {
            j++;
            for(int k=i+1;j<len1,k<len;k++,j++)
            {
                if(str[k] == sub[j])
                {
                    count++;
                    if(count == len1)
                        return i;
                }
                else 
                    break;

            }
            j = 0;
            count = 1;
        }
    }
    return -1;
}
int main()
{
    string str = "tesTING";
    string sub = "tes";
    int index = substring(str,sub);
    cout<<str<<endl<<sub<<endl;
    if(index < 0)
        cout<<"Not found\n";
    else
        cout<<"Found at index "<<index<<endl;
    getchar();
    return 0;
}