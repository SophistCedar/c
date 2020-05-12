##进入与退出
进入GDB　　#gdb test.out
　　test是要调试的程序，由gcc -g test.c  -o test.out生成。进入后提示符变为(gdb) 。
退出GDB　　(gdb) q


##断点设置
设置断点　　(gdb) b 6
　　这样会在运行到源码第6行时停止，可以查看变量的值、堆栈情况等；这个行号是gdb的行号。
查看断点处情况　　(gdb) info b
　　可以键入"info b"来查看断点处情况，可以设置多个断点；
设置条件断点        break + 行号 + if + 条件　　
        break 10 if i==3　　　用于设置条件断点，在循环中使用非常方便
清除断点        clear + 要清除的断点行号　　
        clear 10　　　　用于清除对应行的断点，要给出断点的行号，清除时GDB会给出提示
删除断点        delete + 要清除的断点编号　　
        delete 3　　　　用于清除断点和自动显示的表达式的命令，要给出断点的编号，清除时GDB不会给出任何提示


##查看命令
查看源码　　(gdb) l
　　源码会进行行号提示。
　　如果需要查看在其他文件中定义的函数，在l后加上函数名即可定位到这个函数的定义及查看附近的其他源码。或者：使用断点或单步运行，到某个函数处使用s进入这个函数。
显示变量值　　(gdb) p n
　　在程序暂停时，键入"p 变量名"(print)即可；
　　GDB在显示变量值时都会在对应值之前加上"$N"标记，它是当前变量值的引用标记，以后若想再次引用此变量，就可以直接写作"$N"，而无需写冗长的变量名；
观察变量　　(gdb) watch n
        在某一循环处，往往希望能够观察一个变量的变化情况，这时就可以键入命令"watch"来观察变量的变化情况，GDB在"n"设置了观察点；
查看函数        step(s)        
        s        进入式（会进入到所调用的子函数中）单步执行，进入函数的前提是，此函数被编译有debug信息
观察堆栈        f/frame　　
        frame 1　　用于打印指定栈帧
查看堆栈        info stack / info f　
        info f　　    查看堆栈使用情况


##运行命令
r/run　　程序开始执行，
程序继续运行　　(gdb) c
　　使程序继续往下运行，直到再次遇到断点或程序结束；
start        程序开始单步运行
next(n)　　n　　非进入式（不会进入到所调用的子函数中）单步执行
until + 行数　　u 3　　运行到函数某一行