func twoSum(nums []int, target int) []int {
	n := len(nums)
	ans := make([]int, 0)

	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			if nums[i]+nums[j] == target {
				ans = append(ans, i)
				ans = append(ans, j)
				return ans
			}
		}
	}
	return ans
}
