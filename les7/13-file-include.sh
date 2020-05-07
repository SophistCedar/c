#!/bin/bash

#使用 . 号来引用1-test.sh 文件
# 注：被包含的文件 1-test.sh 不需要可执行权限。
. ./1-test.sh

# 或者使用以下包含文件代码
# source ./1-test.sh

echo "菜鸟教程官网地址：$url"