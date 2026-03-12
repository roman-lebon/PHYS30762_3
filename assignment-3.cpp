#include <iostream>
#include "source.h"
#include "detector.h"
#include <cstdlib> 
#include <ctime>

int main() {

    srand(time(0)); // Ensures each run similuates a new measurement

    Source s1("Cs-137", "2024-01-01", 50.0, 1);
    Detector d1("Geiger", true);

    d1.detect(s1);   // run detection

    s1.print_source();
    d1.print_detector();

    return 0;
}