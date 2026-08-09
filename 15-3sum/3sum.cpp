#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        
        // Step 1: Sort the array to use two pointers and easily handle duplicates
        sort(nums.begin(), nums.end());
        
        // Step 2: Iterate through the array
        for (int i = 0; i < n - 2; i++) {
            
            // Skip duplicate elements for the first number (nums[i])
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            // Initialize two pointers
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    // Triplet found
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicate elements for the second number (nums[left])
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    // Skip duplicate elements for the third number (nums[right])
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    
                    // Move both pointers inward after processing a valid triplet
                    left++;
                    right--;
                } 
                else if (sum < 0) {
                    // Sum is too small, move left pointer to a larger value
                    left++;
                } 
                else {
                    // Sum is too large, move right pointer to a smaller value
                    right--;
                }
            }
        }
        
        return result;
    }
};