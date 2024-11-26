#include <iostream>
using namespace std;
struct ASC {
    bool operator()(int a, int b) const {
        return a < b;
    }
};
template <class T>
struct Pivot {
    int pivot;
    T asc;

    Pivot(int pivot) : pivot(pivot) {}

    void operator()(int* ini, int* fin) {

        for (int* it = ini; it <= fin; ) {
            if (asc(*it, pivot)) {
                swap(*it, *ini);
                ++ini;
                ++it;
            }
            else if (!asc(*it, pivot) && *it != pivot) {
                swap(*it, *fin);
                --fin;
            }
            else {
                ++it;
            }
        }

    }
};
int main() {
    int arr[] = { 1, 13, 20, 15, 3, 5, 30, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);

    Pivot<ASC> inst(15);

    inst(arr, arr + n - 1);

    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
}

