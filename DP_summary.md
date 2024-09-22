# 动态规划中的问题

## 01背包/完全背包

由于特殊性，默认**先遍历物品，再遍历背包容量**

### 01背包

每一个物品只能使用一次，**背包需要从大容量向小容量遍历**，每个物品只会填充一次

### 完全背包

每一个物品可以使用多次，背包需要**从小容量向大容量遍历**，每个物品可以使用多次

## 组合问题/排列问题

### 组合

我们不会考虑填充物品的顺序，所以**先背包还是先物品，无所谓**，其实背包问题也是这样，但我们默认先物后包

### 排列问题

我们需要考虑物品放入的顺序，所以**外层遍历包，内层遍历物**，并且内层需要进行if判断

# 简单的动态规划题目

## 509.斐波那契数列

- dp数组定义：`dp[i]`表示第i个斐波那契数
- dp数组递推关系：`dp[i] = dp[i-1] + dp[i-2]`
- dp数组初始化：`dp[0] = 0, dp[1] = 1`
- dp数组遍历方向：从前往后遍历

```c++
vector<int> dp(n+1, 0);
dp[0] = 0;
dp[1] = 1;
for(int i = 2; i <= n; i++){
  dp[i] = dp[i-1] + dp[i-2];
}
return dp[n];
```

## 70.爬楼梯

- dp数组定义：`dp[i]`表示爬到第i层楼梯的方法数
- dp数组递推关系：`dp[i] = dp[i-1] + dp[i-2]`
- dp数组初始化：`dp[1] = 1, dp[2] = 2`
- dp数组遍历方向：从前往后遍历

```c++
if(n <= 1) return n;
vector<int> dp(n+1, 0);
dp[1] = 1;
dp[2] = 2;
for(int i = 3; i <= n; i++){
  dp[i] = dp[i-1] + dp[i-2];
}
return dp[n];
```

## 746.使用最小花费爬楼梯

- dp数组定义：`dp[i]`表示爬到第i层楼梯的最小花费
- dp数组递推关系：`dp[i] = min(dp[i-1]  + cost[i - 1], dp[i-2] + cost[i - 2])`，因为一次可以走1或者2步
- dp数组初始化：`dp[0] = cost[0], dp[1] = cost[1]`,因为可以从0或者1开始
- dp数组遍历方向：从前往后遍历

```c++
dp[0] = cost[0];
dp[1] = cost[1];
for(int i = 2; i < n; i++){
  dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
}
return min(dp[n-1], dp[n-2]);//最后一步可以走1或者2步
```

## 62.不同路径

- dp数组定义：`dp[i][j]`表示从(0,0)到(i,j)的路径数
- dp数组递推关系：`dp[i][j] = dp[i-1][j] + dp[i][j-1]`
- dp数组初始化：第一行和第一列都是1,因为只有一种走法，没有障碍物所有初始化1
- dp数组遍历方向：从前往后遍历,从上到下

```c++
vector<vector<int>> dp(m, vector<int>(n, 1));
for(int i = 1; i < m; i++){
  for(int j = 1; j < n; j++){
    dp[i][j] = dp[i-1][j] + dp[i][j-1];
  }
}
return dp[m-1][n-1];
```

## 63.不同路径II

- dp数组定义：`dp[i][j]`表示从(0,0)到(i,j)的路径数
- dp数组递推关系：`dp[i][j] = dp[i-1][j] + dp[i][j-1]`（如果没有障碍物）
- dp数组初始化：默认填充0，遍历第一行第一列遇到障碍物之前都是1，遇到障碍物停止填充
- dp数组遍历方向：从前往后遍历,从上到下

```c++
if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;
vector<vector<int>> dp(m, vector<int>(n, 0));
for(int i = 0; i < m && obstacleGrid[i][0] == 0; i++) dp[i][0] = 1;
for(int j = 0; j < n && obstacleGrid[0][j] == 0; j++) dp[0][j] = 1;
for(int i = 1; i < m; i++){
  for(int j = 1; j < n; j++){
    if(obstacleGrid[i][j] == 0) dp[i][j] = dp[i-1][j] + dp[i][j-1];
  }
}
return dp[m-1][n-1];
```
# 自己确认背包容量，查看是否有解的题目，包含01背包，完全背包，多重背包

## 343.整数拆分

- dp数组定义：`dp[i]`拆分i，可以得到的最大乘积
- dp数组递推关系：`dp[i] = max({dp[i], j * (i - j), j * dp[i - j]})`
    - 其中`dp[i]`表示不拆分的情况,`j * (i - j)`表示拆分成两个数,`j * dp[i - j]`表示拆分成多个数
- dp数组初始化：`dp[2] = 1`
- dp数组遍历方向：从前往后遍历

```c++
vector<int> dp(n+1, 0);
dp[2] = 1;
for(int i = 3; i <= n; i++){//i表示拆分的数
  for(int j = 1; j <= i / 2; j++){//j表示拆分的位置,从1开始，拆分为j和i-j，所以j最大为i/2
    dp[i] = max({dp[i], j * (i - j), j * dp[i - j]});
  }
}
return dp[n];
```

## 96.不同的二叉搜索树

- dp数组定义：`dp[i]`表示i个节点可以组成的二叉搜索树的个数
- dp数组递推关系：`dp[i] = dp[j] * dp[i - j - 1]`
    - 其中`dp[j]`表示左子树的个数,`dp[i - j - 1]`表示右子树的个数
- dp数组初始化：`dp[0] = 1`
- dp数组遍历方向：从前往后遍历

```c++
vector<int> dp(n+1, 0);
dp[0] = 1;
for(int i = 1; i <= n; i++){//i表示总的节点数
  for(int j = 0; j < i; j++){//j表示左子树的节点数,注意j最大为i-1，因为代表左子树节点数，肯定小于总节点数
    dp[i] += dp[j] * dp[i - j - 1];
  }
}
return dp[n];
```

## 经典01背包问题

- dp数组定义：`dp[j]`表示背包容量为j时，可以装的最大价值
- dp数组递推关系：`dp[j] = max(dp[j], dp[j - weight[i]] + value[i])`
    - 其中`dp[j]`表示不装第i个物品的价值,`dp[j - weight[i]] + value[i]`表示装第i个物品的价值
- dp数组初始化：`dp[0] = 0`，总体来说，初始化为0，因为不装任何物品的价值为0
- 01背包，每个物品只能用一次，所以背包容量从大到小遍历，不考虑顺序，无所谓先物品还是先背包，但是默认就是先物品后背包

```c++
vector<int> dp(size + 1, 0);
for(int i = 0; i < n; i++){//i表示物品
  for(int j = size; j >= weight[i]; j--){//j表示背包容量,当j小于weight[i]时，不能装第i个物品，就不用更新
    dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
  }
}
return dp[size];
```

## 416.分割等和子集

本题本质为01背包问题，只不过背包容量为sum/2，每个物品的重量和价值都为nums[i]，看能否装满

- dp数组定义：`dp[j]`表示背包容量为j时，可以装的最大价值
- dp数组递推关系：`dp[j] = max(dp[j], dp[j - nums[i]] + nums[i])`
- dp初始化，因为是01背包问题，所以初始化为0，如果有负数，就要初始化为INT_MIN
- 01背包，每个物品只能用一次，所以背包容量从大到小遍历，不考虑顺序，无所谓先物品还是先背包，但是默认就是先物品后背包

```c++
int sum = accumulate(nums.begin(), nums.end(), 0);
if(sum % 2 != 0) return false;
int target = sum / 2;
vector<int> dp(target + 1, 0);
for(int i = 0; i < n; i++){//i表示物品
  for(int j = target; j >= nums[i]; j--){//j表示背包容量,当j小于nums[i]时，不能装第i个物品，就不用更新
    dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
  }
}
return dp[target] == target;//如果最后背包装满，就返回true
```

## 1049.最后一块石头的重量II

类似于上面的分割等和子集，只不过这里是求最后一块石头的重量，也就是尽量平均分配，使得两堆石头的重量差最小

- dp数组定义：`dp[j]`表示背包容量为j时，可以装的石头的最大重量
- dp数组递推关系：`dp[j] = max(dp[j], dp[j - stones[i]] + stones[i])`
- dp初始化，因为是01背包问题，所以初始化为0，如果有负数，就要初始化为INT_MIN
- 01背包，每个物品只能用一次，所以背包容量从大到小遍历，不考虑顺序，无所谓先物品还是先背包，但是默认就是先物品后背包

```c++
int sum = accumulate(stones.begin(), stones.end(), 0);
int target = sum / 2;//最大重量的一半
vector<int> dp(target + 1, 0);//只需要设置背包最大容量为target，因为分配的石头总和不会超过target
for(int i = 0; i < n; i++){//i表示物品
  for(int j = target; j >= stones[i]; j--){//j表示背包容量,当j小于stones[i]时，不能装第i个物品，就不用更新
    dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
  }
}
return (sum - dp[target]) - dp[target];//最后一块石头的重量就是总重量减去两堆石头的重量差
```

## 494.目标和

我们要找和为target，则一定可以分成两堆left和right，使得`left - right = target`，所以`lwft - (sum - left) = target`，所以`left = (target + sum) / 2`
，所以本题就是求和为`left`的子集个数

- dp数组定义：`dp[j]`装满容量为j的背包方法数
- dp数组递推关系：`dp[j] += dp[j - nums[i]]`
- dp初始化：`dp[0] = 1`，因为和为0的方法数为1
- 01背包，每个物品只能用一次，所以背包容量从大到小遍历，不考虑顺序，无所谓先物品还是先背包，但是默认就是先物品后背包

```c++
int sum = accumulate(nums.begin(), nums.end(), 0);
if((target + sum) % 2 != 0) return 0;
int left = (target + sum) / 2;
vector<int> dp(left + 1, 0);
dp[0] = 1;
for(int i = 0; i < n; i++){//i表示物品
  for(int j = left; j >= nums[i]; j--){//j表示背包容量,当j小于nums[i]时，不能装第i个物品，就不用更新
    dp[j] += dp[j - nums[i]];
  }
}
return dp[left];
```

## 474.一和零

给你一个二进制字符串数组`strs`和两个整数`m`和`n`,请你找出并返回`strs`的最大子集的大小，该子集中最多有m个0和n个1。

`strs`数组里的元素相当于一个物品，每个物品有两个属性，0的个数和1的个数，我们可以看成是一个01背包问题，只不过背包容量有两个，一个是0的个数，一个是1的个数，背包有两个维度

- dp数组定义：`dp[i][j]`最多有i个0和j个1的子集的最大个数
- dp数组递推关系：`dp[i][j] = max(dp[i][j], dp[i - zero][j - one] + 1)`
- dp初始化：默认为0，因为是01背包问题，所以初始化为0
- 01背包，每个物品只能用一次，所以背包容量从大到小遍历，不考虑顺序，无所谓先物品还是先背包，但是默认就是先物品后背包

```c++
vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));//初始化为0
for(auto str : strs){//这就是这个题的物品遍历
  int zero = 0, one = 0;
  for(auto c : str){//每次遍历物品，需要累计0和1的个数
    if(c == '0') zero++;
    else one++;
  }
  for(int i = m; i >= zero; i--){//遍历第一种背包容量，01背包，所以从大到小遍历
    for(int j = n; j >= one; j--){//遍历第二种背包容量，01背包，所以从大到小遍历
      dp[i][j] = max(dp[i][j], dp[i - zero][j - one] + 1);
    }
  }
}
return dp[m][n];
```

## 518.零钱兑换II

给硬币的面值数组`coins`，每个硬币的面值是`coins[i]`，再给一个整数`amount`表示总金额，问你可以凑成总金额的硬币组合数，硬币无限使用

- dp数组定义：`dp[j]`表示凑成总金额为j的硬币组合数
- dp数组递推关系：`dp[j] += dp[j - coins[i]]`
- dp初始化：`dp[0] = 1`，因为总金额为0的组合数为1（类似我在小米一面那种去找对应面额的设置为1，其实是不需要的）
- 完全背包，每个物品可以用多次，所以背包容量从小到大遍历，不考虑顺序，无所谓先物品还是先背包，但是默认就是先物品后背包

```c++
vector<int> dp(amount + 1, 0);
dp[0] = 1;//总金额为0的组合数为1，就是不选硬币
for(int i = 0; i < n; i++){//i表示物品
  for(int j = coins[i]; j <= amount; j++){
  //j表示背包容量,当j小于coins[i]时，不能装第i个物品，就不用更新
  //完全背包，所以从小到大遍历
    dp[j] += dp[j - coins[i]];
  }
}
return dp[amount];
```

## 322.零钱兑换

类似于上面的零钱兑换，也是完全背包，但是求的是凑成总金额的最少硬币数量

- dp数组定义：`dp[j]`表示凑成总金额为j的硬币的最少数量
- dp数组递推关系：`dp[j] = min(dp[j], dp[j - coins[i]] + 1)`
- dp初始化：`dp[0] = 0`，因为总金额为0的硬币数量为0
- 完全背包，每个物品可以用多次，所以背包容量从小到大遍历，不考虑顺序，无所谓先物品还是先背包，但是默认就是先物品后背包

```c++
vector<int> dp(amount + 1, INT_MAX);//初始化为INT_MAX，因为要求最小值
dp[0] = 0; // 凑够0元需少要0个硬币
for(int i = 0; i < n; i++){//i表示物品
  for(int j = coins[i]; j <= amount; j++){
  //j表示背包容量,当j小于coins[i]时，不能装第i个物品，就不用更新
  //完全背包，所以从小到大遍历
    if(dp[j - coins[i]] != INT_MAX) 
      dp[j] = min(dp[j], dp[j - coins[i]] + 1);
  }
}    
return dp[amount] == INT_MAX ? -1 : dp[amount];//注意判断是否有解
```

## 混合背包零钱兑换

[代码随想录多重背包](https://www.programmercarl.com/%E8%83%8C%E5%8C%85%E9%97%AE%E9%A2%98%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%80%E5%A4%9A%E9%87%8D%E8%83%8C%E5%8C%85.html)

类似于上题，此时coins[0]代表硬币的面值，coins[1]代表硬币的个数，每个硬币的面值是`coins[0][i]`，硬币的个数是`coins[1][i]`，再给一个整数`amount`表示总金额，问你可以凑成总金额的最少硬币数量

- dp数组定义：`dp[j]`表示凑成总金额为j的硬币的最少数量
- dp数组递推关系：`dp[j] = min(dp[j], dp[j - coins[0][i]] + 1)`
- dp初始化：`dp[0] = 0`，因为总金额为0的硬币数量为0
- 多重背包，多重背包和01背包是非常像的， 为什么和01背包像呢？
    - 每件物品最多有Mi件可用，把Mi件摊开，其实就是一个01背包问题了。

```c++
int minCoinsToAmount(const vector<vector<int>>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0; // base case

    for (int i = 0; i < coins[0].size(); ++i) {//遍历物品
        int coinValue = coins[0][i];
        int coinCount = coins[1][i];

        for (int j = amount; j >= 0; --j) {//遍历背包容量
            if (dp[j] != INT_MAX) { // only proceed if the current amount is reachable
                for (int k = 1; k <= coinCount && j + k * coinValue <= amount; ++k) {
                //对于多重背包，每个物品可以用多次，所以需要再次遍历物品的个数
                    dp[j + k * coinValue] = min(dp[j + k * coinValue], dp[j] + k);
                }
            }
        }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
}
```

## 377.组合总和IV

给定一个由不同整数组成的数组`nums`和一个目标整数`target`，请你从`nums`中找出并返回总和为`target`的元素组合的个数，可以重复使用数组中的元素
类似于零钱兑换的01背包问题，只不过这里是求组合数，而不是求最大值，所以先包后物，才是求组合数

- dp数组定义：`dp[j]`表示凑成总金额为j的硬币组合数
- dp数组递推关系：`dp[j] += dp[j - nums[i]]`
- dp初始化：`dp[0] = 1`，因为总金额为0的组合数为1
- 求组合数，所以先遍历背包，再遍历物品

```c++
vector<int> dp(target + 1, 0);
dp[0] = 1;
for(int i = 0; i <= target; ++i) {//求组合，先遍历背包
    for(int j = 0; j < nums.size(); ++j) {//再遍历物品
        if(i >= nums[j] && dp[i] < INT_MAX - dp[i - nums[j]]) {
        //一般先包后物，没法考虑包能否装下，一般要再加一个if判断
        //因为dp[i]可能会溢出，所以要加上dp[i] < INT_MAX - dp[i - nums[j]]
            dp[i] += dp[i - nums[j]];
        }
    }
}
return dp[target];
```

## 70.爬楼梯进阶版

需要爬n阶楼梯，每次最多可以爬m阶，求有多少种不同的方法爬到楼顶。
其实是一个完全背包问题，1~m阶的变化可以看成是物品，楼顶就是背包，每一种物品（爬多少阶就是物品）

- dp数组定义：`dp[i]`表示爬到第i层楼梯的方法数
- dp数组递推关系：`dp[i] = dp[i-1] + dp[i-2] + ... + dp[i - m]`
- dp数组初始化：`dp[0] = 1`，因为只有一种方法，就是不爬
- 完全背包，每个物品可以用多次，所以背包容量从小到大遍历
    - 但是此问题需要考虑顺序，因为1，2爬和2，1是不一样的，所以先遍历背包再遍历物品

```c++
vector<int> dp(n + 1, 0);
dp[0] = 1;
for(int i = 1; i <= n; ++i) {//先遍历背包
    for(int j = 1; j <= m; ++j) {//再遍历物品
      if(i >= j) //先包后物，一般需要添加判断，如果楼梯数大于爬的阶数才能爬
        dp[i] += dp[i - j];
    }
}
return dp[n];
```

## 279.完全平方数

给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。

给你一个整数 n ，返回和为 n 的完全平方数的 最少数量 。

完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。

- dp数组定义：`dp[i]`表示凑成i的最少完全平方数的个数
- dp数组递推关系：`dp[i] = min(dp[i], dp[i - j * j] + 1)`
- dp初始化：`dp[0] = 0`，因为0的最少完全平方数个数为0
- 完全背包，每个完全平方数可以用多次，所以背包容量从小到大遍历，不考虑顺序，无所谓先物品还是先背包，但是默认就是先物品后背包

```c++
 int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i * i <= n; i++) { // 遍历物品
            for (int j = i * i; j <= n; j++) { // 遍历背包
                dp[j] = min(dp[j - i * i] + 1, dp[j]);
            }
        }
        return dp[n];
    }
```

## 139.单词拆分
给定一个非空字符串 s 和一个包含非空单词的列表 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。

- dp数组定义：`dp[i]`表示s的前i个字符是否可以拆分
- dp数组递推关系：如果dp[j]为true，且s[j, i)在wordDict中，那么dp[i]为true
- dp初始化：`dp[0] = true`，空字符串可以拆分,否则后面的递推关系无法进行
- 遍历顺序，注意这里单词拆分是有顺序的，所以先遍历背包，再遍历物品。并且每个单词可以多次用，所以是完全背包，背包容量从小到大遍历

```c++
bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {   // 遍历背包
            for (int j = 0; j < i; j++) {       // 遍历物品
                string word = s.substr(j, i - j); //substr(起始位置，截取的个数)
                if (wordSet.find(word) != wordSet.end() && dp[j]) {
                    dp[i] = true;
                }
            }
        }
        return dp[s.size()];
    }
```
# 股票问题

# 编辑距离问题

## 392.判断子序列

给定字符串 s 和 t ，判断 s 是否为 t 的子序列。

字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。

- dp数组定义：`dp[i][j]`表示以下标i-1为结尾的字符串s，和以下标j-1为结尾的字符串t，相同的子序列长度为`dp[i][j]`
- dp数组递推关系：`dp[i][j] = dp[i - 1][j - 1] + 1`，如果s[i - 1] == t[j - 1]
- dp初始化：`dp[0][0] = 0`，空字符串的子序列长度为0

```c++
bool isSubsequence(string s, string t) {
      vector<vector<int> > dp(s.size() + 1, vector<int>(t.size() + 1, 0));
      for (int i = 1; i <= s.size(); ++i) {
        for (int j = 1; j <= t.size(); ++j) {
          if (s[i - 1] == t[j - 1])
            dp[i][j] = dp[i - 1][j - 1] + 1;//如果相等，就加1
          else
            //如果不相等，因为是s匹配t的子序列，所以只能等于和t的前j-1个字符相等的数量
            dp[i][j] = dp[i][j - 1];
        }
      }
      return dp[s.size()][t.size()] == s.size();
    }
```
## 115.不同的子序列

给定一个字符串 s 和一个字符串 t ，计算在 s 的子序列中 t 出现的个数。

字符串的一个 子序列 是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。（例如，"ACE" 是 "ABCDE" 的一个子序列，而 "AEC" 不是）

题目数据保证答案符合 32 位带符号整数范围。


# 单个数组递增问题

## 300.最长递增子序列

## 674.最长连续递增序列

# 两个数组公共数问题

## 718.最长重复子数组

## 1143.最长公共子序列

# 回文串问题

## 5.最长回文子串

## 647.回文子串

## 516.最长回文子序列





