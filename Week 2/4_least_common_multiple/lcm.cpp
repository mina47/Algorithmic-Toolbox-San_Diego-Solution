#include <iostream>
using namespace std ;

long long gcd (long long a ,long long b)
{
    if (b==0) return a ;
    else
        gcd(b ,a%b);
}
long long lcm_naive(long long  a, long long  b) {
  long long g = gcd(a ,b) ;
  return (a/g) * b ;
}

int main() {
  long long  a, b;
  cin >> a >> b;
  cout << lcm_naive(a, b) << endl;
  return 0;
}
