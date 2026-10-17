import java.util.HashMap;
import java.util.Map;

class Solution {
    private static final int MOD = 1_000_000_007;

    class LazySegmentTree {
        int n;
        long[] sumSq; // Stores the sum of squares of counts
        long[] sumVal; // Stores the sum of counts
        long[] lazy;   // Lazy propagation array

        public LazySegmentTree(int n) {
            this.n = n;
            sumSq = new long[4 * n];
            sumVal = new long[4 * n];
            lazy = new long[4 * n];
        }

        private void push(int node, int l, int r) {
            if (lazy[node] != 0) {
                int mid = (l + r) / 2;
                apply(2 * node, l, mid, lazy[node]);
                apply(2 * node + 1, mid + 1, r, lazy[node]);
                lazy[node] = 0;
            }
        }

        private void apply(int node, int l, int r, long v) {
            // If we add v to every count in range [l, r] of length len:
            // sum((c + v)^2) = sum(c^2) + 2*v*sum(c) + v^2 * len
            long len = (r - l + 1);
            sumSq[node] = (sumSq[node] + 2 * v * sumVal[node] + v * v % MOD * len) % MOD;
            sumVal[node] = (sumVal[node] + v * len) % MOD;
            lazy[node] = (lazy[node] + v) % MOD;
        }

        public void update(int node, int l, int r, int ql, int qr, long v) {
            if (ql > r || qr < l) return;
            if (ql <= l && r <= qr) {
                apply(node, l, r, v);
                return;
            }
            push(node, l, r);
            int mid = (l + r) / 2;
            update(2 * node, l, mid, ql, qr, v);
            update(2 * node + 1, mid + 1, r, ql, qr, v);
            sumSq[node] = (sumSq[2 * node] + sumSq[2 * node + 1]) % MOD;
            sumVal[node] = (sumVal[2 * node] + sumVal[2 * node + 1]) % MOD;
        }

        public long querySumSq() {
            return sumSq[1];
        }
    }

    public int sumCounts(int[] nums) {
        int n = nums.length;
        LazySegmentTree tree = new LazySegmentTree(n);
        Map<Integer, Integer> lastSeen = new HashMap<>();
        long totalSumSq = 0;

        for (int r = 0; r < n; r++) {
            int l = lastSeen.getOrDefault(nums[r], -1) + 1;
            
            // Update range [l, r] by adding 1 to distinct counts
            tree.update(1, 0, n - 1, l, r, 1);
            
            // Record last seen index for the current number
            lastSeen.put(nums[r], r);
            
            // Add current total sum of squares to the overall answer
            totalSumSq = (totalSumSq + tree.querySumSq()) % MOD;
        }

        return (int) totalSumSq;
    }
}