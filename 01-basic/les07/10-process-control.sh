#!/bin/bash

# if
# 以下实例判断两个变量是否相等：
a=10
b=20
if [ $a == $b ]
then
   echo "a 等于 b"
elif [ $a -gt $b ]
then
   echo "a 大于 b"
elif [ $a -lt $b ]
then
   echo "a 小于 b"
else
   echo "没有符合的条件"
fi
# if else语句经常与test命令结合使用，如下所示：
# 代码中的 [] 执行基本的算数运算，如：
# result=$[a+b] 注意等号两边不能有空格
num1=$[2*3]
num2=$[1+5]
if test $[num1] -eq $[num2]
then
    echo '两个数字相等!'
else
    echo '两个数字不相等!'
fi

# for
# 顺序输出当前列表中的数字：
for loop in 1 2 3 4 5
do
    echo "The value is: $loop"
done
# 顺序输出字符串中的字符：
for str in 'This is a string'
do
    echo $str
done

# while 语句
int=1
while(( $int<=5 ))
do
    echo $int
    let "int++"
done
# 以上实例使用了 Bash let 命令，它用于执行一个或多个表达式，变量计算中不需要加上 $ 来表示变量.
# while循环可用于读取键盘信息。下面的例子中，输入信息被设置为变量FILM，按<Ctrl-D>结束循环。
echo '按下 <CTRL-D> 退出'
echo -n '输入你最喜欢的网站名: '
while read FILM
do
    echo "是的！$FILM 是一个好网站"
done


# case
# case ... esac 与其他语言中的 switch ... case 语句类似，是一种多分枝选择结构，
# 每个 case 分支用右圆括号开始，用两个分号 ;; 表示 break，即执行结束，跳出整个 case ... esac 语句，
# esac（就是 case 反过来）作为结束标记。
echo '输入 1 到 4 之间的数字:'
echo '你输入的数字为:'
read aNum
case $aNum in
    1)  echo '你选择了 1'
    ;;
    2)  echo '你选择了 2'
    ;;
    3)  echo '你选择了 3'
    ;;
    4)  echo '你选择了 4'
    ;;
    *)  echo '你没有输入 1 到 4 之间的数字'
    ;;
esac

site="runoob"
case "$site" in
   "runoob") echo "菜鸟教程" 
   ;;
   "google") echo "Google 搜索" 
   ;;
   "taobao") echo "淘宝网" 
   ;;
esac