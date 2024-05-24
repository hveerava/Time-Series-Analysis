#ifndef FORECASTING_HPP
#define FORECASTING_HPP

#include <vector>
#include <stdexcept>

class ARIMA {
public:
    ARIMA(const std::vector<double>& data, int p = 1, int d = 1, int q = 1);
    std::vector<double> predict(int steps);
    void setOrder(int p, int d, int q);

private:
    std::vector<double> data;
    int p;
    int d;
    int q;
    double mean(const std::vector<double>& series);
    std::vector<double> diff(const std::vector<double>& series, int lag);
};

class SeasonalDecomposition {
public:
    SeasonalDecomposition(int period);
    std::vector<double> decompose(const std::vector<double>& data);
private:
    int period;
    std::vector<double> loess(const std::vector<double>& x, const std::vector<double>& y, int window);
};

#endif
