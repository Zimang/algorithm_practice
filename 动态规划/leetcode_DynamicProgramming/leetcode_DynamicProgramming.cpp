// leetcode_DynamicProgramming.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxRotateFunction_First(vector<int>& nums) {//没有运用表记录有用数据
        int sum,sub_sum,balance;
        for (int i = 0; i < nums.size(); i++)
        {
            sub_sum = 0;
            balance = 0;
            for (int  j = 0; j < nums.size(); j++)//找到sub_sum
            {
                sub_sum += j * nums[(j + balance) % nums.size()];
            }
            if (i==0)
            {
                sum = sub_sum;
            }
            else
                sum = sub_sum > sum ? sub_sum : sum;
        }
     
        return sum;
    }
};
int main()
{
    std::cout << "Hello World!\n";
}

