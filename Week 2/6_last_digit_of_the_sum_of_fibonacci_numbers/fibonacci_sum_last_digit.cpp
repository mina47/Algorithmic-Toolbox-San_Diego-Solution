#include <iostream>
using namespace std ;
const int N =1000;
long long F[N];
long long  sum [60]; //sequence of sum repeated after 60 numbers
int fibonacci_sum_naive(long long n) {
    F[1]=1;
    sum[1] = 1 ;
    for(int i=2 ;i<N ;i++)
        F[i]= ((F[i-1] %10)+(F[i-2] %10) ) %10 ;

    for(int i=2 ;i<60 ;i++)
    {
        sum[i]=(sum[i-1] + F[i]) % 10 ;
    }
    return sum [ n %60] ;
}

int main() {
    long long n = 0;
    cin >> n;
    cout << fibonacci_sum_naive(n);
}
