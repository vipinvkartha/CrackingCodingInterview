#include <iostream>
#include <bitset>
#include <vector>
#include <string>

using namespace std;

bool isUniqueChar(const string &str)
{
	if (str.length() > 128)
		return false;
	vector<bool> char_set(128);
	for (int i = 0; i < str.length(); i++)
	{
		int val = str[i];
		if (char_set[val])
		{
			return false;
		}
		char_set[val] = true;
	}
	return true;
}
int main()
{
    vector<string> words = {"test","hai","world","India","cool"};
    for(auto word:words)
    {
        if(isUniqueChar(word))
            cout<<word<<" is "<<"Unique\n";
         else
            cout<<word<<" is "<<"Not Unique\n";
    }

    getchar();
    return 0;
}