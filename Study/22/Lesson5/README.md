## 第七节 拓补排序与关键路径

##### *Problem#1*  家谱树

###### 【题目描述】

有个人的家族很大，辈分关系很混乱，请你帮整理一下这种关系。 给出每个人的孩子的信息。 输出一个序列，使得每个人的后辈都比那个人后列出。

###### 【输入格式】

第1行一个整数N（1<=N<=100），表示家族的人数。 接下来N行，第I行描述第I个人的儿子。 每行最后是0表示描述完毕。

###### 【输出格式】

输出一个序列，使得每个人的后辈都比那个人后列出。 如果有多解输出任意一解。

###### 【样例】

```
**样例输入**
5
0
4 5 1 0
1 0
5 3 0
3 0
**样例输出**
2 4 5 3 1
```

##### *Problem#2*  奖金

###### 【题目描述】

由于无敌的凡凡在2005年世界英俊帅气男总决选中胜出，Yali  Company总经理Mr.Z心情好，决定给每位员工发奖金。公司决定以每个人本年在公司的贡献为标准来计算他们得到奖金的多少。于是Mr.Z下令召开m方会谈。每位参加会谈的代表提出了自己的意见：“我认为员工a的奖金应该比b高！”Mr.Z决定要找出一种奖金方案，满足各位代表的意见，且同时使得总奖金数最少。每位员工奖金最少为100元。

###### 【输入格式】

第一行两个整数n,m，表示员工总数和代表数；以下m行，每行2个整数a,b，表示某个代表认为第a号员工奖金应该比第b号员工高。

###### 【输出格式】

若无法找到合理方案，则输出“Poor Xed”；否则输出一个数表示最少总奖金。

###### 【样例】

```
**样例输入**
2 1
1 2
**样例输出**
201
```

##### *Problem#3* Instrction Arrangement              

###### 【题目描述】

Ali has taken the Computer Organization and Architecture course this  term. He learned that there may be dependence between instructions, like WAR (write after read), WAW, RAW. If the distance between two instructions is less than the Safe Distance, it will result in hazard, which may cause wrong result. So we need to  design special circuit to eliminate hazard. However the most simple way  to solve this problem is to add bubbles (useless operation), which means wasting time to ensure that the distance between two instructions is  not smaller than the Safe Distance. The definition of the distance between two instructions is the  difference between their beginning times. Now we have many instructions, and we know the dependent relations and  Safe Distances between instructions. We also have a very strong CPU with infinite number of cores, so you can run as many instructions as you  want simultaneity, and the CPU is so fast that it just cost 1ns to  finish any instruction. Your job is to rearrange the instructions so that the CPU can finish all the instructions using minimum time. 

有n个指令m个要求 例如 X,Y,Z 代表 指令Y必须在指令X后Z秒执行 输出cpu运行的最小时间运行最小时间 也就是要满足最大的时间要求。

###### 【输入格式】

The first line has two integers N, M (N <= 1000, M <= 10000),  means that there are N instructions and M dependent relations. The following M lines, each contains three integers X, Y , Z, means the  Safe Distance between X and Y is Z, and Y should run after X. The  instructions are numbered from 0 to N - 1. 

第一行有两个整数 N，M （N <= 1000，M <= 10000），表示存在 N 指令和 M 依赖关系。 以下 M 行包含三个整数 X、Y、Z，表示 X 和 Y 之间的安全距离为 Z，Y 应在 X 之后运行。指令编号为 0 到 N - 1。

###### 【输出格式】

Print one integer, the minimum time the CPU needs to run. 

一个整数，这是 CPU 需要运行的最短时间。

###### 【样例】

```
**样例输入**
5 2
1 2 1
3 4 1
**样例输出**
2
**样例说明**
In the 1st ns,instruction 0, 1 and 3 are executed;
In the 2nd ns,instruction 2 and 4 are executed.
So the answer should be 2.
```

##### *Problem#4* 车站分级

###### 【题目描述】

一条单向的铁路线上，依次有编号为 1, 2, …, n 的 n 个火车站。每个火车站都有一个级 别，最低为 1 级。现有若干趟车次在这条线路上行驶，每一趟都满足如下要求：如果这趟车 次停靠了火车站 x，则始发站、终点站之间所有级别大于等于火车站 x 的都必须停靠。（注 意：起始站和终点站自然也算作事先已知需要停靠的站点） 例如，下表是 5 趟车次的运行情况。其中，前 4 趟车次均满足要求，而第 5 趟车次由于 停靠了 3 号火车站（2 级）却未停靠途经的 6 号火车站（亦为 2 级）而不满足要求。 

![1](https://user-images.githubusercontent.com/95161611/163671413-0c5266c6-9cb0-485f-8363-3e116411cc92.jpg)


现有 m 趟车次的运行情况（全部满足要求），试推算这 n 个火车站至少分为几个不同的 级别。

###### 【输入格式】

第一行包含 2 个正整数 n, m，用一个空格隔开。 第 i + 1 行（1 ≤ i ≤ m）中，首先是一个正整数 si（2 ≤ si ≤ n），表示第 i 趟车次有 si 个停 靠站；接下来有 si 个正整数，表示所有停靠站的编号，从小到大排列。每两个数之间用一个 空格隔开。输入保证所有的车次都满足要求。

###### 【输出格式】

输出只有一行，包含一个正整数，即 n 个火车站最少划分的级别数。

###### 【样例】

```
**样例输入1**
9 2
4 1 3 5 6
3 3 5 6
**样例输出1**
2
**样例输入2**
9 3
4 1 3 5 6
3 3 5 6
3 1 5 9
**样例输出2**
3
```

###### 【数据范围与提示】

对于 20%的数据，1 ≤ n, m ≤ 10； 

对于 50%的数据，1 ≤ n, m ≤ 100； 

对于 100%的数据，1 ≤ n, m ≤ 1000。
