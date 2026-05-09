#include <iostream>
#include <cstdint>
using namespace std;

int main() {
    uint8_t buffer[64] = {0};
    uint8_t* ptr = buffer;

    // TODO 1: Print the address of buffer[0]
    cout << (void*)ptr << endl;
    // TODO 2: Print the address of buffer[16]
    cout << (void*)(ptr + 16) << endl;
    // TODO 3: Calculate the difference between them (should be 16)
    cout << (ptr + 16) - ptr << endl;
    
    /* More proper
    cppptrdiff_t diff = (uint8_t*)(ptr + 16) - ptr;
    cout << diff << endl;
    */

    // TODO 4: Write the integer value 1234 starting at byte offset 8
    int* as_intSpot8 = (int*)(ptr + 8);
    *as_intSpot8 = 1234;
    // TODO 5: Read it back and print it
    cout << *as_intSpot8 << endl;
}