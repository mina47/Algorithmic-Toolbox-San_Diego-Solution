#include <iostream>
using namespace std ;
long long  gcd_naive(long long  a, long long  b) {
  if (b==0) return a ;
  else
    gcd_naive(b ,a%b) ;
}

int main() {
  long long  a, b;
  cin >> a >> b;
  cout << gcd_naive(a, b) << endl;
  return 0;
}
