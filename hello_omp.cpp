#include <iostream>
#include <omp.h>

using namespace std;

int main() {
    omp_set_num_threads(4);
    //cout << omp_get_num_threads();
    //cout << omp_get_max_threads();
    int thread_id = 0;
    int num_threads = 0;
    double start = 0, end = 0;
    start = omp_get_wtime();
    long long int i = 0; 

    const int SIZE = 100;
    int* a = new int[SIZE];
    int* b = new int[SIZE];
    int* c = new int[SIZE];

    for (i = 0; i < SIZE; i++){
        a[i] = b[i] = c[i] = 1; 
    }
    #pragma omp parallel shared(num_threads, i, a, b, c, SIZE) private(thread_id) 
    {
        thread_id = omp_get_thread_num();
        #pragma omp for schedule(static, 25)
        for (i = 0; i < SIZE; i++) {
            c[i] = a[i] + b[i];
            cout << "Hilo " << thread_id << " ejecuta " << i << "\n";  
        }
    }
    end = omp_get_wtime();
    cout << end - start;
    for (i = 0; i < SIZE; i++) {
        cout << c[i] << "\n"; 
    }
    
    delete[] a;
    delete[] b;
    delete[] c;
    return 0;
}
