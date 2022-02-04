#include <iostream>
#include <vector>

using namespace std;
int sum (int n)
{
return ((n+1)*n)/2;
}
vector<int> optimal_summands(int n) {
  vector<int> summands;
for(int i=1 ; ;i++)
{
    if(sum(i)== n)
    {
        summands.push_back(i);
        break;
    }
    else if (sum(i) <n)
        summands.push_back(i);
    else
    {
        int current_sum = sum(summands.size());
        while ((n- current_sum)<= summands.size())
        {  //cout<<"SUM BEFORE POP   "<<summands.size()<<'\n';
            summands.pop_back();
          // cout<<"SUM AFTER POP   "<<summands.size()<<'\n';
            current_sum = sum(summands.size());
        }
        summands.push_back(n-current_sum);
        break;
    }
}
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
