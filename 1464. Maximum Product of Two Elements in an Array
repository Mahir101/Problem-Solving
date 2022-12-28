class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_elem = INT_MIN;
        int second_max = INT_MIN;

        for(int num : nums) {
            if(num > max_elem) {
                second_max = max_elem;
                max_elem = num;
            }
            else if(num > second_max) {
                second_max = num;
            }
        }
        
        return (max_elem-1)*(second_max-1);
    }
};
