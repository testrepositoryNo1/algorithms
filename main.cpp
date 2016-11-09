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
     * bug no 1: для такого случия vector<int> vec{1, 1, 1, 3, 6, 8, 8, 10, 10, 12};
     *           бывают колизии и цикл продолжается бесконечно, вот по этому и нужна
     *           проверка  'f(r > l)'
     * bug no 2: исправлен баг 'if(r >= l)'
     *           ***--- например если _value = 13 и vec.size() >= 60
     *           на экран выводит "13 not founded" ---***
     * bug no 3: без проверки 'middle < container.size()', в том случае если
     *           значение _value больше чем максимальный элемент контейнера,
     *           получается ошибка 'std::out_of_range', потому что переменная l
     *           в конце становится равным vec.size(), и что естественно мы выходим
     *           за границы контейнера при проверке 'container.at(middle)'
     *
     */
        if(r >= l && middle < container.size()) {
            if (container.at(middle) == _value) {
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

      for (int i = 0; i < 10; ++i) {
          vec.push_back(i);
          //a[var] = rnd.int_boost_rnd(1, 15);
        }

      //sort(vec.begin(), vec.end());


      /*for (auto j : vec)
              cout << j << " ";
      cout << endl;*/


      int s = 11; // rnd.int_boost_rnd(1, 250);
          int x = bin_search_containers(vec, s);

          if(x < 0)
            cout << s << " not founded" << endl;
          else
            cout << s << " at a[" << x << "]" << endl;



//---------------------------------------------------------------
      boost::chrono::milliseconds end(clock());
      using ms = boost::chrono::milliseconds;
      ms dur = boost::chrono::duration_cast<ms>(end - start);
      double dd = dur.count();
      cout << dd / 1000.0 << " sec. = " << end - start << endl;

  return 0;
}
