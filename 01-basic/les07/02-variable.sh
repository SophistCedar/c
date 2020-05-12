#!/bin/bash
#定义变量,显式地直接赋值
your_name="runoob.com"
echo $your_name
echo ${your_name} # use this type with {}

# 用语句给变量赋值
for skill in Ada Coffe Action Java; do
    echo "I am good at ${skill}Script"
done
# for file in $(ls /etc); do
#     echo ${file}
# done

# 已定义的变量，可以被重新定义
your_name = "tom"
echo ${your_name}
your_name = "alibaba"
echo ${your_name}

# 只读变量
# 使用 readonly 命令可以将变量定义为只读变量，只读变量的值不能被改变。
myUrl="http://www.google.com"
readonly myUrl
echo ${myUrl}

# 删除变量
# 使用 unset 命令可以删除变量。语法：unset variable_name
myUrl1="http://www.runoob.com"
unset myUrl1
echo ${myUrl1}
# 以上实例执行将没有任何输出。

# 变量类型
# 运行shell时，会同时存在三种变量：
#     1) 局部变量 局部变量在脚本或命令中定义，仅在当前shell实例中有效，其他shell启动的程序不能访问局部变量。
#     2) 环境变量 所有的程序，包括shell启动的程序，都能访问环境变量，有些程序需要环境变量来保证其正常运行。必要的时候shell脚本也可以定义环境变量。
#     3) shell变量 shell变量是由shell程序设置的特殊变量。shell变量中有一部分是环境变量，有一部分是局部变量，这些变量保证了shell的正常运行

