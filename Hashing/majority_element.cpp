#include<bits/stdc++.h>
using namespace std;

vector<int> majorityelement(const vector<int>& nums)
{
    vector<int> result;
    int value;
    int offset=nums.size()/3;
    unordered_map<int,int> counts;//key= elements and value=frequency of the elements
    for(int i=0;i<nums.size();i++)
    {
        
        if(counts.count(nums[i]))
        {
            counts[nums[i]]++;
        }
        else{
            counts[nums[i]]=1;
        }
    }

    for(auto const&[key,value]:counts)
    {
        if(value>offset)
            result.push_back(key);
            
    }

    return result;
}

int main()
{
    vector<int> arr={2,2};
    vector<int> result= majorityelement(arr);
    for(int ele:result)
        cout<<ele;
    return 0;
}