#include "anomaly_detection.hpp"
#include <cmath>

std::vector<int> AnomalyDetector::detectAnomalies(const std::vector<double>& data) {
    std::vector<int> anomalies;
    double mean = average(data);
    double variance = 0.0;
    for (double value : data) {
        variance += (value - mean) * (value - mean);
    }
    variance /= data.size();
    double stddev = sqrt(variance);

    // z score
    const double threshold = 3.0;
    for (size_t i = 0; i < data.size(); ++i) {
        double zscore = (data[i] - mean) / stddev;
        if (std::abs(zscore) > threshold) {
            anomalies.push_back(i);
        }
    }

    return anomalies;
}

double AnomalyDetector::average(const std::vector<double>& data) {
    double sum = 0.0;
    for (double value : data) {
        sum += value;
    }
    return sum / data.size();
}