# 分治算法实验报告

## 学号：20201060335

## 实验目的

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

随机数据集（10 个，100 个，1000 个，2000 个，5000 个，10000 个，100000 个，……）

## 实验内容

以冒泡排序、合并排序和快速排序算法为例，以生成的随机数作为实验中使用的测试数据。对每个算法，记录程序执行中随着测试数据增加算法基本操作执行次数，分析并以图形方式展现增长率；对以上三个排序算法，对比随着测试数据增加算法增长率变化趋势；测试、验证、对比算法时间复杂度的理论结论。  
**代码链接**：  
[BubleSort.c](https://github.com/yxyki/homewrok_template/blob/main/Experiment_1/BubleSort.c)  
[MergeSort.c](https://github.com/yxyki/homewrok_template/blob/main/Experiment_1/MergeSort.c)  
[QuickSort.c](https://github.com/yxyki/homewrok_template/blob/main/Experiment_1/QuickSort.c)  

(1) “比较”是以上排序算法的基本操作（即决定算法执行效率的主要操作），在算法中设置比较操作的计数器，编程实现算法（输出最终的计数值）并进行测试，保证程序正确无误。  
(2) 使用随机数生成方法生成包含 100 个随机数的测试数据，记录这些数据，并分别记录以上三个排序算法比较操作的执行次数；再重新生成包含 100 个随机数的测试数据，记录这些数据三个排序算法比较操作的执行次数。对比两次生成的测试数据和算法执行中比较操作的次数，理解算法复杂度分析时输入数据等价类的含义。  
(3) 使用随机数生成方法生成不同规模的测试数据（10 个，100 个，1000 个，2000 个，5000 个，10000 个，100000 个，……），对于每种规模的测试数据，分别记录 BubbleSort、MergeSort 和 QuickSort 算法执行中比较操作的执行次数，使用 MS Excel、Matlab 或 Origin 等图表绘制工具生成随着输入数据增加、以上三个算法比较操作次数增加的对比曲线图（折线）。基于生成的曲线图，与时间复杂度的理论结论对比分析，理解计算时间渐进性态和增长率的概念。  
(4) 在 MergeSort 和 QuickSort 算法中设置比较操作执行的全局计数器，编程实现算法（输出最终的计数值）；设置记录每次递归调用时描述问题规模的变量，程序结束时输出其值；通过测试保证程序正确无误，注意递归程序的实现、调试和测试。使用（3）中生成的测试数据（10 个，100 个，1000 个，2000 个，5000个，10000 个，100000 个，……），对于每种规模的测试数据，分别记录以上两个算法执行中各子问题的规模，并用表格方式记录所有情形各子问题的规模值。

## 实验预期结果与实际结果
+ 实验预期结果：以n个随机数为例,可以预测实验结果：BubleSort比较次数为n*(n-1)/2次，MergeSort比较次数为

以下实验过程是以10个随机数为例（100及以上数据过多）

**实验过程及实验结果:**  
（C版,BubleSort）
```bash
gitpod /workspace/homewrok_template/Experiment_1 (main) $ gcc -o BubleSort.exe BubleSort.c
gitpod /workspace/homewrok_template/Experiment_1 (main) $ ./BubleSort.exe
请输入排序的元素个数:10
请输入元素的最大值（取值范围）:100
生成的随机序列为:53 99 29 73 43 91 27 59 44 65 
排序之后为:27 29 43 44 53 59 65 73 91 99 
规模为10的数据比较次数为42
```
（C版，MergeSorrt）
```bash
gitpod /workspace/homewrok_template/Experiment_1 (main) $ gcc -o MergeSort.exe MergeSort.c
gitpod /workspace/homewrok_template/Experiment_1 (main) $ ./MergeSort.exe
请输入排序的元素个数:10
请输入最大元素(取值范围):100
生成的随机序列为:83 38 62 18 74 97 21 11 90 10 
排序之后为:10 11 18 21 38 62 74 83 90 97 
规模为10的序列的比较次数为:23
```
（C版，QuickSort）
```bash
gitpod /workspace/homewrok_template/Experiment_1 (main) $ gcc -o QuickSort.exe QuickSort.c
gitpod /workspace/homewrok_template/Experiment_1 (main) $ ./QuickSort.exe
请输入排序的元素个数:10
请输入最大元素(取值范围):50
生成的随机序列为:33 5 18 48 37 29 35 3 35 2 
排序之后为:2 3 5 18 29 33 35 35 37 48 
规模为10的序列的比较次数为:22
```
由matlab软件画出该三种算法随着数据规模的增加，比较次数的曲线图如下：  
*三种算法的比较曲线：*  
![](https://github.com/yxyki/homewrok_template/raw/main/Experiment_1/img/exp1_1.png)

*MergeSort与QuickSort之间的比较：*  
![](https://github.com/yxyki/homewrok_template/raw/main/Experiment_1/img/exp1_2.png)  
