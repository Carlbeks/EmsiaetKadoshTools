import time
import threading
import _thread
#这是我自己写的一条函数，这个东西其实挺方便的，放在这里了。
#作用是可以判断target是否属于list，如果是则函数值位1，否则为0
#（有关list）list定义就是list=[A,B,C]
#如果要汉字输入或者是字符的话要打引号，数字打引号也是字符格式
#如果直接是数字的话那就是int或者float，可以直接拿来计算。
def belong(target,listName):
    output=0
    for position in range(len(listName)):
         if target==listName[position-1]:
            output=1
    return output


def main():
    doki=0
    dokitime=3
#一个list的定义的实例。当然方括号里面如果是空的那就是空集。跟集合比较像
#如果你知道list怎么用那就当我放P
    fruit=['苹果','草莓','梨子','桃子']
    while True:
        ipt=input(' >>> ')
        if ipt[:2]=='投喂':
            if belong(ipt[2:],fruit)==1:
                print('ahmmm.humm...mmm.mmm..omm\n美味しいです！')
                doki+=3
            else:
                print('没见过的东西呢。。')
                time.sleep(0.5)
                print('啊~~~！')
                time.sleep(1)
                print('！来るな！！不要塞给我奇怪的东西啊啊啊！！')
                times=0
                while times<=12:
                    print('啊！')
                    times+=1
                    time.sleep(0.05)
                dokitime-=1
        else:
            pass


_thread.start_new_thread(main,())
             
