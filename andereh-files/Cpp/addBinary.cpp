#include <iostream>

using namespace std;

string addBinary(string a, string b) {
    int indx_a = a.length() - 1, indx_b = b.length() - 1;
    string res = "";
    int carry = 0;

    do {
        int sum = carry;

        if (indx_a >= 0) sum += a[indx_a] - '0';
        if (indx_b >= 0) sum += b[indx_b] - '0';

        carry = sum / 2;
        res.insert(res.begin(), (sum % 2) + '0');

        indx_a--;
        indx_b--;

    } while (indx_a >= 0 || indx_b >= 0);

    if (carry != 0) res.insert(res.begin(), carry + '0');

    return res;
}

int main(int argc, char *argv[]) {
    string test = addBinary("1", "1");
    cout << test << '\n';
    return 0;
}

