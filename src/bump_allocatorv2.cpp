#include <iostream>
#include <cstdint>
#include <cstddef>
using namespace std;

// Rounds size up to nearest multiple of 8
// You don't need to modify this
size_t align8(size_t size) {
    return (size + 7) & ~7;
}

class BumpAllocator {
public:
    // TODO 1: Define two member variables
    //         - a uint8_t array called 'buffer' of size 256
    //         - a size_t called 'offset' initialized to 0

    BumpAllocator() {
        // TODO 2: Set offset to 0
    }

    void* allocate(size_t size) {
        // TODO 3: Align the size using align8()

        // TODO 4: Check if there's enough space left
        //         (offset + aligned size should not exceed 256)
        //         If not enough space, print "Out of memory!" and return nullptr

        // TODO 5: Get a pointer to the current position in the buffer
        //         (hint: buffer + offset)

        // TODO 6: Advance offset by the aligned size

        // TODO 7: Return the pointer from TODO 5
    }

    void reset() {
        // TODO 8: Set offset back to 0
    }

    size_t used() {
        // TODO 9: Return offset (how many bytes have been used)
    }
};

int main() {
    BumpAllocator allocator;

    // Allocate an int
    void* a = allocator.allocate(sizeof(int));
    // Write 42 into it
    *(int*)a = 42;

    // Allocate a char
    void* b = allocator.allocate(sizeof(char));
    // Write 'Z' into it
    *(char*)b = 'Z';

    // Print results
    cout << "Int value: " << *(int*)a << endl;
    cout << "Char value: " << *(char*)b << endl;
    cout << "Bytes used: " << allocator.used() << endl;

    // Reset and verify
    allocator.reset();
    cout << "After reset, bytes used: " << allocator.used() << endl;
}