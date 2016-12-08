#include "main.hpp"

using namespace std;

/*
   merge sort algorithm for two sorted files
   algorithm will not work correctly, if source files are not sorted
   modified (improved)
*/
void merger_(string first_file_name, string second_file_name)
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

    first_part.pop_back();  /* без этого не обойтись, удаляем лишнее*/
    second_part.pop_back(); /* без этого не обойтись, удаляем лишнее */

    auto iter1 = first_part.begin();
    auto iter2 = second_part.begin();

    /*--- realisation of algorithm ---*/
    for (size_t i = 0; i < first_part.size() * 2; ++i){
            if (*iter1 <= *iter2) {
                    fout << *iter1 << "\n";
                    //vec.push_back(*iter1);
                    if (iter1 == first_part.end() - 1) {
                            /* всего лишь надо было понять,
                               что если достигли конца в одном файле,
                               а во втором еще есть элементы то эти элементы
                               из второго файла просто надо добавить в конец выходного файла
                               (потому как они уже отсортированы,
                               и больше максимального элемента первого файла)!
                             */
                            while (iter2 != second_part.end()) {
                                    fout << *iter2 << "\n";
                                    //vec.push_back(*iter2);
                                    ++iter2;
                                } break;
                        }
                    else {
                            ++iter1;
                        }
                }
            else if (*iter1 >= *iter2) {
                    fout << *iter2 << "\n";
                    //vec.push_back(*iter2);
                    if (iter2 == second_part.end() - 1) {
                            /* см. обяснеие выше стоящего цыкла 'while' */
                            while (iter1 != first_part.end()) {
                                    fout << *iter1 << "\n";
                                    //vec.push_back(*iter1);
                                    ++iter1;
                                } break;
                        }
                    else {
                            ++iter2;
                        }
                }
        }
    /*---*---*/
    fout.close();
}




int main ()
{
    Srand();
    boost::chrono::milliseconds start(clock());
//----------------------------------------------------------------

    big_files_generator(50, -50, 50);
    string first_file_name  = "first_part",
           second_file_name = "second_part";

    merger_(first_file_name, second_file_name); /* modified */


//---------------------------------------------------------------
    boost::chrono::milliseconds end(clock());
    using ms = boost::chrono::milliseconds;
    ms dur = boost::chrono::duration_cast<ms>(end - start);
    double dd = dur.count() / 1000.0;
    cout << fixed << dd / 1000.0 << " sec. = " << (end - start) / 1000.0 << endl;

return 0;
}
