// File: exercise03.cpp
// Author(s): Julio David Resendiz Cruz - A01709375, Carlos Hernández Arciniega - A01709003
// Description: This file contains the code that implements the
//				enumeration sort algorithm using the OpenMP 
//				technology. To compile:
//				g++ -o app -fopenmp exercise03.cpp
//
// Copyright (c) 2024 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
//
// =================================================================
// =================================================================
//
// Tiempo secuencial: 62.635 ms
// Tiempo paralelo: 44.728 ms
// Speedup: 1.4
//
// =================================================================

#include <iostream>
#include <iomanip>
#include <chrono>
#include <cstring>
#include "utils.h"

using namespace std;
using namespace std::chrono;

#define SIZE 10000

void MetodoenumerationSort(int arr[], int size) {
    // Implementación del método de enumeración (enumeration sort)
    #pragma omp parallel for
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                std::swap(arr[i], arr[j]);
            }
        }
    }
}

int main(int argc, char* argv[]) {
	int *origin, *copy, result;
	// These variables are used to keep track of the execution time.
	high_resolution_clock::time_point start, end;
	double timeElapsed;

	origin = new int[SIZE];
	random_array(origin, SIZE);
	display_array("before", origin);

	copy = new int[SIZE];

	cout << "Starting...\n";
	timeElapsed = 0;
	for (int j = 0; j < N; j++) {
		memcpy(copy, origin, SIZE * sizeof(int));

		start = high_resolution_clock::now();

	   MetodoenumerationSort(copy, SIZE);

		end = high_resolution_clock::now();
		timeElapsed += 
			duration<double, std::milli>(end - start).count();
	}
	display_array("after", copy);
	cout << "avg time = " << fixed << setprecision(3) 
		 << (timeElapsed / N) <<  " ms\n";

	delete [] origin;
	delete [] copy;
	
	return 0;
}
