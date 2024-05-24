#ifndef TIMESERIES_HPP
#define TIMESERIES_HPP

#include <vector>
#include <string>

class TimeSeries {
public:
    TimeSeries(const std::string& filename);
    std::vector<double> getData() const;
private:
    std::vector<double> data;
};

#endif