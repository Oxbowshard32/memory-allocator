#include <iostream>
#include <cstdint>
using namespace std;

int main() {
    int x = 99;
    int* p = &x;

    // Try these one at a time, predict the output before running
    cout << x << endl;       // what prints?
    cout << &x << endl;      // what prints?
    cout << p << endl;       // what prints?
    cout << *p << endl;      // what prints?
}