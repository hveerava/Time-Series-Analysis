#ifndef ANOMALY_DETECTION_HPP
#define ANOMALY_DETECTION_HPP

#include <vector>

class AnomalyDetector {
public:
    
    std::vector<int> detectAnomalies(const std::vector<double>& data);
    void setThreshold(double threshold);
private:
    double average(const std::vector<double>& data);
    double threshold = 2.0; // todo: change and observe
};

std::vector<int> AnomalyDetector::detectAnomalies(const std::vector<double>& data) {
    std::vector<int> anomalies;
    double avg = average(data);
    for (size_t i = 0; i < data.size(); ++i) {
        if (data[i] > threshold * avg) {
            anomalies.push_back(i);
        }
    }

    return anomalies;
}

void AnomalyDetector::setThreshold(double threshold) {
    this->threshold = threshold;
}

double AnomalyDetector::average(const std::vector<double>& data) {
    double sum = 0.0;
    for (double value : data) {
        sum += value;
    }
    return sum / data.size();
}

#endif
