func isAnagram(s string, t string) bool {
    n, m := len(s), len(t)

    if n != m {
        return false;
    }

    arr := [26]int{}

    for i := 0; i < n; i++ {
        arr[s[i] - 'a']++;
        arr[t[i] - 'a']--
    }

    for _, val := range arr {
        if(val != 0) {
            return false;
        }
    }

    return true;
}
