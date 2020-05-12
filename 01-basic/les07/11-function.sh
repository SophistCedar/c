#!/bin/bash

funWithReturn(){
    echo "这个函数会对输入的两个数字进行相加运算..."
    echo "输入第一个数字: "
    read aNum
    echo "输入第二个数字: "
    read anotherNum
    echo "两个数字分别为 $aNum 和 $anotherNum !"
    return $(($aNum+$anotherNum))
}
funWithReturn
echo "输入的两个数字之和为 $? !"
echo $?
# 函数返回值在调用该函数后通过 $? 来获得。调用函数仅使用其函数名即可。
# 注意：所有函数在使用前必须定义。这意味着必须将函数放在脚本开始部分，直至shell解释器首次发现它时，才可以使用。
# $? 仅对其上一条指令负责，一旦函数返回后其返回值没有立即保存入参数，那么其返回值将不再能通过 $? 获得。
# 调用funWithReturn后，函数得到的返回值（$?值）为 return $(($aNum+$anotherNum))
# echo $?内, $?是上一条 echo 命令的返回值