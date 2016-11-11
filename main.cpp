#include "main.hpp"

using namespace std;


/*
*
* Предполагается что в эту функцию передается предварительно отсортированный
* масив(вектор): [1...N + 1] (или любая другая последовательность чисел
* например [i,(i+1),(i+2)...(N + 1)]), в котором не хватает одного числа,
* функция находит данное число и выводит его на экран.
*
*/
int find_not_exist_var(vector<int> vec)
{
    int not_exist = -1;
    int l = 0;
    int r = vec.size() + 1;
    int middle = (l + r) / 2;

    while((r - l) >= 2) {
        middle = (l + r) / 2;
        if ( vec.at(middle) != middle + vec.front() ) {
            r = middle;
          }
        else {
            l = middle;
          }
      }
   return not_exist = (vec.at(l) + vec.at(r) ) / 2;
}

int main()
{
      boost::chrono::milliseconds start(clock());
//----------------------------------------------------------------

      /*--- Test of the algorithm ---*/
      vector<int>       main_vec;
      my_boost_int_Rnd  rnd;
      double            _rand = 0;

      for (size_t j = 1; j <= 5; ++j){
          _rand = rnd.int_boost_rnd(2, 200); // bug: not working if not exixt 1,
                                             //or element is more than max_element
           cout << "rand = " << _rand << endl;

          for (size_t i = 1; i <= 200; ++i)
            main_vec.push_back(i);

          auto pos = remove(main_vec.begin(), main_vec.end(), _rand);
          main_vec.erase(pos, main_vec.end());

          cout << "not exist: " << find_not_exist_var(main_vec) << endl;
          main_vec.clear();
        }
      /*--- Test of the algorithm ---*/


//---------------------------------------------------------------
      boost::chrono::milliseconds end(clock());
      using ms = boost::chrono::milliseconds;
      ms dur = boost::chrono::duration_cast<ms>(end - start);
      double dd = dur.count();
      cout << dd / 1000.0 << " sec. = " << end - start << endl;

  return 0;
}

