#include<bits/stdc++.h>
using namespace std;
int pairsum(vector<int> nums, int target)
{
    unordered_map<int,int> pair;//key=arr[i], value=i
    for(int i=0;i<nums.size();i++)
    {
        int comp=target - nums[i];
        if(pair.count(comp))
        {
            cout<<"pairs of indices"<<pair[comp]<<" "<<i<<endl;
        }

        pair[nums[i]]=i;
    }

    return -1;
}
int main()
{
    vector<int> nums={1,2,3,2,6,7,8,0};
    pairsum(nums,9);
    return 0;
}