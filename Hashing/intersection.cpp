#include <bits/stdc++.h>
using namespace std;

vector<int> Intersection(vector<int> arr, vector<int> arr1)
{
    vector<int> result;
    unordered_set<int> s;
    for (int ele : arr)
    {
        s.insert(ele);
    }

    for (int ele : arr1)
    {
        if (s.count(ele))
            result.push_back(ele);
    }

    return result;
}

int main()
{
    vector<int> result;
    vector<int> arr={1,2,3,4};
    vector<int> arr1={3,4};

    result=Intersection(arr,arr1);
    for(int ele: result)
        cout<<ele;
    return 0;
}