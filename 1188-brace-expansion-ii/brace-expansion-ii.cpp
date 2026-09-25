#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_set>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        stack<pair<set<string>, set<string>>> st;
        set<string> curr_union;
        set<string> curr_concat = {""};

        for (int i = 0; i < expression.length(); ++i) {
            char ch = expression[i];

            if (ch == '{') {
                // Push current state to stack and enter new scope
                st.push({curr_union, curr_concat});
                curr_union.clear();
                curr_concat = {""};
            } 
            else if (ch == '}') {
                // Finish inner scope
                for (const string& s : curr_concat) {
                    curr_union.insert(s);
                }
                
                // Pop outer scope state
                auto [prev_union, prev_concat] = st.top();
                st.pop();

                // Cross product of previous concat with current inner union
                set<string> next_concat;
                for (const string& p : prev_concat) {
                    for (const string& u : curr_union) {
                        next_concat.insert(p + u);
                    }
                }
                
                curr_union = prev_union;
                curr_concat = next_concat;
            } 
            else if (ch == ',') {
                // End current concatenation block, add to current union
                for (const string& s : curr_concat) {
                    curr_union.insert(s);
                }
                curr_concat = {""};
            } 
            else { // Lowercase character
                string letter(1, ch);
                set<string> next_concat;
                for (const string& p : curr_concat) {
                    next_concat.insert(p + letter);
                }
                curr_concat = next_concat;
            }
        }

        // Final union merge
        for (const string& s : curr_concat) {
            curr_union.insert(s);
        }

        return vector<string>(curr_union.begin(), curr_union.end());
    }
};