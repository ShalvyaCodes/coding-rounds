class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.length() ;
        if (n<3) return 0;
        int count = 0;

        for(int i = 0 ; i <= n-3; ++i){
            char a = s[i];
            char b = s[i+1];
            char c = s[i+2];
            if(a!=b && b != c && c!=a){
                count++;
            }
        }
        return count ;
        
    }
};