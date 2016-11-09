#include "main.hpp"

using namespace std;

template <typename T, typename  Type>
int bin_search_containers(T container, Type _value)
{
    Type l = 0;
    Type r = container.size();
    int middle = (l + r) / 2;

    while ( middle >= 1 ) {
        middle = (l + r) / 2;

     /*
     * для такого случия vector<int> vec{1, 1, 1, 3, 6, 8, 8, 10, 10, 12};
     * бывают колизии и цикл продолжается бесконечно, вот по этому и нужна
     * проверка  'f(r > l)',  исправлен баг 'if(r >= l)'
     * ***--- например если _value = 13 и vec.size() >= 60
     * на экран выводит "13 not founded" ---***
     */
        if(r >= l) {
            if (_value == container.at(middle)) {
                return middle;
              }
            if (_value < container.at(middle)) {
                r = middle - 1;
              }
            else {
                l = middle + 1;
              }
          }
        else {
            return -1;
          }
      }
    return -1;
}

int main()
{
      boost::chrono::milliseconds start(clock());
//----------------------------------------------------------------

      my_boost_int_Rnd rnd;
      vector<int> vec;

      for (int i = 0; i < 250; ++i) {
          vec.push_back(i);
          //a[var] = rnd.int_boost_rnd(1, 15);
        }

      //sort(vec.begin(), vec.end());


      /*for (auto j : vec)
              cout << j << " ";
      cout << endl;*/

      int s = rnd.int_boost_rnd(1,15);
      int x = bin_search_containers(vec, 13);

      if(x < 0)
        cout << 13 << " not founded" << endl;
      else
        cout << 13 << " at a[" << x << "]" << endl;



//---------------------------------------------------------------
      boost::chrono::milliseconds end(clock());
      using ms = boost::chrono::milliseconds;
      ms dur = boost::chrono::duration_cast<ms>(end - start);
      double dd = dur.count();
      cout << dd / 1000.0 << " sec. = " << end - start << endl;

  return 0;
}
