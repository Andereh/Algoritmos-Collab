#include <iostream>

using namespace std;

// time: 7"35'
// programa para retornar la longitud de la ultima palabra en una cadena

int lengthOfLastWord(string s) {
    int count = 0;
    int i = s.length() - 1;

    while (i >= 0) {
        if (s[i] == ' ' && count > 0) return count;
        if (s[i] != ' ') count++;
        i--;
    }

    return count;
}

int main(int argc, char *argv[]) {
    string test = "  io                   ";

    cout << lengthOfLastWord(test) << '\n';
    return 0;
}

