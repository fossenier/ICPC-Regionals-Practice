#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    // The first line will contain the number of temperature preferences
    int num_preferences;
    std::cin >> num_preferences;

    std::vector<int> cold_tolerances;
    std::vector<int> hot_tolerances;
    // Read in all preferences
    for (int i = 0; i < num_preferences; i++)
    {
        int cold_tolerance, hot_tolerance;
        std::cin >> cold_tolerance >> hot_tolerance;
        cold_tolerances.push_back(cold_tolerance);
        hot_tolerances.push_back(hot_tolerance);
    }

    // Determine the least cold-tolerant and the least hot-tolerant preferences
    // (hottest cold and coldest hot)
    int maxCold = *std::max_element(cold_tolerances.begin(),
                                    cold_tolerances.end());
    int minHot = *std::min_element(hot_tolerances.begin(),
                                   hot_tolerances.end());

    // If maxCold is more than minHot, then there is no good temperature
    if (maxCold > minHot)
    {
        std::cout << "bad news" << std::endl;
    }
    // There is an acceptable temparature, set it to maxCold for energy savings
    // but mention how many temperatures would have worked
    else
    {
        int numGood{minHot - maxCold + 1};
        std::cout << numGood << " " << maxCold << std::endl;
    }
}