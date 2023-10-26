#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1352 lang=cpp
 *
 * [1352] Product of the Last K Numbers
 */

// @lc code=start
class ProductOfNumbers
{
  public:
    vector<int> preProd;
    ProductOfNumbers()
    {
        preProd.push_back(1);
    }

    void add(int num)
    {
        if (num == 0)
        {
            preProd.clear();
            preProd.push_back(1);
            return;
        }
        int n = preProd.size();
        preProd.push_back(preProd[n - 1] * num);
    }

    int getProduct(int k)
    {
        int n = preProd.size();
        if (n < k + 1)
        {
            return 0;
        }
        return preProd[n - 1] / preProd[n - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
// @lc code=end
