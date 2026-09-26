#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        // 1. Build hash map from knowledge base
        unordered_map<string, string> dict;
        for (const auto& pair : knowledge) {
            dict[pair[0]] = pair[1];
        }

        string result = "";
        int n = s.length();
        
        // 2. Iterate through s
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                string key = "";
                // Extract key inside brackets
                while (i + 1 < n && s[i + 1] != ')') {
                    key += s[++i];
                }
                i++; // Skip the closing bracket ')'

                // Replace key with value or '?'
                if (dict.count(key)) {
                    result += dict[key];
                } else {
                    result += '?';
                }
            } else {
                // Regular character
                result += s[i];
            }
        }

        return result;
    }
};