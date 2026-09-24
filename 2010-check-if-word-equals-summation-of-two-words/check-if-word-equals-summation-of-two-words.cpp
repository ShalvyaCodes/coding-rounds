class Solution {
public:
    // Aapka exact addStrings wala function (bas - '0' ki jagah - 'a' hua hai)
    string addWords(string num1, string num2) {
        string result = "";
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;

            if (i >= 0) {
                sum += num1[i] - 'a'; // 'a' subtract karke numeric digit milegi
                i--;
            }
            if (j >= 0) {
                sum += num2[j] - 'a';
                j--;
            }

            carry = sum / 10;
            result.push_back((sum % 10) + '0');
        }

        reverse(result.begin(), result.end());
        return result;
    }

    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        // 1. firstWord + secondWord ka sum aapke wale tarike se nikala
        string calculatedSum = addWords(firstWord, secondWord);

        // 2. targetWord ki numeric string banayi
        string targetValue = "";
        for (char c : targetWord) {
            targetValue.push_back((c - 'a') + '0');
        }

        // 3. Leading zeros strip/remove kar rahe hain (jaise "005" -> "5")
        size_t pos1 = calculatedSum.find_first_not_of('0');
        size_t pos2 = targetValue.find_first_not_of('0');

        string s1 = (pos1 != string::npos) ? calculatedSum.substr(pos1) : "0";
        string s2 = (pos2 != string::npos) ? targetValue.substr(pos2) : "0";

        // 4. Compare karke bool return
        return s1 == s2;
    }
};