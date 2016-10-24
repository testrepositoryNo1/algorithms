#include "main.hpp"

using namespace std;

int64_t effective_fib(int n)
{
//array realisation
  /*
     int f[n+1];

  f[0] = 0;
  f[1] = 1;
  f[2] = 1;

  for(int j = 3; j <= n; ++j)
    f[j] = f[j - 1] + f[j - 2];

  return f[n];
*/

//vector realisation

  vector<int64_t> vec;
  vec.push_back(0);
  vec.push_back(1);
  vec.push_back(1);

  for(int i = 3; i <= n; ++i)
    vec.push_back(vec.at(i - 1) + vec.at(i - 2));

    return vec.at(n);
}

// not effective algorithm
int fib(int n)
{
  if(n == 0)
    return 0;
  else if (n == 1)
    return 1;
  else
    return fib(n - 1) + fib(n - 2);
}

int main()
{
  boost::chrono::milliseconds start(clock());
//----------------------------------------------------------------

  for (size_t i = 0; i < 100; ++i)
     cout << effective_fib(i) << endl;




//---------------------------------------------------------------
      boost::chrono::milliseconds end(clock());
      using ms = boost::chrono::milliseconds;
      ms dur = boost::chrono::duration_cast<ms>(end - start);
      double dd = dur.count();
      cout << dd / 1000.0 << " sec. = " << end - start << endl;

  return 0;
}
