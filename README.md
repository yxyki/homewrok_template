# 分治算法实验报告

## 学号：20201060335

## 实验目的：

通过排序算法的程序实现和执行时间测试，与理论上的结论进行对比分析，深入理解算法时间复杂度渐进性态和和增长率的概念；理解分治算法设计的基本思想、递归程序实现的基本方法，加深对分治算法设计与分析思想的理解。

## 实验原理

* **算法时间复杂度分析的相关概念**

(1) 算法的计算时间取决于算法中某些操作的执行次数，这些操作是算法时间复杂度分析的依据。增长率反映了算法的计算时间复杂度，即随着算法输入规模的增加、算法计算时间增加的趋势。算法的计算时间复杂度针对输入数据的等价类来分析或测试。

* **随机数生成算法**

通过程序生成（伪）随机数，作为实验用测试数据。可使用编程语言自带的random 函数生成，也可以采用一些有效的随机数生成算法生成，例如“线性同余法”，基于该算法，只要参数选择合适，所产生的伪随机数就能满足均匀性和独立性，与真正的随机数具有相近的性质。该算法的基本思想如下：

通过设置 X<sub>i+1</sub>=(aX<sub>i</sub>+c) mod m, n>=0，其中的 4 个整数参数：m——模数, m>0；a——乘数, 0<=a<m；c——增量，0<=c<m；X<sub>0</sub>——开始值， 0<=X<sub>0</sub><m。这样得到所求的随机数序列{X<sub>i</sub>}，称作线形同余序列。

* **分治算法**

分治算法的基本思想是将一个规模为 n 的问题分解为 k 个规模较小的子问题，这些子问题相互独立且与原问题性质相同。求出子问题的解，就可得到原问题的解。分治算法设计的一般步骤包括：
1. 分解，将要解决的问题划分成若干规模较小的同类问题；
2. 求解，当子问题划分得足够小时，用较简单的方法解决；
3. 合并，按原问题的要求，将子问题的解逐层合并构成原问题的解。

分治法的基本设计范式如下：
```C
DivideAndConquer(data,n,solution) 
  if(n≤SizeLimit) then 
    DirectSolution(data,n,solution) 
  else 
    DivideInput(data,n,smallerSets,smallerSizes,numberSmaller) 
    for i=1 to numberSmaller do 
      DivideAndConquer(smallerSets[i],smallerSizes[i],smallerSolution[i]) 
    end for 
    CombineSolutions(smallerSolution,numberSmaller,solution) 
  end if 
```
## 实验输入数据集

文本数据集：5,1,2,3,7,14,6  
文件数据集：[数据集](./data/list.txt)

## 实验内容

以冒泡排序、合并排序和快速排序算法为例，以生成的随机数作为实验中使用的测试数据。对每个算法，记录程序执行中随着测试数据增加算法基本操作执行次数，分析并以图形方式展现增长率；对以上三个排序算法，对比随着测试数据增加算法增长率变化趋势；测试、验证、对比算法时间复杂度的理论结论。


## 实验预期结果与实际结果
+ 实验预期结果：14

实验过程及实验结果（Java版）

```bash
gitpod /workspace/homewrok_template (main) $ javac Max.java
Picked up JAVA_TOOL_OPTIONS:  -Xmx3435m
gitpod /workspace/homewrok_template (main) $ java Max
Picked up JAVA_TOOL_OPTIONS:  -Xmx3435m
14

```

实验过程及实验结果（C版）

```bash
gitpod /workspace/homewrok_template (main) $ gcc -o max.exe max.c
gitpod /workspace/homewrok_template (main) $ ./max.exe 
14

```

实验过程及实验结果（Python版）

```bash
gitpod /workspace/homewrok_template (main) $ python max.py 
14

```