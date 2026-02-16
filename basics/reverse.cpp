#include <iostream>
using namespace std;

int reverse(int);
int main()
{
   cout<<reverse(1000);
}

int reverse(int n)
{
    int rn=0,rem;
    while(n>0)
    {
        int rem=n%10;
        rn=rn*10 + rem;
        n=n/10;
    }
    return rn;
}