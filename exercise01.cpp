// File: exercise01.cpp
// Author(s):Julio David Resendiz Cruz - A01709375, Carlos Hernández Arciniega - A01709003
// Description: This file contains the code to count the number of
//				even numbers within an array using the OpenMP 
//				technology. To compile:
//				g++ -o app -fopenmp exercise01.cpp
//
// =================================================================
// =================================================================
//
// Tiempo secuencial: 822.425 ms
// Tiempo paralelo: 201.369 ms 
// Speedup: 4.084
//
// =================================================================

#include <iostream>
#include <iomanip>
#include <chrono>
#include <omp.h>
#include "utils.h"

using namespace std;
using namespace std::chrono;

// array size
#define SIZE 500000000

long long SumaPares(int* arreglo, int tamano) {
    long long sumatoria = 0;

    #pragma omp parallel for reduction(+:sumatoria)
    for (int i = 0; i < tamano; i++) {
        if (arreglo[i] % 2 == 0) {
            sumatoria += arreglo[i];
        }
    }

    return sumatoria;
}

int main(int argc, char* argv[]) {
	int *array;
	long long result;
	// These variables are used to keep track of the execution time.
	high_resolution_clock::time_point start, end;
	double timeElapsed;

	array = new int[SIZE];
	fill_array(array, SIZE);
	display_array("array", array);

	cout << "Starting...\n";
	timeElapsed = 0;
	for (int j = 0; j < N; j++) {
		start = high_resolution_clock::now();

		result=SumaPares(array, SIZE);

		end = high_resolution_clock::now();
		timeElapsed += 
			duration<double, std::milli>(end - start).count();
	}
	cout << "result = " << result << "\n";
	cout << "avg time = " << fixed << setprecision(3) 
		 << (timeElapsed / N) <<  " ms\n";

	delete [] array;
	return 0;
}
