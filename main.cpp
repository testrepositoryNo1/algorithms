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
            if(v.at(i) < v.at(j)) {
                exch(v.at(i), v.at(j));
                ++c;
            }
        }
        ++c;
    }
}

template<typename  _Type>
void insertion_sort(vector<_Type> &v)
{
    _Type min = v.front(), pos = 0;

    for(size_t i = 0; i < v.size(); ++i) {
        size_t j = i;
        min = v.at(j);
        while (j < v.size()) {
            /* < - сортировка по возростанию, > - сортировка по убыванию*/
            if (v.at(j) < min){
                min = v.at(j);
                pos = j;
            }
            ++j;
            ++c;
        }
        exch(v.at(i), v.at(pos));
        j = 0;
        ++c;
    }
}

template<typename _Type>
void shellsort(vector<_Type> &vec)
{
    size_t h = 1;
    size_t r = vec.size();
    size_t l = 0;

    for ( ; h < (r - l) / 9; h = (3 * h) + 1);
    for( ; h > 0; h /= 3)
        for(size_t i = l + h; i < r; ++i) {
            size_t j = i;
            _Type v = vec.at(i);
            while (j >= l + h && v < vec.at(j - h)) {
                vec.at(j) = vec.at(j - h);
                j -= h;
            }
            vec.at(j) = v;
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
    size_t sz = 200;

    gen(vec, sz);
    _sort(vec.begin(), vec.end());
    //bubble_sort(vec);


    //shellsort(vec);
    //sort(vec.begin(), vec.end());

    /*for (auto a : vec)
        cout << a << " ";
    cout << endl;*/

    cout << "c = " << c <<  endl;

//---------------------------------------------------------------
      boost::chrono::milliseconds end(clock());
      using ms = boost::chrono::milliseconds;
      ms dur = boost::chrono::duration_cast<ms>(end - start);
      double dd = dur.count() / 1000.0;
      cout << fixed << dd / 1000.0 << " sec. = " << (end - start) / 1000.0 << endl;

  return 0;
}
