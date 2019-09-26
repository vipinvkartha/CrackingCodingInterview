#include <iostream>

using namespace std;

void inertionSort(int A[],int len)
{
    for(int i = 1;i<len;i++)
    {
        int k = i;
        int val = A[i];
        while((k > 0) && (A[k-1] > val ))
        {
            A[k] = A[k-1];
            k--;
        }
        A[k] = val;
    }
}

void Merge(int A[],int l,int m,int r)
{
    int n1 = m-l+1;
    int n2 = r-m; 
    int i = 0,j=0,k=l;
    int left[n1],right[n2];
    for(int i = 0;i<n1;i++)
    {
        left[i] = A[l+i];
    }
    for(int j = 0;j<n2;j++)
    {
        right[j] = A[m+1+j];
    }
    //i=0;
    //j=0;
    k=l;
    while((i<n1) && (j<n2))
    {
        if(left[i] <= right[j])
        {
            A[k] = left[i];
            i++;
            k++;
        }
        else
        {
            A[k] = right[j];
            j++;
            k++;
        }
    }
    while(i<n1)
    {
        A[k] = left[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        A[k] = right[j];
        j++;
        k++;
    }
}
void MergeSort(int A[],int l,int r)
{
    if(l<r)
    {
        int m = (l+r)/2;
        MergeSort(A,l,m);
        MergeSort(A,m+1,r);
        Merge(A,l,m,r);
    }
}
void display(int a[],int len)
{
    for(int i = 0;i<len;i++)
        cout<<a[i]<<" ";
}
int main()
{
    int A[] = {4,2,7,1,6,5};
    //inertionSort(a,5);
    MergeSort(A,0,5);
    display(A,5);
    getchar();
    return 0;
}