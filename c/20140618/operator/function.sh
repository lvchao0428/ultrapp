#########################################################################
# File Name: function.sh
# Author: Comst
# mail: lvchao0428@163.com
# Created Time: Wed 18 Jun 2014 09:29:40 AM EDT
#########################################################################
#!/bin/bash
echo"=========================="
echo"***************************"
echo"	1.create static lib		"	//静态库创建
echo"	2.create shared lib		"	//动态库创建
echo"***************************"
echo"==========================="
echo"please input your operator:"
read op
case $op in
"1") #//以静态库的方式
gcc -c ${1}.c #	//$ {1}接受第一个传进来的参数func，并编译
ar arsv lib${1}.a ${1}.o #//将其打包为静态库
gcc -o ${2} ${2}.c -L. -I${1} #//${2} 接受第二个传进来的main
./${2}		#//运行main程序结果
"2") #以动态库的方式
gcc -fpic -c ${1}.c
gcc -shared -o lib${1}.so ${1}.o
gcc -o ${2} ${2}.c -L. -I ${1}
sudo cp lib#{1}.so /lib/		#切换到用户下
./${2}

*)
exit 3;;
