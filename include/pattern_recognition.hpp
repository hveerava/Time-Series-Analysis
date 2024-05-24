#ifndef PATTERN_RECOGNITION_HPP
#define PATTERN_RECOGNITION_HPP

#include <vector>

enum class Pattern {
    UpwardTrend,
    DownwardTrend,
    NoPattern
};

class PatternRecognizer {
public:
    Pattern identifyPattern(const std::vector<double>& data);
};

#endif