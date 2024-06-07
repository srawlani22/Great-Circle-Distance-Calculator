// Author: Sparsh Rawlani
// Purpose: Assessment for Software Developer Role at University of Texas Austin's Bureau of Economic Geology.
// Date: 06/07/2024
// Short Description: The below code is for calculating the distance between two points on the earth's surface, given their longitudes and
//                    latitudes. The algorithm uses Haversine formula to calculate the distance precisely. There's also check in the main
//                    function that checks whether the coordinates are entered correctly or not(which is between -90 and +90 degrees).
//                    The time and space complexcities are both constant (O(1)) since there's no usage of any data structures.
// Example Testcase: lat1 = 40.7128, lon1 = -74.0060, lat2 = 51.5074, lon2 = -0.1278. Expected Output =  5570.230049 km (3461.180086 miles), which is approximate distance between New York City and London.
// Refrences Used:
// 1. https://en.wikipedia.org/wiki/Haversine_formula
// 2. https://cplusplus.com/reference/cmath/
// 3. https://cplusplus.com/reference/iomanip/

#include <iostream>
#include <iomanip> // For setting precision
#include <cmath> // For trigonometric functions

// Constants for Earth's radius using WGS84 value for higher precision
const double earth_radius_km = 6371.009; // Earth's radius in kilometers
const double earth_radius_mi = 3958.761; // Corresponding radius in miles

// Function to convert degrees to radians
double toRadians(double degrees) {
    return degrees * M_PI / 180.0;
}

// Function to calculate the Great Circle Distance using the Haversine Formula
void calculateGreatCircleDistanceHaversine(double lat1, double lon1, double lat2, double lon2) {
    // Convert latitude and longitude from degrees to radians
    lat1 = toRadians(lat1); // Convert first latitude to radians
    lon1 = toRadians(lon1); // Convert first longitude to radians
    lat2 = toRadians(lat2); // Convert second latitude to radians
    lon2 = toRadians(lon2); // Convert second longitude to radians
    
    // Compute differences
    double dLat = lat2 - lat1; // Difference in latitude
    double dLon = lon2 - lon1; // Difference in longitude
    
    // Apply the Haversine formula
    double a = sin(dLat / 2) * sin(dLat / 2) +
               cos(lat1) * cos(lat2) *
               sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance_km = earth_radius_km * c; // Distance in kilometers
    double distance_mi = earth_radius_mi * c; // Distance in miles
    
    // Output the results with high precision
    std::cout << std::fixed << std::setprecision(6); // Set precision for output
    std::cout << "Great Circle Distance: " << distance_km << " km (" << distance_mi << " miles)" << std::endl;
}

// Functions to validate latitude and longitude
bool isValidLatitude(double lat) {
    return lat >= -90.0 && lat <= 90.0;
}

bool isValidLongitude(double lon) {
    return lon >= -180.0 && lon <= 180.0;
}

int main() {
    double lat1, lon1, lat2, lon2;
    
    // Input and validate the coordinates
    std::cout << "Enter latitude of first location (in decimal degrees):" << std::endl;
    std::cin >> lat1;
    if (!isValidLatitude(lat1)) {
        std::cerr << "Invalid latitude. Must be between -90 and 90 degrees." << std::endl;
        return 1;
    }
    
    std::cout << "Enter longitude of first location (in decimal degrees):" << std::endl;
    std::cin >> lon1;
    if (!isValidLongitude(lon1)) {
        std::cerr << "Invalid longitude. Must be between -180 and 180 degrees." << std::endl;
        return 1;
    }
    
    std::cout << "Enter latitude of second location (in decimal degrees):" << std::endl;
    std::cin >> lat2;
    if (!isValidLatitude(lat2)) {
        std::cerr << "Invalid latitude. Must be between -90 and 90 degrees." << std::endl;
        return 1;
    }
    
    std::cout << "Enter longitude of second location (in decimal degrees):" << std::endl;
    std::cin >> lon2;
    if (!isValidLongitude(lon2)) {
        std::cerr << "Invalid longitude. Must be between -180 and 180 degrees." << std::endl;
        return 1;
    }
    
    // Calculate and display the Great Circle Distance using the Haversine Formula
    calculateGreatCircleDistanceHaversine(lat1, lon1, lat2, lon2);
    
    return 0;
}
