## 第一节 数的概念 第二节 二叉树         

##### *Problem#1* 找树根和孩子              

###### 【题目描述】

给定一棵树，输出树的根root，孩子最多的结点max以及他的孩子

###### 【输入格式】

第一行：n（结点数 < =100），m（边数< = 200）。 　　 以下m行；每行两个结点x和y， 表示y是x的孩子(x,y < =1000)。

###### 【输出格式】

第一行：树根：root。 　　 第二行：孩子最多的结点max。 　　 第三行：max的孩子。

###### 【样例】

```
**样例输入**
8 7
4 1
4 2
1 3
1 5
2 6
2 7
2 8
**样例输出**
4
2 
6 7 8
```

##### *Problem#2*  查找二叉树              

###### 【题目描述】

已知一棵二叉树用邻接表结构存储，中序查找二叉树中值为x的结点，并指出是第几个结点。例：如图二叉树的数据文件的数据格式如下 ![img](http://faioj.brynhild.online/images/1296m/1.jpg)

```
7 
15 
5 2 3 
12 4 5 
10 0 0 
29 0 0 
15 6 7 
8 0 0 
23 0 0 
```

###### 【输入格式】

第一行n为二叉树的结点个树，n<=100；第二行x表示要查找的结点的值；以下第一列数据是各结点的值，第二列数据是左儿子结点编号，第三列数据是右儿子结点编号。

###### 【输出格式】

输出一个数即查找的结点编号。

###### 【样例】

```
**样例输入**
7
15
5 2 3
12 4 5
10 0 0
29 0 0
15 6 7
8 0 0
23 0 0
**样例输出**
4
```

##### *Problem#3* 遍历二叉树              

###### 【题目描述】

所谓二叉树的遍历是指按一定的规律和次序访问树中的各个结点，而且每个结点仅被访问一次。“访问”的含义很广，可以是对结点作各种处理，如输出结点的信息等。遍历一般按照从左到右的顺序，共有3种遍历方法，先（根）序遍历，中（根）序遍历，后（根）序遍历。 现在按前序遍历顺序输入这个树，空节点用$表示，#表示输入结束。 用嵌套括号表示法输出二叉树，输出前序、中序、后续遍历。节点都用大写字母表示。

###### 【输入格式】

现在按前序遍历顺序输入这个树，空节点用$表示，#表示输入结束。

###### 【输出格式】

4行，用嵌套括号表示法输出二叉树，输出前序、中序、后续遍历。

###### 【样例】

```
**样例输入**
-+a$$*b$$-c$$d$$/e$$f$$#
**样例输出**
-(+(a,*(b,-(c,d))),/(e,f))
-+a*b-cd/ef
a+b*c-d-e/f
abcd-*+ef/-
```

##### *Problem#4* 求树的后序遍历              

###### 【题目描述】

现给出一颗二叉树的前序遍历和中序遍历，输出它的后序遍历，长度均不超过26。

###### 【输入格式】

第一行为一个字符串，为该二叉树的中序遍历； 第二行为一个字符串，为该二叉树的前序遍历。

###### 【输出格式】

仅一行，为一个字符串，表示该二叉树的后序遍历。

###### 【样例】

```
**样例输入**
DBGEACHFI
ABDEGCFHI
**样例输出**
DGEBHIFCA
```

##### *Problem#5* 扩展二叉树

###### 【题目描述】

由于先序、中序和后序序列中的任一个都不能唯一确定一棵二叉树，所以对二叉树做如下处理，将二叉树的空结点用·补齐，如图所示。

 ![img](http://faioj.brynhild.online/images/1292m/1.jpg)

我们把这样处理后的二叉树称为原二叉树的扩展二叉树，扩展二叉树的先序和后序序列能唯一确定其二叉树。

现给出扩展二叉树的先序序列，要求输出其中序和后序序列。

###### 【输入格式】

扩展二叉树的先序序列

###### 【输出格式】

输出其中序和后序序列

###### 【样例】

```
**样例输入**
ABD..EF..G..C..
**样例输出**
DBFEGAC
DFGEBCA
```

##### *Problem#6* 小球              

###### 【题目描述】

许多的小球一个一个的从一棵满二叉树上掉下来组成FBT（Full Binary  Tree，满二叉树），每一时间，一个正在下降的球第一个访问的是非叶子节点。然后继续下降时，或者走右子树，或者走左子树，直到访问到叶子节点。决定球运动方向的是每个节点的布尔值。最初，所有的节点都是FALSE，当访问到一个节点时，如果这个节点是FALSE，则这个球把它变成TRUE，然后从左子树走，继续它的旅程。如果节点是TRUE，则球也会改变它为FALSE，而接下来从右子树走。满二叉树的标记方法如下图。

 ![img](http://faioj.brynhild.online/images/1293m/1.jpg)

因为所有的节点最初为FALSE，所以第一个球将会访问节点1，节点2和节点4，转变节点的布尔值后在在节点8停止。第二个球将会访问节点1、3、6,在节点12停止。明显地，第三个球在它停止之前，会访问节点1、2、5，在节点10停止。 　现在你的任务是，给定FBT的深度D，和I，表示第I个小球下落，你可以假定I不超过给定的FBT的叶子数，写一个程序求小球停止时的叶子序号

###### 【输入格式】

输入文件仅一行包含两个用空格隔开的整数D和I。其中2<=D<=20，1<=I<=524288。

###### 【输出格式】

对应输出第I个小球下落停止时的叶子序号。

###### 【样例】

```
**样例输入**
4 2
**样例输出**
12
```

##### *Problem#7* 二叉树遍历              

###### 【题目描述】

树和二叉树基本上都有先序、中序、后序、按层遍历等遍历顺序，给定中序和其它一种遍历的序列就可以确定一棵二叉树的结构。 　假定一棵二叉树一个结点用一个字符描述，现在给出中序和按层遍历的字符串，求该树的先序遍历字符串。

###### 【输入格式】

共两行，每行是由字母组成的字符串（一行的每个字符都是唯一的），分别表示二叉树的中序遍历和按层遍历的序列。

###### 【输出格式】

一行，表示二叉树的先序序列。

###### 【样例】

```
**样例输入**
DBEAC
ABCDE
**样例输出**
ABDEC
```

##### *Problem#8* 二叉树输出              

###### 【题目描述】

树的凹入表示法主要用于树的屏幕或打印输出，其表示的基本思想是兄弟间等长，一个结点要不小于其子结点的长度。二叉树也可以这样表示，假设叶结点的长度为1，一个非叶结点的长并等于它的左右子树的长度之和。

```
    一棵二叉树的一个结点用一个字母表示（无重复），输出时从根结点开始： 
	每行输出若干个结点字符（相同字符的个数等于该结点长度）， 
	如果该结点有左子树就递归输出左子树； 
	如果该结点有右子树就递归输出右子树。 
	假定一棵二叉树一个结点用一个字符描述，现在给出先序和中序遍历的字符串，用树的凹入表示法输出该二叉树。 
```

###### 【输入格式】

共两行，每行是由字母组成的字符串（一行的每个字符都是唯一的），分别表示二叉树的先序遍历和中序遍历的序列。

###### 【输出格式】

行数等于该树的结点数，每行的字母相同.

###### 【样例】

```
**样例输入**
ABCDEFG
CBDAFEG
**样例输出**
AAAA
BB
C
D
EE
F
G
```

##### *Problem#9* 圣诞树              

###### 【题目描述】

“叮叮当，叮叮当，铃儿响叮当……”一年一度的圣诞节又来临了。 今年，霍比特人Timmy打算自己布置一棵圣诞树，瞧，他正在圣诞树上挂彩灯和苹果呢。Timmy的圣诞树是图1的一种形式：

这是一棵严格意义上的“二叉树”。然后，将其稍做变化如图2所示，就可以变成另一种形状不同的圣诞树！ Timmy一下来了兴趣，他有N个彩灯或苹果要挂在圣诞树上，因此，圣诞树必须有且仅有N个节点。你能帮助Timmy统计出这样的“圣诞树”一共有多少种么？

###### 【输入格式】

输入文件包含一行一个整数N（1 < n < 1000 ）。

###### 【输出格式】

输出文件包含一行一个整数，为“圣诞树”的种数。

###### 【样例】

```
**样例输入**
2
**样例输出**
2
```

##### *Problem#10* 美国血统              

###### 【题目描述】

农夫约翰非常认真地对待他的奶牛们的血统。然而他不是一个真正优秀的记帐员。他把他的奶牛们的家谱作成二叉树，并且把二叉树以更线性 的”树的中序遍历“和”树的前序遍历“的符号加以记录而不是用图形的方法。 你的任务是在被给予奶牛家谱的”树中序遍历“和”树前序遍历“的符号后，创建奶牛家谱的”树的后序遍历“的符号。每一头奶牛的姓名被 译为一个唯一的字母。（你可能已经知道你可以在知道树的两种遍历以后可以经常地重建这棵树。）显然，这里的树不会有多余26个的顶点。 这是在样例输入和样例输出中的树的图形表达方式：

```
                  C
                /   \
               /     \
              B       G
             / \     /
            A   D   H
               / \
              E   F

树的中序遍历是打印左子树，根和右子树。 
树的前序遍历是打印根，左子树和右子树。 
树的后序遍历是打印左子树，右子树和根。 
```

###### 【输入格式】

第一行： 树的中序遍历 第二行： 同样的树的前序遍历

###### 【输出格式】

单独的一行表示该树的后序遍历。

###### 【样例】

```
**样例输入**
ABEDFCHG
CBADEFGH
**样例输出**
AEFDBHGC
```

##### *Problem#11* FBI树

###### 【题目描述】

我们可以把由“0”和“1”组成的字符串分为三类：全“0”串称为B串，全“1”串称为I串，既含“0”又含“1”的串则称为F串。 FBI树是一种二叉树 ，它的结点类型也包括F结点，B结点和I结点三种。由一个长度为2N的“01”串S可以构造出一棵FBI树T，递归的构造方法如下：

1. T的根结点为R，其类型与串S的类型相同；
2. 若串S的长度大于1，将串S从中间分开，分为等长的左右子串S1和S2；由左子串S1构造R的左子树T1，由右子串S2构造R的右子树T2。 现在给定一个长度为2^N的“01”串，请用上述构造方法构造出一棵FBI树，并输出它的后序遍历序列。

###### 【输入格式】

第一行是一个整数N（ 0 <= N <= 10），第二行是一个长度为2N的“01”串。

###### 【输出格式】

包括一行，这一行只包含一个字符串，即FBI树的后序遍历序列。

###### 【样例】

```
**样例输入**
3
10001011
**样例输出**
IBFBBBFIBFIIIFF
```

###### 【数据范围与提示】

对于40%的数据，N <= 2； 对于全部的数据，N <= 10。

##### *Problem#12* 

###### 【题目描述】

一棵有点权的有根树如果满足以下条件，则被轩轩称为**对称二叉树**：

1. 二叉树；
2. 将这棵树**所有**节点的左右子树交换，新树和原树对应位置的结构相同且点权相等。

下图中节点内的数字为权值，节点外的 $id$表示节点编号。

![img](https://uploadfiles.nowcoder.com/images/20181110/306604_1541848852978_E09FB8BAC799B78F2BA4FA809F4F25DE)

现在给出一棵二叉树，希望你找出它的一棵子树，**该子树为对称二叉树，且节点数最多**。请输出这棵子树的节点数。

注意：只有树根的树也是对称二叉树。本题中约定，以节点 $T$为子树根的一棵「子树」指的是：节点  $T$  和它的**全部**后代节点构成的二叉树。

###### 【输入格式】

输入文件名为 `tree.in`。

第一行一个正整数 $n$  ，表示给定的树的节点的数目，规定节点编号 $1$ ~$n$ ，其中节点 1是树根。
 第二行n个正整数，用一个空格分隔，第i个正整数$v_i$代表节点i的权值。
 接下来n行，每行两个正整数$l_i,r_i$，分别表示节点 i的左右孩子的编号。如果不存在左 / 右孩子，则以-1表示。两个数之间用一个空格隔开。

###### 【输出格式】

输出文件名为 `tree.out`。

输出文件共一行，包含一个整数，表示给定的树的最大对称二叉子树的节点数。

###### 【样例】

```
**样例输入1**
2 
1 3 
2 -1 
-1 -1 
**样例输出1**
1
**样例输入2**
10 
2 2 5 5 5 5 4 4 2 3 
9 10 
-1 -1 
-1 -1 
-1 -1 
-1 -1 
-1 2 
3 4 
5 6 
-1 -1 
7 8
**样例输出2**
3
样例 3
见附加文件中的 tree3.in 和 tree3.ans。
```

###### 【数据范围与提示】

#样例解释 1

![img](https://i.loli.net/2018/11/11/5be7dc1eacbf9.png)

最大的对称二叉子树为以节点 2 为树根的子树，节点数为1 。

#样例解释 2

![img](https://i.loli.net/2018/11/11/5be7dc1fa0e72.png)

最大的对称二叉子树为以节点7 为树根的子树，节点数为3。

共 25个测试点,$v_i<=1000$ 。

测试点1~3    , n<=10 ，保证根结点的左子树的所有节点都没有右孩子，根结点的右子树的所有节点都没有左孩子。
 测试点 4~8      ,    n<=10   。
 测试点 9~12, $n<=10^5$ ，保证输入是一棵「满二叉树」。
 测试点  13~16 ,$n<=10^5$ ，保证输入是一棵「完全二叉树」。
 测试点17~20 , $n<=10^5$  ，保证输入的树的点权均为1 。
 测试点 21~25, $n<=10^5$。

#### 本题约定：

**层次**：节点的层次从根开始定义起，根为第一层，根的孩子为第二层。树中任一节点的层次等于其父亲节点的层次加 1。 树的深度:树中节点的最大层次称为树的深度。

**满二叉树**：设二叉树的深度为 h，且二叉树有 $2^h-1$ 个节点，这就是满二叉树。

![img](https://uploadfiles.nowcoder.com/images/20181110/306604_1541859030087_B663B244A48AAD0CE81DCC50E78E1386)

**完全二叉树**：设二叉树的深度为h，除第h层外，其它各层的结点数都达到最大个数，第 

   层所有的结点都连续集中在最左边，这就是完全二叉树。

![img](https://uploadfiles.nowcoder.com/images/20181110/306604_1541859056448_08E14E77121B5C0CDDB7A458EF4DC4C3)


