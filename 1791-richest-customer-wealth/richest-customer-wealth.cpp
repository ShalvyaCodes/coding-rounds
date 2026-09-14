class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = 0;
        
        for(int i = 0; i < accounts.size(); i++) {
            int currentCustomerWealth = 0;
            
            for(int j = 0; j < accounts[i].size(); j++) {
                currentCustomerWealth += accounts[i][j]; 
            }
            
            // Is 'if' ko outer loop ke andar hi rakhna hai!
            if(currentCustomerWealth > maxWealth) {
                maxWealth = currentCustomerWealth;
            }
        } // Outer loop yahan khatam hoga
        
        return maxWealth;
    }
};