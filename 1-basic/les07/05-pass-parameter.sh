#!/bin/bash
# Shell 传递参数
# 我们可以在执行 Shell 脚本时，向脚本传递参数，脚本内获取参数的格式为：$n。
# n 代表一个数字，1 为执行脚本的第一个参数，2 为执行脚本的第二个参数，以此类推……
# 实例
# 以下实例我们向脚本传递三个参数，并分别输出，其中 $0 为执行的文件名：
echo "Shell 传递参数实例！";
echo "执行的文件名：$0";
echo "第一个参数为：$1";
echo "第二个参数为：$2";
echo "第三个参数为：$3";
echo "参数个数为：$#";
echo "传递的参数作为一个字符串显示：$*";

echo "-- \$* 演示 ---"
for i in "$*"; do
    echo $i
done

echo "-- \$@ 演示 ---"
for i in "$@"; do
    echo $i
done
