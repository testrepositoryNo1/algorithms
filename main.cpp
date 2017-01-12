#include "main.hpp"

using namespace std;

void printt(vector<int> vec)
{
    for (auto elem : vec) {
            cout << elem << " ";
        }
    cout << endl;
}

template<typename T>
void Sort(vector<T> &v)
{
    sort(v.begin(), v.end());
}

template <typename Item>
void merge_(Item a[], int l, int m, int r)
{
    int i, j;
    static Item aux[10], b[10];

  /*  for(size_t u = 0; u < 10; ++u){
            cout << a[u] << endl;
        }
*/
    //sleep(3);


    for (i = m + 1; i > l; --i) {
            aux[i - 1] = a [i - 1];
        }
    for (j = m; j < r; ++j) {
            int indx = r + m - j;
            aux[indx] = a[j + 1];
        }


    for(size_t u = 0; u < 10; ++u){
                cout << aux[u] << " ";
            }
    cout << endl;
    sleep(3);

    for (int k = l; k < r; ++k) {
            if (aux[j] < aux[i]) {
                b[k] = aux[j--];
                }
            else {
                    b[k] = aux[i++];
                }
        }

    for(size_t u = 0; u < 10; ++u){
            cout << b[u] << " ";
        }
    cout << endl;

}


void merger(int a[], int l, int m, int r)
{
    vector<int> first_part, second_part;
    vector<int> vec;

    for(size_t i = 0, j = 5; i < 5; ++i, ++j) {
            first_part.push_back(a[i]);
            second_part.push_back(a[j]);
        }



    auto iter1 = first_part.begin();
    auto iter2 = second_part.begin();

    Sort(first_part);
    Sort(second_part);


    for (size_t i = 0; i < first_part.size() + second_part.size(); ++i) {
            if (*iter1 <= *iter2) {
                    vec.push_back(*iter1);
                    if (iter1 == first_part.end() - 1) {
                            while (iter2 != second_part.end()) {
                                    vec.push_back(*iter2);
                                    ++iter2;
                                } break;
                        }
                    else {
                            ++iter1;
                        }
                }
            else  {
                    vec.push_back(*iter2);
                    if (iter2 == second_part.end() - 1) {
                            while (iter1 != first_part.end()) {
                                    vec.push_back(*iter1);
                                    ++iter1;
                                } break;
                        }
                    else {
                            ++iter2;
                        }
                }
        }
    for (auto elem : vec)
        cout << elem << " ";
    cout << endl;
}


template <typename Item>
void mergesort(Item a,  int l, int r)
{
    if (r <= 1) return;
    int m = (r + l) / 2;
    mergesort(a, l, m);
    mergesort(a, m + 1, r);
    merge_(a, l, m, r);
}

/*
* function for priority queue SORT algotithm realisation
*/
vector<int>::iterator find_max(vector<int>::iterator beg, vector<int>::iterator end)
{
    auto iter = beg;
    auto max = beg;

    for ( ; iter != end; ++iter) {
            if (*iter > *max) {
                    max = iter;
                }
        }
    return max;
}

/*
* function for priority queue SORT algotithm realisation
*/
template <typename T>
void iterator_swaper(T a, T b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

/*
* priority queue SORT algotithm realisation
*/
template <typename T>
void PQ_sort(T &vec)
{
    for (size_t i = 0; i < vec.size(); ++i) {
            auto max = find_max(vec.begin(), vec.end() - i);
            auto back = (vec.end() - (i + 1));
            iterator_swaper(max, back);
        }
}


/*
* константы для поразрядной сортировки
*/
const size_t bitsword = 32;
const size_t bitsbyte = 8;
const size_t byteword = bitsword / bitsbyte;
const size_t R = 1 << bitsbyte;

/*
* влечение B-ого байта из двоичного А слова
*/
inline int digit(long A, int B)
{
    return (A & (1 << B)) != 0;
}




int main ()
{
    Srand();
    boost::chrono::milliseconds start(clock());
//----------------------------------------------------------------

    vector<char> vec{'v', 'y', 'q', 'a', 'n', 'u', 'w', 'z', 'b', 'q'};

    //bubble_sort(vec);


    for(size_t i = 0; i < vec.size(); ++i) {
            cout << vec.at(i) << " ";
            int c = 8;
            while(c >= 0) {
                    cout << digit(vec.at(i), c) << " ";
                    --c;
                }
            cout << endl;
        }

//---------------------------------------------------------------
    boost::chrono::milliseconds end(clock());
    using ms = boost::chrono::milliseconds;
    ms dur = boost::chrono::duration_cast<ms>(end - start);
    double dd = dur.count() / 1000.0;
    cout << fixed << dd / 1000.0 << " sec. = " << (end - start) / 1000.0 << endl;

return 0;
}


