#ifndef _SORTING_H_
#define _SORTING_H_

#include <vector>
#include <iostream>
#include <string>

using namespace std;

namespace sorting {
  
  //************
  // QuickSort *
  //************
  void QuickSort(vector<int> &arr, int left, int right);

  int partition(vector<int> &A, int first, int last);
  //************
  // MergeSort *
  //************
  void mergeTwoSortedArray(vector<int> &ori, vector<int> &cache, int begin, int pivot, int end);
  void MergeSort(vector<int> &origin, vector<int> &cache, int low, int high);

  //************
  // Heapsort  *
  //************
  int leftchild(int const &nodeIdx);
  int parent(int const &nodeIdx);
  void percDown(vector<int> &A, int node, int arr_size);
  void HeapSort(vector<int> &A, int len);

  //************
  // Shellsort *
  //************
  void ShellSort(vector<int> &a, int n);

  //*******************
  // Helper functions *
  //*******************
  void randomizeVector(vector<int> &array, int n);
  
 }
#endif 
