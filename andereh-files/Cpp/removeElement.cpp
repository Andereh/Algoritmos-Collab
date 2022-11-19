#include <iostream>
#include <vector>

// time: 26"28
// programa para "eliminar" un elemento (y todas sus apariciones) de una lista,
// como en C++ no se pueden alterar las listas, pasamos los elementos a eliminar
// hacia el final. La funcion retorna el numero de elementos hasta encontrar el
// valor a eliminar

using namespace std;

int removeElement(vector<int>& nums, int val) {
    int k = nums.size() - 1;

    bool is_clear = false;
    while (!is_clear) {
        for (int i = 0; i < k; ++i) {
            if (nums[i] == val) {
                if (nums[k] == val) k--;
                int aux = nums[i];
                nums[i] = nums[k];
                nums[k] = aux;
                k--;
            }
        }

        is_clear = true;
        for (int i = 0; i < k; ++i)
            if (nums[i] == val) is_clear = false;
    }

    k = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != val) k++;
    }
    return k;
}

int main(int argc, char* argv[]) {
    vector<int> nums = {3, 2, 2, 3, 1, 2, 3, 5};
    vector<int> nums2 = {1};

    cout << removeElement(nums2, 1) << ": ";

    for (int i = 0; i < nums2.size(); ++i) {
        cout << nums2[i] << ' ';
    }
    return 0;
}

