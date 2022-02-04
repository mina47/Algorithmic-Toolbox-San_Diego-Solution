#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int goal, int tank, vector<int> & stops) {
    // write your code here
    int n =stops.size();
    int num =0 ,start =0 ,curr_station =0 ;
    while (curr_station < n)
    {
        int prev = curr_station ;
        if (goal -start <= tank) return num ;
        while (curr_station< n && stops[curr_station] - start <= tank)
            curr_station++;
        if (prev == curr_station) return -1 ;
        if(curr_station<=n)
        {
            num++;
            start = stops[curr_station-1];
        }
    }
    if (goal - start <= tank)
    return num ;
    else
        return -1 ;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);

    for (size_t i = 0; i<n; ++i)
        cin >> stops.at(i);
        cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
