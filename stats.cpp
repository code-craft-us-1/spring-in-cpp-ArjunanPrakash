#include "stats.h"
#include <vector>
#include <cmath>  // For NAN and std::abs
#include <numeric> // For std::accumulate
#include <algorithm> //For std::max_element and std::min_element

namespace Statistics
{
    // Function to compute basic statistics (average, max, min) from a vector of floats.
    Stats ComputeStatistics(const std::vector<float>& data) {
        Stats result;

        // Handle the base case where the input data vector is empty.
        if (data.empty()) {
            result.average = NAN;
            result.max = NAN;
            result.min = NAN;
            return result;
        }

        // Calculate the average value of the elements in the data vector.
        auto const count = static_cast<float>(data.size());
        result.average = std::accumulate(data.begin(), data.end(), 0.0f) / count;

        // Calculate the maximum and minimum values in the data vector.
        result.max = *std::max_element(data.begin(), data.end());
        result.min = *std::min_element(data.begin(), data.end());

        return result;
    }
}
