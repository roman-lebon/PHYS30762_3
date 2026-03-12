#include "source.h"
#include <iostream>
#include <cstdlib>
#include <vector>

// Vector containing allowed sources
const std::vector<std::string> valid_sources {
    // Assignment required sources
    "Na-22",
    "Cs-136",
    "Co-92",
    // Naturally-occurring sources
    "C-14",
    "Cl-36",
    "Pb-210",
    "H-3",
    // Artificially-produced sources
    "Am-241",
    "Cs-137",
    "Cr-51",
    "Co-60",
    "La-140",
    "Sc-46",
    "Ag-110m",
    "Tc-99m",
    "Ir-192",
    "Kr-85",
    "Mn-54",
    "Ni-63",
    "Se-75",
    "Sr-90",
    "Tl-204",
    "Yb-169",
    "Zn-65"
};

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

    std::cout << "Source information:\n";
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

    // Validation loop checks if sources are in the accepted list
     for (const std::string& s : valid_sources) {
        if (s == t) {
            type = t;
            return;
        }
    }
    
    // Program exits if not 
    std::cout << "-> Invalid source type: " << t << ". Please check config file.";
    exit(1);
}

void Source::set_date(std::string d) {
    // Validates a date exists
    if (d.empty()) {
        std::cout << "-> Invalid date, must not be empty. Please check config file.";
        exit(1);
    }

    date = d;
}

void Source::set_activity(double a) {
    // Validates activity is non-negative 
    if (a < 0) {
        std::cout <<"\n-> Invalid activity, must be >= 0. Please check config file.";
        exit(1);
    }

    activity = a;
}

void Source::set_id(int i) {
    // Validates ID is non-negative
    if (i < 0) {
        std::cout <<"-> Invalid ID, must be >= 0. Please check config file.";
        exit(1);
    }

    id = i;
}


