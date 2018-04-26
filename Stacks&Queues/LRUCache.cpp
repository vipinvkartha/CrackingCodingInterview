#include <iostream>
#include<list>
#include <unordered_map>

using namespace std;

class LRUCache
{
public:
    int n;
    list<int> q;
    unordered_map<int,list<int>::iterator> mq;
    LRUCache(int sz)
    {
        n = sz;
    }
    void add(int val);
    void display();
};
void LRUCache::add(int val)
{
    if(mq.find(val) == mq.end())
    {
        if(q.size() == n)
        {
            int temp = q.back();
            q.pop_back();
            mq.erase(temp);
        }
    }
    else
    {
        if(!q.empty())
            q.erase(mq[val]);
    }
    q.push_front(val);
    mq[val] = q.begin();
}
void LRUCache::display()
{
    for(auto itr = q.begin();itr != q.end();itr++)
    {
        cout<<*itr<<" ";
    }
    cout<<endl;
}
int main()
{
    LRUCache lc(4);
    lc.add(4);
    lc.add(5);
    lc.add(6);
    lc.add(4);
    lc.add(3);
    lc.add(1);
    lc.display();
    getchar();
    return 0;

}