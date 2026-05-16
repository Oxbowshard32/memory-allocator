#include <iostream>
#include <cstdint>
using namespace std;

// To run type ./block

/**
    The analogy for this file is a parking lot. The Buffer is the parking lot, and the Block Headers
    are the parking spaces (The chalk that marks the parking spot). 
    Each Block Header contains information about the size of the parking space,
    whether it's free or not, and a pointer to the next parking space. When we allocate
    memory, we look for a free parking space that can fit our car (the requested size). 
    If we find one, we mark it as occupied and return a pointer to that space.
    When we free memory, we mark the corresponding parking space as free again.
*/

// This struct represents the header of a memory block in a custom allocator.
// It contains the size of the block, whether it's free or not, and a pointer to the next block.
struct BlockHeader {
    size_t size;
    bool is_free;
    BlockHeader* next;
};

int main() {
    uint8_t buffer[256] = {0};

    // Stamp a BlockHeader at the  start of the buffer
    BlockHeader* header = (BlockHeader*)buffer;

    // Write to its fields
    header->size = 32;
    header->is_free = true;
    header->next = nullptr;

    // Read them back
    cout << "Size: " << header->size << endl;
    cout << "Is free: " << header->is_free << endl;
    cout << "Next: " << header->next << endl;

    // How many bytes did the header take up?
    cout << "Header size: " << sizeof(BlockHeader) << endl;
}