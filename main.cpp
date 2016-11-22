#include "main.hpp"

using namespace std;

size_t c = 0;

template<typename  _Type>
void exch(_Type &a, _Type &b)
{
    _Type temp;
    temp = a;
    a = b;
    b = temp;
}

template<typename  _Type>
void bubble_sort(vector<_Type> &v)
{
    for(size_t i = 0; i < v.size(); ++i) {
        for(size_t j = 0; j < v.size(); ++j) {
            /* < - сортировка по возростанию, > - сортировка по убыванию*/
            if(v.at(i) > v.at(j)) {
                exch(v.at(i), v.at(j));
                ++c;
            }
        }
    }
}

void gen(vector<int> &v, size_t _size)
{
    my_boost_int_Rnd rnd;
    for (size_t i = 0; i < _size; ++i)
        v.push_back(rnd.int_boost_rnd(1, 100));
}

int main ()
{
    setlocale(0, "");
    srand(time(0));
    srand(rand());
    ostream_iterator<int> out(cout, "\n");
    boost::chrono::milliseconds start(clock());
//----------------------------------------------------------------

    vector<int> vec;

    gen(vec, 30);

    bubble_sort(vec);


    for(auto a : vec)
        cout << a << " ";
    cout << endl;

    cout << "c = " << c << endl;


//---------------------------------------------------------------
      boost::chrono::milliseconds end(clock());
      using ms = boost::chrono::milliseconds;
      ms dur = boost::chrono::duration_cast<ms>(end - start);
      double dd = dur.count() / 1000.0;
      cout << fixed << dd / 1000.0 << " sec. = " << (end - start) / 1000.0 << endl;

  return 0;
}
