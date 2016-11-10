#include "main.hpp"

using namespace std;


int main()
{
      boost::chrono::milliseconds start(clock());
//----------------------------------------------------------------

      size_t c = 10;
      int *arr = new int[c]; // динамическое выделение паяти

      for (size_t i = 0; i < c; ++i) {
          *(arr + i) = i; // можно и 'arr[i] = i'
          cout << arr + i << endl;
        }

      cout << "----------------------\n";

      for (size_t i = 0; i < c; ++i)
        cout << *(arr + i) << "\n"; // можно и 'cout << arr[i] << "\n"'
      cout << endl;

      delete [] arr; // освобождение памяти

//---------------------------------------------------------------
      boost::chrono::milliseconds end(clock());
      using ms = boost::chrono::milliseconds;
      ms dur = boost::chrono::duration_cast<ms>(end - start);
      double dd = dur.count();
      cout << dd / 1000.0 << " sec. = " << end - start << endl;

  return 0;
}
