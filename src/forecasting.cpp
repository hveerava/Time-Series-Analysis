#include "forecasting.hpp"
#include <cmath>
#include <numeric>

const int DEFAULT_P = 1;
const int DEFAULT_D = 1;
const int DEFAULT_Q = 1;

ARIMA::ARIMA(const std::vector<double>& data, int p, int d, int q)
    : data(data), p(p), d(d), q(q) {}

std::vector<double> ARIMA::predict(int steps) {
    std::vector<double> predictions;

    if (data.size() < p + q) {
        throw std::runtime_error("Insufficient data for ARIMA prediction");
    }

    double phi = 0.9; 
    double mu = mean(data); 

    double forecast = data.back();

    for (int i = 0; i < steps; ++i) {
        forecast = mu + phi * (forecast - mu);
        predictions.push_back(forecast);
    }

    return predictions;
}

void ARIMA::setOrder(int p, int d, int q) {
    this->p = p;
    this->d = d;
    this->q = q;
}

double ARIMA::mean(const std::vector<double>& series) {
    return std::accumulate(series.begin(), series.end(), 0.0) / series.size();
}

std::vector<double> ARIMA::diff(const std::vector<double>& series, int lag) {
    std::vector<double> diff_series(series.size() - lag);
    for (size_t i = lag; i < series.size(); ++i) {
        diff_series[i - lag] = series[i] - series[i - lag];
    }
    return diff_series;
}

std::vector<double> SeasonalDecomposition::decompose(const std::vector<double>& data) {
    std::vector<double> seasonal(data.size(), 0.0);

    int window = 3;
    seasonal = loess(data, data, window);

    return seasonal;
}

std::vector<double> SeasonalDecomposition::loess(const std::vector<double>& x, const std::vector<double>& y, int window) {
    std::vector<double> smoothed_series(y.size(), 0.0);
    for (size_t i = 0; i < y.size(); ++i) {
        double sum = 0.0;
        int count = 0;
        for (int j = std::max(0, static_cast<int>(i - window + 1)); j <= static_cast<int>(i); ++j) {
            sum += y[j];
            ++count;
        }
        smoothed_series[i] = sum / count;
    }
    return smoothed_series;
}