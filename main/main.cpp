#include "timeseries.hpp"
#include "forecasting.hpp"
#include "anomaly_detection.hpp"
#include "pattern_recognition.hpp"
#include "utils.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>

int main() {
    std::vector<std::string> filenames = {"data1.csv", "data2.csv", "data3.csv"};
    std::vector<std::vector<double>> allData;
    for (const std::string& filename : filenames) {
        TimeSeries ts(filename);
        allData.push_back(ts.getData());
    }

    for (size_t i = 0; i < allData.size(); ++i) {
        std::vector<double> data = allData[i];
        std::cout << "Dataset " << i+1 << ":\n";

        double mean = Utils::average(data);
        double stdDev = Utils::standardDeviation(data);
        std::cout << "Mean: " << mean << ", Standard Deviation: " << stdDev << std::endl;

        int p, d, q;
        std::cout << "Enter ARIMA parameters (p, d, q): ";
        std::cin >> p >> d >> q;

        ARIMA arima(data, p, d, q);
        std::vector<double> forecast = arima.predict(5);
        std::cout << "Forecasted values: ";
        for (double val : forecast) {
            std::cout << val << " ";
        }
        std::cout << std::endl;

        std::ofstream outFile("forecast_dataset" + std::to_string(i+1) + ".csv");
        if (outFile.is_open()) {
            for (double val : forecast) {
                outFile << val << std::endl;
            }
            outFile.close();
            std::cout << "Forecast saved to forecast_dataset" << i+1 << ".csv\n";
        } else {
            std::cerr << "Unable to open file for writing\n";
        }

        AnomalyDetector detector;
        std::vector<int> anomalies = detector.detectAnomalies(data);
        if (!anomalies.empty()) {
            std::cout << "Anomalies detected at indices: ";
            for (int idx : anomalies) {
                std::cout << idx << " ";
            }
            std::cout << std::endl;
        } else {
            std::cout << "No anomalies detected\n";
        }

        PatternRecognizer recognizer;
        Pattern pattern = recognizer.identifyPattern(data);
        std::cout << "Pattern recognition: ";
        switch (pattern) {
            case Pattern::UpwardTrend:
                std::cout << "Upward trend detected\n";
                break;
            case Pattern::DownwardTrend:
                std::cout << "Downward trend detected\n";
                break;
            case Pattern::NoPattern:
                std::cout << "No clear pattern detected\n";
                break;
        }
    }

    return 0;
}