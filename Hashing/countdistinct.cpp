#include <bits/stdc++.h>
using namespace std;

int countdistinct(const vector<int>& arr)
{
    unordered_set<int> s;
    for(int ele:arr)
    {
        s.insert(ele);
    }


    return s.size();
}

int main() 
{
    vector<int> arr={4,3,2,5,6,7,3,4,2,1};
    cout<<"Number of distinct elements is = "<<countdistinct(arr);
    return 0;
}