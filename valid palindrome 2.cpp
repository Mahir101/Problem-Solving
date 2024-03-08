bool validPalindrome(string& s) {
    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            int newLeft = left + 1;
            int newRight = right;
            bool palinLeft = true;
            while (newLeft < newRight) {
                if (s[newLeft] != s[newRight]) {
                    palinLeft = false;
                    break;
                }
                newLeft++;
                newRight--;
            }

            int newLeft = left;
            int newRight = right - 1;
            bool palinRight = true;
            while (newLeft < newRight) {
                if (s[newLeft] != s[newRight]) {
                    palinRight = false;
                    break;
                }
                newLeft++;
                newRight--;
            }

            return palinLeft || palinRight;
        }

        left++;
        right--;
    }

    return true;
}
