#include <iostream>
using namespace std;

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
string palindrome(int x)
{
    int rn=reverse(x);
    if(rn == x)
        return "true";
    return "false";
}

int main()
{
    cout<<palindrome(1221);
    return 0;
}