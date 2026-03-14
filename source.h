#ifndef SOURCE_H
#define SOURCE_H

#include <string>

// Source class - represents radioactive source 

class Source {
    private: // Private variables store the data describing the source (cannot be acessed from outside the class)

        std::string type; // Which element the source is (e.g Na-22)
        std::string date; // Source acquisition date
        double activity; // Source activity (in Bq/kg)
        int id; // Source ID 

    public:
        // Constructors
        Source();

        Source(std::string type, std::string date, double activity, int id);

        // Descrutctor
        ~Source(); 

        // Member functions allowing us to interact with the object
        void print_source();

        // Getters
        std::string get_type() const;
        std::string get_date() const;
        double get_activity() const;
        int get_id() const;

        // Setters
        void set_type(std::string t);
        void set_date(std::string d);
        void set_activity(double a);
        void set_id(int i);

};       

#endif 
