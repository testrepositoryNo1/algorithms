#include "main.hpp"

using namespace std;

template<typename  _Type>
void my_sort(vector<_Type> &v)
{
    _Type temp = 0;

    for(size_t i = 0; i < v.size(); ++i) {
        for(size_t j = 0; j < v.size(); ++j) {
            if(v.at(i) > v.at(j)) {
                temp = v.at(j);
                v.at(j) = v.at(i);
                v.at(i) = temp;
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

    gen(vec, 20);

    my_sort(vec);


    for(auto a : vec)
        cout << a << " ";
    cout << endl;




//---------------------------------------------------------------
      boost::chrono::milliseconds end(clock());
      using ms = boost::chrono::milliseconds;
      ms dur = boost::chrono::duration_cast<ms>(end - start);
      double dd = dur.count() / 1000.0;
      cout << fixed << dd / 1000.0 << " sec. = " << (end - start) / 1000.0 << endl;

  return 0;
}
