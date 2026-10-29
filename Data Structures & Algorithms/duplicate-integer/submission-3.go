func hasDuplicate(nums []int) bool {
    st := make(map[int]struct{})

    for _, num := range nums {
        _, exist := st[num]

        if exist {
            return true;
        }

        st[num] = struct{}{}
    }

    return false
}
