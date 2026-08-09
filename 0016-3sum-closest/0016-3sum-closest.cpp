#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // Step 1: Sort the array
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        // Initialize closest_sum with the sum of the first three elements
        int closest_sum = nums[0] + nums[1] + nums[2];
        
        // Step 2: Lock one element and use two pointers for the rest
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int current_sum = nums[i] + nums[left] + nums[right];
                
                // If we find an exact match, return immediately
                if (current_sum == target) {
                    return current_sum;
                }
                
                // If the current sum is closer to the target, update closest_sum
                if (abs(current_sum - target) < abs(closest_sum - target)) {
                    closest_sum = current_sum;
                }
                
                // Move pointers based on how current_sum compares to target
                if (current_sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        
        return closest_sum;
    }
};