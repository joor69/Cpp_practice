#include<bits/stdc++.h>
using namespace std;

vector<int> Union(const vector<int>& arr1,const vector<int>& arr2)
{
    vector<int> result;
    unordered_set<int> s;
    for(int ele:arr1)
        s.insert(ele);
    for(int ele:arr2)
        s.insert(ele);
    
    for(int x:s)
        result.push_back(x);

    return result;
    
}

int main()
{
    vector<int> result;
    vector<int> arr1={1,2,3,4}, arr2={3,4,6};
    result=Union(arr1,arr2);
    for(int ele:result)
        cout<<ele;
    return 0;
}