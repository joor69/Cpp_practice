#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // largest code
    int largest(int arr[], int size)
    {
        int max = arr[0];
        for (int i = 1; i <= size; i++)
        {
            if (arr[i] > max)
            {
                max = arr[i];
            }
        }

        return max;
    }
    // second largest code
    int secondlargest(int arr[], int size)
    {
        int m = INT_MIN;
        int sm = INT_MIN;

        for (int i = 0; i < size; i++)
        {
            if (arr[i] > m)
            {
                sm = m;
                m = arr[i];
            }
            else if (arr[i] > sm && arr[i] != m)
                sm = arr[i];
        }

        return sm;
    }

    // Sorted or not:
    string checksorted(vector<int> arr)
    {
        int n = arr.size();
        if (n == 1)
        {
            return "true";
        }
        int f = 0, s = 1;
        while (f < s && s < n)
        {
            if (arr[f] > arr[s])
                return "false";
            f++;
            s++;
        }
        return "true";
    }
};
int main()
{
    Solution obj1;
    int arr[] = {3, 6, 2, 8, 3, 9, 0};
    vector<int> arr1 = {1, 2, 3, 4, 5, 6};
    vector<int> arr2 = {1, 2, 3, 1, 8};
    vector<int> arr3 = {1};
    vector<int> arr4 = {4, 1};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << obj1.largest(arr, n);
    cout << obj1.secondlargest(arr, n);
    cout << obj1.checksorted(arr1);
    cout << obj1.checksorted(arr2);
    cout << obj1.checksorted(arr3);
    cout << obj1.checksorted(arr4);
    return 0;
}