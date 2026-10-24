#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int countDaysTogether(std::string arriveAlice, std::string leaveAlice, std::string arriveBob, std::string leaveBob) {
        // Days in each month for a non-leap year
        std::vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        // Helper lambda to convert "MM-DD" to day of the year
        auto convertToDays = [&](const std::string& date) {
            int month = std::stoi(date.substr(0, 2));
            int day = std::stoi(date.substr(3, 2));
            int totalDays = day;
            for (int i = 0; i < month - 1; ++i) {
                totalDays += daysInMonth[i];
            }
            return totalDays;
        };
        
        int aliceArrival = convertToDays(arriveAlice);
        int aliceLeave = convertToDays(leaveAlice);
        int bobArrival = convertToDays(arriveBob);
        int bobLeave = convertToDays(leaveBob);
        
        // Find the start and end of the overlapping period
        int overlapStart = std::max(aliceArrival, bobArrival);
        int overlapEnd = std::min(aliceLeave, bobLeave);
        
        // Calculate the number of overlapping days (inclusive)
        return std::max(0, overlapEnd - overlapStart + 1);
    }
};