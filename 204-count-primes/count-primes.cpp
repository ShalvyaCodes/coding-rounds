class Solution {
public:
    int countPrimes(int n) {
        static vector<int> primes;
        static int limit = 0;

        if (n <= 2) return 0;

        if (limit < n) {
            limit = n;

            primes.assign(n, 1);
            primes[0] = primes[1] = 0;

            for (int i = 2; 1LL * i * i < n; i++) {
                if (primes[i]) {
                    for (int j = i * i; j < n; j += i) {
                        primes[j] = 0;
                    }
                }
            }
        }

        int ans = 0;

        for (int i = 2; i < n; i++) {
            if (primes[i]) ans++;
        }

        return ans;
    }
};

