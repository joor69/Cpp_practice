#include<bits/stdc++.h>
using namespace std;

int ksumsubarray(const vector<int>& nums,int k)
{
    int sum=0;
    int length=0;
    int Max=0;
    int diff;
    unordered_map<int,int> sub;

    sub[0]=-1;
    for(int i=0;i<nums.size();i++)
    {
        sum+=nums[i];
        diff=sum-k;
        if(sub.count(diff))
        {
            length=i-sub[diff];
            Max=max(length,Max);
        }
        
        if(sub.find(sum)==sub.end())
        {
            sub[sum]=i;
        }
    }
    return Max;
}

int main()
{
    vector<int> arr={5,-5,5,-5,5};
    cout<<ksumsubarray(arr,0);
    return 0;
}