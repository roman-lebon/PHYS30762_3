#include <iostream>
#include "source.h"
#include "detector.h"
#include <cstdlib> 
#include <ctime>
#include <fstream>
#include <sstream>
#include <vector>

int main() {

    srand(time(0)); // Ensures each run similuates a new measurement

    // Vectors to store all info read from config file 
    std::vector<Source> sources;
    std::vector<Detector> detectors;

    // Open config file and validate successful open
    std::ifstream file("config.txt");

    if (!file) {
        std::cout << "\n-> Error: Could not open config file.\n";
        return 1;
    }

    std::string line;

    // Read config file line by line
    while (std::getline(file, line)) {
        std::stringstream ss(line); // Stringstream allows for easy extract of values from each line
        
        std::string tag;
        ss >> tag; // First word tells us which object to create

        // Extract values according to which object they refer to
        if (tag == "SOURCE") {
            std::string type;
            std::string date;
            double activity;
            int id;

            ss >> type >> date >> activity >> id;
            sources.emplace_back(type, date, activity, id); // Creates a Source object and stores in source vector
        }

        if (tag == "DETECTOR") {
            std::string type;
            int status;

            ss >> type >> status;
            detectors.emplace_back(type, status);
        } 
    }

    // Loop through all sources for each detector and output corresponding information
    for (Detector& d : detectors) {
        for (Source& s : sources) {
            d.detect(s);
            std::cout << "\n-----\n";
            s.print_source();
            std::cout << "\n";
            d.print_detector();
            std::cout << "-----";
        }
    }

    return 0;
}