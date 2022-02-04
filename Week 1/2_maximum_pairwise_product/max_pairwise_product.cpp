#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;
long long  MaxPairwiseProduct(vector<int> numbers) {
     int n =numbers.size();
     sort (numbers.begin() ,numbers.end());
     return ((long long )(numbers[n-1]))* numbers[n-2];
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << '\n';
    return 0;
}
