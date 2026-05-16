#include <iostream>
#include <cstdint>
#include <cstddef>
using namespace std;

// run ./bump in cl to test

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
    uint8_t buffer[256] ={0};
    size_t offset = 0;
    
    BumpAllocator() {
        // TODO 2: Set offset to 0
        offset = 0;
    }

    void* allocate(size_t size) {
        // TODO 3: Align the size using align8()
        size_t aligned_size = align8(size);
        // TODO 4: Check if there's enough space left
        //         (offset + aligned size should not exceed 256)
        //         If not enough space, print "Out of memory!" and return nullptr
        if (offset + aligned_size > 256) {
            cout << "Out of memory" << endl;
            return nullptr;
        }
        // TODO 5: Get a pointer to the current position in the buffer
        //         (hint: buffer + offset)
        uint8_t* ptr = buffer + offset;
        // TODO 6: Advance offset by the aligned size
        offset = offset + aligned_size;

        // TODO 7: Return the pointer from TODO 5
        return ptr;
    }

    void reset() {
        // TODO 8: Set offset back to 0
        offset = 0;
    }

    size_t used() {
        // TODO 9: Return offset (how many bytes have been used)
        return offset;
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