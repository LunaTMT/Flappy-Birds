// utilities.cpp
#include "utilities.h"
//#include "globals.h"  // Include any headers that define global constants if needed
#include <random>

int getRandomInt(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distribution(min, max);

    return distribution(gen);
}
