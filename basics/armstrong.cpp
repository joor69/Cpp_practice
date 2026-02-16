#include <iostream>
#include <cmath>

using namespace std;

int count(int x)
{
    return (log10(x)+1);
}

int armstrong(int num)
{
    int digit,cur_num=num,n=count(num);
    double sum=0;
    while(num>0)
    {
        digit=num%10;
        sum=sum+pow(digit,n);
        num=num/10;
    }

    return sum;
}
int main()
{
    cout<<armstrong(371);
    return 0;
}