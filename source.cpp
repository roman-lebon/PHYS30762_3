#include "source.h"
#include <iostream>

// Constructors
Source::Source() {
    
    type = "Unknown";
    date = "Unknown";
    activity = 0.0;
    id = 0;
}

Source::Source(std::string t, std::string d, double a, int i) {

    type = t;
    date = d;
    activity = a;
    id = i;
}

// Destructor 
Source::~Source() {}

// Print function
void Source::print_source() {

    std::cout << "Source information:" << "\n";
    std::cout << "Type: " << type << "\n";
    std::cout << "Date: " << date << "\n";
    std::cout << "Activity: " << activity << "\n";
    std::cout << "Source ID: " << id << "\n";

}

