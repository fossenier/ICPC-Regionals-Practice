#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

int main()
{
    // The first line will contain the number of flights
    int num_flights;
    std::cin >> num_flights;

    std::vector<int> flights;
    // Read in all flights
    for (int i = 0; i < num_flights; i++)
    {
        int flight;
        std::cin >> flight;
        flights.push_back(flight);
    }

    // Determine the most expensive and the cheapest flights
    int minValue = *std::min_element(flights.begin(), flights.end());
    int maxValue = *std::max_element(flights.begin(), flights.end());

    // The best (lowest) personal cost will be the cheapest flight minus half of
    // the most expensive flight
    double cost = minValue - (maxValue / 2.0);
    if (cost < 0)
    {
        cost = 0;
    }

    std::cout << cost << std::endl;
}