## 第六章 贪心算法

##### *Problem#1* 排队接水                     

###### 【题目描述】

有N个人排队到R个水龙头去打水，他们装满水桶的时间为T1，T2，…，Tn为整数且各不相等，应如何安排他们的打水顺序才能使他们花费的时间最少？

###### 【输入格式】

输入文件共两行，第一行为n,r；第二行分别表示第1个人到第n个人每人的接水时间T1，T2，…，Tn，每个数据之间有1个空格。

###### 【输出格式】

一行，总共花费时间

###### 【样例】

```
**样例输入**
4  2
2  6  4  5 
**样例输出**
23
```

##### *Problem#2* 均分纸牌              

###### 【题目描述】

有 N 堆纸牌，编号分别为 1，2，…, N。每堆上有若干张，但纸牌总数必为 N 的倍数。可以在任一堆上取若于张纸牌，然后移动。 　移牌规则为：在编号为 1 堆上取的纸牌，只能移到编号为 2 的堆上；在编号为 N 的堆上取的纸牌，只能移到编号为 N-1 的堆上；其他堆上取的纸牌，可以移到相邻左边或右边的堆上。 　现在要求找出一种移动方法，用最少的移动次数使每堆上纸牌数都一样多。

```
例如 N=4，4 堆纸牌数分别为： 
①　9　②　8　③　17　④　6 
移动3次可达到目的： 
从 ③ 取 4 张牌放到 ④ （9 8 13 10） —> 从 ③ 取 3 张牌放到 ②（9 11 10 10）—> 从 ② 取 1 张牌放到①（10 10 10 10）。 
```

###### 【输入格式】

第一行，一个数N（N 堆纸牌，1 <= N <= 100）； 　第二行，n个数，A1 A2 … An （N 堆纸牌，每堆纸牌初始数，l<= Ai <=10000）

###### 【输出格式】

仅一行，所有堆均达到相等时的最少移动次数。

###### 【样例】

```
**样例输入**
4
9 8 17 6
**样例输出**
3
```

##### *Problem#3* 删数问题              

###### 【题目描述】

输入一个高精度的正整数N，去掉其中任意S个数字后剩下的数字按原左右次序组成一个新的正整数。编程对给定的N和S，寻找一种方案使得剩下的数字组成的新数最小。 输出新的正整数。（N不超过240位）输入数据均不需判错。

###### 【输入格式】

```
n 
s 
```

###### 【输出格式】

最后剩下的最小数。

###### 【样例】

```
**样例输入**
175438
4
**样例输出**
13
```

##### *Problem#4* 拦截导弹问题             

###### 【题目描述】

某国为了防御敌国的导弹袭击，开发出一种导弹拦截系统，但是这种拦截系统有一个缺陷：虽然它的第一发炮弹能够到达任意的高度，但是以后每一发炮弹都不能高于前一发的高度。某天，雷达捕捉到敌国的导弹来袭，由于该系统还在试用阶段。所以一套系统有可能不能拦截所有的导弹。 输入导弹依次飞来的高度（雷达给出的高度不大于30000的正整数）。计算要拦截所有导弹最小需要配备多少套这种导弹拦截系统。

###### 【输入格式】

n颗依次飞来的高度（1≤n≤1000）.

###### 【输出格式】

要拦截所有导弹最小配备的系统数k。

###### 【样例】

```
**样例输入**
389  207  155  300  299  170  158  65
**样例输出**
2
**?**
输入：导弹高度： 7 9 6 8 5 
输出：导弹拦截系统K=2 
输入：导弹高度： 4 3 2 
输出：导弹拦截系统K=1 
```

##### *Problem#5* 活动安排                            

###### 【题目描述】

设有n个活动的集合E={1,2,...,n}，其中每个活动都要求使用同一资源，如演讲会场等，而在同一时间内只有一个活动能使用这一资源。每个活动 i都有一个要求使用该资源的起始时间 si 和一个结束时间fi，且si<fi。如果选择了活动i，则它在时间区间[si,fi) 内占用资源。若区间  [si,fi)与区间[sj,fj)不相交，则称活动i与活动 j是相容的。也就是说，当fj<=si或 fi<=sj时，活动i与活动j相容。选择出由互相兼容的活动组成的最大集合。

###### 【输入格式】

第一行一个整数 n；

接下来的n行，每行两个整数si和 fi。

###### 【输出格式】

输出互相兼容的最大活动个数。

###### 【样例】

```
**样例输入**
4
1 3
4 6
2 5
1 7
**样例输出**
2
```

###### 【数据范围与提示】

1<=n<=1000

##### *Problem#6* 整数区间              

###### 【题目描述】

请编程完成以下任务： 　　 

1.从文件中读取闭区间的个数及它们的描述； 　　 

2.找到一个含元素个数最少的集合,使得对于每一个区间,都至少有一个整数属于该集合，输出该集合的元素个数。

###### 【输入格式】

首行包括区间的数目n,1<=n<=10000,接下来的n行,每行包括两个整数a,b,被一空格隔开,0<=a<=b<=10000,它们是某一个区间的开始值和结束值。

###### 【输出格式】

第一行集合元素的个数,对于每一个区间都至少有一个整数属于该区间,且集合所包含元素数目最少。

###### 【样例】

```
**样例输入**
4
3 6
2 4
0 2
4 7
**样例输出**
2
```

##### *Problem#7* 最大整数                                      

###### 【题目描述】

设有n个正整数（n≤20），将它们联接成一排，组成一个最大的多位整数。 例如：n=3时，3个整数13，312，343联接成的最大整数为：34331213 又如：n=4时，4个整数7，13，4，246联接成的最大整数为：7424613

###### 【输入格式】

n

n个数

###### 【输出格式】

联接成的多位数

###### 【样例】

```
**样例输入**
3
13  312  343
**样例输出**
34331213
```

##### *Problem#8* 纪念品分组

###### 【题目描述】

元旦快到了，校学生会让乐乐负责新年晚会的纪念品发放工作。为使得参加晚会的同学所获得的纪念品价值相对均衡，他要把购来的纪念品根据价格进行分组，但每组最多只能包括两件纪念品，并且每组纪念品的价格之和不能超过一个给定的整数。为了保证在尽量短的时间内发完所有纪念品，乐乐希望分组的数目最少。 你的任务是写一个程序，找出所有分组方案中分组数最少的一种，输出最少的分组数目。

###### 【输入格式】

输入文件包含n+2行： 第1行包括一个整数w，为每组纪念品价格之和的上限。 第2行为一个整数n，表示购来的纪念品的总件数。 第3~n+2行每行包含一个正整数pi (5 <= pi <= w)，表示所对应纪念品的价格。

###### 【输出格式】

输出文件仅一行，包含一个整数，即最少的分组数目。

###### 【样例】

```
**样例输入**
100
9
90
20
20
30
50
60
70
80
90
**样例输出**
6
```

###### 【数据范围与提示】

```
50%的数据满足：1 <= n <= 15 
100%的数据满足：1 <= n <= 30000, 80 <= w <= 200 
```

##### *Problem#9* 组合的生成              

###### 【题目描述】

学校里有一个水房，水房里一共装有m 个龙头可供同学们打开水，每个龙头每秒钟的 供水量相等，均为1。 现在有n 名同学准备接水，他们的初始接水顺序已经确定。将这些同学按接水顺序从1 到n 编号，i 号同学的接水量为wi。接水开始时，1 到m 号同学各占一个水龙头，并同时打 开水龙头接水。当其中某名同学j 完成其接水量要求wj 后，下一名排队等候接水的同学k 马上接替j 同学的位置开始接水。这个换人的过程是瞬间完成的，且没有任何水的浪费。即 j 同学第x 秒结束时完成接水，则k 同学第x+1 秒立刻开始接水。若当前接水人数n’不足m， 则只有n’个龙头供水，其它m−n’个龙头关闭。 现在给出n 名同学的接水量，按照上述接水规则，问所有同学都接完水需要多少秒。

###### 【输入格式】

第1 行2 个整数n 和m，用一个空格隔开，分别表示接水人数和龙头个数。 第2 行n 个整数w1、w2、……、wn，每两个整数之间用一个空格隔开，wi 表示i 号同 学的接水量。

###### 【输出格式】

输出只有一行，1 个整数，表示接水所需的总时间。

###### 【样例】

```
**样例输入1**
5 3
4 4 1 2 1
**样例输出1**
4
**样例输入2**
8 4
23 71 87 32 70 93 80 76
**样例输出2**
163
**样例说明**
【输入输出样例1 说明】 第1 秒，3 人接水。第1 秒结束时，1、2、3 号同学每人的已接水量为1，3 号同学接完 水，4 号同学接替3 号同学开始接水。 第2 秒，3 人接水。第2 秒结束时，1、2 号同学每人的已接水量为2，4 号同学的已接 水量为1。 第3 秒，3 人接水。第3 秒结束时，1、2 号同学每人的已接水量为3，4 号同学的已接 水量为2。4 号同学接完水，5 号同学接替4 号同学开始接水。 第4 秒，3 人接水。第4 秒结束时，1、2 号同学每人的已接水量为4，5 号同学的已接 水量为1。1、2、5 号同学接完水，即所有人完成接水。 总接水时间为4 秒。
```

###### 【数据范围与提示】

1 ≤ n ≤ 10000，1 ≤m≤ 100 且m≤ n； 1 ≤ wi ≤ 100。

##### *Problem#10* 导弹拦截            

###### 【题目描述】

经过11 年的韬光养晦，某国研发出了一种新的导弹拦截系统，凡是与它的距离不超过 其工作半径的导弹都能够被它成功拦截。当工作半径为0 时，则能够拦截与它位置恰好相同 的导弹。但该导弹拦截系统也存在这样的缺陷：每套系统每天只能设定一次工作半径。而当 天的使用代价，就是所有系统工作半径的平方和。 某天，雷达捕捉到敌国的导弹来袭。由于该系统尚处于试验阶段，所以只有两套系统投 入工作。如果现在的要求是拦截所有的导弹，请计算这一天的最小使用代价。

###### 【输入格式】

第一行包含4 个整数x1、y1、x2、y2，每两个整数之间用一个空格隔开，表示这两套导 弹拦截系统的坐标分别为(x1, y1)、(x2, y2)。 第二行包含1 个整数N，表示有N 颗导弹。接下来N 行，每行两个整数x、y，中间用 一个空格隔开，表示一颗导弹的坐标(x, y)。不同导弹的坐标可能相同。

###### 【输出格式】

输出只有一行，包含一个整数，即当天的最小使用代价。

```
【提示】 
两个点(x1, y1)、(x2, y2)之间距离的平方是(x1− x2)^2+(y1−y2)^2。 
两套系统工作半径r1、r2 的平方和，是指r1、r2 分别取平方后再求和， 
即r1^2+r2^2。
```

###### 【样例】

```
**样例输入1**
0 0 10 0
2
-3 3
10 0
**样例输出1**
18
**样例输入2**
0 0 6 0
5
-4 -2
-2 3
4 0
6 -2
9 1
**样例输出2**
30
```

###### 【数据范围与提示】

【样例1 说明】 样例1 中要拦截所有导弹，在满足最小使用代价的前提下，两套系统工作半径的平方分 别为18 和0。

【样例2 说明】 样例中的导弹拦截系统和导弹所在的位置如下图所示。要拦截所有导弹，在满足最小使 用代价的前提下，两套系统工作半径的平方分别为20 和10。



```
【数据范围】 
对于10%的数据，N = 1 
对于20%的数据，1 ≤ N ≤ 2 
对于40%的数据，1 ≤ N ≤ 100 
对于70%的数据，1 ≤ N ≤ 1000 
对于100%的数据，1 ≤ N ≤ 100000，且所有坐标分量的绝对值都不超过1000。
```
![图片](https://user-images.githubusercontent.com/95161611/162606442-30ee9e5d-56e4-4495-9752-0b33f3493f93.png)

##### *Problem#11* 三国游戏

###### 【题目描述】

小涵很喜欢电脑游戏，这些天他正在玩一个叫做《三国》的游戏。 在游戏中，小涵和计算机各执一方，组建各自的军队进行对战。游戏中共有N 位武将（N 为偶数且不小于4），任意两个武将之间有一个“默契值”，表示若此两位武将作为一对组合 作战时，该组合的威力有多大。游戏开始前，所有武将都是自由的（称为自由武将，一旦某 个自由武将被选中作为某方军队的一员，那么他就不再是自由武将了），换句话说，所谓的 自由武将不属于任何一方。游戏开始，小涵和计算机要从自由武将中挑选武将组成自己的军 队，规则如下：小涵先从自由武将中选出一个加入自己的军队，然后计算机也从自由武将中 选出一个加入计算机方的军队。接下来一直按照“小涵→计算机→小涵→……”的顺序选择 武将，直到所有的武将被双方均分完。然后，程序自动从双方军队中各挑出一对默契值最高 的武将组合代表自己的军队进行二对二比武，拥有更高默契值的一对武将组合获胜，表示两 军交战，拥有获胜武将组合的一方获胜。 已知计算机一方选择武将的原则是尽量破坏对手下一步将形成的最强组合，它采取的具 体策略如下：任何时刻，轮到计算机挑选时，它会尝试将对手军队中的每个武将与当前每个 自由武将进行一一配对，找出所有配对中默契值最高的那对武将组合，并将该组合中的自由 武将选入自己的军队。 下面举例说明计算机的选将策略，例如，游戏中一共有6 个武将，他们相互之间的默契值如下表所示

| 武将编号 | 1    | 2    | 3    | 4    | 5    | 6    |
| -------- | ---- | ---- | ---- | ---- | ---- | ---- |
| 1        | -    | 5    | 28   | 16   | 29   | 27   |
| 2        | 5    | -    | 23   | 3    | 20   | 1    |
| 3        | 28   | 23   | -    | 8    | 32   | 26   |
| 4        | 16   | 3    | 8    | -    | 33   | 11   |
| 5        | 29   | 20   | 32   | 33   | -    | 12   |
| 6        | 27   | 1    | 26   | 11   | 12   | -    |

双方选将过程如下所示：

|        | 小涵  | 轮到计算机时可选的自由武将 | 计算机 | 计算机选将说明                                               |
| ------ | ----- | -------------------------- | ------ | ------------------------------------------------------------ |
| 第一轮 | 5     | 1 2 3 4 6                  | 4      | 小涵手中5号武将与4号的默契值最高，所以选择4号                |
| 第二轮 | 5 3   | 1 2 6                      | 4 1    | 小涵手中的5号和3号武将与自由武将中配对可产生的最大默契值为29，是由5号与1号配对产生的，因此计算机选择1号 |
| 第三轮 | 5 3 6 | 2                          | 4 1 2  |                                                              |

小涵想知道，如果计算机在一局游戏中始终坚持上面这个策略，那么自己有没有可能必 胜？如果有，在所有可能的胜利结局中，自己那对用于比武的武将组合的默契值最大是多 少？ 假设整个游戏过程中，对战双方任何时候均能看到自由武将队中的武将和对方军队的武 将。为了简化问题，保证对于不同的武将组合，其默契值均不相同。


###### 【输入格式】

第一行为一个偶数N，表示武将的个数。 第2 行到第N 行里，第（i+1）行有（N−i）个非负整数，每两个数之间用一个空格隔 开，表示i 号武将和i+1，i+2，……，N 号武将之间的默契值（0 ≤ 默契值≤ 1,000,000,000）。

###### 【输出格式】

共1 或2 行。 若对于给定的游戏输入，存在可以让小涵获胜的选将顺序，则输出1，并另起一行输出 所有获胜的情况中，小涵最终选出的武将组合的最大默契值。 如果不存在可以让小涵获胜的选将顺序，则输出0。

###### 【样例】

```
**样例输入1**
6
5 28 16 29 27
23 3 20 1
8 32 26
33 11
12
**样例输出1**
1
32
**样例输入2**
8
42 24 10 29 27 12 58
31 8 16 26 80 6
25 3 36 11 5
33 20 17 13
15 77 9
4 50
19
**样例输出2**
1 
77
```

###### 【数据范围与提示】

【输入输出样例1说明】 首先小涵拿走5 号武将；计算机发现5 号武将和剩下武将中的4 号默契值最高，于是拿 走4 号；小涵接着拿走3 号；计算机发现3、5 号武将之一和剩下的武将配对的所有组合中， 5 号和1 号默契值最高，于是拿走1 号；小涵接着拿走2 号；计算机最后拿走6 号。在小涵 手里的2，3，5 号武将中，3 号和5 号配合最好，默契值为32，而计算机能推出的最好组合 为1 号和6 号，默契值为27。结果为小涵胜，并且这个组合是小涵用尽所有方法能取到的 最好组合。

```
【数据范围】 
对于40%的数据有N≤ 10。 
对于70%的数据有N≤ 18。 
对于100%的数据有N≤ 500。
```

##### *Problem#12* 推销员             
![图片](https://user-images.githubusercontent.com/95161611/162606755-289cb795-aa73-4bf8-8661-6c4412363cfc.png)
![图片](https://user-images.githubusercontent.com/95161611/162606767-8970aaa8-9c82-422f-8da8-f519da011049.png)
![图片](https://user-images.githubusercontent.com/95161611/162606774-7223c4d0-4558-48db-957f-c793302b2ba8.png)
![图片](https://user-images.githubusercontent.com/95161611/162606779-b59f2105-8b3d-4cb5-950b-7ec8af08bb82.png)

##### *Problem#13* 数列极差              

###### 【题目描述】

佳佳的老师在黑板上写了一个由n个正整数组成的数列，要求佳佳进行如下操作：每次擦去其中的两个数a和b，然后在数列中加入一个数a*b+1，如此下去直至黑板上剩下一个数为止，在所有按这种操作方式最后得到的数中，最大的为max，最小的为min， 则该数列的极差定义为M=max-min。

由于佳佳忙于准备期末考试，现请你帮助他，对于给定的数列，计算出相应的极差M。

###### 【输入格式】

第一行为一个正整数n  表示正整数序列的长度；
 在接下来n行中，每行输入一个正整数。
 接下来的一行有一个0，表示数据结束。

###### 【输出格式】

输出只有一行，为相应的极差d。

###### 【样例】

```
**样例输入**
3
1
2
3
0
**样例输出**
2
```

###### 【数据范围与提示】

对于全部数据， 0<=n<=50000  ，保证所有数据计算均在32位有符号整数范围内。

##### *Problem#14* 保卫牧场              

###### 【题目描述】

风景迷人的小城 Y 市，拥有n个美丽的景点。由于慕名而来的游客越来越多，Y 市特意安排了一辆观光公交车，为游客提供更便捷的交通服务。

观光公交车在第0分钟出现在1号景点，随后依次前往 2,3,...,n号景点。从第i号景点开到第i+1号景点需要Di分钟。任意时刻，公交车只能往前开，或在景点处等待。

设共有 m个游客，每位游客需要乘车1次从一个景点到达另一个景点，第i位游客在Ti分钟来到景点       ，希望乘车去景点Bi(Ai<Bi)。为了使所有乘客都能顺利到达目的地，公交车在每站都必须等待需要从该景点出发的所有乘客都上车后才能出发开往下一景点。假设乘客上下车不需要时间。

一个乘客的旅行时间，等于他到达目的地的时刻减去他来到出发地的时刻。因为只有一辆观光车，有时候还要停下来等其他乘客，乘客们纷纷抱怨旅行时间太长了。于是聪明的司机 ZZ 给公交车安装了k个氮气加速器，每使用一个加速器，可以使其中一个Di减1。对于同一个Di可以重复使用加速器，但是必须保证使用后Di>=0。

那么 ZZ 该如何安排使用加速器，才能使所有乘客的旅行时间总和最小？

###### 【输入格式】

第 1行是3个整数 n,m,k，每两个整数之间用一个空格隔开。分别表示景点数、乘客数和氮气加速器个数。

第 2行是n-1个整数，每两个整数之间用一个空格隔开，第i个数表示从第i个景点开往第i+1个景点所需要的时间，即Di。

第3行至m+2行每行3个整数Ti,Ai,Bi，每两个整数之间用一个空格隔开。第i+2行表示第i位乘客来到出发景点的时刻，出发的景点编号和到达的景点编号。

###### 【输出格式】

共一行，包含一个整数，表示最小的总旅行时间。

###### 【样例】

```
**样例输入**
3 3 2
1 4
0 1 3
1 1 2
5 2 3
**样例输出**
10
**样例说明**
对D2使用2个加速器，从2号景点到3号景点时间变为2分钟。
公交车在第1分钟从1号景点出发，第2分钟到达2号景点，第5分钟从2号景点出发，
第7分钟到达3号景点。
第1个旅客旅行时间7-0=7分钟。
第2个旅客旅行时间2-1=1分钟。
第3个旅客旅行时间7-5=2分钟。
总时间7+1+2=10分钟。
```

###### 【数据范围与提示】

对于8% 的数据，k=0 ；

对于16%的数据，k=1；

对于32%的数据，2<=n<=50，m<=1000，k<=20  ，Di<=10 ,  Ti<=500；

对于48% 的数据，n<=100，m<=1000 ，k<=100 ，Ti<=10^4；

对于80%的数据，n<=1000 ，m<=10^4 ，k<=10^5 ，Di<=100 ，Ti<=10^5 ；

对于100%的数据，1<=n,m<=10^5 ，0<=k<=5*10^6 ，0<=Di<=1000，0<=Ti<=10^6。(❌)

##### *Problem#15* 加工生产调度

###### 【题目描述】

某工厂收到了n个产品的订单，这n个产品分别在 A、B 两个车间加工，并且必须先在 A 车间加工后才可以到 B 车间加工。

某个产品i在 A，B 两车间加工的时间分别为Ai,Bi。怎样安排这n个产品的加工顺序，才能使总的加工时间最短。

这里所说的加工时间是指：从开始加工第一个产品到最后所有的产品都已在 A，B 两车间加工完毕的时间。

###### 【输入格式】

第一行仅—个数据n，表示产品的数量；

接下来n个数据是表示这n个产品在 A 车间加工各自所要的时间；

最后的n个数据是表示这n个产品在 B 车间加工各自所要的时间。

###### 【输出格式】

第一行一个数据，表示最少的加工时间；

第二行是一种最小加工时间的加工顺序。

###### 【样例】

```
**样例输入**
5
3 5 8 7 10
6 2 1 4 9
**样例输出**
34
1 5 4 2 3
```

###### 【数据范围与提示】

对于100%的数据，0<n<1000，所有数值皆为整数。

本题的 SPJ 对行尾多余空格敏感，各位输出答案时不要留行尾多余空格~
