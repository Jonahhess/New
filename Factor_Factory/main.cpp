#include <iostream>
#include <fstream>
const int N = 10000;

    // Algorithm layed out here: https://www.youtube.com/watch?v=iJ8pnCO0nTY&ab_channel=Mathologer
    // Implemented by: Jonah Hess

void MakeSpaces(long long spaces[N]) {
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            spaces[i] = i+1;
        } 
        else {
            spaces[i] = i/2+1;
        }
    }
}

void MakeArr(long long spaces[N], long long arr[N]) {
    arr[0] = 1;
    for (int i = 0; i < N-1; i++) {
        arr[i+1] = arr[i] + spaces[i+1];
    }
}

void MakeSequence(long long arr[N],long long sequence[N]) {
    int sign,sum,j;
    sequence[0] = 1;

    for (int i = 1; i < N; i++) {
        sum = 0; j = 0; sign = 1;

        while (arr[j] <= i) {
            sum += sign * sequence[i-arr[j]];
            j++;
            if (j % 2 == 0) {
                sign *= -1;
            }
        }
        
        sequence[0] += 1; /* comment out for the regular series */
        sequence[i] = sum;
    }
}


int main() {
    long long spaces[N], arr[N], sequence[N];
    MakeSpaces(spaces);
    MakeArr(spaces,arr);
    MakeSequence(arr,sequence);
    std::ofstream primes("primes.txt");

    for (int i = 0; i < N; i++) {
        sequence[i] -= i;

        if (sequence[i] == 1) {
            std::cout << i << ' ';
            primes << i << '/n';
        }
    }
    system("pause");
    return 0;
}

/* regular series (comment out line 41):
1 1 2 3 5 7 11 15 22 30 42 56 77 101 135 176 231 297 385 490 627 792 1002 
1255 1575 1958 2436 3010 3718 4565 5604 6842 8349 10143 12310 14883 17977 
21637 26015 31185 37338 44583 53174 63261 75175 89134 105558 124754 147273 
173525 204226 239943 281589 329931 386155 451276 526823 614154 715220 
831820 966467 1121505 1300156 1505499 1741630 2012558 2323520 2679689 
3087735 3554345 4087968 4697205 5392783 6185689 7089500 8118264 9289091 
10619863 12132164 13848650 15796476 18004327 20506255 23338469 26543660 
30167357 34262962 38887673 44108109 49995925 56634173 64112359 72533807 
82010177 92669720 104651419 118114304 133230930 150198136 169229875

sum of prime factors series (ignore first entry):
100 1 3 4 7 6 12 8 15 13 18 12 28 14 24 24 31 18 39 20 42 32 36 24 60 31 42 40 56 
30 72 32 63 48 54 48 91 38 60 56 90 42 96 44 84 78 72 48 124 57 93 72 98 54 120 
72 120 80 90 60 168 62 96 104 127 84 144 68 126 96 144 72 195 74 114 124 140 96 
168 80 186 121 126 84 224 108 132 120 180 90 234 112 168 128 144 120 252 98 171 156

finding primes (until 100):
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97
*/