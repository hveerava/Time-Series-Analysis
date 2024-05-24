#include "pattern_recognition.hpp"
#include <cmath>

Pattern PatternRecognizer::identifyPattern(const std::vector<double>& data) {
    if (data.size() < 2) {
        return Pattern::NoPattern;
    }

    double sum_change = 0.0;
    for (size_t i = 1; i < data.size(); ++i) {
        sum_change += (data[i] - data[i - 1]) / data[i - 1];
    }
    double avg_change = sum_change / (data.size() - 1);

    double sum_squared_deviation = 0.0;
    for (size_t i = 1; i < data.size(); ++i) {
        double change = (data[i] - data[i - 1]) / data[i - 1];
        sum_squared_deviation += (change - avg_change) * (change - avg_change);
    }
    double std_deviation = sqrt(sum_squared_deviation / (data.size() - 1));

    if (avg_change > 0.05 && std_deviation < 0.02) {
        return Pattern::UpwardTrend;
    } else if (avg_change < -0.05 && std_deviation < 0.02) {
        return Pattern::DownwardTrend;
    } else {
        return Pattern::NoPattern;
    }
}
