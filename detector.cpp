#include "detector.h"
#include <iostream>
#include <cstdlib>
#include <vector>

// Vector containing allowed detectors
const std::vector<std::string> valid_detectors {
    "Scintillator",
    "Geiger",
    "Germanium_detector",
    "Silicon_detector",
    "Proportional_counter",
    "Ionisation_chamber"
};

// Constructors
Detector::Detector() {

    type = "Unknown";
    status = false; // Detector turned off by default
    counts = 0;
}

Detector::Detector(std::string t, bool s) {

    set_type(t);
    set_status(s);
    counts = 0;
}

// Destructor 
Detector::~Detector() {}

// Print function
void Detector::print_detector() {

    std::cout << "Detector Information:\n";
    std::cout << "Type: " << type << "\n";
    std::cout << "Status: " << (status ? "ON" : "OFF")  << "\n"; // Ternary operator outputs "ON"/"OFF" if status is true/false
    std::cout << "Counts: " << counts;
}

// Getters
std::string Detector::get_type() {
    return type;
}

bool Detector::get_status() {
    return status;
}

int Detector::get_counts() {
    return counts;
}

// Setters
void Detector::set_type(std::string t) {
    
    // Validation loop checks if detectors are in the accepted list
    for (const std::string& d : valid_detectors) {
        if (d == t) {
            type = t;
            return;
        }
    }
    
    // Program exits if not 
    std::cout << "\n-> Invalid detector type: " << t << ". Please check config file.\n";
    exit(1);
}

void Detector::set_status(bool s) {
    status = s;
}

int Detector::detect(const Source& s) {

    if (!status) {
        return 0;
    }

    counts = rand() % 1000;
    return counts;
}