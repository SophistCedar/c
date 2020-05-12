#!/bin/bash

# 输出重定向
who > users
cat users
# 输出重定向会覆盖文件内容，请看下面的例子：
echo "菜鸟教程：www.runoob.com" > users
cat users
# 如果不希望文件内容被覆盖，可以使用 >> 追加到文件末尾，例如：
echo "菜鸟教程：www.runoob.com" >> users
cat users


# 输入重定向
# 在命令行中通过 wc -l 命令计算 Here Document 的行数：
wc -l << EOF
    欢迎来到
    菜鸟教程
    www.runoob.com
EOF

ls /etc > /dev/null
find /etc -name "*.txt"  >list 2>&1
# /dev/null 文件
# 如果希望执行某个命令，但又不希望在屏幕上显示输出结果，那么可以将输出重定向到 /dev/null：
# /dev/null 是一个特殊的文件，写入到它的内容都会被丢弃；如果尝试从该文件读取内容，那么什么也读不到。
# 但是 /dev/null 文件非常有用，将命令的输出重定向到它，会起到"禁止输出"的效果。
# 如果希望屏蔽 stdout 和 stderr，可以这样写：
# command > /dev/null 2>&1 
# 放在>后面的&，表示重定向的目标不是一个文件，而是一个文件描述符
# &>或者>&视作整体，分开没有单独的含义
# 对于上面 '2>&1'，举个例子，比如说:
# $ find /etc -name "*.txt"  >list 2>&1
# 从左往右执行，执行到 >list，此时的 stdout 为 list；而执行到 2>&1，表示 stderr 重定向到 stdout，这里也就是 list 文件。

# Shell 输入/输出重定向
# 大多数 UNIX 系统命令从你的终端接受输入并将所产生的输出发送回​​到您的终端。一个命令通常从一个叫标准输入的地方读取输入，默认情况下，这恰好是你的终端。同样，一个命令通常将其输出写入到标准输出，默认情况下，这也是你的终端。
# 重定向命令列表如下：
# 命令	说明
# command > file	将输出重定向到 file。
# command < file	将输入重定向到 file。
# command >> file	将输出以追加的方式重定向到 file。
# n > file	将文件描述符为 n 的文件重定向到 file。
# n >> file	将文件描述符为 n 的文件以追加的方式重定向到 file。
# n >& m	将输出文件 m 和 n 合并。
# n <& m	将输入文件 m 和 n 合并。
# << tag	将开始标记 tag 和结束标记 tag 之间的内容作为输入。
# 需要注意的是文件描述符 0 通常是标准输入（STDIN），1 是标准输出（STDOUT），2 是标准错误输出（STDERR）。