You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 
Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
==================================================================================================================
  ============================================== Brut Force==================================================

#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    int retVal = 0;
    for(int i =0; i < prices.size(); ++i) {
        for(int j=i+1; j<prices.size(); ++j) {
            int diff = prices[j]-prices[i];
            if(diff>0 && retVal <=diff) {
                retVal=diff;
            }
        }
        
    }
    return retVal;
}

int main()
{
    vector<int> dummy = {7,1,5,3,6,4};
    int ret = maxProfit(dummy);
    
    std::cout<<"Value is: " << ret <<endl;

    return 0;
}

======================================== Avoiding TimeComplexity O(n*n)======================================
int maxProfit(vector<int>& prices) {
    int maxprofit = 0;
    int minVal = INT_MAX;
    for(int i=0; i < prices.size(); ++i) {
        if (prices[i] < minVal) {
            minVal=prices[i];
        }
        // if((prices[i]-minVal) > maxprofit) {
        //     maxprofit = (prices[i]-minVal);
        // }
        maxprofit = prices[i] - minVal > maxprofit ? prices[i] - minVal : maxprofit;
    }
    return maxprofit;
}
