define x g++
endef
#z的值必须被赋值之后才算被定义,否则默认为非定义
################
#define z cc
#这种方式一般用来定义通用的调用方式以及命令
#endef
###############
z=cc##这表明z已经被定义
text=feet on the street
Pattern=a.o b.o c.o
Filter=a.o b.c c.s k.h
reverse=$(1),$(2)#类似数组赋值一类
_reverse=$(2),$(1)
hello:hello.o
ifeq ($(x),cc)
	cc -o hello hello.o
hello.o:hello.c
	cc -c hello.c
else
	g++ -o hello hello.o
hello.o:hello.c
	g++ -c hello.c
endif
PHONY:clean
clean:
ifdef z
	rm -f hello
endif
ifndef y
	rm -f *.o
endif
all:
#字符替换函数，将text变量中的ee转化为EE
#方式1
	@echo $(subst ee,EE,$(text))
#方式2
	@echo $(text:ee=EE)
##方式2测试失败,原因该方式只针对模式中的最后一个字母进行转换

#模式字符串替换,将Pattern变量中的.o模式全部转化为.c模式
#方式1
	@echo $(patsubst %.o,%.c,$(Pattern))
#方式2
	@echo $(Pattern:.o=.c)
#q去掉空格符,去掉字符串a b c  开头和结尾的空格
	@echo $(strip a b c)
#查找字符串函数
	@echo $(findstring avoid,get avoid)
	@echo $(findstring a,b c) 
#过滤函数,符合模式---保留变量中.o与.c部分的字符串
	@echo $(filter %.o %.c %.h,$(Filter))
#要加模式，之间用空格隔开
#反过滤函数，不符合模式---不保留变量中.o与.c部分的字符串
	@echo $(filter-out %.o %.c,$(Filter))
#排序函数
	@echo $(sort 3 5 4)
	@echo $(sort foo bar loser)
#取单词函数,取变量中的第二单词
	@echo $(word 2,$(text))
#取单词串函数,取变量中的2-4的单词串
	@echo $(wordlist 2,4,$(text))
#单词个数统计,统计变量中单词个数
	@echo $(words $(text))
#首单词函数，取一个变量中的首字母
	@echo $(firstword $(text))
#取目录函数，取/之前的字符串
	@echo $(dir src/hello.o dir.cc)
#取文件函数，取/之后的字符串
	@echo $(notdir src/hello.o dir.cc)
#取后缀函数,取.o和.cc
	@echo $(suffix src/hello.o dir.cc)
#取前缀函数,取.o和.cc之前的字符串
	@echo $(basename src/hello.o dir.cc)
#加后缀函数
	@echo $(addsuffix .c,hello dir)
#加前缀函数
	@echo $(addprefix src/,hello.o dir.cc )
#连接函数
	@echo $(join 111112222,abcdf)
#foreach函数，仿照unix中的for函数
	@echo $(foreach n,$(text),$(n).o)
##注foreach：n是变量，意思是从list变量中一个一个取出变量,然后赋值给var，然后再执行text中的表达式----->> foreach <var>,<list>,<text>

#if语句的使用
	@echo $(if 1,then,else)
	@echo $(if ,then,else)
#而 if 函数的返回值是,如果 <condition> 为真(非空字符串),那个 <then-part> 会是整个函数的返回值,如果 <condition> 为假(空字符串),那么 <else-part> 会是整个函数的返回值

#call函数，将a,b按照reverse中的顺序进行赋值
	@echo $(call reverse,a,b)
	@echo $(call _reverse,a,b)

#origin函数，变量定义的情况
	@echo $(origin Filter)
	@echo $(origin CC)
#shell函数,顾名思义其实就是shell
	@echo $(shell pwd) 



