#include "Vector.h"
#include<iostream>
#include<Windows.h>
using namespace std;
Vector::Vector()
{
    arr = nullptr;
    size = 0;
}
Vector::Vector(int s)
{
    size = s;
    arr = new int[size] {0};
}
Vector::~Vector()
{
    delete[] arr;
    size = 0;
}
void Vector::InputRand()
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 76 - 55;
    }
}
void Vector::Print()
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << "\n------------------------------------------------------------------------------------------\n";
}
void Vector::PushBack(int a)
{
    int* temp = new int[size + 1];
    for (int i = 0; i < size; i++)
    {
        temp[i] = arr[i];
    }
    temp[size] = a;
    delete[] arr;
    arr = temp;
    size++;
}
int Vector::PopBack()
{
    if (size == 0) return -1;
    int* temp = new int[size - 1];
    for (int i = 0; i < size - 1; i++)
    {
        temp[i] = arr[i];
    }
    int el = arr[size - 1];
    delete[] arr;
    arr = temp;
    size--;
    return el;
}
void Vector::AddFirst(int a)
{
    int* temp = new int[size + 1];
    temp[0] = a;
    for (int i = 0; i < size; i++)
    {
        temp[i + 1] = arr[i];
    }
    delete[] arr;
    arr = temp;
    size++;
}
void Vector::InsertAt(int index, int value)
{
    if (index < 0 || index > size) return;
    int* temp = new int[size + 1];
    for (int i = 0; i < index; i++)
    {
        temp[i] = arr[i];
    }
    temp[index] = value;
    for (int i = index; i < size; i++)
    {
        temp[i + 1] = arr[i];
    }
    delete[] arr;
    arr = temp;
    size++;
}
int Vector::DeleteAt(int index)
{
    if (index < 0 || index >= size) return -1;
    int* temp = new int[size - 1];
    int el = arr[index];
    for (int i = 0; i < index; i++)
    {
        temp[i] = arr[i];
    }
    for (int i = index + 1; i < size; i++)
    {
        temp[i - 1] = arr[i];
    }
    delete[] arr;
    arr = temp;
    size--;
    return el;
}
int Vector::DeleteFirst()
{
    if (size == 0) return -1;
    int* temp = new int[size - 1];
    int el = arr[0];
    for (int i = 1; i < size; i++)
    {
        temp[i - 1] = arr[i];
    }
    delete[] arr;
    arr = temp;
    size--;
    return el;
}
void Vector::MergeArray(const int* newArr, int newSize)
{
    int* temp = new int[size + newSize];
    for (int i = 0; i < size; i++)
    {
        temp[i] = arr[i];
    }
    for (int i = 0; i < newSize; i++)
    {
        temp[size + i] = newArr[i];
    }
    delete[] arr;
    arr = temp;
    size += newSize;
}
Vector& Vector::operator+=(int count)
{
    int* temp = new int[size + count];
    for (int i = 0; i < size; i++)
    {
        temp[i] = arr[i];
    }
    for (int i = size; i < size + count; i++)
    {
        temp[i] = 0;
    }
    delete[] arr;
    arr = temp;
    size += count;

    return *this;
}
Vector& Vector::operator-=(int count)
{
    if (size < count) return *this;
    int* temp = new int[size - count];
    for (int i = 0; i < size - count; i++)
    {
        temp[i] = arr[i];
    }
    delete[] arr;
    arr = temp;
    size -= count;
    return *this;
}
Vector& Vector::operator*=(int value)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] *= value;
    }
    return *this;
}
Vector operator-(int count, const Vector& vec)
{
    if (vec.size <= count) return Vector(0);
    Vector result(vec.size - count);
    for (int i = 0; i < result.size; i++)
    {
        result.arr[i] = vec.arr[i + count];
    }
    return result;
}
