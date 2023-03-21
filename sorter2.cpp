#include <iostream>
#include <vector>
#include "sorts.h"
using namespace std;

int main()
{
  vector<int> vect{20, 30, 10, 11, 65, 2, 4, 7, 34};
  vector<int> vect2{48, 32, 16, 1, 3, 11, 9, 99, 234};
  vector<int> vect3{77, 42, 19, 9, 45, 431, 94, 46, 48, 10, 32, 56, 98, 11};
  vector<int> vect4{487, 73, 93, 83, 44, 63, 43, 39, 24};
  vector<int> vect5{84, 34, 14, 3, 44, 12, 49, 93, 34};
  vector<int> vect6{83, 45, 14, 66, 44, 17, 92, 209, 344, 111};
  cout << "before bubblesort" << endl;
  for (int x : vect)
  {
    cout << x << ", ";
  }
  cout << endl;
  BubbleSort(vect, 0, vect.size() - 1);
  cout << "after bubblesort" << endl;
  for (int x : vect)
  {
    cout << x << ", ";
  }

  cout << endl;
  cout << endl;
  cout << "before insertion sort" << endl;
  for (int x : vect2)
  {
    cout << x << ", ";
  }
  cout << endl;
  InsertionSort(vect2, 0, vect2.size() - 1);
  cout << "after inserstionsort" << endl;
  for (int x : vect2)
  {
    cout << x << ", ";
  }

  cout << endl;
  cout << endl;
  cout << "before Quick sort" << endl;
  for (int x : vect3)
  {
    cout << x << ", ";
  }
  cout << endl;
  QuickSort(vect3, 0, vect3.size() - 1);
  cout << "after quick sort" << endl;
  for (int x : vect3)
  {
    cout << x << ", ";
  }

  cout << endl;
  cout << endl;
  cout << "before Shell sort" << endl;
  for (int x : vect4)
  {
    cout << x << ", ";
  }
  cout << endl;
  ShellSort(vect4, 0, vect4.size() - 1);
  cout << "after Shell sort" << endl;
  for (int x : vect4)
  {
    cout << x << ", ";
  }

  cout << endl;
  cout << endl;
  cout << "before Mergesort" << endl;
  for (int x : vect5)
  {
    cout << x << ", ";
  }
  cout << endl;
  MergeSort(vect5, 0, vect5.size() - 1);
  cout << "after Merge sort" << endl;
  for (int x : vect5)
  {
    cout << x << ", ";
  }

  cout << endl;
  cout << endl;
  cout << "before ITERATIVE Mergesort" << endl;
  for (int x : vect6)
  {
    cout << x << ", ";
  }
  cout << endl;
  IterativeMergeSort(vect6, 0, vect6.size() - 1);
  cout << "after Merge sort" << endl;
  for (int x : vect6)
  {
    cout << x << ", ";
  }
  cout << endl;
}
