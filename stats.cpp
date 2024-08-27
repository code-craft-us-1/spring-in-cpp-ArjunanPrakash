#include "stats.h"
#include <vector>
#include <cmath>    // For NAN and std::abs
#include <numeric>  // For std::reduce
#include <ranges>   // For ranges and views
#include <algorithm> // FOr max and min

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

        // Calculate the average using std::reduce and ranges
        auto const count = static_cast<float>(data.size());
        result.average = std::reduce(data.begin(), data.end(), 0.0f) / count;

        // Calculate max and min using std::ranges
        result.max = std::ranges::max(data);
        result.min = std::ranges::min(data);

        return result;
    }
}
