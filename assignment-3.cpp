#include <iostream>
#include "source.h"

int main() {

    Source s1;

    s1.set_type("Na-22");
    s1.set_date("2026-01-01");
    s1.set_activity(1200);
    s1.set_id(1);

    s1.print_source();
    
    return 0;
}