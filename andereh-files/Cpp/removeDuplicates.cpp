#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

// time: 26"28
// programa para "eliminar" un elemento (y todas sus apariciones) de una lista,
// como en C++ no se pueden alterar las listas, pasamos los elementos a eliminar
// hacia el final. La funcion retorna el numero de elementos hasta encontrar el
// valor a eliminar

using namespace std;

int removeElement(vector<int>& nums) {
    unordered_map<int, int> appears;

    for (int i = 0; i < nums.size(); ++i) appears[nums[i]]++;

    int k = 0;
    for (auto kv : appears) {
        nums[k] = kv.first;
        k++;
    }

    // sort(&nums[0], &nums[k]);
    return k;
}

int main(int argc, char* argv[]) {
    vector<int> nums = {0, 0, 1, 1, 2, 2, 3, 3, 4};
    vector<int> nums2 = {};

    cout << removeElement(nums) << ": ";

    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << ' ';
    }
    return 0;
}

