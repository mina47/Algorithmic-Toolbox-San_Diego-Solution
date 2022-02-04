#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using namespace std;
struct Segment {
  int start, end;
};

bool sort_ascending (const Segment &a , const Segment &b  )
{
    return a.start < b.start ;
}
bool intersect (Segment a ,Segment b)
{
    if (b.start >= a.start && b.start <= a.end)
        return true ;
    else
        return false ;
}
bool all_segment_intersection (vector <Segment> segments , int curr , int prev)
{  if (curr == prev) return true ;
    for(int i= curr ; i-1>= prev ;i--)
    {
        if(!intersect(segments[i-1] , segments[curr]))
            return false ;
    }
    return true ;
}
vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  //write your code here
  int n = segments.size();
  int curr_segment =0 ,prev_segment=0 ;
  while (curr_segment < n )
  {     prev_segment= curr_segment;
        int point = segments[curr_segment].end ;
        while (curr_segment <n && all_segment_intersection(segments ,curr_segment , prev_segment))
        {
            curr_segment++;
        }
         for (int i= prev_segment ;i<curr_segment ;i++)
         {
          point = min (point , segments[i].end);
         // cout<<"MIN HERE is   "<<point<<'\n';
         }
         //cout<<"MIN OUTER HERE is   "<<point<<'\n';

      points.push_back(point);

  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }

  sort (segments.begin() ,segments.end() ,sort_ascending); // sort with respect to start of this segment
  /* Debug code
  for(int i=0 ;i< segments.size();i++)
    std::cout<<segments[i].start <<"   "<< segments[i].end <<'\n';
*/
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
