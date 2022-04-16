## #STL应用      

##### *Problem#1* 大理石在哪儿(UVa10474）              

###### 【题目描述】

Raju and Meena love to play with Marbles. They have got a lot of marbles with numbers written on them. At the beginning, Raju would place the  marbles one after another in ascending order of the numbers written on  them. Then Meena would ask Raju to ﬁnd the ﬁrst marble with a certain  number. She would count 1...2...3. Raju gets one point for correct  answer, and Meena gets the point if Raju fails. After some ﬁxed number  of trials the game ends and the player with maximum points wins. Today  it’s your chance to play as Raju. Being the smart kid, you’d be taking  the favor of a computer. But don’t underestimate Meena, she had written a program to keep track how much time you’re taking to give all the  answers. So now you have to write a program, which will help you in your role as Raju.

 现有N个大理石，每个大理石上写了一个非负整数。首先把各数从小到大排序，然后回  答Q个问题。每个问题问是否有一个大理石写着某个整数x，如果是，还要回答哪个大理石上 写着x。排序后的大理石从左到右编号为1～N。

###### 【输入格式】

There can be multiple test cases. Total no of test cases is less than  65. Each test case consists begins with 2 integers: N the number of  marbles and Q the number of queries Mina would make. The next N lines  would contain the numbers written on the N marbles. These marble numbers will not come in any particular order. Following Q lines will have Q  queries. Be assured, none of the input numbers are greater than 10000  and none of them are negative. Input is terminated by a test case where N = 0 and Q = 0.

###### 【输出格式】

For each test case output the serial number of the case. For each of the queries, print one line of output. The format of this line will depend  upon whether or not the query number is written upon any of the marbles. The two diﬀerent formats are described below: • ‘x found at y’, if the  ﬁrst marble with number x was found at position y. Positions are  numbered 1,2,...,N. • ‘x not found’, if the marble with number x is not  present. Look at the output for sample input for details.

###### 【样例】

```
**样例输入**
4 1
2
3
5
1
5
5 2
1
3
3
3
1
2
3
0 0
**样例输出**
CASE #1:
5 found at 4
CASE #2:
2 not found
3 found at 3
```

##### *Problem#2*  积木问题(UVa101）              

###### 【题目描述】

Many areas of Computer Science use simple, abstract domains for both  analytical and empirical studies. For example, an early AI study of  planning and robotics (STRIPS) used a block world in which a robot arm  performed tasks involving the manipulation of blocks. 

在计算机科学中的很多地方都会使用简单，抽象的方法来做分析和实验验究。比如在早期的规划学和机器人学的人工智能研究就利用一个积木世界，让机械臂执行操作积木的任务。

In this problem you will model a simple block world under certain  rules and constraints. Rather than determine how to achieve a specified  state, you will "program" a robotic arm to respond to a limited set of  commands.

 在这个问题中，你将在确定的规则和约束条件下构建一个简单的积木世界。这不是让你来研究怎样达到某种状态，而是编写一个“机械臂程序”来响应有限的命令集。

问题 The problem is to parse a series of commands that instruct a robot arm  in how to manipulate blocks that lie on a flat table. Initially there  are n blocks on the table (numbered from 0 to n-1) with block bi  adjacent to block bi + 1 for all 0 ≤ i < n - 1 as shown in the  diagram below: 

问题就是分析一系列的命令，告诉机械臂如何操纵放在一个平台上的积木。最初平台上有n个积木（编号由0到n - 1），对于任意的0 ≤ i < n - 1，积木bi都与bi + 1相临。

The valid commands for the robot arm that manipulates blocks are: 

机械臂操作积木的有效指令列举如下：

move a onto b where a and b are block numbers, puts block a onto block b after  returning any blocks that are stacked on top of blocks a and b to their  initial positions.  pile a over b where a and b are block numbers, puts the pile of blocks consisting of  block a, and any blocks that are stacked above block a, onto the top of  the stack containing block b. The blocks stacked above block a retain  their original order when moved.

a和b都是积木的编号，先将a和b上面所有的积木都放回原处，再将a放在b上。(b上原有积木不动）, 将a和其上面所有的积极组成的一摞整体移动到b所在一摞积木的最上面一个积木上。移动的一摞积木要保持原来的顺序不变。

quit terminates manipulations in the block world. 结束积木世界的操纵。 Any command in which a = b or in which a and b are in the same stack of  blocks is an illegal command. All illegal commands should be ignored and should have no affect on the configuration of blocks. 

当a = b或a和b处在同一摞时，任何企图操作a和b的命令都是非法的。所有非法的命令都要忽略，且不能对当前积木的状态产生作用。

###### 【输入格式】

The input begins with an integer n on a line by itself representing the  number of blocks in the block world. You may assume that 0 < n <  25. 

输入由1个整数n开始开始，该整数独占一行，表示积木世界中的积木数量。你可以假定0 < n < 25。

The number of blocks is followed by a sequence of block commands, one command per line. Your program should process all commands until the  quit command is encountered. 

从积木数量值的下一行开始是一系列的命令，每条命令独占一行。你的程序要处理所有的命令直到输入退出命令。

You may assume that all commands will be of the form specified above. There will be no syntactically incorrect commands. 

你可以假定所有的命令都按上文所示的格式给出。不会出现语法错误的命令。

###### 【输出格式】

The output should consist of the final state of the blocks world. Each  original block position numbered i (0 ≤ i < n where n is the number  of blocks) should appear followed immediately by a colon. If there is at least a block on it, the colon must be followed by one space, followed  by a list of blocks that appear stacked in that position with each block number separated from other block numbers by a space. Don't put any  trailing spaces on a line.

 以积木世界的最终状态作为输出。每一个原始积木的位置i（0 ≤ i <  n，n为积木数量）后面都要紧跟一个冒号。如果至少有一个积木在该位置上，冒号后面都要紧跟一个空格，然后是该位置上所有积木编号的序列。每2个积木的编号之间以一个空格隔开。行尾不能出现多余的空格。

There should be one line of output for each block position (i.e., n  lines of output where n is the integer on the first line of input). 

每个积木位置独占一行（即第一行输入的n，对应输出n行数据）。

###### 【样例】

```
**样例输入**
10
move 9 onto 1
move 8 over 1
move 7 over 1
move 6 over 1
pile 8 over 6
pile 8 over 5
move 2 over 1
move 4 over 9
quit
**样例输出**
0: 0
1: 1 9 2 4
2:
3: 3
4:
5: 5 8 7 6
6:
7:
8:
9:
```

##### *Problem#3* 安迪的第一个字典（UVa10815）              

###### 【题目描述】

Andy, 8, has a dream - he wants to produce his very own dictionary. This is  not an easy task for him, as the number of words that he knows is, well, not quite enough. Instead of thinking up all the words himself, he has a briliant idea. From his bookshelf he would pick one of his favourite  story books, from which he would copy out all the distinct words. By  arranging the words in alphabetical order, he is done! Of course, it is a really time-consuming job, and this is where a computer program is  helpful.

You are asked to write a program that lists all the different words  in the input text. In this problem, a word is defined as a consecutive  sequence of alphabets, in upper and/or lower case. Words with only one  letter are also to be considered. Furthermore, your program must be CaSe InSeNsItIvE. For example, words like "Apple", "apple" or "APPLE" must  be considered the same.

输入一个文本，找出所有不同的单词（连续的字母序列），按字典序从小到大输出。单词不区分大小写。

###### 【输入格式】

The input file is a text with no more than 5000 lines. An input line has at most 200 characters. Input is terminated by EOF.

###### 【输出格式】

Your output should give a list of different words that appears in the  input text, one in a line. The words should all be in lower case, sorted in alphabetical order. You can be sure that he number of distinct words in the text does not exceed 5000.

###### 【样例】

```
**样例输入**
Adventures in Disneyland
Two blondes were going to Disneyland when they came to a fork in the
road. The sign read: "Disneyland Left."
So they went home.
**样例输出**
a
adventures
blondes
came
disneyland
fork
going
home
in
left
read
road
sign
so
the
they
to
two
went
were
when
```

##### *Problem#4* 反片语（UVa156）

###### 【题目描述】

Most crossword puzzle fans are used to anagrams--groups of words with the  same letters in different orders--for example OPTS, SPOT, STOP, POTS and POST. Some words however do not have this attribute, no matter how you  rearrange their letters, you cannot form another word. Such words are  called ananagrams, an example is QUIZ.

Obviously such definitions depend on the domain within which we are  working; you might think that ATHENE is an ananagram, whereas any  chemist would quickly produce ETHANE. One possible domain would be the  entire English language, but this could lead to some problems. One could restrict the domain to, say, Music, in which case SCALE becomes a  relative ananagram (LACES is not in the same domain) but NOTE is not  since it can produce TONE.

Write a program that will read in the dictionary of a restricted  domain and determine the relative ananagrams. Note that single letter  words are, ipso facto, relative ananagrams since they cannot be  "rearranged'' at all. The dictionary will contain no more than 1000  words.

输入一些单词，找出所有满足如下条件的单词：该单词不能通过字母重排，得到输入文本中的另外一个单词。在判断是否满足条件时，字母不分大小写，但在输出时应保留输入中的大小写，按字典序进行排序。

###### 【输入格式】

Input will consist of a series of lines. No line will be more than 80  characters long, but may contain any number of words. Words consist of  up to 20 upper and/or lower case letters, and will not be broken across  lines. Spaces may appear freely around words, and at least one space  separates multiple words on the same line. Note that words that contain  the same letters but of differing case are considered to be anagrams of  each other, thus tIeD and EdiT are anagrams. The file will be terminated by a line consisting of a single #.

###### 【输出格式】

Output will consist of a series of lines. Each line will consist of a  single word that is a relative ananagram in the input dictionary. Words  must be output in lexicographic (case-sensitive) order. There will  always be at least one relative ananagram.

###### 【样例】

```
**样例输入**
ladder came tape soon leader acme RIDE lone Dreis peat
 ScAlE orb  eye  Rides dealer  NotE derail LaCeS  drIed
noel dire Disk mace Rob dries
#
**样例输出**
Disk
NotE
derail
drIed
eye
ladder
soon
```

##### *Problem#5* 团体队列（UVa540）

###### 【题目描述】

Queues and Priority Queues are data structures which are known to most  computer scientists. The Team Queue, however, is not so well known,  though it occurs often in everyday life. At lunch time the queue in  front of the Mensa is a team queue, for example.

In a team queue each element belongs to a team. If an element enters  the queue, it first searches the queue from head to tail to check if  some of its teammates (elements of the same team) are already in the  queue. If yes, it enters the queue right behind them. If not, it enters  the queue at the tail and becomes the new last element (bad luck).  Dequeuing is done like in normal queues: elements are processed from  head to tail in the order they appear in the team queue.

Your task is to write a program that simulates such a team queue.

有t个团队的人正在排一个长队。每次新来一个人时,如果他有队友在排队,那么这个 新人会插队到最后一个队友的身后。如果没有任何一个队友排队,则他会排到长队的队尾。 输入每个团队中所有队员的编号,要求支持如下3种指令(前两种指令可以穿插进 行)。 ENQUEUEx:编号为x的人进入长队。 DEQUEUE:长队的队首出队。 STOP:停止模拟。 对于每个DEQUEUE指令,输出出队的人的编号。

###### 【输入格式】

The input file will contain one or more test cases. Each test case begins  with the number of teams t ( 1≤t≤1000). Then t team descriptions follow, each one consisting of the number of elements belonging to the team and the elements themselves. Elements are integers in the range 0 - 999999. A team may consist of up to 1000 elements. Finally, a list of commands follows. There are three different kinds of  commands:

```
ENQUEUE x - enter element x into the team queue
DEQUEUE - process the first element and remove it from the queue
STOP - end of test case
```

The input will be terminated by a value of 0 for t.

Warning: A test case may contain up to 200000 (two hundred thousand)  commands, so the implementation of the team queue should be efficient:  both enqueing and dequeuing of an element should only take constant  time.

###### 【输出格式】

For each test case, first print a line saying “ Scenario #k”, where k is the number of the test case. Then, for each DEQUEUE command, print the  element which is dequeued on a single line. Print a blank line after  each test case, even after the last one.

###### 【样例】

```
**样例输入**
2
3 101 102 103
3 201 202 203
ENQUEUE 101
ENQUEUE 201
ENQUEUE 102
ENQUEUE 202
ENQUEUE 103
ENQUEUE 203
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
STOP
2
5 259001 259002 259003 259004 259005
6 260001 260002 260003 260004 260005 260006
ENQUEUE 259001
ENQUEUE 260001
ENQUEUE 259002
ENQUEUE 259003
ENQUEUE 259004
ENQUEUE 259005
DEQUEUE
DEQUEUE
ENQUEUE 260002
ENQUEUE 260003
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
STOP
0
**样例输出**
Scenario #1
101
102
103
201
202
203
Scenario #2
259001
259002
259003
259004
259005
260001
```

##### *Problem#6* 集合栈计算机（UVa12096）

###### 【题目描述】

Background from Wikipedia: “Set theory is a branch of mathematics created  principally by the German mathematician Georg Cantor at the end of the  19th century. Initially controversial, set theory has come to play the  role of a foundational theory in modern mathematics, in the sense of a  theory invoked to justify assumptions made in mathematics concerning the existence of mathematical objects (such as numbers or functions) and their properties. Formal versions of set theory also have a foundational role to play as  specifying a theoretical ideal of mathematical rigor in proofs.” Given this importance of sets, being the basis of mathematics, a set of  eccentric theorist set off to construct a supercomputer operating on sets instead of numbers. The  initial SetStack Alpha is under construction, and they need you to simulate it in order to verify the  operation of the prototype. The computer operates on a single stack of sets, which is initially  empty. After each operation, the cardinality of the topmost set on the stack is output. The cardinality  of a set S is denoted |S| and is the number of elements in S. The instruction set of the SetStack Alpha is  PUSH, DUP, UNION, INTERSECT, and ADD.

```
• PUSH will push the empty set {} on the stack.
• DUP will duplicate the topmost set (pop the stack, and then push that set on the stack twice).
• UNION will pop the stack twice and then push the union of the two sets on the stack.
• INTERSECT will pop the stack twice and then push the intersection of the two sets on the stack
ADD will pop the stack twice, add the first set to the second one, and then push the resulting set
on the stack.
For illustration purposes, assume that the topmost element of the stack is
A = {{}, {{}}}
and that the next one is
B = {{}, {{{}}}}
For these sets, we have |A| = 2 and |B| = 2. Then:
• UNION would result in the set {{}, {{}}, {{{}}}}. The output is 3.
• INTERSECT would result in the set {{}}. The output is 1.
• ADD would result in the set {{}, {{{}}}, {{},{{}}}}. The output is 3.
```

有一个专门为了集合运算而设计的“集合栈”计算机。该机器有一个初始为空的栈，并且支持以下操作。

```
PUSH：空集“{}”入栈。
DUP：把当前栈顶元素复制一份后再入栈。
UNION：出栈两个集合，然后把二者的并集入栈。
INTERSECT：出栈两个集合，然后把二者的交集入栈。
ADD：出栈两个集合，然后把先出栈的集合加入到后出栈的集合中，把结果入栈。
每次操作后，输出栈顶集合的大小（即元素个数）。例如，栈顶元素是A={{}，{{}}}，下一个元素是B={{}，{{{}}}}，则：
UNION操作将得到{{}，{{}}，{{{}}}}，输出3。
INTERSECT操作将得到{{}}，输出1。
ADD操作将得到{{}，{{{}}}，{{}，{{}}}}，输出3。
```

输入不超过2000个操作，并且保证操作均能顺利进行（不需要对空栈执行出栈操作）。

###### 【输入格式】

An integer 0 ≤ T ≤ 5 on the first line gives the cardinality of the set of test cases. The first line of each test case contains the number of operations 0 ≤ N ≤ 2000. Then follow N lines each containing one of the five commands. It is guaranteed that the SetStack computer can execute all the commands in the sequence without ever popping an empty stack.

###### 【输出格式】

For each operation specified in the input, there will be one line of output consisting of a single integer. This integer is the cardinality of the topmost element of the stack after the corresponding command has executed. After each test case there will be a line with ‘***’ (three asterisks).

###### 【样例】

```
**样例输入**
2
9
PUSH
DUP
ADD
PUSH
ADD
DUP
ADD
DUP
UNION
5
PUSH
PUSH
ADD
PUSH
INTERSECT
**样例输出**
0
0
1
0
1
1
2
2
2
***
0
0
1
0
0
***
```

