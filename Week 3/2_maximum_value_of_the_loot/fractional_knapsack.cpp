#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
   int n = weights.size();
  vector <double> u (n);
  for(int i=0 ;i<n ;i++)
  {u[i] = (double) (values[i]) / weights[i];}
  for (int i=0 ;i<n ;i++)
  {
      int idx = max_element(u.begin() , u.end()) - u.begin(); // get index of large item with value per unit
      //u[idx]=0;
      int w =weights[idx] ,v = values[idx];
      int a = min(capacity ,w);
      capacity -= a;
      value += u[idx] * a;
      u[idx]=0 ; // so next time when search for large value do not get the same value
      if (capacity == 0) return value;
  }



  return value;
}

int main() {
  int n;
  int capacity;
  cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  cout.precision(10);
  cout << optimal_value << endl;

  return 0;
}
