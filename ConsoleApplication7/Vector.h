#pragma once
class Vector
{
    int* arr;
    int size;
public:
    Vector();
    ~Vector();
    Vector(int s);
    void InputRand();                                
    void Print();                                    
    void PushBack(int a);                            
    int PopBack();                                   
    void AddFirst(int a);                            
    void InsertAt(int index, int value);             
    int DeleteAt(int index);                         
    int DeleteFirst();                               
    void MergeArray(const int* newArr, int newSize); 
    Vector& operator+=(int count);
    Vector& operator-=(int count);
    Vector& operator*=(int value);
    friend Vector operator-(int count, const Vector& vec);
};
