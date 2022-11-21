#include <iostream>
#include <vector>

using namespace std;

// time: 18"59'
// dado un entero representado como una arreglo (123 = {1, 2, 3}) retornar un
// arreglo quivalente al entero inicial + 1
//
// Ej1. Entrada: {1, 2, 3}
//      proceso: 123 + 1 = 124.
//      Salida esperada {1, 2, 4}
//
// Ej2. Entrada: {9, 9}
//      proceso: 99 + 1 = 100.
//      Salida esperada {1, 0, 0}

vector<int> plusOne(vector<int>& digits) {
    int carry = 1, i = digits.size() - 1;

    do {
        int sum = digits[i] + carry;

        carry = (sum) / 10;
        digits[i] = (sum) % 10;

        i--;
    } while (carry != 0 && i >= 0);

    if (carry != 0) digits.insert(digits.begin(), carry);

    return digits;
}

int main(int argc, char* argv[]) {
    vector<int> nums = {9, 9};

    vector<int> result = plusOne(nums);

    for (int i : result) cout << i << " ";

    cout << '\n';

    return 0;
}

