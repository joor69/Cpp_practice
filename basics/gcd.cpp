#include<iostream>
#include<algorithm>
using namespace std;
//Brute force::::::
// int gcd(int n,int m)
// {
//     int x=max(n,m),cd=1;
//     for(int i=1;i<=x;i++)
//     {
//         if(n%i==0 && m%i==0)
//         {
//             cd=max(cd,i);
//         }
//     }
//     return cd;
// }


//Optimised Euclidean algo:

int gcd(int n, int m)
{
    int gcd;
    while(n>0 && m > 0)
    {
        if(n>=m)
        {
            n=n%m;
        }
        else
        {
            m=m%n;
        }

        if(n==0)
            return m;
    }
    return n;

}


int main()
{
    cout<<gcd(20,15);
    return 0;
}