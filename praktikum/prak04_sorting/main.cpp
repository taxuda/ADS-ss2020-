#define CATCH_CONFIG_RUNNER
#include "catch.h"

#include <iostream>
//#include "/usr/local/Cellar/libomp/12.0.0/include/omp.h"
#include "/usr/local/opt/libomp/include/omp.h"

#include "sorting.h"
#include "hashtable.h"

using namespace std;

//benchmark functions
void benchmark_quicksort();
void benchmark_mergesort();
void benchmark_shellsort();
void benchmark_heapsort();


int main(int argc, char** argv) {

  Catch::Session().run();
  std::cin.get();

  HashTable mytable{1000};
  int size = 200;
  int lowerBound = 1000;
  for(int i = 0; i < size; i++){
      int item = lowerBound + rand() % 501;
      mytable.insert(item);
  }
  cout << "Quantity of collisions: " << mytable.getCollisionCount() << endl;

  //benchmark_quicksort();
  //benchmark_heapsort();
  //benchmark_mergesort();
  benchmark_shellsort();

  return 0;
}




//executes benchmark for quicksort
void benchmark_quicksort() {

  //file stream
  ofstream quicksort_measurement;
  quicksort_measurement.open("/Users/dattran/Desktop/projects/ads(ss2020)/praktikum/prak04_sorting/quicksort.txt", ios::out | ios::app);

  //benchmark parameters / variables
  double dtime;
  int n_start = 1000;
  int n_step = 1000;
  int n_end = 1000000;

  vector<int> V;

  //actual benchmark loop
  for (int n = n_start; n<=n_end; n += n_step) {
	
	//"progress bar"
    std::cout << "Running Quicksort with n: " << n << std::endl;

	//generate n random integers
	sorting::randomizeVector(V, n);

	//start measurement
    dtime = omp_get_wtime();
    
	//execzute sorting algorithm
    sorting::QuickSort(V,0,V.size()-1);

	//stop time
    dtime = omp_get_wtime() - dtime;

	//write to file
    quicksort_measurement << n << "\t" << setprecision(10) << scientific << dtime << endl;
  }

  //close file handle
  quicksort_measurement.close();
}

//executes benchmark for mergesort
void benchmark_mergesort() {

    //file stream
    ofstream mergesort_measurement;
    mergesort_measurement.open("/Users/dattran/Desktop/projects/ads(ss2020)/praktikum/prak04_sorting/gnuplot_time_measurement/mergesort.txt", ios::out | ios::app);

    //benchmark parameters / variables
    double dtime;
    int n_start = 1000;
    int n_step = 1000;
    int n_end = 1000000;

    vector<int> V;

    //actual benchmark loop
    for (int n = n_start; n<=n_end; n += n_step) {

        //"progress bar"
        std::cout << "Running Mergesort with n: " << n << std::endl;

        //generate n random integers
        sorting::randomizeVector(V, n);
        vector<int> cache(n, 0);
        //start measurement
        dtime = omp_get_wtime();

        //execute sorting algorithm
        sorting::MergeSort(V,cache, 0,V.size()-1);

        //stop time
        dtime = omp_get_wtime() - dtime;

        //write to file
        mergesort_measurement << n << "\t" << setprecision(10) << scientific << dtime << endl;
    }

    //close file handle
    mergesort_measurement.close();
}

//executes benchmark for shellsort
void benchmark_shellsort() {

    //file stream
    ofstream shellsort_measurement;
    shellsort_measurement.open("/Users/dattran/Desktop/projects/ads(ss2020)/praktikum/prak04_sorting/gnuplot_time_measurement/shellsort.txt", ios::out | ios::app);

    //benchmark parameters / variables
    double dtime;
    int n_start = 1000;
    int n_step = 1000;
    int n_end = 1000000;

    vector<int> V;

    //actual benchmark loop
    for (int n = n_start; n<=n_end; n += n_step) {

        //"progress bar"
        std::cout << "Running Shellsort with n: " << n << std::endl;

        //generate n random integers
        sorting::randomizeVector(V, n);

        //start measurement
        dtime = omp_get_wtime();

        //execzute sorting algorithm
        sorting::ShellSort(V, V.size());

        //stop time
        dtime = omp_get_wtime() - dtime;

        //write to file
        shellsort_measurement << n << "\t" << setprecision(10) << scientific << dtime << endl;
    }

    //close file handle
    shellsort_measurement.close();
}

//executes benchmark for heapsort
void benchmark_heapsort() {

    //file stream
    ofstream heapsort_measurement;
    heapsort_measurement.open("/Users/dattran/Desktop/projects/ads(ss2020)/praktikum/prak04_sorting/gnuplot_time_measurement/heapsort.txt", ios::out | ios::app);

    //benchmark parameters / variables
    double dtime;
    int n_start = 1000;
    int n_step = 1000;
    int n_end = 1000000;

    vector<int> V;

    //actual benchmark loop
    for (int n = n_start; n<=n_end; n += n_step) {

        //"progress bar"
        std::cout << "Running Heapsort with n: " << n << std::endl;

        //generate n random integers
        sorting::randomizeVector(V, n);

        //start measurement
        dtime = omp_get_wtime();

        //execzute sorting algorithm
        sorting::HeapSort(V,V.size());

        //stop time
        dtime = omp_get_wtime() - dtime;

        //write to file
        heapsort_measurement << n << "\t" << setprecision(10) << scientific << dtime << endl;
    }

    //close file handle
    heapsort_measurement.close();
}