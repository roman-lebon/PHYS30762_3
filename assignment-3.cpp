#include <iostream>
#include "source.h"
#include "detector.h"
#include <cstdlib> 
#include <ctime>
#include <fstream>
#include <sstream>
#include <vector>

// Function to validate date
bool valid_date(const std::string& date) {
    std::stringstream ss(date);
    int year;
    int month;
    int day;
    char dash_1;
    char dash_2;

    if (!(ss >> year >> dash_1 >> month >> dash_2 >> day)) {
        return false;
    }

    if (dash_1 != '-' || dash_2 != '-') {
        return false;
    }
    
    if (month < 1 || month > 12) {
        return false;
    }

    const int days_in_month[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int max_days = days_in_month[month -1];
    bool is_leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    if (month == 2 && is_leap) {
        max_days += 1;
    }

    if (day < 1 || day > max_days) {
        return false;
    }

    return true;
}     

int main() {

    srand(time(0)); // Ensures each run similuates a new measurement

    // Vectors to store all info read from config file 
    std::vector<Source> sources;
    std::vector<Detector> detectors;

    // Open config file and validate successful open
    std::ifstream file("config.txt");

    if (!file) {
        std::cout << "-> Error: Could not open config file.";
        return 1;
    }

    std::string line;

    // Read config file line by line
    while (std::getline(file, line)) {

        if (line.empty()) { // Allows for whitespace lines in config
            continue;
        }

        std::stringstream ss(line); // Stringstream allows for easy extract of values from each line
        
        std::string tag;
        ss >> tag; // First word tells us which object to create

        // Extract values according to which object they refer to
        if (tag == "SOURCE") {
            std::string type;
            std::string date;
            double activity;
            int id;

            // Validate SOURCE data input
            if (!(ss >> type >> date >> activity >> id)) {
                std::cout << "-> Invalid SOURCE format. Please check config file.";
                return 1;
            }

            // Check for any extra input
            std::string extra;
            if (ss >> extra) {
                std::cout << "-> Unexpected data in SOURCE line: " << extra;
                return 1;
            }

            // Validate date
            if (!valid_date(date)) {
                std::cout << "-> Invalid date format in config file: " << date << ". Requires a valid date, in the format: YYYY-MM-DD.";
                return 1;
            }

            // Ensure source ID is unique
            for (const Source& s : sources) {
                if (s.get_id() == id) {
                    std::cout << "-> Duplicate source ID: " << id << ". IDs must be unique.";
                    return 1;
                }
            }

            sources.emplace_back(type, date, activity, id); // Creates a Source object and stores in source vector
        }

        else if (tag == "DETECTOR") {
            std::string type;
            int status;

            if (!(ss >> type >> status)) {
                std::cout << "-> Invalid DETECTOR format. Please check config file.";
                return 1;
            }

            std::string extra;
            if (ss >> extra) {
                std::cout << "-> Unexpected data in DETECTOR line: " << extra;
                return 1;
            }

            if (status != 0 && status != 1) {
                std::cout << "-> Invalid detector status: " << status << ". Must be 0 (OFF) or 1 (ON).";
                return 1;
            }

            detectors.emplace_back(type, status);
        }

        else {
            std::cout << "-> Unknown config entry: " << tag << ". Must be either SOURCE or DETECTOR.";
            return 1;
        }
    }

    // Confirm there is at least one source and detector
    if (sources.empty() || detectors.empty()) {
        std::cout << "-> Config file must contain at least one SOURCE and one DETECTOR.";
        return 1;
    }   

    // Loop through all sources for each detector and output corresponding information
    for (Detector& d : detectors) {
        std::cout << "\n===============================================================================\n";
        d.print_detector();

        for (Source& s : sources) {
            std::cout << "\n-------------------------------------------------------------------------------\n";
            s.print_source();
            std::cout << "Counts detected: " << d.detect(s);
            std::cout << "\n-------------------------------------------------------------------------------";
        }
        
        if (!d.get_status()) {
                std::cout << "\n(Sources could not be measured as the detector is switched off)";
            }
            std::cout << "\n===============================================================================\n";
    }

    return 0;
}