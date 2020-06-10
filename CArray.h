#ifndef CARRAY_H_INCLUDED
#define CARRAY_H_INCLUDED

#include <iostream>
#include <new>
#include <vector>
#include <time.h>
using namespace std;

template <typename T>
class CArray
{
public:
  // ����������� �� ���������
  CArray()
  {
    count = 0;
  }

  // ����������� ����������� - ����������
  CArray(const CArray& _A)
  {
    try {
      // ������� �������� ������ ��� ������� ���� T
      A = new T[_A.count];
      count = _A.count;

      for (int i = 0; i < count; i++)
        A[i] = _A.A[i];
    }
    catch (bad_alloc e)
    {
      count = 0;
      cout << "Error. Cannot allocate memory." << endl;
      cout << e.what() << endl;
    }
  }

  // �������� �����������
  CArray& operator=(const CArray& _A)
  {
    // ���������� �������������� ���������� ������
    if (count > 0)
      delete[] A;

    // �������� ������ �� ������
    try {
      A = new T[_A.count];
      count = _A.count;

      for (int i = 0; i < count; i++)
        A[i] = _A.A[i];
    }
    catch (bad_alloc e)
    {
      count = 0;
      cout << "Error. Cannot allocate memory." << endl;
      cout << e.what() << endl;
    }
    return *this;
  }

  // ����������
  ~CArray()
  {
    // ���������� �������������� ���������� ������
    if (count > 0)
      delete[] A;
  }

  // �������� ������� � ����� �������
  void push_back(T value)
  {
    T* A2; // �������������� ��������� �� ������

    // ������� �������� ������
    try {
      A2 = new T[count + 1];

      // ���� ������ ��������, �� ��������� �� 1 ����� ���������
      count++;

      // ����������� ������ A � ������ A2
      for (int i = 0; i < count - 1; i++)
        A2[i] = A[i];

      // �������� ������� value
      A2[count - 1] = value;

      // ���������� ������, ���������� ��� ������ A
      if ((count - 1) > 0)
        delete[] A;

      // ������������� ��������� A �� ������ A2
      A = A2;
    }
    catch (bad_alloc e)
    {
      cout << "Error. Cannot allocate memory." << endl;
      cout << e.what() << endl;
    }
  }

  // �����, ������� ������� ������ A - ����� ��� ������������
  void print()
  {
    cout << "Array A: " << endl;

    if (!count)
    {
      cout << "Array is empty." << endl;
      return;
    }

    for (int i = 0; i < count; i++)
      cout << A[i] << " ";
    cout << endl;
  }

  // �������� ������� � ������ �� ��������� �������
  void insert(int _index, const T& _value)
  {
    // �������� �� ������������ �������
    if (!CheckIndex(_index))
    {
      cout << "Error. Bad index. ";
      return;
    }

    T* A2;
    A2 = Alloc(count + 1); // ������� �������� ������
    if (A2 == nullptr)
    {
      cout << "Error. Method insert(). Cannot allocate memory." << endl;
      return;
    }

    // ����������� A � A2 �� ������� _index
    for (int i = 0; i < _index; i++)
      A2[i] = A[i];

    // ������� � ������� _index
    A2[_index] = _value;

    // ����������� A � A2 ����� ������� _index
    for (int i = _index + 1; i < count + 1; i++)
      A2[i] = A[i - 1];

    // ���������� �������������� ���������� ���'��� ��� ������� A
    if (count > 1)
      delete[] A;

    count++; // ��������� ���������� ��������� ������� �� 1

    // ������������� ��������� A �� ������ A2
    A = A2;
  }

  // ����� erase() - ������� ������� �� ������� �� ��������� ������� _index
  void erase(int _index)
  {
    // ��������, ��������� �� ������
    if (!CheckIndex(_index))
    {
      cout << "Bad index." << endl;
      return;
    }

    // ���� �������� �� ������� �������� � ������� _index
    for (int i = _index; i < count - 1; i++)
      A[i] = A[i + 1];

    count--; // ��������� ���������� ��������� ������� �� 1

    // ���������������� ������
    T* A2 = Alloc(count); // �������� ������ �� ������

    // ����������� A � A2
    for (int i = 0; i < count; i++)
      A2[i] = A[i];

    // ���������� ������, ���������� ��� ������� A
    if (count > 0)
      delete[] A;

    // ������������� ��������� A �� A2
    A = A2;
  }

  // �����, ������������ ������ �������
  int size()
  {
    return count;
  }

  // �����, ��������� ������
  void clear()
  {
    if (count > 0)
    {
      delete[] A;
      count = 0;
    }
  }

  // ����������� ������� operator[], ����������� �������� �������������� �������
  T& operator[](int _index)
  {
    if (CheckIndex(_index))
      return A[_index];
    else
    {
      T value = 0;
      cout << "Bad index." << endl;
      return value;
    }
  }

protected:
  T* A; // ������ ������
  int count; // ���������� ��������� � �������

  // ���������� �����, ������� ���������, ���� �� �������� ������� � ���������� ��������
  // ���������� true, ���� ������ _index ���������
  bool CheckIndex(int _index)
  {
    if ((_index < 0) || (_index >= count))
      return false;
    return true;
  }

  // �����, ���������� ������ ��� ������� ���� T,
  // ����� ���������� ��������� �� ��������� ������
  T* Alloc(int _count)
  {
    T* A2 = nullptr;

    try {
      A2 = new T[_count];
    }
    catch (bad_alloc e)
    {
      cout << e.what() << endl;
      return nullptr;
    }
    return A2; // ������� ��������� �� ���������� ��������
  }
};




#endif // CARRAY_H_INCLUDED
