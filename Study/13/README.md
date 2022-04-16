## 第五章 搜索与回溯算法

##### *Problem#1* 迷宫问题              

###### 【题目描述】

设有一个n*n（2< = n <  =10）方格的迷宫，入口和出口分别在左上角和右上角。迷宫格子中分别放0和1，0表示可通，1表示不能，入口和出口处肯定是0。迷宫走的规则如下：即从某点开始，有八个方向可走，前进方格中数字为0时表示可通过，为1时表示不可通过，要另找路径。找出所有从入口到出口的路径，输出路径总数，如无法到达，则输出0。

###### 【输入格式】

第一行一个整数N 接下来N*N迷宫

###### 【输出格式】

一行,输出路径总数，如无法到达，则输出0。

###### 【样例】

```
**样例输入**
3
0 0 0 
0 1 1
1 0 0
**样例输出**
2
```

##### *Problem#2* 素数环    (❌)

###### 【题目描述】

将从1到n这n个整数围成一个圆环，若其中任意2个相邻的数字相加，结果均为素数，那么这个环就成为素数环。

n=20时，下面的序列就是一个素数环:

`1 2 3 4 7 6 5 8 9 10 13 16 15 14 17 20 11 12 19 18`

###### 【输入格式】

输入一个数n （2 <= n < = 16）

###### 【输出格式】

输出方案总数

###### 【样例】

```
**样例输入**
6
**样例输出**
12
```

##### *Problem#3* 自然数拆分

###### 【题目描述】

任何一个大于1的自然数n，总可以拆分成若干个小于n的自然数之和。 当n=7共14种拆分方法：

```
7=1+1+1+1+1+1+1 
7=1+1+1+1+1+2 
7=1+1+1+1+3 
7=1+1+1+2+2 
7=1+1+1+4 
7=1+1+2+3 
7=1+1+5 
7=1+2+2+2 
7=1+2+4 
7=1+3+3 
7=1+6 
7=2+2+3 
7=2+5 
7=3+4 
total=14 
```

###### 【输入格式】

一个自然数n

###### 【输出格式】

输出若干行，每行一个拆分方案

###### 【样例】

```
**样例输入**
7
**样例输出**
1+1+1+1+1+1+1
1+1+1+1+1+2
1+1+1+1+3
1+1+1+2+2
1+1+1+4
1+1+2+3
1+1+5
1+2+2+2
1+2+4
1+3+3
1+6
2+2+3
2+5
3+4
```

##### *Problem#4* N皇后问题             

###### 【题目描述】

在N*N的棋盘上放置N个皇后（n<=10）而彼此不受攻击（即在棋盘的任一行，任一列和任一对角线上不能放置2个皇后），编程求解所有的摆放方法。

###### 【输入格式】

输入：n

###### 【输出格式】

每行输出一种方案，每种方案顺序输出皇后所在的列号，各个数占5列。若无方案，则输出no solute!

###### 【样例】

```
**样例输入**
4
**样例输出**
  2  4  1  3
  3  1  4  2
```

##### *Problem#5* 工作分配问题              

###### 【题目描述】

设有n件工作分配给n个人。将工作i分配给第j个人所需的费用为cij。试设计一个算法，为每一个人都分配一件不同的工作，并使总费用达到最小。 

【编程任务】 设计一个算法，对于给定的工作费用，计算最佳工作分配方案，使总费用达到最小。

###### 【输入格式】

第一行有1个正整数n (1≤n≤20)。接下来的n行，每行n个数，第i行表示第i个人各项工作费用。

###### 【输出格式】

输出计算出的最小总费

###### 【样例】

```
**样例输入**
3
4  2  5
2  3  6
3  4  5
**样例输出**
9
```

##### *Problem#6* 跳马问题                         

###### 【题目描述】

在n*n格的棋盘上，有一只中国象棋的马，从（1,1）点出发，按日字跳马，它可以朝8个方向跳，但不允许出界或跳到已跳过的格子上，要求马跳遍整个棋盘。（n< = 10） n=5一个方案示例：

```
1   16   21   10   25 
20  11   24   15   22 
17  2    19   6    9 
12  7    4    23   14 
3   18   13   8    5
```

###### 【输入格式】

输入一个整数n

###### 【输出格式】

输出总方案数

###### 【样例】

```
**样例输入**
5
**样例输出**
304
```

##### *Problem#7* 数的划分                                        

###### 【题目描述】

将整数 n分k份，且每份不能为空，问有多少种不同的分法。当n=7,k=3 时，下面三种分法被认为是相同的：1,1,5 ;1,5,1 ; 5,1,1

###### 【输入格式】

一行两个数 n , k 。

###### 【输出格式】

一行一个整数，即不同的分法数。

###### 【样例】

```
**样例输入**
7 3
**样例输出**
4
**样例说明**
四种分法为：1,1,5；1,2,4；1,3,3；2，2,3
```

##### *Problem#8* 全排列问题              

###### 【题目描述】

列出所有从数字1到数字n的连续自然数的排列，要求所产生的任一数字序列中不允许出现重复的数字。

###### 【输入格式】

n （1<=n<=9）

###### 【输出格式】

由1—n组成的所有不重复的数字序列，每行一个序列

###### 【样例】

```
**样例输入**
3
**样例输出**
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
```

##### *Problem#9* 组合的生成              

###### 【题目描述】

排列与组合是常用的数学方法，其中组合就是从n个元素中抽出r个元素（不分顺序，且r<=n），我们可以简单地将n个元素理解为自然数1，2，…，n，从中任取r个数。

###### 【输入格式】

一行两个自然数n，r（1 < n < 21,1 < = r < = n）

###### 【输出格式】

所有的组合，每一行组合占一行且其中的元素按由小到大的顺序排列，每个元素占三个字符的位置，所有的组合也按字典顺序。

###### 【样例】

```
**样例输入**
5 3
**样例输出**
1 2 3
1 2 4
1 2 5
1 3 4
1 3 5
1 4 5
2 3 4
2 3 5
2 4 5
3 4 5
```

##### *Problem#10* 有重复元素的排列问题              

###### 【题目描述】

设R={ r1, r2 , …, rn}是要进行排列的n个元素。其中元素r1, r2 , …, rn可能相同。试设计一个算法，列出R的所有不同排列。 【编程任务】 给定n 以及待排列的n 个元素。计算出这n 个元素的所有不同排列。

###### 【输入格式】

文件的第1 行是元素个数n，1≤n≤500。接下来的1 行是待排列的n个元素。

###### 【输出格式】

计算出的n个元素的所有不同排列输出。文件最后1行中的数是排列总数。

###### 【样例】

```
**样例输入**
4
aacc
**样例输出**
aacc
acac
acca
caac
caca
ccaa
6
```

##### *Problem#11* 子集和问题                    

###### 【题目描述】

子集和问题的一个实例为〈S,t〉。其中，S={ x1， x2，…， xn}是一个正整数的集合，c是一个正整数。子集和问题判定是否存在S的一个子集S1，使得子集S1和等于c。 【编程任务】 对于给定的正整数的集合S={ x1， x2，…， xn}和正整数c，编程计算S 的一个子集S1，使得子集S1和等于c。


###### 【输入格式】

文件第1行有2个正整数n和c，n表示S的个数，c是子集和的目标值。接下来的1 行中，有n个正整数，表示集合S中的元素。

###### 【输出格式】

序运行结束时，将子集和问题的解输出，选出子集位置的字典序最小。当问题无解时，输出“No Solution!”。

###### 【样例】

```
**样例输入**
5  10
2  2  6  5  4
**样例输出**
2  2  6
```

##### *Problem#12* 部落卫队                      

###### 【题目描述】

原始部落byteland中的居民们为了争夺有限的资源，经常发生冲突。几乎每个居民都有他的仇敌。部落酋长为了组织一支保卫部落的队伍，希望从部落的居民中选出最多的居民入伍，并保证队伍中任何2 个人都不是仇敌。 【编程任务】 给定byteland部落中居民间的仇敌关系，编程计算组成部落卫队的最佳方案。

###### 【输入格式】

第1行有2个正整数n和m，表示byteland部落中有n个居民，居民间有m个仇敌关系。居民编号为1，2，…，n。接下来的m行中，每行有2个正整数u和v，表示居民u与居民v是仇敌。

###### 【输出格式】

第1行是部落卫队的顶人数；文件的第2行是卫队组成x i，1≤i≤n，xi =0 表示居民i不在卫队中，xi=1表示居民i在卫队中。

###### 【样例】

```
**样例输入**
7  10
1  2
1  4
2  4
2  3
2  5
2  6
3  5
3  6
4  5
5  6
**样例输出**
3
1 0 1 0 0 0 1
```

###### 【数据范围与提示】

n < = 200 ,m< = 5000

##### *Problem#13* 图的m着色问题              

###### 【题目描述】

给定无向连通图G和m种不同的颜色。用这些颜色为图G的各顶点着色，每个顶点着一种颜色。如果有一种着色法使G中每条边的2个顶点着不同颜色，则称这个图是m可着色的。图的m着色问题是对于给定图G和m种颜色，找出所有不同的着色法。 【编程任务】 对于给定的无向连通图G和m种不同的颜色，编程计算图的所有不同的着色法。

###### 【输入格式】

第1行有3个正整数n，k 和m，表示给定的图G有n个顶点和k条边，m种颜色。顶点编号为1，2，…，n。接下来的k行中，每行有2个正整数u,v，表示图G 的一条边(u,v)。

n< = 100 k< = 2500 m< = 10

###### 【输出格式】

程序运行结束时，将计算出的不同的着色方案数输出

###### 【样例】

```
**样例输入**
5 8 4
1 2
1 3
1 4
2 3
2 4
2 5
3 4
4 5
**样例输出**
48
```

##### *Problem#14* 保卫牧场              

###### 【题目描述】

The farm has many hills upon which Farmer John would like to place guards  to ensure the safety of his valuable milk-cows. He wonders how many  guards he will need if he wishes to put one on top of each hill. He has a map supplied as a matrix of integers; the matrix has N (1 < N <=  700) rows and M (1 < M <= 700) columns. Each member of the matrix  is an altitude H_ij (0 <= H_ij <= 10,000). Help him determine the  number of hilltops on the map. A hilltop is one or more adjacent matrix  elements of the same value surrounded exclusively by either the edge of  the map or elements with a lower (smaller) altitude. Two different  elements are adjacent if the magnitude of difference in their X  coordinates is no greater than 1 and the magnitude of differences in  their Y coordinates is also no greater than 1.

农夫JOHN的农夫上有很多小山丘，他想要在那里布置一些保镖（……）去保卫他的那些相当值钱的奶牛们。 他想知道如果在一座小山丘上布置一名保镖的话，他总共需要招聘多少名保镖。 他现在手头有一个用数字矩阵来表示地形的地图。 这个矩阵有N行（1 < N < = 100)和M列( 1 < M < = 70) 。 矩阵中的每个元素都有一个值H_ij(0 < = H_ij < =10,000)来表示该地区的海拔高度。 请你帮助他统计出地图上到底有多少个小山丘。 小山丘的定义是： 若地图中一个元素所邻接的所有元素都比这个元素高度要小（或它邻接的是地图的边界），则该元素和其周围所有按照这样顺序排列的元素的集合称为一个小山丘。 这里邻接的意义是： 若一个元素与另一个横坐标纵坐标和它的横纵坐标相差不超过1，则称这两个元素邻接。

###### 【输入格式】

- Line 1: Two space-separated integers: N and M
- Lines 2..N+1: Line i+1 describes row i of the matrix with M space-separated integers: H_ij

第一行：两个由空格隔开的整数N和M

第二行到第N+1行：第I+1行描述了地图上的第I行，有M个由空格隔开的整数：H_ij.

###### 【输出格式】

- Line 1: A single integer that specifies the number of hilltops

第一行：小山丘的个数

###### 【样例】

```
**样例输入**
8 7
4 3 2 2 1 0 1
3 3 3 2 1 0 1
2 2 2 2 1 0 0
2 1 1 1 1 0 0
1 1 0 0 0 1 0
0 0 0 1 1 1 0
0 1 2 2 1 1 0
0 1 1 1 2 1 0
**样例输出**
3
**样例说明**
三个山丘分别是：左上角的高度为4的方格，右上角的高度为1的方格，还有最后一行中高度为2的方格．
**来源**
[USACO2008NOV] [DFS] Guarding the Farm 保卫牧场
```

##### *Problem#15* 地震损坏              

###### 【题目描述】

农夫John的农场遭受了一场地震. 有一些牛棚遭到了损坏,但幸运地,所有牛棚间的路经都还能使用. FJ的农场有P(1 <= P <= 30,000)个牛棚,编号1..P. C(1 <= C <=  100,000)条双向路经联接这些牛棚,编号为1..C. 路经i连接牛棚a_i和b_i (1 <= a_i<= P;1 <=  b_i <= P). 路经可能连接a_i到它自己,两个牛棚之间可能有多条路经.农庄在编号为1的牛棚. N (1 <= N <= P)头在不同牛棚的牛通过手机短信report_j(2 <= report_j <=  P)告诉FJ它们的牛棚(report_j)没有损坏,但是它们无法通过路经和没有损坏的牛棚回到到农场. 当FJ接到所有短信之后,找出最小的不可能回到农庄的牛棚数目.这个数目包括损坏的牛棚.

###### 【输入格式】

- 第1行: 三个空格分开的数: P, C, 和 N
- 第2..C+1行: 每行两个空格分开的数: a_i 和 b_i * 第C+2..C+N+1行: 每行一个数: report_j

###### 【输出格式】

第1行: 一个数,最少不能回到农庄的牛的数目(包括损坏的牛棚).

###### 【样例】

```
**样例输入**
4 3 1
1 2
2 3
3 4
3
**样例输出**
3
**样例说明**
牛棚2遭到损坏,导致牛棚2, 3, 4里面的牛无法回到农庄.
**来源**
[USACO2009JAN] [DFS] 地震损坏Damage
```

