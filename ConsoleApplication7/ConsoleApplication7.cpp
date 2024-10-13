#include<iostream>
#include"Vector.h"
using namespace std;

int main()
{
    srand(time(0));
    Vector obj1(5);
    obj1.InputRand();
    obj1.Print();
    obj1.AddFirst(14);
    obj1.Print();
    obj1.InsertAt(2, 89);
    obj1.Print();
    int removed = obj1.DeleteAt(2);
    obj1.Print();
    cout << "Removed element at index 2 = " << removed << endl;
    int first = obj1.DeleteFirst();
    obj1.Print();
    cout << "First removed = " << first << endl;
    int arrToAdd[] = { 890, 870, 900 };
    obj1.MergeArray(arrToAdd, 3);
    obj1.Print();
    obj1 += 4;
    obj1.Print();
    obj1 -= 5;
    obj1.Print();
    obj1 *= 2;
    obj1.Print();
    Vector obj2 = 3 - obj1;
    obj2.Print();
}
