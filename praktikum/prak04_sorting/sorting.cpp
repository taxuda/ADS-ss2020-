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
	void Merge(vector<int> &a, vector<int> &b, int low, int pivot, int high) {

	}

	void MergeSort(vector<int> &a, vector<int> &b, int low, int high) {
	    if(low < high){
	        int pivot = low + (low + high) / 2;
            MergeSort(a, b, low, pivot);
            MergeSort(a, b, pivot + 1, high);
            Merge(a, b, low, pivot, high);
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





