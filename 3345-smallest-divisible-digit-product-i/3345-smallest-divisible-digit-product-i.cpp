class Solution {
public:
    int smallestNumber(int n, int t) {
        while(true){
            int temp = n;
            int prod = 1;
            while(temp > 0){
                prod *= (temp % 10);
                temp /= 10;
            }
            if( prod % t == 0) return n;
            n++;
        }
    }
};

// Space Complexity
// Best Case = O(1)
// Average Case = O(1)
// Worst Case = O(1)

// Time Complexity
// Best Case = O(log10N)
// Average Case = O(log10N)
// Worst Case =  O(log10N)