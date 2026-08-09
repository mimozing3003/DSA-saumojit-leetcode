#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();
        
        // A quadruplet requires at least 4 numbers
        if (n < 4) {
            return result;
        }
        
        // Sorting is necessary to easily skip duplicates and use two pointers
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 3; ++i) {
            // Skip duplicates for the first number
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            for (int j = i + 1; j < n - 2; ++j) {
                // Skip duplicates for the second number
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                
                int left = j + 1;
                int right = n - 1;
                
                while (left < right) {
                    // Use long long for the sum to prevent integer overflow 
                    // since nums[i] can be up to 10^9.
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    
                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        // Skip duplicates for the third number
                        while (left < right && nums[left] == nums[left + 1]) {
                            left++;
                        }
                        // Skip duplicates for the fourth number
                        while (left < right && nums[right] == nums[right - 1]) {
                            right--;
                        }
                        
                        // Move both pointers inward after finding a valid quadruplet
                        left++;
                        right--;
                    } 
                    else if (sum < target) {
                        left++; // We need a larger sum, move left pointer right
                    } 
                    else {
                        right--; // We need a smaller sum, move right pointer left
                    }
                }
            }
        }
        
        return result;
    }
};