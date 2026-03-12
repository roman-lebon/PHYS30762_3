#include <iostream>
#include "source.h"
#include "detector.h"
#include <cstdlib> 
#include <ctime>

int main() {

    srand(time(0)); // Ensures each run similuates a new measurement

    Source s1("Na-22", "2024-01-01", 1200, 1);

    Detector d1("Geiger", true, 0);

    int result = d1.detect(s1);
    std::cout << "\nSource:\n";
    s1.print_source();

    std::cout << "\nDetector:\n";
    d1.print_detector();

    std::cout << "\nCounts detected: " << result << "\n";

    return 0;
}