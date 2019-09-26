#include <iostream>

using namespace std;

void reverse(char *str)
{
    char *ptr1 = str,temp;
    char *ptr2 = ptr1 + strlen(str) -1;
    while(ptr1<ptr2)
    {
        temp = *ptr1;
        *ptr1 = *ptr2;
        *ptr2 = temp;
        ptr1++;
        ptr2--;
    }

}
int main()
{
    char a[] = {'i','n','d','i','a','\0'};
    char *str = new char;

    cout<<"test\n";
    //cin>>str;
    cout<<strlen(a)<<endl;
    reverse(a);
    cout<<a;
    getchar();
    return 0;
}