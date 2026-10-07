#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

class Solution {
private:
    // Helper function to check if a string has valid parentheses
    bool isValid(const std::string& s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') {
                count++;
            } else if (c == ')') {
                count--;
                if (count < 0) return false; // More closing than opening
            }
        }
        return count == 0;
    }

public:
    std::vector<std::string> removeInvalidParentheses(std::string s) {
        std::vector<std::string> result;
        if (s.empty()) return {""};

        std::queue<std::string> q;
        std::unordered_set<std::string> visited;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty()) {
            int levelSize = q.size();
            
            for (int i = 0; i < levelSize; ++i) {
                std::string curr = q.front();
                q.pop();

                if (isValid(curr)) {
                    result.push_back(curr);
                    found = true; // Mark that a valid level was reached
                }

                if (found) continue; // Skip generating next level if answer is already found

                // Generate next state by removing one parenthesis at a time
                for (int j = 0; j < curr.length(); ++j) {
                    if (curr[j] != '(' && curr[j] != ')') continue;

                    std::string nextState = curr.substr(0, j) + curr.substr(j + 1);

                    if (visited.find(nextState) == visited.end()) {
                        visited.insert(nextState);
                        q.push(nextState);
                    }
                }
            }

            // Once we find valid strings at the current minimum removals, stop BFS
            if (found) break;
        }

        return result;
    }
};