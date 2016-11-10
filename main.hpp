#ifndef MAIN_HPP
#define MAIN_HPP
#include "stdfx.hpp"

#define DATA_TYPE boost::int64_t  /* for boost spreadsort*/

class my_boost_int_Rnd
{
public:


  int64_t int_boost_rnd()
  {
    boost::random::mt19937 temp_gen(clock() * time(0) / rand());       /* seed */
    boost::random::uniform_int_distribution<>temp_di;
    boost::random::mt19937 gen(temp_di(temp_gen));
    boost::random::uniform_int_distribution<> dist;
    return dist(gen);
  }


  int64_t int_boost_rnd(int a, int b)
  {
    boost::random::mt19937 temp_gen(clock() * time(0) / rand());       /* seed is clock*/
    boost::random::uniform_int_distribution<>temp_di;
    boost::random::mt19937 gen(temp_di(temp_gen));
    boost::random::uniform_int_distribution<> dist(a, b);
    return dist(gen);
  }

  long double double_boost_rnd()
  {
    my_boost_int_Rnd ob;

    double r =  ob.int_boost_rnd() / 1.0;
    double x = r / ob.int_boost_rnd() * ob.int_boost_rnd(1, 100);
    return x;
  }
};


/*
*
* template function of binart search tree (BST) for containers
*
*/
static size_t counter = 0;  // count of comparisons

template <typename T, typename  Type>
int bin_search_containers(T container, Type _value)
{
    Type l = 0;
    Type r = container.size();
    Type middle = (l + r) / 2;


    while ( middle >= 1 ) {
        middle = (l + r) / 2;
        ++counter;

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

/*
* for qsort(vec.data(), vec.size(), sizeof(int), compare);
*/
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}


#endif // MAIN_HPP
