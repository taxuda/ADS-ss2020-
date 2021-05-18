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

	int partition(vector<int> &arr, int low, int high){
	    int pivot = arr[high]; // pivot phần tử cuối của array
	    int left = low;
	    int right = high - 1;
	    while(true){
	        // tìm phần tử bên trái lớn hơn pivot
	        while(left <= right && arr[left] < pivot) left++;
            // tìm phần tử bên phải nhỏ hơn pivot
	        while(right >= left && arr[right] > pivot) right--;

	        // duyệt xong array khi:
	        // con trỏ từ hai đầu gặp hoặc vượt qua nhau
	        if(left >= right) break;

	        // hoán đổi vị trí: phần tử nhỏ hơn sang bên trái,
	        // phần tử lớn hơn sang bên phải
	        swap(arr[left], arr[right]);
	        left++;
	        right--;
	    }
	    // đặt pivot chính giữa hai phần
	    // bên trái < pivot < bên phải
	    swap(arr[left], arr[high]);

	    // trả lại vị trí của pivot
	    return left;
	}

	//************
	// MergeSort *
	//************
	void mergeTwoSortedArray(vector<int> &A, vector<int> &B, int begin, int pivot, int end) {
	    int left = begin;
	    int right = pivot + 1;

	    for(int i = begin; i <= end; i++){
	        // insert min( A[left], A[right] )
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
	    }

	    for(int i = begin; i <= end; i++){
	        A[i] = B[i];
	    }
	}

	void MergeSort(vector<int> &origin, vector<int> &cache, int low, int high) {
	    if(low < high){
	        int pivot = (low + high) / 2;
            MergeSort(origin, cache, low, pivot);
            MergeSort(origin, cache, pivot + 1, high);
            mergeTwoSortedArray(origin, cache, low, pivot, high);
	    }
	}



	//************
	// Heapsort  *
	//************

	void HeapSort(vector<int> &a, int n) {


		//***************************
		// implement heapsort here *
		//***************************

	}



	//************
	// Shellsort *
	//************
	void ShellSort(vector<int> &a, int n)
	{

		//***************************
		// implement shellsort here *
		//***************************


	}


  void randomizeVector(vector<int> &array, int n) {
    array.resize(n);

    for(unsigned int i=0;i<array.size();i++)
      array[i]=rand() % 1000000;
  }


}





