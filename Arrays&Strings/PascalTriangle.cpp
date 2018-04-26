#include <iostream>

using namespace std;

void printPascal(int n)
{
    int arr[n][n];
    int k = n;
    for(int line = 0;line < n;line++)
    {
        for(int i = 0;i<=line;i++)
        {
            if((line == i) || (0 == i))
            {
                arr[line][i] = 1;
            }
            else
            {
                arr[line][i] = arr[line-1][i-1] + arr[line-1][i];
            }
            //for(int j = 0;j < k;j++)
              //  cout<<" ";
            k--;
            cout<<arr[line][i]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    printPascal(5);
    getchar();
    return 0;
}