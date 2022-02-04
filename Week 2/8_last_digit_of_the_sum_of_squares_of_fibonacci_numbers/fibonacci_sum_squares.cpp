#include <iostream>
using namespace std ;
const int N =1000;
long long SF[N];
long long  sum [N];
int fibonacci_sum_squares_naive(long long n) {
    SF[1]=1;
    sum[1] = 1 ;
    for(int i=2 ;i<N ;i++)
        {
            SF[i]= ((SF[i-1] %10)+(SF[i-2] %10) ) %10 ; // compute normal fib
        }

        for(int i=2 ;i<N ;i++)
        {
             SF[i] = (SF[i]*SF[i]) %10; // then last digit of square fib
        }
  for(int i=2 ;i<N ;i++)
    {
        sum[i]=(sum[i-1] + SF[i]) % 10 ;
    }
// Debug code
/*for(int i=0 ;i<70 ;i++)
{
    cout<<sum[i] <<"  " ;
    if((i+1)%10 ==0) cout<<'\n';
}*/
// From Above for loop we see that numbers repeated periodically length of period = 30

return sum[n%30] ;
}


int main() {
    long long n = 0;
    cin >> n;
    cout << fibonacci_sum_squares_naive(n);
}
