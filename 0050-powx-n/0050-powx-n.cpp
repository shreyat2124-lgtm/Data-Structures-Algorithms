class Solution {
public:

    double myPow(double x, int n)
    {
        // Store n in long long.
        // Handles INT_MIN safely.
        long long N = n;

        // If power is negative,
        // flip the base.
        // Example:
        // 2^-3 = (1/2)^3
        if(N < 0)
        {
            x = 1 / x;
            N = -N;
        }

        double ans = 1;

        while(N > 0)
        {
            // Odd power.
            // One 'x' can't be paired.
            // Multiply it directly.
            if(N % 2 == 1)
            {
                ans *= x;
                N--;
            }

            // Even power.
            // Pair everything.
            // x*x becomes the new base.
            else
            {
                x *= x;
                N /= 2;
            }
        }

        return ans;
    }
};