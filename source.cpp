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

// Getters
std::string Source::get_type() {
    return type;
}

std::string Source::get_date() {
    return date;
}

double Source::get_activity() {
    return activity;
}

int Source::get_id() {
    return id;
}

// Setters
void Source::set_type(std::string t) {
    type = t;
}

void Source::set_date(std::string d) {
    date = d;
}

void Source::set_activity(double a) {
    activity = a;
}

void Source::set_id(int i) {
    id = i;
}


