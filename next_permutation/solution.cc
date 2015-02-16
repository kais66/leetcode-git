class Solution {
public:
    // classic algorithm from wiki:
    // http://fisherlei.blogspot.com/2012/12/leetcode-next-permutation.html
    void nextPermutation(vector<int> &num) {
        int n = num.size();
        int i = n-2;
        while (i >= 0 && num[i] >= num[i+1]) { --i; }
        if (i == -1) {
            reverse(num.begin(), num.end());
            return;
        }

        int j = n - 1;
        while (num[i] >= num[j]) { --j; }
        swap(num[i], num[j]); // note that num[i+1..n-1] are guaranteed to be decreasing
        reverse(num.begin()+i+1, num.end());
    }
};
