#include <omp.h>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    omp_set_num_threads(3);
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 6; ++j) {
            #pragma omp critical
            {
                cout << i << " " << j << " hilo: "<< omp_get_thread_num() << endl; 
            }
        }
    }
    cout << "---\n";
    #pragma omp parallel for
    for (int ij = 0; ij < 3 * 6; ij++) {
        #pragma omp critical    
        {
            cout << ij / 6 << " " << ij % 6 << " hilo: "<< omp_get_thread_num() << endl; 
        }        
    }    
    return 0;
}