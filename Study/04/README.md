## 第四章 循环结构

##### *Problem#1*  求前N个数和

###### 【题目描述】

求s=1+2+3+4+…+n

###### 【输入格式】

输入一个正整数n  (n<=10000)

###### 【输出格式】

输出1+2+3+4+…+n的值

###### 【样例】

```
**样例输入**
3
**样例输出**
6
```

##### *Problem#2* 求n的阶乘

###### 【题目描述】

输入一个正整数n，求n的阶乘（n!=1 * 2 * 3*...*n）

###### 【输入格式】

输入一个正整数

###### 【输出格式】

输出n!的值

###### 【样例】

```
**样例输入**
3
**样例输出**
6
```

###### 【数据范围与提示】

结果在long long 范围内

##### *Problem#3* 菲波那契数

###### 【题目描述】

菲波那契数列是指这样的数列: 数列的第一个和第二个数都为1，接下来每个数都等于前面2个数之和。给出一个正整数k，要求菲波那契数列中第k个数是多少。

###### 【输入格式】

输入一行，包含一个正整数k。（1 ≤ k ≤ 46）

###### 【输出格式】

输出一行，包含一个正整数，表示菲波那契数列中第k个数的大小。

###### 【样例】

```
**样例输入**
19
**样例输出**
4181
```

##### *Problem#4* 累加和第N项

###### 【题目描述】

求s=1 +2 +3……+n，当加到第几项时，s的值会超过sum？

###### 【输入格式】

sum的值

###### 【输出格式】

N的值

###### 【样例】

```
**样例输入**
100
**样例输出**
14
```

##### *Problem#5* 求最大公约数

###### 【题目描述】

求两个数m和n的最大公约数。(m >0，n >0)

###### 【输入格式】

输入二个数，即m和n的值。

###### 【输出格式】

输出最大公约数。

###### 【样例】

```
**样例输入**
8 6
**样例输出**
2
```

##### *Problem#6* 分数和最小N值              

###### 【题目描述】

编一程序求满足不等式1+ 1/2 + 1/3 …+1/n >=sum的最小n值

###### 【输入格式】

输入一个整数sum

###### 【输出格式】

输出n

###### 【样例】

```
**样例输入**
5
**样例输出**
83
```

##### *Problem#7* 数据统计

###### 【题目描述】

输入一些整数，求出它们的最小值、最大值和平均值（保留3位小数）。输入保证这些数都是不超过1000的整数。

###### 【输入格式】

输入一些整数

###### 【输出格式】

输出它们的最小值、最大值和平均值（保留3位小数）

###### 【样例】

```
**样例输入**
2 8 3 5 1 7 3 6
**样例输出**
1 8 4.375
```

##### *Problem#8*  求乘积末尾数

###### 【题目描述】

求n个n的乘积的末两位数是多少？

###### 【输入格式】

输入n

###### 【输出格式】

输出乘积末尾两位数

###### 【样例】

```
**样例输入**
1992
**样例输出**
36
```

##### *Problem#9*  奖励方案              

###### 【题目描述】

校体操队到操场集合,排成每行2人,最后多出1人;排成每行3人,也多出1人;分别按每行排4,5,6人,都多出1人;当排成每行7人时,正好不多。求校体操队至少多少人?

###### 【输出格式】

校队人数

##### *Problem#10* 求阶乘和

###### 【题目描述】

求s=1!+2!+3!+…+n!

###### 【输入格式】

输入一个正整数n (n< 13)

###### 【输出格式】

输出s的值

###### 【样例】

```
**样例输入**
3
**样例输出**
9 
```

##### *Problem#11* 输出直角三角形

###### 【题目描述】

对于给定的自然数n(n<20)，输出仅由“*”构成的n行的直角三角形。 例如：当n=5时，输出：

```
*
**
***
****
*****
```


###### 【输入格式】

一行：n

###### 【输出格式】

n行 第i行有i个*

###### 【样例】

```
**样例输入**
3 
**样例输出**
*
**
***
```

##### *Problem#12*  百钱买百鸡              

###### 【题目描述】

鸡翁一，值钱五，鸡母一，值钱三，鸡雏三，值钱一，百钱买百鸡，问鸡翁、鸡母、鸡雏各几何？

###### 【输出格式】

一行一个解，每个解输出3个数，分别是公鸡、母鸡、小鸡的数量，两个数之间用空格分开；如果有多组解，公鸡数量少的先输出

##### *Problem#13* 元素之和

输入一个三位数n，输出所有小于等于n的水仙花数。

###### 【输入格式】

输入一个三位数n

###### 【输出格式】

输出所有小于等于n的水仙花数。每行一个符合条件的水仙花数，从小到大输出

###### 【样例】

```
**样例输入**
400
**样例输出**
153
370
371
```

##### *Problem#14* 求区间素数

###### 【题目描述】

输入n，m，统计n到m的素数一共有多少个，并将每个素数输出。（n < m < 10000）

###### 【输入格式】

一行：n m

###### 【输出格式】

第1行，从小到大输出n到m的素数，每个用空格隔开。 第2行，一个数，区间素数个数

###### 【样例】

```
**样例输入**
100 200
**样例输出**
101 103 107 109 113 127 131 137 139 149 151 157 163 167 173 179 181 191 193 197 199 
21
```

##### *Problem#15* 完全平方数              

###### 【题目描述】

输出所有形如aabb的四位完全平方数（即前两位数字相等，后两位数字也相等）。

###### 【输出格式】

输出所有四位完全平方数（从小到大），每个一行

##### *Problem#16* 质因数分解              

###### 【题目描述】

把一个合数分解成若干个质因数乘积的形式(即求质因数的过程)叫做分解质因数。分解质因数(也称分解素因数)只针对合数。

###### 【输入格式】

输入一个正整数n  (n< 10000)

###### 【输出格式】

输出一行，将n分解成质因数乘积的形式。

###### 【样例】

```
**样例输入**
36
**样例输出**
36=2*2*3*3
```

##### *Problem#17* 阶乘之和

###### 【题目描述】

计算S=1! + 2! + 3! + … + n!的末6位(不含前导0)。n<=10^6， n!表示前n个正整数之积。

###### 【输入格式】

输入n

###### 【输出格式】

输出S的末6位(不含前导0)

###### 【样例】

```
**样例输入**
10
**样例输出**
37913
```

