class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
        std::vector<int> counts;
        int i = 0;
        while (i < arr.size()) {
            int count = 1;
            
            while (i + 1 < arr.size() && arr[i] == arr[i + 1]) {
                count++;
                i++;
            }
            counts.push_back(count);
            i++;
        }
        
        // Step 3: Sort the counts list
        std::sort(counts.begin(), counts.end());
        
        // Step 4: Check if any two counts next to each other are equal
        for (int j = 0; j < counts.size() - 1; j++) {
            if (counts[j] == counts[j + 1]) {
                return false; // Duplicate frequency found!
            }
        }
        
        return true; // All frequencies are unique!
    }
};
        
    
