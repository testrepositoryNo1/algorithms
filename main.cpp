#include "main.hpp"

using namespace std;

static int c = 0;


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
    if ((*t) == 0) {                  // Если дерева не существует
            (*t) = new node;          // Выделяем память
            (*t)->info = a;           // Кладем в выделенное место аргумент a
            (*t)->l = (*t)->r = 0;    // Очищаем память для следующего роста
            return;                   // Заложили семечко, выходим
        }
    //Дерево есть
    if (a > (*t)->info)
        push(a, &(*t)->r);      // Если аргумент а больше чем текущий элемент,
    // кладем его вправо
    else
        push(a, &(*t)->l);     // Иначе кладем его влево
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



class BinaryTree
{
public:
    ~BinaryTree() {}
    int info;
    BinaryTree *tree = 0;
    BinaryTree *left;
    BinaryTree *right;
    void push(int var, BinaryTree *temp);

};

void BinaryTree::push(int var, BinaryTree *temp)
{
    BinaryTree *tree = new BinaryTree;

    temp->info = var;

    if (var > temp->info)
        push(var, temp->right);      // Если аргумент а больше чем текущий элемент,
    // кладем его вправо
    else
        push(var, temp->left);     // Иначе кладем его влево

}



int main()
{
      boost::chrono::milliseconds start(clock());
//----------------------------------------------------------------


      vector<int> vec;
      my_boost_int_Rnd  rnd;




      BinaryTree btree;

      int c = 5;
      int x = 0;

      while (c) {
          cout << "ввод: ";
          cin >> x;
          btree.push(x, btree.tree);
          --c;
      }


      int n = 0; //Количество элементов
      int s = 0; //Число, передаваемое в дерево

      while (1) {
          cout << "введите количество элементов  ";
          cin >> n; //Вводим количество элементов

          //for (int i=0; i < n; ++i) {

          cout << "массив: ";
              while (vec.size() < n) {
                  s = rnd.int_boost_rnd(1, 25);
                  vec.push_back(s); //Считываем элемент за элементом
                  cout << s <<  " ";
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




//---------------------------------------------------------------
      boost::chrono::milliseconds end(clock());
      using ms = boost::chrono::milliseconds;
      ms dur = boost::chrono::duration_cast<ms>(end - start);
      double dd = dur.count() / 1000.0;
      cout << fixed << dd / 1000.0 << " sec. = " << (end - start) / 1000.0 << endl;

  return 0;
}
