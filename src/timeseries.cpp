#include "timeseries.hpp"
#include <fstream>
#include <sstream>

TimeSeries::TimeSeries(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        double value;
        iss >> value;
        data.push_back(value);
    }
}

std::vector<double> TimeSeries::getData() const {
    return data;
}
