#include <iostream>
#include <string>
#include <vector>
using namespace std;

string compress(string str)
{
	size_t len = str.length();
	if (len < 2)
		return str;
	int count = 1;
	string dup{ "" };
	for (size_t i = 0; i<len - 1; i++)
	{
		if (str[i] == str[i + 1])
			count++;
		else
		{
			dup += str[i];
			dup += to_string(count);
			count = 1;
		}
		if (dup.length() > len)
			return str;
	}
	dup += str[len - 1];
	dup += to_string(count);
	if (dup.length() > len)
		return str;
	else
		return dup;
}
int main()
{
	string str = "aassssbbbbbpp";
	cout << "Original " << str;
	cout << "\nAfter compression " << compress(str);
	getchar();
	return 0;
}