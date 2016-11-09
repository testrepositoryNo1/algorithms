#include "main.hpp"

using namespace std;


int bin_search(int a[], int v, int l, int r)
{
  while ((r - l) >= 1 ) {
     int m = (l + r) / 2;
     if (v == a[m]) return m;
     if (v < a[m]) r = m - 1; else l = m + 1;
    }
  return -1;
}


template <typename T, typename  Type>
int bin_search_containers(T container, Type _value)
{
  size_t size = container.size();
  int middle = 0;
  Type l = container.front();
  Type r = container.back();

  int z = r - l;

  while ( z >= 1 ) {
     middle = size / 2;
     if (_value == container.at(middle)) return middle;
     if (_value < container.at(middle)) r = middle - 1; else l = middle + 1;
    }
  return -1;
}

int main()
{
      boost::chrono::milliseconds start(clock());
//----------------------------------------------------------------

      my_boost_int_Rnd rnd;
      vector<int> vec;
      int a[10];

      for (int var = 0; var < 10; ++var) {
         vec.push_back(rnd.int_boost_rnd(1, 15));
         a[var] = rnd.int_boost_rnd(1, 15);
        }

      sort(begin(a), end(a));
      sort(vec.begin(), vec.end());

      for (auto j : vec)
              cout << j << " ";
      cout << endl;
      int s = rnd.int_boost_rnd(1,15);
      int x = bin_search_containers(vec, 5);

      if(x < 0)
        cout << s << " not founded" << endl;
      else
        cout  << s << " at a[" << x << "]" << endl;



     /* for (auto j : a)
        cout << j << " ";
      cout << endl;

      int s = rnd.int_boost_rnd(1,15);

      int x = bin_search(a, s, 0, 10);

      if(x < 0)
        cout << s << " not founded" << endl;
      else
        cout  << s << " at a[" << x << "]" << endl;

*/

//---------------------------------------------------------------
      boost::chrono::milliseconds end(clock());
      using ms = boost::chrono::milliseconds;
      ms dur = boost::chrono::duration_cast<ms>(end - start);
      double dd = dur.count();
      cout << dd / 1000.0 << " sec. = " << end - start << endl;

  return 0;
}
