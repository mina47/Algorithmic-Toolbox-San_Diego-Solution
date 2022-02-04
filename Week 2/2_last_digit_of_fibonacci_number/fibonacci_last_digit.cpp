#include <iostream>
using namespace std ;
 int fib_digits[10000001] ={0};
int get_fibonacci_last_digit_naive(int n) {
 fib_digits[1]=1 ;
 for(int i=2 ;i<n+1 ;i++)
    fib_digits[i] = ((  fib_digits[i-1] %10 )+ (fib_digits[i-2] %10 )) % 10 ;


 return fib_digits[n] ;
}

int main() {
    int n;
    cin >> n;
    int c = get_fibonacci_last_digit_naive(n);
    cout << c << '\n';
    }
