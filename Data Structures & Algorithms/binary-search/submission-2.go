func search(nums []int, target int) int {
    n := len(nums)

    ans, l, r := -1, 0, n - 1

    for ; l <= r; {
        mid := (l + r) / 2

        if(nums[mid] == target) {
            ans = mid;
            break;
        } else if(nums[mid] > target) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    } 

    return ans;
}
