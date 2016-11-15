#include "main.hpp"

using namespace std;

static int c = 0;

int f(int n)
{
  ++c;
  while (n) {
      cout << n << endl;
   return f(n-1);
    }
  return -1;
}


template <class ForwardIterator>
  ForwardIterator _max_element ( ForwardIterator first, ForwardIterator last )
{
  if (first == last) return last;
  ForwardIterator largest = first;

  while (++first != last)
    if (*largest < *first)    // or: if (comp(*largest,*first)) for version (2)
      largest = first;
  return largest;
}


/*
*
* рекурсивный поиск максимума
*
*/
int max(int a[], int l, int r)
{
  if (l == r) return a[l];
  int m = (l + r) / 2;
  int u = max(a, l , m);
  int v = max(a, m + 1, r);
  if (u > v) return u; else return v;
}




// Наша структура
struct node
{
    int info;     // Информационное поле
    node *l, *r;  // Левая и Правая часть дерева
};

node *tree = 0; //Объявляем переменную, тип которой структура Дерево

/*--- ФУНКЦИЯ ЗАПИСИ ЭЛЕМЕНТА В БИНАРНОЕ ДЕРЕВО ---*/
void push(int a, node **t)
{
    if ((*t) == 0) {              // Если дерева не существует
        (*t) = new node;          // Выделяем память
        (*t)->info = a;           // Кладем в выделенное место аргумент a
        (*t)->l = (*t)->r = 0;    // Очищаем память для следующего роста
        return;                 // Заложили семечко, выходим
    }
       //Дерево есть
        if (a > (*t)->info)
          push(a, &(*t)->r);      // Если аргумент а больше чем текущий элемент,
                                  // кладем его вправо
        else push(a, &(*t)->l);   // Иначе кладем его влево
}

/*--- ФУНКЦИЯ ОТОБРАЖЕНИЯ ДЕРЕВА НА ЭКРАНЕ ---*/
void print (node *t, int u)
{
    if (t == 0) return;       //Если дерево пустое, то отображать нечего, выходим
    else {
        print(t->l, ++u);     //С помощью рекурсивного посещаем левое поддерево
    for (int i = 0; i < u; ++i)
      cout << "-";
    cout << t->info << endl;  //И показываем элемент
    u--;
      }
    print(t->r, ++u);         // С помощью рекурсии посещаем правое поддерево
    delete t;                 // Освобождаем выделенную память
}

int myrandom () { return rand()%100;}

int main()
{
      boost::chrono::milliseconds start(clock());
//----------------------------------------------------------------


      vector<int> vec;
      my_boost_int_Rnd  rnd;




      int n = 0; //Количество элементов
      int s = 0; //Число, передаваемое в дерево

      while (1) {
          cout << "введите количество элементов  ";
          cin >> n; //Вводим количество элементов

          //for (int i=0; i < n; ++i) {

          cout << "массив: ";
              while (vec.size() < n) {
                  s = rnd.int_boost_rnd(1, 25);
                  vec.push_back(s);
                  cout << s <<  " "; //Считываем элемент за элементом
                }
              cout << endl;
              //sort(vec.begin(), vec.end());
              //unique(vec.begin(), vec.end());
              //random_shuffle(vec.begin(), vec.end());

              for (auto a: vec)
                push(a, &tree); //И каждый кладем в дерево
            //}
          cout << "ваше дерево\n";
          print(tree, 0);
          cout << endl;
          vec.clear();
  }



     /* auto it = vec.begin();

      for (; it != vec.end(); ++it)
        if(*it > max)
        max = *it;*/

 /*     auto pos1 = vec.begin();
      thread th([&pos1,&vec](){
          auto tmp_pos = _max_element(vec.begin(), (vec.begin() + vec.size() / 2));
          pos1 = tmp_pos;
        });

*/

/*
      auto  pos1 = _max_element(vec.begin(), (vec.begin() + vec.size() / 2));
      //int   max1 = *pos1;

      auto  pos2 = _max_element((vec.begin() + vec.size() / 2), vec.end());
      //int   max2 = *pos2;

      //th.join();
      if(*pos1 > *pos2)
        cout << *pos1 << endl;
      else
        cout << *pos2 << endl;
      */

//---------------------------------------------------------------
      boost::chrono::milliseconds end(clock());
      using ms = boost::chrono::milliseconds;
      ms dur = boost::chrono::duration_cast<ms>(end - start);
      double dd = dur.count() / 1000.0;
      cout << fixed << dd / 1000.0 << " sec. = " << (end - start) / 1000.0 << endl;

  return 0;
}
