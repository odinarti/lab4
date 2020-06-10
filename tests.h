#ifndef TESTS_H_INCLUDED
#define TESTS_H_INCLUDED


#include"CArray.h"
using namespace std;

// Тесты для демонстрации работы класса
// 1.1. Добавить в цикле 20 случайных чисел в диапазоне от 0 до 100
void Test_1_1(CArray<int>& A)
{
  int i, number;

  cout << "Test 1.1. Form the array with 20 random numbers." << endl;

  srand(time(NULL));
  for (i = 0;i < 20;i++)
  {
    // сформировать случайное число от 0 до 100
    number = rand() % 100;

    // добавить число в конец массива
    A.push_back(number);
  }
}

// 1.2. Упорядочивание набора чисел по возрастанию
void Test_1_2(CArray<int>& A)
{
  int i, j;
  int t;

  cout << "Test 1.2. Sorting the array." << endl;

  // сортировка методом вставки
  for (i=0; i<A.size()-1; i++)
    for (j=i; j>=0; j--)
      if (A[j] > A[j + 1])
      {
        t = A[j];
        A[j] = A[j + 1];
        A[j + 1] = t;
      }
}

// 1.3. Удаление каждого второго элемента
void Test_1_3(CArray<int>& A)
{
  CArray<int> B; // новый масив

  cout << "Test 1.3. Deleting every secont item." << endl;

  B.clear();
  for (int i = 0; i < A.size();i++)
  {
    if (i % 2 == 1)
      B.push_back(A[i]);
  }
  A = B;
}

// 1.4. Вставка 10 случайных чисел в диапазоне от 0 до 100 на случайные позиции
void Test_1_4(CArray<int>& A)
{
  int i;
  int number, pos;
  int t;

  cout << "Test 1.4. Inserting 10 random numbers to random positions" << endl;

  // привязаться к текущему времени при генерировании случайных чисел
  srand(time(NULL));

  t = 0; // переменная, определяющая количество добавленных чисел
  for (i = 0; i < 10; i++)
  {
    number = rand() % 100; // случайное число
    pos = rand() % (10 + t); // случайная позиция (0..10+t)
    A.insert(pos, number);
    t++; // количество добавленных чисел
  }
}

// 1.5. Очистка контейнера
void Test_1_5(CArray<int>& A)
{
  cout << "Test 1.5. Clear the array." << endl;
  A.clear();
}

// Демонстрация работи класса с числами int
void DemoInt()
{
  CArray<int> A; // массив, который должен быть протестирован

  // Тест 1.1
  Test_1_1(A);
  A.print(); // вывести массив на экран

  // Тест 1.2
  Test_1_2(A);
  A.print();

  // Тест 1.3
  Test_1_3(A);
  A.print();

  // Тест 1.4
  Test_1_4(A);
  A.print();

  // Тест 1.5
  Test_1_5(A);
  A.print();
}

// 2. Работа с объектами (std::string)
// 2.1. Добавление в цикле 15 случайно выбранных слов, состоящих из латинських букв в нижнем регистре
void Test_2_1(CArray<string>& A)
{
  int i, j;
  int len; // длина слова
  string word;
  char symbol;

  cout << "Test 2.1. Adding 15 new words." << endl;
  srand(time(NULL));

  // цикл формирования слов
  for (i = 0; i < 15; i++)
  {
    len = rand() % 6 + 1; // случайная длина слова от 1 до 6

    // сформировать случайное слово
    word = "";
    for (j = 0;j < len;j++)
    {
      // получить случайный символ
      symbol = 'a' + rand() % ((int)'z' - (int)'a' + 1);
      word += symbol; // добавить символ к слову
    }
    A.push_back(word); // добавить случайное слово в массив
  }
}

// 2.2. Упорядочивание набора слов по возрастанию
void Test_2_2(CArray<string>& A)
{
  int i, j;
  string t;

  cout << "Test 2.2. Sorting words." << endl;

  // сортировка методом вставки
  for (i = 0;i < A.size() - 1;i++)
  {
    for (j=i; j>=0; j--)
      if (A[j] > A[j + 1])
      {
        t = A[j];
        A[j] = A[j + 1];
        A[j + 1] = t;
      }
  }
}

// 2.3. Удаление каждого слова, включающего в себя любую из букв a,b,c,d,e
void Test_2_3(CArray<string>& A)
{
  // дополнительные переменные
  int i, j;
  string word;
  CArray<string> B;
  bool f_delete;

  cout << "Test 2.3. Deleting words wit characters a..z " << endl;

  // цикл создания нового массива B, который не содержит слов
  for (i = 0; i < A.size(); i++)
  {
    word = A[i];
    f_delete = false;
    for (j=0; j<word.length(); j++)
      if (('a' <= word[j]) && (word[j] <= 'e')) // если символ в пределах 'a'..'e'
    {
      f_delete = true; // то можна удалять
      break;
    }

    // добавить слово в масив B, которое не содержит 'a'..'e'
    if (!f_delete)
      B.push_back(word);
  }
  A = B; // скопировать массив B в A
}

// 2.4. Вставка 3-х новых случайных слов на случайные позиции
void Test_2_4(CArray<string>& A)
{
  int i, j;
  int len; // случайная длина случайного слова
  string word; // случайное слово
  char symbol; // случайный символ
  int position; // случайная позиция (0, 1, ...)
  int t; // количество добавленных слов

  cout << "Test 2.4. Inserting 3 new random words to random positions" << endl;

  // привязка к таймеру при формировании случайных слов
  srand(time(NULL));

  // Цикл добавления случайных слов
  for (i = 0, t = 0; i < 3; i++, t++)
  {
    // взять случайную позицию
    position = rand() % (A.size() + t);

    // взять случайную длину слова 1..6
    len = rand() % 6 + 1;

    // сгенерировать случайное слово
    word = "";

    for (j = 0; j < len; j++)
    {
      // сформировать случайный символ
      symbol = 'a' + rand() % ((int)'z' - (int)'a' + 1);
      word += symbol; // добавить символ к слову
    }

    // вставить случайное слово word в случайную позицию position
    A.insert(position, word);
  }
}

// Метод, демонстрирующий работу с объектами std::string
void DemoString()
{
  CArray<string> A; // объявить массив слов для тестирования

  Test_2_1(A);
  A.print();

  Test_2_2(A);
  A.print();

  Test_2_3(A);
  A.print();

  Test_2_4(A);
  A.print();
}


#endif // TESTS_H_INCLUDED
