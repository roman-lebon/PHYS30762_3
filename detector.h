#ifndef DETECTOR_H
#define DETECTOR_H

#include <string>
#include "source.h"

// Detector class - represents radiation detector used

class Detector {
    private: // Private variables store the data describing the source (cannot be acessed from outside the class)

        std::string type; // Detector type
        bool status; // True/false if detector is on/off
        int counts; // Number of counts detected

    public:
        // Constructors
        Detector();

        Detector(std::string type, bool status);

        // Descrutctor
        ~Detector(); 

        // Member functions allowing us to interact with the object
        void print_detector();

        // Getters
        std::string get_type();
        bool get_status();
        int get_counts();

        // Setters
        void set_type(std::string t);
        void set_status(bool s);
        int detect(Source s); // Takes a source object as input returning number of counts (doesnt work if detector is off)
};       

#endif 