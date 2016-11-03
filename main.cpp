#include "main.hpp"

using namespace std;

unsigned long long int factorial(unsigned long long int N)
{
  if (N == 0) return 1;
  else
    return N * factorial(N - 1);
}

int main()
{
      boost::chrono::milliseconds start(clock());
//----------------------------------------------------------------

      int N = 50;

      cout << factorial(N) << endl;

/*
      unsigned long long int t = 1, i = 1;
      for (; i <= N; ++i)
        t *= i;

      cout << t << endl;
*/
//---------------------------------------------------------------
      boost::chrono::milliseconds end(clock());
      using ms = boost::chrono::milliseconds;
      ms dur = boost::chrono::duration_cast<ms>(end - start);
      double dd = dur.count();
      cout << dd / 1000.0 << " sec. = " << end - start << endl;

  return 0;
}
