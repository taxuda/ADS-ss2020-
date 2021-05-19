#include "sorting.h"


namespace sorting {

	//************
	// QuickSort *
	//************      
	void QuickSort(vector<int> &arr, int left, int right) {
        if (left < right) {
            int pivot = partition(arr, left, right);
            QuickSort(arr, left, pivot - 1);
            QuickSort(arr, pivot + 1, right);
        }
    }

	int partition(vector<int> &A, int first, int last){
	    int random = first + rand() % (last - first);
	    swap(A[random], A[last]);
	    int pivot = A[last];
	    int smallerSet = first - 1;
	    // duyệt lần lượt từ first đến last - 1
	    for(int i = first; i < last; i++){
	        if(A[i] < pivot){
	            // smallerSet thêm một phần tử mới
	            smallerSet++;
	            swap(A[smallerSet], A[i]);
	        }
	    }
	    // đặt pivot vào giữa: smallerSet + pivot + greaterSet
	    swap(A[smallerSet + 1], A[last]);
	    return smallerSet + 1;
	}

	//************
	// MergeSort *
	//************
	void mergeTwoSortedArray(vector<int> &A, vector<int> &B, int begin, int pivot, int end) {
	    int left = begin;
	    int right = pivot + 1;
        int i = begin;
	    while(left <= pivot && right <= end){
	        // insert min(sub left , sub right) into B
	        if(A[left] < A[right])
	            B[i++] = A[left++];
	        else
	            B[i++] = A[right++];
	    }
	    // previous while loop break when one of two sub arrays is empty
	    // so, maybe there is rest of sub left or sub right to copy
	    while(left <= pivot) B[i++] = A[left++];    // copy rest sub left into B
	    while(right <= end) B[i++] = A[right++];    // copy rest sub right into B

	    /*
	    for(int i = begin; i <= end; i++){
	        // insert min( A[left], A[right] ) into B
	        if(A[left] < A[right])
	            B[i] = A[left++];
	        else
	            B[i] = A[right++];

	        // sub left A[left] is empty, copy the rest of sub right A[right] to B
	        if(left == pivot + 1){
	            i = i + 1;
	            while(i <= end) B[i++] = A[right++];
                break;
	        }

            // sub right A[right] is empty, copy the rest of sub left A[left] to B
	        if(right == end + 1){
	            i = i + 1;
	            while(i <= end) B[i++] = A[left++];
	            break;
	        }
	    }*/

	    for(int i = begin; i <= end; i++){
	        A[i] = B[i];
	    }
	}

	void MergeSort(vector<int> &origin, vector<int> &cache, int low, int high) {
	    if(low < high){
	        int pivot = low + (high - low) / 2; // tương tự (low + high)/2, tránh tràn số khi low và high lớn
            MergeSort(origin, cache, low, pivot);
            MergeSort(origin, cache, pivot + 1, high);
            mergeTwoSortedArray(origin, cache, low, pivot, high);
	    }
	}



	//************
	// Heapsort  *
	//************
	/**
	 * @param nodeIdx
	 * @return index of node's left child
	 */
	int leftchild(int const &nodeIdx){
	    return 2 * nodeIdx + 1;
	}

    int parent(int const &nodeIdx){
        return (nodeIdx - 1) / 2;
    }

	/**
	 * max heap: put toPerc node at
	 * right place in min heap tree
	 * @param A
	 * @param toPerc
	 * @param arr_size
	 */
	void percDown(vector<int> &A, int toPerc, int arr_size){
        int left = leftchild(toPerc);
        while(left < arr_size){
            int max_child = left;
            if(left < arr_size - 1){    // toPerc has both left and right children
                int right = left + 1;
                max_child = A[left] < A[right] ? right : left;
            }

            // toPerc is smaller than its children
            if(A[toPerc] < A[max_child])
                swap(A[toPerc], A[max_child]);

            toPerc = max_child; // update new place
            left = leftchild(toPerc);
        }
	}

	void HeapSort(vector<int> &A, int arr_size) {
	    // TRANSFORMATION ARRAY TO MAX HEAP
	    // bottom up: start at parent of last leaf node
	    int i = parent(arr_size - 1);
	    while(i >= 0){
            percDown(A, i, arr_size);
            i = i - 1;
	    }

	    // HEAPSORT WITH MAX HEAP
	    int last = arr_size - 1;
	    while(last > 0){
	        // root of max heap is maximum
	        // swap maximum value with last element in array
	        swap(A[0], A[last]);

	        // max heap with new root and smaller size = last = arr_size  - 1 (before was arr_size),
	        // have to put this new root in right place
	        // in order to maintain max heap
            percDown(A, 0, last);   // "last" is new size of this heap
            last = last - 1;
	    }
	}



	/**
	 * indexGap = 1: normal insertion sort function
	 * @param A
	 * @param indexGap
	 */
	void insertionSort(vector<int>&A, int indexGap){
	    for(int i = indexGap; i < A.size(); i++){
	        int key = A[i];
	        int sortedSubLeft = i - indexGap;
	        // insert key at right position in sorted Subleft
	        while(sortedSubLeft >= 0 && key < A[sortedSubLeft]){
	            swap(A[sortedSubLeft], A[i]);
	            i = sortedSubLeft;  // update new index of key in sorted Subleft
	            sortedSubLeft -= indexGap;
	        }
	    }
	}

	void ShellSort(vector<int> &A, int len)
	{
	    int indexGap = len / 2;
	    for(; indexGap > 0; indexGap /= 2){
            //insertionSort(A, indexGap);
            // Insertion Sort von Elementen mit Abstand gap
            for (int i = indexGap; i < len; i++) {
                int tmp = A[i];
                int j = i;
                for (; j >= indexGap && tmp < A[j-indexGap]; j -= indexGap) {
                    A[j] = A[j-indexGap]; }
                A[j] = tmp; }
            // Elemente sind im Abstand gap sortiert
	    }
	}


  void randomizeVector(vector<int> &array, int n) {
    array.resize(n);

    for(unsigned int i=0;i<array.size();i++)
      array[i]=rand() % 1000000;
  }


}





