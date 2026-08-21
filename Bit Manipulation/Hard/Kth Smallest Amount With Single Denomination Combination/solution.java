class Solution {

    // Calculate GCD
    private long gcd(long a, long b) {
        while (b != 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Calculate LCM
    private long lcm(long a, long b) {
        return (a / gcd(a, b)) * b;
    }

    // Count how many valid amounts are <= x
    private long count(long x, int[] coins) {

        int n = coins.length;
        long total = 0;

        // Generate every non-empty subset
        for (int mask = 1; mask < (1 << n); mask++) {

            long currentLCM = 1;
            int bits = 0;
            boolean valid = true;

            for (int i = 0; i < n; i++) {

                // If ith coin is part of this subset
                if ((mask & (1 << i)) != 0) {

                    bits++;

                    currentLCM = lcm(currentLCM, coins[i]);

                    // If LCM > x, this subset contributes 0
                    if (currentLCM > x) {
                        valid = false;
                        break;
                    }
                }
            }

            if (!valid) {
                continue;
            }

            long multiples = x / currentLCM;

            // Inclusion-Exclusion
            if (bits % 2 == 1) {
                total += multiples;
            } else {
                total -= multiples;
            }
        }

        return total;
    }

    public long findKthSmallest(int[] coins, int k) {

        int minCoin = Integer.MAX_VALUE;

        for (int coin : coins) {
            minCoin = Math.min(minCoin, coin);
        }

        long low = 1;
        long high = (long) minCoin * k;

        // Binary Search
        while (low < high) {

            long mid = low + (high - low) / 2;

            if (count(mid, coins) >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
}