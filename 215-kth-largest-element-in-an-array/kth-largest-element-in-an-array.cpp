#include <vector>
#include <queue>

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        // Min-heap to keep track of the top k largest elements
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

        for (int num : nums) {
            minHeap.push(num);
            // Maintain heap size of k
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        // The root of the min-heap is the kth largest element
        return minHeap.top();
    }
};