#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using namespace std ;
bool  is_better(string a , string b)
{
    if((a+b) > (b+a)) return true ;
    else return  false ;
}

string largest_number(vector<string> a) {
  //write your code here
  string MAX ;
  string result;
  //std::stringstream ret;

  while (!a.empty()) {
    int idx =0 ;
    MAX = a[0];
    for(int j =0 ;j<a.size() ;j++)
    {
        if (is_better(a[j] ,MAX))
        {
            idx=j;
            MAX =a[j];
        }
    }
    //std::cout<<" HI HERE ERASED =  "<< a[idx] <<'\n';
    a.erase(a.begin() + idx);
     result += MAX ;
  }

  //ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
