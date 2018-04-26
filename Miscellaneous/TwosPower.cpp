#include <iostream>
#include <math.h>

using namespace std;

int maxPower2(int n)
{
    int res = 0;
    for(int i = n;i >= 1;i--)
    {
        if((i & (i-1)) == 0)
        {
            res = i;
            break;
        }
    }
    return res;
}
int minPower2(int n)
{
    int count = ceil(log2(n));
    int res = 1;
    res = res<<count;
    return res;
}
int main()
{
    cout<<maxPower2(10)<<endl;
    cout<<minPower2(17)<<endl;
    getchar();
    return 0;
}