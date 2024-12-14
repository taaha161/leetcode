class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // Find the maximum pile size (upper bound of speed)
        int maxSpeed = 0;
        for (int pile : piles) {
            maxSpeed = max(maxSpeed, pile);
        }

        int start = 1;         // Minimum speed (1 banana/hour)
        int end = maxSpeed;    // Maximum speed (largest pile size)
        int result = maxSpeed; // Initialize result to maximum possible speed

        while (start <= end) {
            int mid = start + (end - start) / 2; // Calculate mid-speed
            int totalTime = 0;

            // Calculate total hours needed at speed `mid`
            for (int pile : piles) {
                totalTime += (pile + mid - 1) / mid; // Avoid using ceil
            }

            if (totalTime <= h) {
                // If we can finish within `h` hours, try a smaller speed
                result = mid;
                end = mid - 1;
            } else {
                // Otherwise, try a larger speed
                start = mid + 1;
            }
        }

        return result;
    }
};
