#include <iostream>
using namespace std ;


long long F[60]; //sequence of numbers repeated after 60 numbers
long long get_fibonacci_partial_sum_naive(long long from, long long to) {
   long long res =0 ;
    F[1]=1;
    for(int i=2 ;i<60 ;i++)
        F[i]= ((F[i-1] %10)+(F[i-2] %10) ) %10 ;

// sum of any adjacent 60 numbers = 280 so last digit is 0

long long  dif = (to - from ) +1 ;
//cout<<"Difference here is   " << dif <<'\n';
dif =dif % 60 ;
//cout<<"Difference after remainder  is   " << dif <<'\n';
long long s = from%60;
int cnt =0 ;
if (dif ==0 ) return 0;

while (true )
{
    res+= F[s] ;
    s++;
    if (s==60 ) s=0;
    cnt++;
    if(cnt == dif ) break;
}
res =res%10 ;
return res;
}








int main() {
    long long from, to;
    cin >> from >> to;
    cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
}
