#include <iostream>
#include "source.h"
#include "detector.h"
#include <cstdlib> 
#include <ctime>

int main() {

    srand(time(0)); // Ensures each run similuates a new measurement

    Source s1("Na-22", "2024-01-01", 1200, 1);
    Source s2("Cs-137", "2023-05-10", 900, 2);
    Source s3("Ir-192", "2022-11-03", 500, 3);
    Source s7("Co-60", "2024-01-01", 0, 7);

    s1.print_source();
    s2.print_source();
    s3.print_source();
    s7.print_source();

    return 0;
}