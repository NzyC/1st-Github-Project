//
//  @param {number[]} nums
//  @param {number} target
//  @return {number[]}
//  
 var twoSum = function(nums, target) {
  let i = 0;
  let output = []
  while (i < nums.length + 1) {
    let j = nums[i + 1];
    while (j < nums.length + 1) {
      if (i + j == target) {
        output.push(i);
        output.push(j);
        return output;
      }
    }
  }
};