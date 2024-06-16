#include <utils.h>

uint16_t rotateLeft(uint16_t value, unsigned int rotation) {
    rotation %= 16; // Ensure rotation is within 0-15
    return (value << rotation) | (value >> (16 - rotation));
}

// Function to rotate a 16-bit unsigned integer right
uint16_t rotateRight(uint16_t value, unsigned int rotation) {
    rotation %= 16; // Ensure rotation is within 0-15
    return (value >> rotation) | (value << (16 - rotation));
}