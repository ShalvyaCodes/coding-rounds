import java.util.HashSet;
import java.util.List;

public class Solution {
    public int sumCounts(List<Integer> nums) {
        int totalSum = 0;
        int n = nums.size();
        
        // Outer loop picks the start of the subarray
        for (int i = 0; i < n; i++) {
            HashSet<Integer> distinctElements = new HashSet<>();
            
            // Inner loop picks the end of the subarray
            for (int j = i; j < n; j++) {
                distinctElements.add(nums.get(j));
                
                // Add the square of the number of distinct elements
                int count = distinctElements.size();
                totalSum += count * count;
            }
        }
        
        return totalSum;
    }
}