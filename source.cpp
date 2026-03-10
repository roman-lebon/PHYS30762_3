#include "source.h"
#include <iostream>

// Default constructor 
Source::Source() {
    
    type = "Unknown";
    date = "Unknown";
    activity = 0.0;
    id = 0;
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

