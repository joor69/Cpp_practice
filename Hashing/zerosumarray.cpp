#include<bits/stdc++.h>
using namespace std;

int largestsubarray(const vector<int>& arr)
{
    //BRUTE FORCE
    // int n=arr.size();
    // int Max=0,length=0,current=0;
    // for(int i=0;i<n-1;i++)
    // {
    //     current=arr[i];
    //     for(int j=i+1;j<n;j++)
    //     {
    //         current=current+arr[j];
    //         if(current==0)
    //         {
    //             length=j-i+1;
    //             Max= max(Max,length);
    //         }
    //     }
    // }

    //Optimised 
    unordered_map<int,int> s;
    int sum=0,ans=0;
    for(int i=0;i<arr.size();i++)
    {
        sum+=arr[i];
        //the sum doesnot exist in map
        if(s.find(sum)==s.end())
        {
            s[sum]=i;
        }
        else
        {
           int length=i - s[sum];//i -idx
           ans=max(ans,length);
        }
    }

    unordered_map<int,int>().swap(s);

    return ans;
}

int ksumarray(const vector<int>& nums,int k)
{
    unordered_map<int, int> prevSums;
    prevSums[0] = 1; // Base case: a sum of 0 has been seen once
    
    int current_sum = 0;
    int total_subarrays = 0;

    for (int x : nums) {
        current_sum += x;
        
        // Check if (current_sum - k) happened before
        if (prevSums.find(current_sum - k) != prevSums.end()) {
            total_subarrays += prevSums[current_sum - k];
        }
        
        // Record this current_sum in the map
        prevSums[current_sum]++;
    }
    
    return total_subarrays;
}


int main()
{
    vector<int> arr={15,-2,2,-8,1,7,10};
    vector<int> arr1={5,-5,5,-5};
    // cout<<largestsubarray(arr);
    cout<<ksumarray(arr1,5);
    return 0;
}
