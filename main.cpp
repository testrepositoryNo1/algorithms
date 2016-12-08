#include "main.hpp"

using namespace std;

size_t c = 0;

void gen(vector<int> &v, size_t _size)
{
    my_boost_int_Rnd rnd;
    for (size_t i = 0; i < _size; ++i) {
        v.push_back(rnd.int_boost_rnd());
        }
}


template <typename  _Type>
void exch(_Type &a, _Type &b)
{
    _Type temp;
    temp = a;
    a = b;
    b = temp;
}


template <typename  Type>
void bubble_sort(vector<Type> &v)
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


template <typename  Type>
void insertion_sort(vector<Type> &v)
{
    Type min = v.front(), pos = 0;

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


template <typename Type>
void shellsort(vector<Type> &vec)
{
    size_t h = 1;
    size_t r = vec.size();
    size_t l = 0;

    for ( ; h < (r - l) / 9; h = (3 * h) + 1);
    for( ; h > 0; h /= 3)
        for(size_t i = l + h; i < r; ++i) {
                size_t j = i;
                Type v = vec.at(i);
                while (j >= l + h && v < vec.at(j - h)) {
                        vec.at(j) = vec.at(j - h);
                        j -= h;
                    }
                vec.at(j) = v;
            }
}


int partition_ (int *a, int p, int r)
{
    int x = *(a+r);
    int i = p - 1;
    int j;
    int tmp;
    for (j = p; j < r; j++)
        {
            if (*(a+j) <= x)
                {
                    i++;
                    tmp = *(a+i);
                    *(a+i) = *(a+j);
                    *(a+j) = tmp;
                }
        }
    tmp = *(a+r);
    *(a+r) = *(a+i+1);
    *(a+i+1) = tmp;
    return i + 1;
}



/*template <typename Type>
void quicksort(int* a, int l, int r)
{
    if (r <= 1) return;
    int i = partition_(a, l, r);
    quicksort(a, l, i - 1);
    quicksort(a, i + 1, r);
}*/


/*void quicksort (int *a, int p, int r)
{
    int q;
    if (p < r)   {
            q = partition_ (a, p, r);
            quicksort (a, p, q-1);
            quicksort (a, q+1, r);
        }
}*/


/*template <typename Type>
void quicksort(vector<Type> &v)
{
    Type l = *v.begin();
    Type r = *v.rbegin();

    if (r <= 1) return;
    auto i = partition(v, l, r);
    quicksort(v, l, i - 1);
    quicksort(v, i + 1, r);
    qsort();

}
*/


/*void quicksort (int *a, int p, int r)
 {
    int q;
    if (p < r)   {
            q = partition_ (a, p, r);
            quicksort (a, p, q-1);
            quicksort (a, q+1, r);
        }
}
*/


/*
   merge sort algorithm for two sorted files
   algorithm will not work correctly, if source files are not sorted
*/
void merger(string first_file_name, string second_file_name)
{
    vector<int> first_part, second_part;;
    ifstream fin1, fin2;
    ofstream fout("merged_file", ios::out);


    fin1.open(first_file_name, ios::in);
    fin2.open(second_file_name, ios::in);

    int a   = 0,
        b   = 0;

    /* считивание из файлов */
    while (fin1 && fin2) {
            fin1 >> a;
            first_part.push_back(a);
            fin2 >> b;
            second_part.push_back(b);
        }

    first_part.pop_back();  /* без этого не обойтись */
    second_part.pop_back(); /* без этого не обойтись */

    auto iter1 = first_part.begin();
    auto iter2 = second_part.begin();

    /*--- realisation of algorithm ---*/
    for
            (size_t i = 0; i < first_part.size() * 2; ++i){
            if (*iter1 <= *iter2) {
                    fout << *iter1 << "\n";
                    //vec.push_back(*iter1); // на случай если захочется записать в массив
                                             //   (но лучше в список)
                    if (iter1 == first_part.end() - 1) {
                            *iter1 = *iter2 + 1; /* без этого не обойтись ()*/
                        }
                    else {
                            ++iter1;
                        }
                }
            else if (*iter1 >= *iter2) {
                    fout << *iter2 << "\n";
                    //vec.push_back(*iter2); // на случай если захочется записать в массив
                                             //   (но лучше в список)
                    if (iter2 == second_part.end() - 1) {
                            *iter2 = *iter1 + 1; /* без этого не обойтись ()*/
                        }
                    else {
                            ++iter2;
                        }
                }
        }
    /*---*---*/
    fout.close();

    /* some boost tricks */
    size_t file_size = boost::filesystem::file_size("merged_file");
    if (file_size > 50000000){
            boost::filesystem::rename("merged_file", "merged_file_is_too_big_don't_open_it");
        }
}


/*
   this function generate tow files,
   which contains sorted integer values
*/
void big_files_generator()
{
    vector<int> vec, first_part, second_part;
    gen(vec, 1000000);

    auto iter  = vec.begin();
    auto iter2 = vec.begin() + vec.size() / 2;

    for (; iter != (vec.begin() + vec.size() / 2); ++iter, ++iter2) {
            first_part.push_back(*iter);
            second_part.push_back(*iter2);
        }

    sort(first_part.begin(), first_part.end());
    sort(second_part.begin(), second_part.end());


    iter  = first_part.begin();
    iter2 = second_part.begin();

    thread thr([&first_part, &iter]()
    {
            ofstream fout;
            fout.open("first_part", ios::out | ios::app);
            for ( ; iter != first_part.end(); ++ iter) {
                    fout << *iter << "\n";
                }
            fout.close();

        });

    ofstream fout;
    fout.open("second_part", ios::out | ios::app);
    for ( ; iter2 != second_part.end(); ++ iter2) {
            fout << *iter2 << "\n";
        }

    thr.join();
}


/*
   this function generate tow files,
   which contains sorted integer values
*/
void small_files_generator()
{
    vector<int> first_part,
                second_part;

    for (size_t i = 0; i < 200; ++i){
            if (i%2 == 0)
                first_part.push_back(i);
            else
                second_part.push_back(i);
        }


    sort(first_part.begin(), first_part.end());
    sort(second_part.begin(), second_part.end());


    auto iter  = first_part.begin();
    auto iter2 = second_part.begin();

    thread thr([&first_part, &iter]()
    {
            ofstream fout;
            fout.open("first_part", ios::out);
            for ( ; iter != first_part.end(); ++ iter) {
                    fout << *iter << "\n";
                }
            fout.close();

        });

    ofstream fout;
    fout.open("second_part", ios::out);
    for ( ; iter2 != second_part.end(); ++ iter2) {
            fout << *iter2 << "\n";
        }

    thr.join();
}


int main ()
{
    Srand();
    boost::chrono::milliseconds start(clock());
//----------------------------------------------------------------

    string first_file_name  = "first_part",
           second_file_name = "second_part";

    merger(first_file_name, second_file_name);


//---------------------------------------------------------------
    boost::chrono::milliseconds end(clock());
    using ms = boost::chrono::milliseconds;
    ms dur = boost::chrono::duration_cast<ms>(end - start);
    double dd = dur.count() / 1000.0;
    cout << fixed << dd / 1000.0 << " sec. = " << (end - start) / 1000.0 << endl;

return 0;
}
