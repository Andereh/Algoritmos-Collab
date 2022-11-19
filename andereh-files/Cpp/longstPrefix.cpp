#include <iostream>
#include <vector>

// time: 19"31'
// programa para encontrar todas las letras en comun al principio de un vector
// de palabras

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    string prefix = "";

    int len = INT32_MAX;

    // obtenemos la longitud mas chica de las palabras en el vector
    for (int i = 0; i < strs.size(); ++i)
        if (strs[i].length() < len) len = strs[i].length();

    for (int letter = 0; letter < len; ++letter) {
        char ch = strs[0][letter];
        for (int word = 1; word < strs.size(); ++word) {
            if (strs[word][letter] != ch)
                return prefix;  // Si encontramos una letra distinta ya no hay
                                // mas letras en comun
        }
        prefix += ch;
    }

    return prefix;
}

int main(int argc, char* argv[]) {
    vector<string> strings1 = {"flowers", "flow", "flight"};
    // "fl". Esta cadena se encuentra al principio de todas las palabras
    vector<string> strings2 = {"racecar", "car", "dog"};
    // "". No existe ninguna letra en comun

    cout << longestCommonPrefix(strings2);
    return 0;
}

