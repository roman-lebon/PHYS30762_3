#include "source.h"
#include <iostream>
#include <cstdlib>

// Constructors
Source::Source() {
    
    type = "Unknown";
    date = "Unknown";
    activity = 0.0;
    id = 0;
}

Source::Source(std::string t, std::string d, double a, int i) {

    set_type(t);
    set_date(d);
    set_activity(a);
    set_id(i);
}

// Destructor 
Source::~Source() {}

// Print function
void Source::print_source() {

    std::cout << "Source information:" << "\n";
    std::cout << "Type: " << type << "\n";
    std::cout << "Date: " << date << "\n";
    std::cout << "Activity: " << activity << " Bq/kg\n";
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

    if (t != "Na-22" && t != "Cs-136" && t!= "Co-92") {
        std::cout << "\n-> Invalid input. Enter a valid source type\n";
        exit(1);
    }

    type = t;
}

void Source::set_date(std::string d) {
    date = d;
}

void Source::set_activity(double a) {

    if (a < 0) {
        std::cout <<"\n-> Invalid input. Activity must be >= 0\n";
        exit(1);
    }

    activity = a;
}

void Source::set_id(int i) {

    if (i < 0) {
        std::cout <<"\n-> Invalid input. ID must be >= 0\n";
        exit(1);
    }

    id = i;
}


