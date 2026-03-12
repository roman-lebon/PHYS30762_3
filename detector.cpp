#include "detector.h"
#include <iostream>
#include <cstdlib>

// Constructors
Detector::Detector() {

    type = "Unknown";
    status = false; // Detector turned off by default
    counts = 0;
}

Detector::Detector(std::string t, bool s, int c) {

    set_type(t);
    set_status(s);
    counts = c;
}

// Destructor 
Detector::~Detector() {}

// Print function
void Detector::print_detector() {

    std::cout << "Detector Information:\n";
    std::cout << "Type: " << type << "\n";
    std::cout << "Status: " << (status ? "ON" : "OFF")  << "\n"; // Ternary operator outputs "ON"/"OFF" if status is true/false
    std::cout << "Counts: " << counts << "\n";
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
    type = t;
}

void Detector::set_status(bool s) {
    status = s;
}

int Detector::detect(Source s) {

    if (!status) {
        std::cout << "\n-> Detector is OFF, Unable to measure source.\n";
        return 0;
    }

    counts = rand() % 100;
    return counts;
}