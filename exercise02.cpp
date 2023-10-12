// =================================================================
// File: exercise02.cpp
// Author(s): Julio David Resendiz Cruz - A01709375, Carlos Hernández Arciniega - A01709003
// Description: This file contains the code to brute-force all
//				prime numbers less than MAXIMUM using the OpenMP 
//				technology. To compile:
//				g++ -o app -fopenmp exercise02.cpp
//
// Copyright (c) 2023 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
//
// =================================================================
// =================================================================
//
// Tiempo secuencial: 2412.102 ms
// Tiempo paralelo: 323.562 ms 
// Speedup: 7.454
//
// =================================================================

#include <iostream>
#include <iomanip>
#include <chrono>
#include <omp.h>
#include "utils.h"

using namespace std;
using namespace std::chrono;

#define MAXIMUM 5000000 //5e6

bool VerificarSiEsPrimo(int num) {
    if (num < 2)
        return false;

    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0)
            return false;
    }

    return true;
}

long long sumaPrimos(int maxNumero) {
    long long suma = 0;

#pragma omp parallel for reduction(+:suma)
    for (int i = 2; i <= maxNumero; ++i) {
        if (VerificarSiEsPrimo(i)) {
            suma += i;
        }
    }

    return suma;
}

int main(int argc, char* argv[]) {
	 long long result;
	// These variables are used to keep track of the execution time.
	high_resolution_clock::time_point start, end;
	double timeElapsed;

	cout << "Starting...\n";
	timeElapsed = 0;
	for (int j = 0; j < N; j++) {
		start = high_resolution_clock::now();

		result=sumaPrimos(MAXIMUM);

		end = high_resolution_clock::now();
		timeElapsed += 
			duration<double, std::milli>(end - start).count();
	}
	cout << "result = " << result << "\n";
	cout << "avg time = " << fixed << setprecision(3) 
		 << (timeElapsed / N) <<  " ms\n";

	return 0;
}
