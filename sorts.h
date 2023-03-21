#ifndef SORTS_H
#define SORTS_H
#include <vector>
#include <iostream>
using namespace std;

#pragma once

class sorts
{
    //---------------------------------------------------------------------
public:
    sorts();
    ~sorts();
    void BubbleSort(vector<int> &vec);
    void InsertionSort(vector<int> &vec, int first, int last);
    void MergeSort(vector<int> &vec, int first, int last);
    void IterativeMergeSort(vector<int> &vec, int first, int last);
    void QuickSort(vector<int> &vec, int first, int last);
    void ShellSort(vector<int> &vec, int first, int last);

private:
};
//------------------------BUBBLESORT HI THERE, sending this back to the pc----------------------------------
/**
 * This is BubbleSort
 * Can sort from a given range passing in from the first index to the last index.
 * PARTIALLY SORTS
 * deals with invalid indexes.
 */
void BubbleSort(vector<int> &vec, int first, int last)
{
    if (last >= vec.size())
    {
        cout << "Indices are out of bounds" << endl;
        return;
    }
    else if (first > last || (first < 0 || last < 0))
    {
        cout << "First Index Can't Be Greater Than Last Index or Negative Numbers" << endl;
        return;
    }
    else if (last > first)
    {
        for (int i = first; i < last - 1; i++)
        {
            for (int j = first; j < last + first - i; j++)
            {
                if (vec[j] > vec[j + 1])
                {
                    swap(vec[j], vec[j + 1]);
                }
            }
        }
    }
}
//------------------------INSERTIONSORT----------------------------------
/**
 * This is the insertion sort
 * Can also sort within the given ranges passed in by the first and last params
 * Partially Sorts
 * deals with invalid indexes.
 */
void InsertionSort(vector<int> &vec, int first, int last)
{
    if (last >= vec.size())
    {
        cout << "Indices are out of bounds" << endl;
        return;
    }
    else if (first > last || (first < 0 || last < 0))
    {
        cout << "First Index Can't Be Greater Than Last Index or Negative Numbers" << endl;
        return;
    }
    else if (last > first)
    {
        for (int i = first; i <= last; i++)
        {
            int temp = vec[i];
            int j = i - 1;
            while (j >= first && vec[j] > temp)
            {
                vec[j + 1] = vec[j];
                j--;
            }
            vec[j + 1] = temp;
        }
    }
}

//------------------------QUICKSORT----------------------------------
/**
 * This is the QuickSort Method
 * Can also sort within the given ranges passed in by the first and last params
 * Partially sorts
 * deals with invalid indexes.
 */
void QuickSort(vector<int> &vec, int first, int last)
{
    if (last - first < 4)
    {
        InsertionSort(vec, first, last);
        return;
    }
    int mid = (first + last) / 2;
    if (vec[first] > vec[last])
    {
        swap(vec[first], vec[last]);
    }
    if (vec[first] > vec[mid])
    {
        swap(vec[first], vec[mid]);
    }
    else if (vec[mid] > vec[last])
    {
        swap(vec[mid], vec[last]);
    }
    int pivot = vec[mid];
    swap(vec[mid], vec[last - 1]);
    int left = first + 1;
    int right = last - 2;
    bool done = false;
    while (!done)
    {
        while (vec[left] < pivot)
        {
            left++;
        }
        while (vec[right] > pivot)
        {
            right--;
        }
        if (right > left)
        {
            swap(vec[left], vec[right]);
            right--;
            left++;
        }
        else
        {
            done = true;
        }
    }

    swap(vec[left], vec[last - 1]);
    QuickSort(vec, first, left - 1);
    QuickSort(vec, left + 1, last);
}

//------------------------SHELLSORT----------------------------------
/**
 * This is the ShellSort Method
 * Can also sort within the given ranges passed in by the first and last params
 * Partially sorts
 * deals with invalid indexes.
 */
void ShellSort(vector<int> &vec, int first, int last)
{
    if (last >= vec.size())
    {
        cout << "Indices are out of bounds" << endl;
        return;
    }
    else if (first > last || (first < 0 || last < 0))
    {
        cout << "First Index Can't Be Greater Than Last Index or Negative Numbers" << endl;
        return;
    }
    else if (last > first)
    {
        int j;
        int size = last - first + 1;
        for (int gap = size / 2; gap > 0; gap /= 2)
        {
            for (int i = gap + first; i <= last; i++)
            {
                int temp = vec[i];
                for (j = i; j >= (gap + first) && vec[j - gap] > temp; j -= gap)
                {
                    vec[j] = vec[j - gap];
                }
                vec[j] = temp;
            }
        }
    }
}

//------------------------MERGE AND MERGESORT----------------------------------
/**
 * This is the MergeSort Method and its helper Merge Function
 * Can also sort within the given ranges passed in by the first and last params
 * Partially sorts
 * deals with invalid indexes.
 */
void Merge(vector<int> &vec, int first, int mid, int last)
{
    if (last > first)
    {
        int size = last - first + 1;
        int *tmp_arr;
        tmp_arr = new int[size];
        int first1 = first;
        int last1 = mid;
        int first2 = mid + 1;
        int last2 = last;
        int index = 0;
        while ((first1 <= last1) && (first2 <= last2))
        {
            if (vec[first1] < vec[first2])
            {
                tmp_arr[index] = vec[first1];
                first1++;
            }
            else
            {
                tmp_arr[index] = vec[first2];
                first2++;
            }
            index++;
        }
        while (first1 <= last1)
        {
            tmp_arr[index] = vec[first1];
            first1++;
            index++;
        }
        while (first2 <= last2)
        {
            tmp_arr[index] = vec[first2];
            first2++;
            index++;
        }
        for (index = 0; index < size; index++)
        {
            vec[first] = tmp_arr[index];
            first++;
        }
        delete[] tmp_arr;
    }
}

// ACTUAL MERGESORT FUNTION
void MergeSort(vector<int> &vec, int first, int last)
{
    if (last >= vec.size())
    {
        cout << "Indices are out of bounds" << endl;
        return;
    }
    else if (first > last || (first < 0 || last < 0))
    {
        cout << "First Index Can't Be Greater Than Last Index or Negative Numbers" << endl;
        return;
    }
    else if (first < last)
    {
        int mid = (first + last) / 2;
        MergeSort(vec, first, mid);
        MergeSort(vec, mid + 1, last);
        Merge(vec, first, mid, last);
    }
}

//------------------------ITERATIVEMERGE AND ITERATIVEMERGESORT----------------------------------
/**
 * This is the ITERATIVE MergeSort Method and its helper Merge Function, this is done iteratively
 * Can also sort within the given ranges passed in by the first and last params
 * Partially sorts
 * deals with invalid indexes.
 */
void IterativeMerge(vector<int> &vec, vector<int> &temp, int first, int mid, int last)
{
    int size = last - first + 1;
    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;
    int index = 0;
    while ((first1 <= last1) && (first2 <= last2))
    {
        if (vec[first1] < vec[first2])
        {
            temp[index] = vec[first1];
            first1++;
        }
        else
        {
            temp[index] = vec[first2];
            first2++;
        }
        index++;
    }
    while (first1 <= last1)
    {
        temp[index] = vec[first1];
        first1++;
        index++;
    }
    while (first2 <= last2)
    {
        temp[index] = vec[first2];
        first2++;
        index++;
    }
    for (index = 0; index < size; index++)
    {
        vec[first] = temp[index];
        first++;
    }
}

// iterative merge sort
void IterativeMergeSort(vector<int> &vec, int first, int last)
{
    if (last >= vec.size())
    {
        cout << "Indices are out of bounds" << endl;
        return;
    }
    else if (first > last || (first < 0 || last < 0))
    {
        cout << "First Index Can't Be Greater Than Last Index or Negative Numbers" << endl;
        return;
    }
    else if (last > first)
    {
        vector<int> temp(last + 1);
        for (int i = 1; i <= last - first; i *= 2)
        {
            for (int j = first; j < last; j += (2 * i))
            {
                int beg = j;
                int mid = j + i - 1;
                int end = min(j + (2 * i) - 1, last);
                IterativeMerge(vec, temp, beg, mid, end);
            }
        }
    }
}

#endif