#include<stdlib.h>

/**
 * Possible approaches:
 * - Just check all pairs: Theta(n^2)
 *   - Add pruning if a number is bigger than target: O(n^2)
 * - Quick-Sort, then go through all permutations: O(n log n + target)
 * - Radix-Sort, then go through all permutations: O(n + target)
 */

// Worst Case: O(n^2)
int *twoSumNaive(int *nums, int numsSize, int target, int *returnSize) {
  for (size_t i=0; i<numsSize; ++i) {
    for (size_t j=i+1; j<numsSize; ++j) {
      if (nums[i] + nums[j] == target) {
        *returnSize = 2;
        int *ret = malloc(sizeof(int) * 2);
        ret[0] = i;
        ret[1] = j;
        return ret;
      }
    }
  }
  return NULL;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
  return twoSumNaive(nums, numsSize, target, returnSize);
}
