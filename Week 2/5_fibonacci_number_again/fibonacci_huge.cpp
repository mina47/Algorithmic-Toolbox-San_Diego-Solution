#include <iostream>
#include <string>
using namespace std;
const long long N = 1000000 ;
 long long F[N];


long long   get_fibonacci_huge_naive(long long n, long long m) {
        F[1]=1;
    for(int i= 2 ;i<N;i++)
        {
            F[i]= ((F[i-1] %m)+(F[i-2]%m)) %m ;
        }
        int len_period = 3;
        for (int i = 1 ; i<= N-3 ;i++)
        {
            if (F[i] == 0 && F[i+1]==1 && F[i+2]==1)
            {
                len_period =i ;
                break;
            }
        }
        int order = n % len_period ;
    return F[order];
}

int main() {
    long long n, m;
    cin >> n >> m;
    cout << get_fibonacci_huge_naive(n, m) << '\n';
}
