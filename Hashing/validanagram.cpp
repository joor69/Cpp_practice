#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        bool validanagram(string x,string y)
        {
            // if(x.length()!=y.length())
            //     return false;

            // //using sorting>>>takes O(nlogn)
            // sort(x.begin(),x.end());
            // sort(y.begin(),y.end());

            // if(x==y)
            //     return true;
            // return false;
           
            //used Unordered_map;O(n)time complexity
            unordered_map<char,int> count;
            if(x.length()!=y.length())
                return false;
            for(char ele:x)
            {
                count[ele]++;
            }

            for(char ele:y)
            {
                count[ele]--;
            }

            for(auto const&[key,value]:count)
            {
                if(value>0)
                    return false;
            }
            return true;
        }

};

int main()
{
    Solution obj1;
    cout<<obj1.validanagram("race","care");
    return 0;
}