#include<bits/stdc++.h>
#include <immintrin.h>
#include <iomanip>
using namespace std;
using namespace chrono;

void printTaxicab(int N) {
	int i = 1, count = 0;
	while (count < N) {
	int int_count = 0;

	    for (int j = 1; j <= pow(i, 1.0/3); j++) 
		    for (int k = j + 1; k <= pow(i, 1.0/3); k++) 
			    if (j*j*j + k*k*k == i)
				    int_count++;
		
	    if (int_count == 2) {
		    count++;
		    cout << count << " " << i << endl; 
	    }

	    i++;
	}
}

void printTaxicabSimd(int N) {
    int count = 0;
    int i = 1;

    while (count < N) {
        __m256i cubeSumVector = _mm256_set_epi32(i + 7, i + 6, i + 5, i + 4, i + 3, i + 2, i + 1, i);
        __m256i cubeVector = _mm256_mullo_epi32(cubeSumVector, cubeSumVector * cubeSumVector);

        alignas(32) int results[8];
        _mm256_storeu_si256((__m256i*)results, cubeVector);

        for (int j = 0; j < 8; ++j) {
            int int_count = 0;
            int i_check = i + j;

            for (int k = 1; k * k * k <= i_check; ++k) {
                for (int l = k + 1; l * l * l <= i_check; ++l) {
                    if (k * k * k + l * l * l == i_check) {
                        int_count++;
                    }
                }
            }

            if (int_count == 2) {
                count++;
                std::cout << count << " " << i_check << std::endl;
            }
        }

        i += 8;
    }
}

int main() {
    int N = 20;

    auto startTaxicab = high_resolution_clock::now();
    cout << "Normal Taxicab Numbers Output: " << endl;
    printTaxicab(N);
    auto stopTaxicab = high_resolution_clock::now();
    auto durationTaxicab = duration_cast<microseconds>(stopTaxicab - startTaxicab);
    cout << "Time taken by Normal Taxicab Numbers function: " << durationTaxicab.count() / 1e6 << " seconds\n" << endl;

    auto startTaxicabSimd = high_resolution_clock::now();
    cout << "SIMD Taxicab Numbers Output: " << endl;
    printTaxicabSimd(N);
    auto stopTaxicabSimd = high_resolution_clock::now();
    auto durationTaxicabSimd = duration_cast<microseconds>(stopTaxicabSimd - startTaxicabSimd);
    cout << "Time taken by SIMD Taxicab Numbers function: " << durationTaxicabSimd.count() / 1e6 << " seconds" << endl;

    cout << "\nComparison Table:" << endl;
    cout << setw(15) << "Function" << setw(40) << "Execution Time (seconds)" << endl;
    cout << setw(14) << "Normal" << setw(25) << durationTaxicab.count() / 1e6 << " Seconds" << endl;
    cout << setw(13) << "SIMD" << setw(25) << durationTaxicabSimd.count() / 1e6 << " Seconds" << endl;

    return 0;
}
