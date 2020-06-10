#ifndef TESTS_H_INCLUDED
#define TESTS_H_INCLUDED


#include"CArray.h"
using namespace std;

// ����� ��� ������������ ������ ������
// 1.1. �������� � ����� 20 ��������� ����� � ��������� �� 0 �� 100
void Test_1_1(CArray<int>& A)
{
  int i, number;

  cout << "Test 1.1. Form the array with 20 random numbers." << endl;

  srand(time(NULL));
  for (i = 0;i < 20;i++)
  {
    // ������������ ��������� ����� �� 0 �� 100
    number = rand() % 100;

    // �������� ����� � ����� �������
    A.push_back(number);
  }
}

// 1.2. �������������� ������ ����� �� �����������
void Test_1_2(CArray<int>& A)
{
  int i, j;
  int t;

  cout << "Test 1.2. Sorting the array." << endl;

  // ���������� ������� �������
  for (i=0; i<A.size()-1; i++)
    for (j=i; j>=0; j--)
      if (A[j] > A[j + 1])
      {
        t = A[j];
        A[j] = A[j + 1];
        A[j + 1] = t;
      }
}

// 1.3. �������� ������� ������� ��������
void Test_1_3(CArray<int>& A)
{
  CArray<int> B; // ����� �����

  cout << "Test 1.3. Deleting every secont item." << endl;

  B.clear();
  for (int i = 0; i < A.size();i++)
  {
    if (i % 2 == 1)
      B.push_back(A[i]);
  }
  A = B;
}

// 1.4. ������� 10 ��������� ����� � ��������� �� 0 �� 100 �� ��������� �������
void Test_1_4(CArray<int>& A)
{
  int i;
  int number, pos;
  int t;

  cout << "Test 1.4. Inserting 10 random numbers to random positions" << endl;

  // ����������� � �������� ������� ��� ������������� ��������� �����
  srand(time(NULL));

  t = 0; // ����������, ������������ ���������� ����������� �����
  for (i = 0; i < 10; i++)
  {
    number = rand() % 100; // ��������� �����
    pos = rand() % (10 + t); // ��������� ������� (0..10+t)
    A.insert(pos, number);
    t++; // ���������� ����������� �����
  }
}

// 1.5. ������� ����������
void Test_1_5(CArray<int>& A)
{
  cout << "Test 1.5. Clear the array." << endl;
  A.clear();
}

// ������������ ������ ������ � ������� int
void DemoInt()
{
  CArray<int> A; // ������, ������� ������ ���� �������������

  // ���� 1.1
  Test_1_1(A);
  A.print(); // ������� ������ �� �����

  // ���� 1.2
  Test_1_2(A);
  A.print();

  // ���� 1.3
  Test_1_3(A);
  A.print();

  // ���� 1.4
  Test_1_4(A);
  A.print();

  // ���� 1.5
  Test_1_5(A);
  A.print();
}

// 2. ������ � ��������� (std::string)
// 2.1. ���������� � ����� 15 �������� ��������� ����, ��������� �� ���������� ���� � ������ ��������
void Test_2_1(CArray<string>& A)
{
  int i, j;
  int len; // ����� �����
  string word;
  char symbol;

  cout << "Test 2.1. Adding 15 new words." << endl;
  srand(time(NULL));

  // ���� ������������ ����
  for (i = 0; i < 15; i++)
  {
    len = rand() % 6 + 1; // ��������� ����� ����� �� 1 �� 6

    // ������������ ��������� �����
    word = "";
    for (j = 0;j < len;j++)
    {
      // �������� ��������� ������
      symbol = 'a' + rand() % ((int)'z' - (int)'a' + 1);
      word += symbol; // �������� ������ � �����
    }
    A.push_back(word); // �������� ��������� ����� � ������
  }
}

// 2.2. �������������� ������ ���� �� �����������
void Test_2_2(CArray<string>& A)
{
  int i, j;
  string t;

  cout << "Test 2.2. Sorting words." << endl;

  // ���������� ������� �������
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

// 2.3. �������� ������� �����, ����������� � ���� ����� �� ���� a,b,c,d,e
void Test_2_3(CArray<string>& A)
{
  // �������������� ����������
  int i, j;
  string word;
  CArray<string> B;
  bool f_delete;

  cout << "Test 2.3. Deleting words wit characters a..z " << endl;

  // ���� �������� ������ ������� B, ������� �� �������� ����
  for (i = 0; i < A.size(); i++)
  {
    word = A[i];
    f_delete = false;
    for (j=0; j<word.length(); j++)
      if (('a' <= word[j]) && (word[j] <= 'e')) // ���� ������ � �������� 'a'..'e'
    {
      f_delete = true; // �� ����� �������
      break;
    }

    // �������� ����� � ����� B, ������� �� �������� 'a'..'e'
    if (!f_delete)
      B.push_back(word);
  }
  A = B; // ����������� ������ B � A
}

// 2.4. ������� 3-� ����� ��������� ���� �� ��������� �������
void Test_2_4(CArray<string>& A)
{
  int i, j;
  int len; // ��������� ����� ���������� �����
  string word; // ��������� �����
  char symbol; // ��������� ������
  int position; // ��������� ������� (0, 1, ...)
  int t; // ���������� ����������� ����

  cout << "Test 2.4. Inserting 3 new random words to random positions" << endl;

  // �������� � ������� ��� ������������ ��������� ����
  srand(time(NULL));

  // ���� ���������� ��������� ����
  for (i = 0, t = 0; i < 3; i++, t++)
  {
    // ����� ��������� �������
    position = rand() % (A.size() + t);

    // ����� ��������� ����� ����� 1..6
    len = rand() % 6 + 1;

    // ������������� ��������� �����
    word = "";

    for (j = 0; j < len; j++)
    {
      // ������������ ��������� ������
      symbol = 'a' + rand() % ((int)'z' - (int)'a' + 1);
      word += symbol; // �������� ������ � �����
    }

    // �������� ��������� ����� word � ��������� ������� position
    A.insert(position, word);
  }
}

// �����, ��������������� ������ � ��������� std::string
void DemoString()
{
  CArray<string> A; // �������� ������ ���� ��� ������������

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
