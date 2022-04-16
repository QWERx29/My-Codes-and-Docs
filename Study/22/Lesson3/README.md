## 第五节 并查集          

##### *Problem#1* 亲戚

###### 【题目描述】

或许你并不知道，你的某个朋友是你的亲戚。他可能是你的曾祖父的外公的女婿的外甥女的表姐的孙子。如果能得到完整的家谱，判断两个人是否亲戚应该是可行的，但如果两个人的最近公共祖先与他们相隔好几代，使得家谱十分庞大，那么检验亲戚关系实非人力所能及。在这种情况下，最好的帮手就是计算机。为了将问题简化，你将得到一些亲戚关系的信息，如Marry和Tom是亲戚，Tom和Ben是亲戚，等等。从这些信息中，你可以推出Marry和Ben是亲戚。请写一个程序，对于我们的关于亲戚关系的提问，以最快的速度给出答案。

###### 【输入格式】

输入由两部分组成。 第一部分以N，M开始。N为问题涉及的人的个数(1≤N≤20000)。这些人的编号为1,2,3,…, N。下面有M行(1≤M≤1 000 000)，每行有两个数ai, bi，表示已知ai和bi是亲戚。 第二部分以Q开始。以下Q行有Q个询问(1≤Q≤1 000 000)，每行为ci, di，表示询问ci和di是否为亲戚。

###### 【输出格式】

对于每个询问ci, di，输出一行：若ci和di为亲戚，则输出“Yes”，否则输出“No”。

###### 【样例】

```
**样例输入**
10 7
2 4
5 7
1 3
8 9
1 2
5 6
2 3
3
3 4
7 10
8 9
**样例输出**
Yes
No
Yes
```

##### *Problem#2*  格子游戏

###### 【题目描述】

Alice和Bob玩了一个古老的游戏：首先画一个n * n的点阵（下图n = 3） 　　接着，他们两个轮流在相邻的点之间画上红边和蓝边：

![img](http://faioj.brynhild.online/images/1335m/1.jpg)

直到围成一个封闭的圈（面积不必为1）为止，“封圈”的那个人就是赢家。因为棋盘实在是太大了(n <= 200)，他们的游戏实在是太长了！他们甚至在游戏中都不知道谁赢得了游戏。于是请你写一个程序，帮助他们计算他们是否结束了游戏？

###### 【输入格式】

输入数据第一行为两个整数n和m。m表示一共画了m条线。以后m行，每行首先有两个数字(x, y)，代表了画线的起点坐标，接着用空格隔开一个字符，假如字符是"D "，则是向下连一条边，如果是"R "就是向右连一条边。输入数据不会有重复的边且保证正确。

###### 【输出格式】

输出一行：在第几步的时候结束。假如m步之后也没有结束，则输出一行“draw”。

###### 【样例】

```
**样例输入**
3 5
1 1 D
1 1 R
1 2 D
2 1 R
2 2 D
**样例输出**
4
```

##### *Problem#3* 寻找满足条件的连通分支

###### 【题目描述】

输入一张顶点带权的无向图，分别计算含顶点数最多的一个连通分支和顶点的权之和最大的一个连通分支。

###### 【输入格式】

n（顶点数，1<=n<=20） 以下n行，依次表示顶点1 ~ 顶点n上的权； e（边数，1<=e<=210） 以下e行，每行为有边连接的一对顶点。

###### 【输出格式】

两行，一行为含顶点数最多的一个连通分支，一行为顶点的权之和最大的一个连通分支，输出时按顶点编号从小到大输出。

###### 【样例】

```
**样例输入**
5
1
2
3
4
5
4
1 2
1 3
1 4
1 5
**样例输出**
1 2 3 4 5
1 2 3 4 5
```

##### *Problem#4* 团伙

###### 【题目描述】

在某城市里住着n个人，任何两个认识的人不是朋友就是敌人，而且满足：

 1、我朋友的朋友是我的朋友；

 2、我敌人的敌人是我的朋友； 　　

所有是朋友的人组成一个团伙。告诉你关于这n个人的m条信息，即某两个人是朋友，或者某两个人是敌人，请你编写一个程序，计算出这个城市最多可能有多少个团伙？

###### 【输入格式】

第1行为n和m，1 < n < 1000,1 < = m <= 100 000； 　　

以下m行，每行为p x y，p的值为0或1，p为0时，表示x和y是朋友，p为1时，表示x和y是敌人。

###### 【输出格式】

一个整数，表示这n个人最多可能有几个团伙。

###### 【样例】

```
**样例输入**
6 4
1 1 4
0 3 5
0 4 6
1 1 2
**样例输出**
3
```

##### *Problem#5* 打击犯罪

###### 【题目描述】

某个地区有n(n<=1000)个犯罪团伙，当地警方按照他们的危险程度由高到低给他们编号为1-n，他们有些团伙之间有直接联系，但是任意两个团伙都可以通过直接或间接的方式联系，这样这里就形成了一个庞大的犯罪集团，犯罪集团的危险程度唯一由集团内的犯罪团伙数量确定，而与单个犯罪团伙的危险程度无关（该犯罪集团的危险程度为n）。现在当地警方希望花尽量少的时间（即打击掉尽量少的团伙），使得庞大的犯罪集团分离成若干个较小的集团，并且他们中最大的一个的危险程度不超过n/2。为达到最好的效果，他们将按顺序打击掉编号1到k的犯罪团伙，请编程求出k的最小值。

###### 【输入格式】

第一行一个正整数n。接下来的n行每行有若干个正整数，第一个整数表示该行除第一个外还有多少个整数，若第i行存在正整数k，表示i，k两个团伙可以直接联系。

###### 【输出格式】

一个正整数，为k的最小值

###### 【样例】

```
**样例输入**
7
2 2 5
3 1 3 4
2 2 4
2 2 3
3 1 6 7
2 5 7
2 5 6
**样例输出**
1
```

##### *Problem#6* 家谱

###### 【题目描述】

现代的人对于本家族血统越来越感兴趣，现在给出充足的父子关系，请你编写程序找到某个人的最早的祖先。

###### 【输入格式】

输入文件由多行组成，首先是一系列有关父子关系的描述，其中每一组父子关系由二行组成，用#name的形式描写一组父子关系中的父亲的名字，用+name的形式描写一组父子关系中的儿子的名字；接下来用?name的形式表示要求该人的最早的祖先；最后用单独的一个$表示文件结束。规定每个人的名字都有且只有6个字符，而且首字母大写，且没有任意两个人的名字相同。最多可能有1000组父子关系，总人数最多可能达到50000人，家谱中的记载不超过30代。

###### 【输出格式】

按照输入文件的要求顺序，求出每一个要找祖先的人的祖先，格式：本人的名字+一个空格+祖先的名字+回车。

###### 【样例】

```
**样例输入**
#George
+Rodney
#Arthur
+Gareth
+Walter
#Gareth
+Edward
?Edward
?Walter
?Rodney
?Arthur
$
**样例输出**
Edward Arthur
Walter Arthur
Rodney George
Arthur Arthur
```

