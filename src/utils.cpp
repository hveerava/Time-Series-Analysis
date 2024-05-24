#include "utils.hpp"
#include <numeric>
#include <cmath>

double Utils::average(const std::vector<double>& data) {
    double sum = std::accumulate(data.begin(), data.end(), 0.0);
    return sum / data.size();
}

double Utils::standardDeviation(const std::vector<double>& data) {
    double mean = average(data);
    double sumSquaredDiff = 0.0;
    for (double val : data) {
        sumSquaredDiff += (val - mean) * (val - mean);
    }
    return std::sqrt(sumSquaredDiff / data.size());
}