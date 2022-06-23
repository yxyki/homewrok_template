# 动态规划算法实验报告

## 学号：20201060335

## *<font color=#0099ff>实验 2.1 动态规划算法的实现与时间复杂度测试</font>*

## 实验目的

编程实现经典的动态规划算法，理解动态规划算法设计的基本思想、程序实现的相关技巧，加深对动态规划算法设计与分析思想的理解。通过程序的执行时间测试结果，与理论上的时间复杂度结论进行对比、分析和验证。

## 实验原理

* **动态规划算法的基本思想**  

动态规划是一种在数学和计算机科学中使用的、用于求解包含重叠子问题的最优化问题的有效方法。其基本思想是：将原问题分解为相似的子问题，在求解的过程中通过子问题的解描述并求出原问题的解。动态规划的思想是多种算法的基础，被广泛应用于计算机科学和工程领域，在查找有很多重叠子问题的情况的最优解时有效。它将问题重新组合成子问题，为了避免多次解决这些子问题，它们的结果都逐渐被计算并保存，从小规模的子问题直到整个问题都被解决。因此，动态规划对每一子问题只做一次计算，具有较高的效率。  

* **测试算法**  

```C
KnapsackDP ({w1, w2, …, wn}, {v1, v2, …, vn}, C) 
  for i=0 to n do 
    m[i,0]=0 
  end for 
  for j=0 to C do 
    m[0,j]=0 
  end for 
  for i=1 to n do 
    for j=1 to C do
      m[i,j]=m[i-1,j] 
      if wi<=j then 
        m[i,j]=max{m[i,j],m[i-1,j-wi]+vi} 
      end if 
    end for 
  end for 
return m[n,C]
```
算法的时间复杂度为 *O(nC)*。

## 实验输入数据集

文本数据集：5,1,2,3,7,14,6  
文件数据集：[数据集](./data/list.txt)

## 实验内容

1. [max.py](./max.py) 算法实现的python版本
1. [max.c](max.c) 算法实现的C语言版本
1. [max.java](max.java) 算法实现的java版本

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

## *<font color=#0099ff>实验 2.2 动态规划算法的适应性测试</font>*

## 实验目的：

对于同一问题，编程实现其分治算法和动态规划算法，通过对比分析，理解动态规划算法的适用情形。通过程序的执行时间测试结果，与理论结论进行对比、分析和验证。

## 实验原理

* **分治算法与动态规划算法的对比：针对子问题是否重叠**  

虽然很多问题均可分解为子问题、动态规划和分治算法都是通过子问题的解决来获得原问题的解。然而，分治算法适用于子问题不重叠（即相互独立）的情形，对于子问题重叠的情形分治法具有较高的时间复杂度，动态规划是针对这类情形的有效算法。  

* **测试算法**  

斐波纳契数列在现代物理、准晶体结构、化学等领域都有直接的应用。斐波那契数列指的是这样一个数列：1、1、2、3、5、8、13、21、……，这个数列从第三项开始，每一项都等于前两项之和，即：


## 实验输入数据集

文本数据集：5,1,2,3,7,14,6  
文件数据集：[数据集](./data/list.txt)

## 实验内容

1. [max.py](./max.py) 算法实现的python版本
1. [max.c](max.c) 算法实现的C语言版本
1. [max.java](max.java) 算法实现的java版本

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