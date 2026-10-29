func minEatingSpeed(piles []int, h int) (ans int) {
    mini, maxi:= 1, -1

    for _, val := range piles {
        maxi = max(maxi, val)
    }

    for ; mini <= maxi; {
        mid := (mini + maxi) / 2

        valid := solve(piles, mid, h)

        if(valid) {
            ans = mid;
            maxi = mid - 1;
        } else {
            mini = mid + 1;
        }
    }

    return ans
}

func solve(arr []int, rate, h int) bool {
    cnt := 0

    for _, val := range arr {
        cnt += (val + rate - 1) / rate
    }

    return cnt <= h
}
