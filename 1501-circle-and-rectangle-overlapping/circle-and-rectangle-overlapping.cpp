#include <algorithm>

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // Find the closest x-coordinate on the rectangle to the circle's center
        int closestX = std::max(x1, std::min(xCenter, x2));
        
        // Find the closest y-coordinate on the rectangle to the circle's center
        int closestY = std::max(y1, std::min(yCenter, y2));
        
        // Calculate the squared distance between the closest point and the circle center
        int dx = xCenter - closestX;
        int dy = yCenter - closestY;
        
        // Compare squared distance with squared radius to avoid floating-point errors
        return (dx * dx + dy * dy) <= (radius * radius);
    }
};