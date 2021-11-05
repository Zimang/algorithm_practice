// leetcode_DynamicProgramming.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    //问题396旋转函数
    int maxRotateFunction_First(vector<int>& nums) {//没有运用表记录有用数据,n^2
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
    int maxRotateFunction_2(vector<int>& nums) {//转化问题为最大子段和
        if (nums.size() == 1)return 0;
        int* a = new int[nums.size()];//存储deltaF
        int* b = new int[nums.size()];//存储最大字段
        int sum=0,sum_nums,begin;
        for (int i = 0; i < nums.size(); i++)
            sum_nums += nums[i];
        for (int i = 0; i < nums.size()-1; i++)//得到f(i+1)-f(i),n:0 to m-2
        {
            a[i] = nums.size() * nums[i] - sum_nums;
        }
        b[0] = a[0]; sum = b[0];
        for (int i = 1; i < nums.size()-1; i++)
        {
            b[i] = b[i - 1] > 0 ? b[i - 1] + a[i] : a[i];//到数组i的最大子段和
            if (sum<b[i])
            {
                sum = b[i];
                begin = i;//
            }
        }

        return sum;
    }
    int maxRotateFunction_3(vector<int>& nums) {
            int N = nums.size();
            int res = 0;
            vector<int>presum(N, 0);
            presum[0] = nums[0];
            for (int i = 1; i < nums.size(); i++) {
                res += i * nums[i];
                presum[i] = presum[i - 1] + nums[i];
            }
            //res=所有元素之和，persum[i]=0 to i的和 
            //cout<<presum[N-1]<<endl;
            int maxi = res;
            for (int i = 1; i < N; i++) {
                int index = N - 1 - i;
                int temp = res;
                // cout<<presum[index]*i<<endl;
                // cout<<(presum[N-1]-presum[index])*(index+1)<<endl;
                temp += presum[index] * i;
                temp -= (presum[N - 1] - presum[index]) * (index + 1);
                //cout<<temp<<endl;
                maxi = max(maxi, temp);
            }
            return maxi;
     }
    int maxRotateFunction_4(vector<int>& A) {
        long long sum = 0;
        long long ans = 0;
        long long obv = 0;
        int n = A.size();

        for (int& x : A) {
            sum += x;
        }
        for (int i = 0; i < n; i++) {
            obv += sum - (long long)n * A[n - i - 1];
            //obv += sum - A[n - i - 1] - (n - 1) * A[n - i - 1]; 合并前的写法
            ans = max(ans, obv);
        }
        for (int i = 0; i < n; i++) {
            ans += A[i] * i;
        }
        return ans;
    }

    //问题53最大子段和
    int maxSubArray_DY(vector<int>& nums) {
        int *a =new int [nums.size()];
        int max=nums[0];
        a[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            a[i] = a[i - 1] > 0 ? a[i - 1] + nums[i] : nums[i];
            if (max <= a[i])  max = a[i];
        }
        return max;
    }



};
int main()
{
    std::cout << "Hello World!\n";
}

