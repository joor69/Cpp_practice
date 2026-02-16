
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void reverse(vector<int> &arr)
    {
        int p1 = 0;
        int p2 = arr.size() - 1;

        while (p1 < p2)
        {
            swap(arr[p1], arr[p2]);
            p1++;
            p2--;
        }
    }

    bool palindrome(string str)
    {
        int p1 = 0;
        int p2 = str.size() - 1;

        while (p1 < p2)
        {
            if (str[p1] != str[p2])
            {
                return false;
            }
            p1++ ;
            p2--;
        }
        return true;
    }


    int fibonacci(int N)
    {
       if(N<=1)
        return N;
    
        int l=fibonacci(N-2);
        int sl=fibonacci(N-1);

        return l+sl;
        
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};

    Solution obj1;
    obj1.reverse(arr);

    //cout << obj1.palindrome("ABCBA");

    cout<<obj1.fibonacci(4);
    return 0;
}