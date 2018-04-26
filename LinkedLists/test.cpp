// Write your code here
#include<bitset>
#include<iostream>
#include<vector>
using namespace std;
void countOnes(vector<int> arr,int q)
{
    int i,count=0;
    string output = "",temp = "";
    for(i = 0;i<q;i++)
    {
        temp = bitset<32>(arr[i]).to_string();
        output+=temp;
    }
    i=0;
    while(output[i]!='\0')
    {
        if(output[i] == '1')
            count++;
        i++;
    }
    cout<<count<<endl;
}
int main()
{
    int n,q,x;
    cout<<"enter n q\n";
    cin>>n>>q;
    vector<int> arr;
    for(int i = 0;i<n;i++)
        cin>>arr[i];
    for(int i = 0;i<q;i++)
    {
        cin>>x;
        countOnes(arr,x);
    }
    return 0;
    
}