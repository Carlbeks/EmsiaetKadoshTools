import math
import time
math.log(100,10)
邢牧羊的值=1
print(f"{time.strftime('%Y年%m月%d日%X')}")
def ekte():
    e=0
    for etimes in range(100):
        e=e+1/math.factorial(etimes)
    return e
def ektpi():
    return 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230
def EmsiaetKadoshToolse():
    return ekte()
def EmsiaetKadoshToolsPi():
    return ektpi()
π,pi=ektpi(),ektpi()
e=ekte()
def fc(Int):
    if isinstance(Int,int)==True:
        return math.factorial(Int)
    else:
        print('阶乘对象不是整数。')
def factorial(Int):
    return math.factorial(Int)
def sind(degree):
    return float("%.15f"%math.sin(degree*pi/180))
def cosd(degree):
    return float("%.15f"%math.cos(degree*pi/180))
def tand(degree):
    return float("%.15f"%math.tan(degree*pi/180))
def sinr(rad):
    return float("%.15f"%math.sin(rad))
def cosr(rad):
    return float("%.15f"%math.cos(rad))
def tanr(rad):
    return float("%.15f"%math.tan(rad))
def sinrp(radmodulus):
    return float("%.15f"%math.sin(radmodulus*pi))
def cosrp(radmodulus):
    return float("%.15f"%math.cos(radmodulus*pi))
def tanrp(radmodulus):
    return float("%.15f"%math.tan(radmodulus*pi))
def arcsind(value):
    return float("%.13f"%(math.asin(value)/pi*180))
def arccosd(value):
    return float("%.13f"%(math.acos(value)/pi*180))
def arctand(value):
    return float("%.13f"%(math.atan(value)/pi*180))
def arcsinr(value):
    return float("%.13f"%math.asin(value))
def arccosr(value):
    return float("%.13f"%math.acos(value))
def arctanr(value):
    return float("%.13f"%math.atan(value))
def arcsinrp(value):
    return float("%.13f"%(math.asin(value)/pi))
def arccosrp(value):
    return float("%.13f"%(math.acos(value)/pi))
def arctanrp(value):
    return float("%.13f"%(math.atan(value)/pi))
def 邢牧羊():
    print('sb')
    print('邢牧羊sb')
    a=0
    while True:
        a=a+1
        print(a*'邢牧羊sb')
def xmy():
    return 邢牧羊()
def XMY():
    return 邢牧羊()
def EmsiaetKadoshTools(TargetFunction):
        if TargetFunction == help:
            print('┌─────────────────────────────────────────────────────────────────┐')
            print('│                                                                 │')
            print('│                      EmsiaetKadosh Functions                    │')
            print('│                                                                 │')
            print('│               EmsiaetKadoshTools(), ektools(), ekt()            │')
            print('└─────────────────────────────────────────────────────────────────┘')
            print('┏━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓')
            print('┃FunctionName ┃FunctionGrammar       ┃Details                     ┃')
            print('┡━━━━━━━━━━━━━╇━━━━━━━━━━━━━━━━━━━━━━╇━━━━━━━━━━━━━━━━━━━━━━━━━━━━┩')
            print('│factorial    │fc(a);factorial(a)    │factorial calculartor       │')
            print('├─────────────┼──────────────────────┼────────────────────────────┤')
            print("│trigonometric│sind(a);sinrp(a)      │'r' means rad. 'p' means Pi.│")
            print('│(also tri)   │cosd(a);cosrp(a)      │sinrp(1/6)="sin(π/6)"       │')
            print('│             │tand(a);tanrp(a)      │=sind(30)=0.5               │')
            print('├─────────────┼──────────────────────┼────────────────────────────┤')
            print('│consts       │ekte()                │defines e                   │')
            print("│             │EmsiaetKadoshToolse() │also 'e' has been assigned  │")
            print('│             │                      │with ekte()                 │')
            print('│             │                      │                            │')
            print('│             │ektpi()               │defines π                   │')
            print("│             │EmsiaetKadoshToolspi()│also 'pi' and π has been    │")
            print('│             │                      │assigned eith ektpi()       │')
            print('├─────────────┼──────────────────────┼────────────────────────────┤')
            print('│MathMode     │ektmathmode()         │Do the maths.               │')
            print('│             │                      │\exit to quit the mod.      │')
            print('│             │                      │Directly input lines to     │')
            print('│             │                      │solve it.                   │')
            print('├─────────────┼──────────────────────┼────────────────────────────┤')
            print('│             │                      │                            │')
            print('├─────────────┼──────────────────────┼────────────────────────────┤')
            print('│             │                      │                            │')
            print('└─────────────┴──────────────────────┴────────────────────────────┘')
            print('另外不要忘了邢牧羊函数：邢牧羊()或者xmy()或者XMY()')
def ekt():
    print('输入"退出"以跳出。')
    while True:
        ipt=input('ekt >>> ')
        if ipt=='help' or ipt=='帮助' or ipt=='用法':
            EmsiaetKadoshTools(help)
        elif ipt=='mathmode' or ipt=='MATHMODE' or ipt=='数学模式':
            ektmathmode()
        elif ipt=='exit' or ipt=='EXIT' or ipt=='退出':
            break
        else:
            print('未定义指令')
##########功能性函数##########
#Part 1 调用函数定义：belong、模组指令分析、数学语法分析函数、计算函数
def solve1D(a,b):
    if a!=0:
        return -b/a
    elif b!=0:
        return 'None'
    else:
        return 'Any'
def solve2D(a,b,c):
    pass
def belong(target,listName):
    output=0
    for position in range(len(listName)):
         if target==listName[position]:
            output=1
    return output
def EmsiaetKadoshTools_CommandCalledByCommand_CommandDistinguish(inputString):
    ipt=inputString
    if inputString=='\\exit\\' or inputString=='\\exit':
        return 'off'
    elif ipt=='\\rad' or ipt=='\\rad\\':
        return 'rad'
    elif ipt=='\\deg' or ipt=='\\deg\\':
        return 'deg'
    elif ipt=='\\radmodulus' or ipt=='\\radmodulus\\':
        return 'radmodu'
    else:
        if ipt=='\\time' or ipt=='\\time\\':
            print(f"{time.strftime('%Y年%m月%d日%X')}")
        elif ipt=='\\help\\' or ipt=='\\help':
            print('┌─────────────────────────────────────────────────────────────────┐')
            print('│                                                                 │')
            print('│                EmsiaetKadosh MathMode Tutorial                  │')
            print('│                                                                 │')
            print('│                          ektmathmode()                          │')
            print('└─────────────────────────────────────────────────────────────────┘')
            print('┏━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━┓')
            print('┃FunctionName      ┃FunctionGrammar       ┃Details                ┃')
            print('┡━━━━━━━━━━━━━━━━━━╇━━━━━━━━━━━━━━━━━━━━━━╇━━━━━━━━━━━━━━━━━━━━━━━┩')
            print('│Absolute Value    │;abs() ;|    |        │factorial culculartor  │')
            print('├──────────────────┼──────────────────────┼───────────────────────┤')
            print("│trigonometric     │;sin(a)               │Only degrees.          │")
            print("│                  │;cosa                 │';'before function     │")
            print('│                  │;tan^2a               │                       │')
            print('├──────────────────┼──────────────────────┼───────────────────────┤')
            print('│                  │                      │                       │')
            print('│                  │                      │                       │')
            print('├──────────────────┼──────────────────────┼───────────────────────┤')
            print('│Under development │Under development     │Under development      │')
            print('│                  │                      │                       │')
            print('│                  │                      │                       │')
            print('│                  │                      │                       │')
            print('├──────────────────┼──────────────────────┼───────────────────────┤')
            print('│MathMode          │ektmathmode()         │Do the maths.          │')
            print('│                  │                      │When in the mode:      │')
            print('│                  │                      │                       │')
            print('│                  │\exit    \exit\       │To quit the mode.      │')
            print('│                  │                      │Directly input lines to│')
            print('│                  │                      │solve it.              │')
            print('│                  │                      │                       │')
            print('│                  │\help    \help\       │To get help.           │')
            print('│                  │                      │                       │')
            print('│                  │\\rad     \\rad\        │To change to radians.  │')
            print('│                  │\deg     \deg\        │To change to degree.   │')
            print('│                  │                      │                       │')
            print('│                  │                      │                       │')
            print('└──────────────────┴──────────────────────┴───────────────────────┘')
        else:
            print('邢牧羊 =',邢牧羊的值)
            print('未知指令')
        return 'on'
# 主函数定义
def ektmathmode():
    sym=['+','-','*','/','(',')','!','|','^']#,'%','[',']'
    num=['1','2','3','4','5','6','7','8','9','0']
    fct=['sin','cos','tan','arcsin','arccos','arctan','abs','SUM','mod']
    def StringDrawer(inputString):#符号分析+数字纠错
        #print('字符提取为列表（基本完成）：————————')
        ipt=inputString
        leng=len(ipt)
        pos=0#总初始化
        sig_fin=0
        sig_wrong=0
        ipl=[]
        while sig_fin==0:#开始对于一个字符进行分析
            rpos=0#每次的分初始化
            sig_oncefin=0
            sig_sym=0
            multisig_point=0
            sig_output=0
            sig_fsym=0
            sig_fmultisym=0
            sig_multisym=0
            while sig_oncefin==0:
                if multisig_point==2:
                    sig_wrong=1
                    rpos=rpos+1
                elif pos+rpos>=leng:
                    sig_fin=1
                    sig_oncefin=1
                elif belong(ipt[pos+rpos],sym):
                    rpos=rpos+1
                    sig_output=1
                    sig_fsym=1
                    #print('\n首位符号','\npos =',pos,'\nrpos =',rpos,'\nsig_sym =',sig_sym,'\nmultisig_point =',multisig_point,'\n',ipl)
                elif ipt[pos+rpos]==';':
                    if pos+rpos+1>=leng:
                        sig_oncefin=1
                        sig_fin=1
                        sig_wrong=1
                        #print('\''+ipt[pos+rpos]+'\'后面需要有一个函数名')
                        rpos+=2
                    elif ipt[pos+rpos+1]=='|':
                        sig_output=1
                        sig_fmultisym=1
                        #print('\n首位分号或冒号，后面是后绝对值符号')
                        rpos=rpos+2
                    elif ipt[pos+rpos+1:pos+rpos+4]=='sin' or ipt[pos+rpos+1:pos+rpos+4]=='cos' or ipt[pos+rpos+1:pos+rpos+4]=='tan':
                        sig_output=1
                        sig_fmultisym=1
                        #print('\n首位分号或冒号，后面是三角函数符号')
                        rpos=rpos+4
                    elif ipt[pos+rpos+1:pos+rpos+4]=='mod' or ipt[pos+rpos+1:pos+rpos+4]=='SUM' or ipt[pos+rpos+1:pos+rpos+4]=='abs':
                        sig_output=1
                        sig_fmultisym=1
                        #print('\n次位分号或冒号，后面是求和、绝对、取余符号')
                        rpos=rpos+4
                    elif ipt[pos+rpos+1:pos+rpos+7]=='arcsin' or ipt[pos+rpos+1:pos+rpos+7]=='arccos' or ipt[pos+rpos+1:pos+rpos+7]=='arctan':
                        sig_output=1
                        sig_fmultisym=1
                        #print('\n首位分号或冒号，后面是反三角函数符号')
                        rpos=rpos+7
                    else:
                        sig_wrong=2
                        sig_oncefin=1
                        sig_fin=1
                        print(' '+ipt)
                        print((pos+rpos)*' ','^')
                        print('表达错误>\n输入表达不符合程序识别规定>\n\';\'后面需要是一个函数算法或者前绝对值符号。')
                elif ipt[pos+rpos]=='.':
                    if pos+rpos+1==len(ipt):
                        if belong(ipt[pos+rpos-1],num)!=1:
                            print(' '+ipt)
                            print((pos+rpos)*' ','^')
                            print('这里有一个单独的小数点！')
                            return 0
                        else:
                            pass
                    else:
                        if belong(ipt[pos+rpos+1],num)!=1:
                            if belong(ipt[pos+rpos-1],num)!=1:
                                print(' '+ipt)
                                print((pos+rpos)*' ','^')
                                print('这里有一个单独的小数点！')
                                return 0
                            else:
                                pass
                        else:
                            pass
                    rpos=rpos+1
                    multisig_point=multisig_point+1
                    #print('\n首位小数点','\npos =',pos,'\nrpos =',rpos,'\nsig_sym =',sig_sym,'\nmultisig_point =',multisig_point,'\n',ipl)
                elif belong(ipt[pos+rpos],num):
                    sig_interfin=0
                    while sig_interfin==0:
                        if multisig_point==2:
                            sig_wrong=1
                            sig_interfin=1
                        elif belong(ipt[pos+rpos],sym):
                            sig_output=1
                            sig_sym=1
                            #print('\n次位符号','\npos =',pos,'\nrpos =',rpos,'\nsig_sym =',sig_sym,'\nmultisig_point =',multisig_point,'\n',ipl)
                            sig_interfin=1
                        elif ipt[pos+rpos]=='.':
                            multisig_point=multisig_point+1
                            #print('\n次位小数点','\npos =',pos,'\nrpos =',rpos,'\nsig_sym =',sig_sym,'\nmultisig_point =',multisig_point,'\n',ipl)
                        elif belong(ipt[pos+rpos],num):
                            #print('\n次位数字','\npos =',pos,'\nrpos =',rpos,'\nsig_sym =',sig_sym,'\nmultisig_point =',multisig_point,'\n',ipl)
                            pass
                        elif ipt[pos+rpos]==';':
                            if pos+rpos+1>=leng:
                                sig_oncefin=1
                                sig_fin=1
                                sig_wrong=1
                                #print('\''+ipt[pos+rpos]+'\'后面需要有一个函数名')
                                rpos+=1#这里只+1是因为在这个if外面的if外，不论如何会给一个rpos+=1(23行以后，不包含空行)
                            elif ipt[pos+rpos+1]=='|':
                                sig_output=1
                                sig_multisym=1
                                sig_multisymcount=2
                                #print('\n次位分号或冒号，后面是后绝对值符号')
                            elif ipt[pos+rpos+1:pos+rpos+4]=='sin' or ipt[pos+rpos+1:pos+rpos+4]=='cos' or ipt[pos+rpos+1:pos+rpos+4]=='tan':
                                sig_output=1
                                sig_multisym=1
                                sig_multisymcount=4
                                #print('\n次位分号或冒号，后面是三角函数符号')
                            elif ipt[pos+rpos+1:pos+rpos+4]=='mod' or ipt[pos+rpos+1:pos+rpos+4]=='SUM' or ipt[pos+rpos+1:pos+rpos+4]=='abs':
                                sig_output=1
                                sig_multisym=1
                                sig_multisymcount=4
                                #print('\n次位分号或冒号，后面是求和、绝对、取余符号')
                            elif ipt[pos+rpos+1:pos+rpos+7]=='arcsin' or ipt[pos+rpos+1:pos+rpos+7]=='arccos' or ipt[pos+rpos+1:pos+rpos+7]=='arctan':
                                sig_output=1
                                sig_multisym=1
                                sig_multisymcount=7
                                #print('\n次位分号或冒号，后面是反三角函数符号')
                            else:
                                sig_wrong=2
                                sig_oncefin=1
                                sig_fin=1
                                print(' '+ipt)
                                print((pos+rpos)*' ','^')
                                print('表达错误>\n输入表达不符合程序识别规定>\n\';\'后面需要是一个函数算法或者前绝对值符号。')
                            sig_interfin=1
                        else:
                            sig_wrong=1
                            sig_interfin=1
                            rpos=rpos+1
                        rpos=rpos+1
                        if pos+rpos>=leng and multisig_point<=1 and sig_wrong==0:
                            sig_interfin=1
                            sig_output=1
                            sig_fin=1
                else:
                    sig_wrong=1
                    rpos=rpos+2
                if sig_wrong==1:
                    sig_oncefin=1
                    sig_fin=1
                    print(' ',ipt)
                    print((pos+rpos)*' '+'^')
                    if multisig_point==2:
                        print('数学错误>小数点数溢出。')
                    else:
                        print('表达错误>检测到非法符号。')
                elif sig_output==1:
                    if sig_fsym==1:
                        ipl.append(ipt[pos+rpos-1])
                        #print('\n输出：符号','\npos =',pos,'\nrpos =',rpos,'\nsig_sym =',sig_sym,'\nmultisig_point =',multisig_point,'\n',ipl)
                        sig_oncefin=1
                        pos=rpos+pos
                        rpos=0
                        sig_fsym=0
                    elif sig_sym==1:
                        if multisig_point==1:
                            ipl.append(float(ipt[pos:(pos+rpos-1)]))
                        else:
                            ipl.append(int(ipt[pos:(pos+rpos-1)]))
                        ipl.append(ipt[pos+rpos-1])
                        #print('\n输出：数字后符号','\npos =',pos,'\nrpos =',rpos,'\nsig_sym =',sig_sym,'\nmultisig_point =',multisig_point,'\n',ipl)
                        sig_oncefin=1
                        pos=rpos+pos
                        rpos=0
                    elif sig_sym==0 and sig_fmultisym==0 and sig_multisym==0:
                        if multisig_point==1:
                            ipl.append(float(ipt[pos:(pos+rpos)]))
                        else:
                            ipl.append(int(ipt[pos:(pos+rpos)]))
                        #print('\n输出：数字后符号','\npos =',pos,'\nrpos =',rpos,'\nsig_sym =',sig_sym,'\nmultisig_point =',multisig_point,'\n',ipl)
                        sig_oncefin=1
                        pos=rpos+pos
                        rpos=0
                    elif sig_multisym==1:#次位检测到多字母的符号或函数名
                        if multisig_point==1:
                            ipl.append(float(ipt[pos:(pos+rpos-1)]))
                        else:
                            ipl.append(int(ipt[pos:(pos+rpos-1)]))
                        #print('\n输出：数字后多字母符号','\npos =',pos,'\nrpos =',rpos,'\nsig_sym =',sig_sym,'\nmultisig_point =',multisig_point,'\n',ipl)
                        ipl.append(ipt[pos+rpos-1:pos+rpos+sig_multisymcount-1])
                        sig_oncefin=1
                        pos=rpos+pos+sig_multisymcount-1
                        rpos=0
                    elif sig_fmultisym==1:#首位检测到多字母的符号或函数名
                        ipl.append(ipt[pos:pos+rpos])
                        #print('\n输出：多字母符号','\npos =',pos,'\nrpos =',rpos,'\nsig_sym =',sig_sym,'\nmultisig_point =',multisig_point,'\n',ipl)
                        sig_oncefin=1
                        pos=rpos+pos
                        rpos=0
        if sig_wrong==0:
            #print(ipl)
            return ipl
        else:
            return 0
    def MathematicJudge(inputstr,inputList):#符号纠错
        #print('\n\n数学语法判断部分（未完成）：————————\n')
        ipt=inputstr
        ipl=inputList
        pos=0
        sig_fin=0
        sig_wrong=0
        typ1=-1
        typ2=-1
        count_num=0
        count_plusminus=0
        count_multiplydivide=0
        count_lbra=0
        count_rbra=0
        count_labs=0
        count_rabs=0
        count_power=0
        count_factorial=0
        count_triabs=0
        count_mod=0
        brabs=[]
        NUM=['0','1','2','3','4','5','6','7','8','9','.']
        triabs=[';sin',';cos',';tan',';arcsin',';arccos',';arctan',';abs']
        while sig_fin==0:
            if pos>=len(ipl):#位数溢出，判断结束。
                sig_fin=1
                typ2=-1
                #print('pos =',pos,'位数溢出，符号判断结束')
            elif isinstance(ipl[pos],int)==True or isinstance(ipl[pos],float):#判断是否为数字。
                typ2=0
                count_num+=1
                #print('第',pos,'位是数字，估计不会不合法')
            elif ipl[pos]=='+' or ipl[pos]=='-':
                typ2=1
                count_plusminus+=1
                #print('第',pos,'位是+-')
            elif ipl[pos]=='*' or ipl[pos]=='/':
                if pos==0: # 首位双向符问题，直接跳过sig_fin、sig_wrongfin，直接return
                    print(' '+ipt)
                    print(' '+'^')
                    print('*/号前面要加对象。你拿啥子乘除哦？')
                    return 0
                typ2=2
                count_multiplydivide+=1
                #print('第',pos,'位是*/')
            elif ipl[pos]=='(':
                typ2=3
                count_lbra+=1
                #print('第',pos,'位是(。目前有',count_lbra,'个左括号')
                brabs.append('(')
            elif ipl[pos]==')':
                if pos==0: # 首位前向符问题，直接跳过sig_fin、sig_wrongfin，直接return
                    print(' '+ipt)
                    print(' '+'^')
                    print('上来一个后括号。你想干什么？')
                    return 0
                typ2=4
                count_rbra+=1
                #print('第',pos,'位是)。目前有',count_rbra,'个右括号')
                if count_lbra==0:
                    sig_wrong=1
                elif brabs[-1]=='(':
                    brabs[-1:]==[]
                else:
                    sig_wrong=1
                    typ2=-1
                    typ1=4
                    description_of_error='语法错误>没有找到符合要求的对应前括号。'
            elif ipl[pos]==';|':
                typ2=5
                count_labs+=1
                #print('第',pos,'位是|。目前有',count_labs,'个左绝对值号')
                brabs.append(';|')
            elif ipl[pos]=='|':
                if pos==0: # 首位前向符问题，直接跳过sig_fin、sig_wrongfin，直接return
                    print(' '+ipt)
                    print(' '+'^')
                    print('这是后绝对值符号诶。。啥意思？')
                    return 0
                typ2=6
                count_rabs+=1
                #print('第',pos,'位是|。目前有',count_rabs,'个左绝对值号')
                if count_labs==0:
                    sig_wrong=1
                elif brabs[-1]==';|':
                    brabs[-1:]==[]
                else:
                    sig_wrong=1
                    typ2=-1
                    typ1=6
                    description_of_error='语法错误>没有找到符合要求的对应前绝对值符号。'
            elif ipl[pos]=='^':
                if pos==0: # 首位双向符问题，直接跳过sig_fin、sig_wrongfin，直接return
                    print(' '+ipt)
                    print(' '+'^')
                    print('^号前面要加对象。你拿啥子幂哦？')
                    return 0
                typ2=7
                count_power+=1
                #print('第',pos,'位是^')
            elif ipl[pos]=='!':
                if pos==0: # 首位双向符问题，直接跳过sig_fin、sig_wrongfin，直接return
                    print(' '+ipt)
                    print(' '+'^')
                    print('!号前面要加对象。你拿啥子阶乘哦？')
                    return 0
                typ2=8
                count_factorial+=1
                #print('第',pos,'位是+-')
            elif belong(ipl[pos],triabs)==1:
                typ2=9
                count_triabs+=1
                #print('第',pos,'位是triabs')
            elif ipl[pos]==';mod':
                if pos==0: # 首位双向符问题，直接跳过sig_fin、sig_wrongfin，直接return
                    print(' '+ipt)
                    print(' '+'^')
                    print('mod前面要加对象。你拿啥子除了取余哦？')
                    return 0
                typ2=10
                count_mod+=1
                #print('第',pos,'位是mod')
            if typ1==-1:######分界线：前面是位数判断相邻两个元素，后面是判断元素关系错误
                pass
            elif typ1==0:
                pass
            elif typ1==1:
                if typ2==0 or typ2==3 or typ2==5 or typ2==9:
                    #print('符合要求的+-')
                    pass
                else:
                    sig_wrong=1;print('×')
                    description_of_error='加减号或正负号后需要接数字、前括号、前绝对值符号、三角函数符号或绝对值函数符号。'
            elif typ1==2:
                if typ2==0 or typ2==3 or typ2==5 or typ2==9:
                    #print('符合要求的*/')
                    pass
                else:
                    sig_wrong=1;print('×')
                    description_of_error='乘除号后需要接数字、前括号、前绝对值符号、三角函数符号或绝对值函数符号。'
            elif typ1==3:
                if typ2==0 or typ2==1 or typ2==3 or typ2==5 or typ2==9:
                    #print('符合要求的(')
                    pass
                else:
                    sig_wrong=1;print('×')
                    description_of_error='左括号后需要接数字、正负号、前绝对值符号、三角函数符号或绝对值符号。'
            elif typ1==4:
                if typ2!=0:
                    #print('符合要求的)')
                    pass
                else:
                    sig_wrong=1;print('×')
                    description_of_error='右括号后不可以直接接数字。'
            elif typ1==5:
                if typ2==0 or typ2==1 or typ2==3 or typ2==5 or typ2==9:
                    #print('符合要求的;|')
                    pass
                else:
                    sig_wrong=1;print('×')
                    description_of_error='前绝对值号后需要接数字、前括号、前绝对值符号、三角函数符号或绝对值函数符号。'
            elif typ1==6:
                if typ2!=0:
                    #print('符合要求的|')
                    pass
                else:
                    sig_wrong=1;print('×')
                    description_of_error='后右绝对值号后不可以直接接数字。'
            elif typ1==7:
                if typ2==0 or typ2==1 or typ2==3 or typ2==5 or typ2==9:
                    #print('符合要求的^')
                    pass
                else:
                    sig_wrong=1;print('×')
                    description_of_error='幂运算符号后需要接数字、正负号、前括号、前绝对值符号、三角函数符号、绝对值函数符号。'
            elif typ1==8:
                if typ2!=0 and typ2!=-1:
                    #print('符合要求的!')
                    pass
                else:
                    if typ2==0:
                        sig_wrong=1;print('×')
                        description_of_error='阶乘必须接整数。'
            elif typ1==9:
                if typ2==0 or typ2==1 or typ2==3 or typ2==5 or typ2==9:
                    #print('符合要求的tri,abs')
                    pass
                else:
                    sig_wrong=1;print('×')
                    description_of_error='三角函数符号和绝对值符号后需要接数字、正负号、前括号、前绝对值符号、前三角函数符号、绝对值函数符号。'
            elif typ1==10:
                if typ2==0 or typ2==1 or typ2==3 or typ2==4 or typ2==9:
                    #print('符合要求的mod')
                    pass
                else:
                    sig_wrong=1;print('×')
                    description_of_error='模运算符号后需要接数字、前括号、前绝对值符号、三角函数符号、绝对值函数符号。'
            if sig_wrong==0:
                pos=pos+1
                typ1=typ2
                typ2=-1
            elif sig_wrong==1:
                sig_fin=1
                '''###
                pos=pos+1
                typ1=typ2
                typ2=-1
                ###'''
        if count_lbra!=count_rbra:
            sig_wrong=1
        if count_labs!=count_rabs:
            sig_wrong=1
        if sig_wrong==1:
            #分号合并
            count_func=count_labs+count_triabs+count_mod
            judgelist1=[
                count_num,
                count_plusminus,
                count_multiplydivide,
                count_lbra,
                count_rbra,
                count_func,
                count_rabs,
                count_power,
                count_factorial,
                count_func,
                count_func
                ]
            judgelist2=[
                NUM,
                ['+','-'],
                ['*','/'],
                ['('],
                [')'],
                [';'],
                ['|'],
                ['^'],
                ['!'],
                [';'],
                [';']
                ]
            CompareValue=judgelist1[typ1]
            CompareList=judgelist2[typ1]
            CountValue=0#小初始化
            SearchPos=0
            sig_wrongfin=0
            rsPos=0
            while sig_wrongfin==0:#循环：原式探索错误：错误定位
                if belong(ipt[SearchPos],CompareList)==1:
                    CountValue+=1
                    SearchPos+=1
                    if CompareList==[';']:
                        if ipt[SearchPos]=='|':
                            rsPos+=1
                        elif ipt[SearchPos:SearchPos+3]=='sin' or ipt[SearchPos:SearchPos+3]=='cos' or ipt[SearchPos:SearchPos+3]=='tan' or ipt[SearchPos:SearchPos+3]=='abs' or ipt[SearchPos:SearchPos+3]=='mod':
                            rsPos+=3
                        elif ipt[SearchPos:SearchPos+6]=='arcsin' or ipt[SearchPos:SearchPos+6]=='arccos' or ipt[SearchPos:SearchPos+6]=='arctan':
                            rsPos+=6
                    if CompareList==['|']:
                        description_of_error='语法错误>没有找到符合要求的对应前绝对值符号。'
                else:
                    SearchPos+=1
                if CountValue==CompareValue:
                    sig_wrongfin=1#停止信号
                else:
                    SearchPos+=rsPos
                    rsPos=0
                '''
                优先级：(),|,!,tri,^;*,/;+,-
            
                0    1   2   3  4  5   6  7  8  9        10
                Num  +-  */  (  )  ;|  |  ^  !  tri,abs  mod
            
                1  +  0  3  5  9
                2  +  0  3  5  9
                3  +  0  1  3  5  9
                4  +  1  2  3  4  5  6  7  8  9  10
                5  +  0  1  3  5  9
                6  +  1  2  3  4  5  6  7  8  9  10
                7  +  0  1  3  5 
                8  +  1  2  3  4  5  6  7  9  10
                9  +  0  1  3  5  9
                10 +  0  1  3  4  9  10
                #舍弃部分代码
                    #对后一字母标错
                    if typ1==1:
                        print('语法错误>该符号不允许直接连在运算符号后。')
                        CountValue+=1
                    elif typ1==2:
                        CountValue+=1
                        print('语法错误>该符号不允许直接连在运算符号后。')
                    elif typ1==3:
                        CountValue+=1
                        if typ2==2 or typ2==7 or typ2==10:
                            print('语法错误>二相运算符左侧必须是一个数字或一个完整的括号。')
                        elif typ2==4:
                            print('数学错误>括号内不包含任何值，无法计算。')
                        elif typ2==6:
                            print('语法错误>括号关系错误>不同括号类型符号相交。')
                        elif typ2==8:
                            print('语法错误>后缀运算符前必须是一个数字或一个完整的符号。')
                    elif typ1==4:
                        CountValue+=1
                        pass'''
            print(' '+ipt)
            print((SearchPos-1)*' ',(rsPos+1)*'^')
            print(description_of_error)
            #给出错误原因
            sig_fin=1
        sig_fin=1
        if sig_fin==1:
            if sig_wrong==0:
                return 1
            else:
                return 0
    '''括号纠错专用函数，已经包含在纠错符号函数里面
        def EmsiaetKadoshTools_CommandCalledByCommand_PairedSymbol_Judge(inputstr,inputList):
        print('______________________________________________________________________________________')
        print('_______________________________括号拆解配对分析处理函数_______________________________')
        ipt=inputstr
        ipl=inputList
        prl=[]
        leng=len(inputList)
        pos=0
        while pos<leng:
            if ipl[pos]=='(' or ipl[pos]==')' or ipl[pos]=='|':
                prl.append(ipl[pos])
                print(pos,prl)
            pos=pos+1'''
    def MTPsignMending(inputDividedList):
        ipdl=inputDividedList
        position_offset_modulus=0
        typ1=-1
        typ2=-1
        triabs=[';sin',';cos',';tan',';arcsin',';arccos',';arctan',';abs']
        for trans in range(len(ipdl)):
            pos=trans+position_offset_modulus
            if isinstance(ipdl[pos],int)==True or isinstance(ipdl[pos],float)==True or ipdl[pos]==')' or ipdl[pos]=='|':
                typ2=1
            elif ipdl[pos]=='(' or ipdl[pos]==';|' or belong(ipdl[pos],triabs)==1:
                typ2=2
            else:typ2=-1
            if typ1==1 and typ2==2:
                aipl=ipdl[pos:]
                ipdl[pos:]=[]
                ipdl.append('*')
                #print(ipl)
                for apos in range(len(aipl)):
                    ipdl.append(aipl[apos])
                #print(ipl)
            typ1=typ2
            typ2=-1
        #print('乘号补充结束')
        return ipdl
    def MathematicProgressUnit(inputDividedList,trimode):#计算单元
        triabs=[';sin',';cos',';tan',';arcsin',';arccos',';arctan',';abs']
        ipdl=inputDividedList
        if len(ipdl)==1:
            return ipdl
        else:
            if len(ipdl)>1:
                position_offset_modulus=0
                for pos in range(len(ipdl)):
                    pos=pos-position_offset_modulus
                    if ipdl[pos]=='!':
                        if isinstance(ipdl[pos-1],int) and ipdl[pos-1]>=0:
                            ipdl[pos-1:pos+1]=[fc(ipdl[pos-1])]
                            position_offset_modulus+=1
                        else: # 阶乘非非负整数报错
                            string=''
                            for i in ipdl:
                                string+=str(i)
                            print(' '+string)
                            print('阶乘前遇到非正整数以外的数')
                            return 1
                position_offset_modulus=0
                for trans in range(len(ipdl)):#第二步：函数运算进行
                    pos=len(ipdl)-trans+position_offset_modulus-1
                    
                    if belong(ipdl[pos],triabs)==1:
                        # 判断后一位是否有正负号的问题
                        if ipdl[pos+1]=='-':
                            ipdl[pos+1:pos+3]=[0-ipdl[pos+2]]
                            position_offset_modulus+=1
                        elif ipdl[pos+1]=='+':
                            ipdl[pos+1:pos+3]=[ipdl[pos+2]]
                            position_offset_modulus+=1
                        # 正式计算
                        if ipdl[pos]==';abs':
                            ipdl[pos:pos+2]=[abs(ipdl[pos+1])]
                        elif ipdl[pos]==';sin':
                            if trimode=='deg':
                                ipdl[pos:pos+2]=[sind(ipdl[pos+1])]
                            elif trimode=='rad':
                                ipdl[pos:pos+2]=[sinr(ipdl[pos+1])]
                            elif trimode=='radmodu':
                                ipdl[pos:pos+2]=[sinrp(ipdl[pos+1])]
                        elif ipdl[pos]==';cos':
                            if trimode=='deg':
                                ipdl[pos:pos+2]=[cosd(ipdl[pos+1])]
                            elif trimode=='rad':
                                ipdl[pos:pos+2]=[cosr(ipdl[pos+1])]
                            elif trimode=='radmodu':
                                ipdl[pos:pos+2]=[cosrp(ipdl[pos+1])]
                        elif ipdl[pos]==';tan':
                            if ipdl[pos+1]%180==90:
                                print('无穷？')
                            else:
                                pass
                            if trimode=='deg':
                                ipdl[pos:pos+2]=[tand(ipdl[pos+1])]
                            elif trimode=='rad':
                                ipdl[pos:pos+2]=[tanr(ipdl[pos+1])]
                            elif trimode=='radmodu':
                                ipdl[pos:pos+2]=[tanrp(ipdl[pos+1])]
                        elif ipdl[pos]==';arcsin':
                            if trimode=='deg':
                                ipdl[pos:pos+2]=[arcsind(ipdl[pos+1])]
                            elif trimode=='rad':
                                ipdl[pos:pos+2]=[arcsinr(ipdl[pos+1])]
                            elif trimode=='radmodu':
                                ipdl[pos:pos+2]=[arcsinrp(ipdl[pos+1])]
                        elif ipdl[pos]==';arccos':
                            if trimode=='deg':
                                ipdl[pos:pos+2]=[arccosd(ipdl[pos+1])]
                            elif trimode=='rad':
                                ipdl[pos:pos+2]=[arccosr(ipdl[pos+1])]
                            elif trimode=='radmodu':
                                ipdl[pos:pos+2]=[arccosrp(ipdl[pos+1])]
                        elif ipdl[pos]==';arctan':
                            if trimode=='deg':
                                ipdl[pos:pos+2]=[arctand(ipdl[pos+1])]
                            elif trimode=='rad':
                                ipdl[pos:pos+2]=[arctanr(ipdl[pos+1])]
                            elif trimode=='radmodu':
                                ipdl[pos:pos+2]=[arctanrp(ipdl[pos+1])]
                        position_offset_modulus+=1
                position_offset_modulus=0
                for trans in range(len(ipdl)):#第一步：幂运算解决
                    pos=len(ipdl)-trans+position_offset_modulus-1
                    if ipdl[pos]=='^':
                        # 判断后一位是否有正负号的问题
                        if ipdl[pos+1]=='-':
                            ipdl[pos+1:pos+3]=[0-ipdl[pos+2]]
                            position_offset_modulus+=1
                        elif ipdl[pos+1]=='+':
                            ipdl[pos+1:pos+3]=[ipdl[pos+2]]
                            position_offset_modulus+=1
                        # 正式计算
                        ipdl[pos-1:pos+2]=[ipdl[pos-1]**ipdl[pos+1]]
                        position_offset_modulus+=2
                position_offset_modulus=0
                for trans in range(len(ipdl)):
                    pos=trans-position_offset_modulus
                    if ipdl[pos]=='*':
                        # 判断后一位是否有正负号的问题
                        if ipdl[pos+1]=='-':
                            ipdl[pos+1:pos+3]=[0-ipdl[pos+2]]
                            position_offset_modulus+=1
                        elif ipdl[pos+1]=='+':
                            ipdl[pos+1:pos+3]=[ipdl[pos+2]]
                            position_offset_modulus+=1
                        # 正式计算
                        ipdl[pos-1:pos+2]=[ipdl[pos-1]*ipdl[pos+1]]
                        position_offset_modulus+=2
                    elif ipdl[pos]=='/':
                        # 判断后一位是否有正负号的问题
                        if ipdl[pos+1]=='-':
                            ipdl[pos+1:pos+3]=[0-ipdl[pos+2]]
                            position_offset_modulus+=1
                        elif ipdl[pos+1]=='+':
                            ipdl[pos+1:pos+3]=[ipdl[pos+2]]
                            position_offset_modulus+=1
                        # 正式计算
                        ipdl[pos-1:pos+2]=[ipdl[pos-1]/ipdl[pos+1]]
                        position_offset_modulus+=2
                    elif ipdl[pos]==';mod':
                        # 判断后一位是否有正负号的问题
                        if ipdl[pos+1]=='-':
                            ipdl[pos+1:pos+3]=[0-ipdl[pos+2]]
                            position_offset_modulus+=1
                        elif ipdl[pos+1]=='+':
                            ipdl[pos+1:pos+3]=[ipdl[pos+2]]
                            position_offset_modulus+=1
                        # 正式计算
                        ipdl[pos-1:pos+2]=[ipdl[pos-1]%[pos+1]]
                        position_offset_modulus+=2
                position_offset_modulus=0
                for trans in range(len(ipdl)):
                    pos=trans-position_offset_modulus
                    if ipdl[pos]=='+':
                        if pos==0: # 首位正负号
                            ipdl[0:2]=[ipdl[1]]
                            position_offset_modulus+=1
                        else: # 正式计算
                            ipdl[pos-1:pos+2]=[ipdl[pos-1]+ipdl[pos+1]]
                            position_offset_modulus+=2
                    elif ipdl[pos]=='-':
                        if pos==0: # 首位正负号
                            ipdl[0:2]=[0-ipdl[1]]
                            position_offset_modulus+=1
                        else: # 正式计算
                            ipdl[pos-1:pos+2]=[ipdl[pos-1]-ipdl[pos+1]]
                            position_offset_modulus+=2
        return ipdl
    '''def PNsignMerging(inputDividedList):
        正负号修正条件：前置连接;|,(,^;func；+-；数字或前置连接。需要放在每个单元里进行；且^!前一个不进行正负号修正
        ipdl=inputDividedList
        position_offset_modulus=0
        typ1=-1
        typ2=-1
        for trans in range(len(ipdl)):
            pos=trans+position_offset_modulus
            if ipdl[pos]=='+' or ipdl[pos]=='-':
                typ2=1
            elif isinstance(ipdl[pos],int)==True or isinstance(ipdl[pos],float)==True:
                typ2=2
            else:typ2=-1
            if typ1==1 and typ2==2:
                if ipdl[pos-1]=='+':
                    ipdl[pos-1]=[]
                elif ipdl[pos-1]=='-':
                    ipdl[pos-1:pos+1]=[0-ipdl[pos]]
                #print(ipl)
            typ1=typ2
            typ2=-1
        #print('正负号整合结束')
        return ipdl'''
    def MathematicProgress(inputDividedList,trimode):#计算部分：来吧！1、括号分解，2、阶乘排除，3、正负号修正
        #print('计算部分')
        end=0
        f=inputDividedList
        bp=[]
        pos=0
        while end==0 and len(f)>=1 and pos<len(f):
            if f[pos]=='(':
                bp.append(pos)
            elif f[pos]==')':
                ex=MathematicProgressUnit(MTPsignMending(f[bp[len(bp)-1]+1:pos]),trimode)
                if ex==1:
                    Return=1
                    break
                else:
                    f[bp[len(bp)-1]:pos+1]=ex
                    pos=bp[len(bp)-1]
                    del bp[len(bp)-1]
            elif f[pos]==';|':
                bp.append(pos)
            elif f[pos]=='|':
                ex=MathematicProgressUnit(MTPsignMending(f[bp[len(bp)-1]+1:pos]),trimode)
                if ex==1:
                    Return=1
                    break
                else:
                    f[bp[len(bp)-1]:pos+1]=[abs(ex[0])]
                    pos=bp[len(bp)-1]
                    del bp[len(bp)-1]
            else:
                pass
            pos+=1
        if len(f)==1:
            Return=f
        else:
            Return=MathematicProgressUnit(MTPsignMending(f),trimode)
        return Return
    sig_mathmode=1
    trimode='deg'
    while sig_mathmode==1:
        ipt=input('EKTMathMode('+trimode+') >>> ')
        if len(ipt)==0:
            pass
        elif ipt[0]=='\\':
            Sig_EmsiaetKadoshTools_CommandCalledByCommand_CommandDistinguish=EmsiaetKadoshTools_CommandCalledByCommand_CommandDistinguish(ipt)
            if Sig_EmsiaetKadoshTools_CommandCalledByCommand_CommandDistinguish=='off':
                break
            elif Sig_EmsiaetKadoshTools_CommandCalledByCommand_CommandDistinguish=='rad':
                trimode='rad'
            elif Sig_EmsiaetKadoshTools_CommandCalledByCommand_CommandDistinguish=='deg':
                trimode='deg'
            elif Sig_EmsiaetKadoshTools_CommandCalledByCommand_CommandDistinguish=='radmodu':
                trimode='radmodu'
            elif Sig_EmsiaetKadoshTools_CommandCalledByCommand_CommandDistinguish=='on':
                pass
        else:
            ipl=StringDrawer(ipt)
            if ipl==0:
                pass
            else:
                if MathematicJudge(ipt,ipl)==1:
                    #print(ipl)
                    output=MathematicProgress(ipl,trimode)
                    if output!=1:
                        print("%.12f"%output[0])
                    else:
                        pass
                else:
                    pass
            #test command
        #print(ipl)
'''
    def aektmathmode():
        sig_MathModeOn=1
        sig_testtime=0
        while sig_MathModeOn==1:
            sig_fin=0
            ipdt=input('EKTMathMode >>> ')
        #recognizing part
            while sig_fin==0:
                ipl=[]
                int_leng=len(ipdt)
                pos=0
                rpos=0
                sig_point=0
                sig_wrong=0
                sig_fin=0
                sig_symelement=0
                if int_leng==0:
                    sig_fin=1
                elif ipdt[pos:]=="\\exit" or ipdt[pos:]=="\\exit\\":
                    sig_fin=1
                    MathModeOn=0
                elif ipdt[pos]=="\\":
                    sig_fin=1
                    print('Unknown command')
                else:
                    while pos<int_leng and sig_fin==0:
                        if belong(ipdt[pos],sym)==1:
                            ipl.append(ipdt[pos])
                            print(ipl)
                            pos=pos+1
                            print('pos=',pos)
                            rpos=0
                        elif belong(ipdt[pos],num)==1:
                            sig_nextelement=1
                            while ((sig_nextelement==1 and pos+rpos+2<int_leng) or pos+rpos+1<int_leng) and sig_wrong==0 and sig_nextelement==1 and sig_fin==0:
                                if belong(ipdt[pos+rpos],num)==1:
                                    rpos=rpos+1
                                    print('rpos=',rpos)
                                    pass
                                elif belong(ipdt[pos+rpos],sym)==1:
                                    sig_nextelement=0
                                    rpos=rpos-1
                                    sig_symelement=1
                                elif ipdt[pos+rpos]=='.':
                                    sig_point=sig_point+1
                                else:
                                    sig_wrong=1
                                if sig_point==2:
                                    sig_nextelement==0
                                    sig_wrong=1
                            if sig_point==2:
                                sig_wrong=1
                            if sig_wrong==1:
                                print('\nUnknow expression:')
                                print(ipdt)
                                print((pos+rpos)*' '+'^')
                                sig_fin=1
                            else:
                                ipl.append(ipdt[(pos):(pos+rpos+1)])
                                print('pos=',pos,'rpos=',rpos,'ipl=',ipl)
                                sig_testtime=sig_testtime+1
                                if pos+rpos+1>=int_leng:
                                    sig_fin=1
                                if sig_symelement==1:
                                    pos=pos+rpos+2
                                    print('pos=',pos)
                                    #ipl.append(ipdt[pos-1])
                                    rpos=0
                            if sig_testtime>=60:
                                sig_fin=1
                                sig_MathModeOn=0
                            if pos>=int_leng:
                                sig_fin=1
                        elif belong(ipdt[pos],sym)==0 and belong(ipdt[pos],num)==0:
                            sig_wrong=1
                        if sig_wrong==1:
                            print('\nUnknow expression:')
                            print(ipdt)
                            print((pos+rpos)*' '+'^')
                            sig_fin=1
                    if pos>=int_leng:
                        sig_fin=1
            #recognizing part                        
    def EmsiaetKadoshTools_CommandCalledByCommand_StringDrawer(inputString):
        ipt=inputString
        leng=len(inputString)
        dat_pos=0
        dat_rpos=0
        sig_fin=0
        sig_wrong=0
        multisig_point=0
        sig_numfin=0
        sig_sym=0
        ipl=[]
        while sig_fin==0:
            if dat_pos+dat_rpos+1>leng:
                sig_fin=1
            elif belong(ipt[dat_pos+dat_rpos],num)==1:#首项数
                dat_rpos=dat_rpos+1#初始化
                sig_numfin=0
                sig_wrong=0
                sig_sym=0
                multisig_point=0
                if dat_pos+dat_rpos+1<leng and sig_sym==0:#一回判断-次项符
                    if multisig_point==0:#小数点分项处理：无
                        ipl.append(int(ipt[dat_pos:(dat_pos+dat_rpos)]))
                        print('一回判断-次项符int','\n\ndat_pos=',dat_pos,'\ndat_rpos=',dat_rpos,'\nipl=',ipl)
                        print('multsig_point=',multisig_point)
                    elif multisig_point==1:#小数点分项处理：有
                        ipl.append(float(ipt[dat_pos:(dat_pos+dat_rpos)]))
                        print('一回判断-次项符float','\n\ndat_pos=',dat_pos,'\ndat_rpos=',dat_rpos,'\nipl=',ipl)
                        print('multsig_point=',multisig_point)
                    else:#小数点分项处理：以防万一
                        print('一回判断-次项符wrong','\n\ndat_pos=',dat_pos,'\ndat_rpos=',dat_rpos,'\nipl=',ipl)
                        print('multsig_point=',multisig_point)
                        sig_wrong=1
                while sig_numfin==0 and dat_pos+dat_rpos+1<=leng and sig_wrong==0 and multisig_point<=1:#一回判断-次项数循环
                    if belong(ipt[dat_pos+dat_rpos],num)==1:
                        #次项数
                        dat_rpos=dat_rpos+1
                        print('一回判断-次项数','multisig_point=',multisig_point)
                    elif ipt[dat_pos+dat_rpos]=='.':
                        #次项点
                        multisig_point=multisig_point+1
                        dat_rpos=dat_rpos+1
                        print('一回判断-次项数','multisig_point=',multisig_point)
                    elif belong(ipt[dat_pos+dat_rpos],sym)==1:
                        #次项符
                        sig_numfin=1
                        sig_sym=1
                        if multisig_point==0:#小数点分项处理：无
                            ipl.append(int(ipt[dat_pos:(dat_pos+dat_rpos)]))
                            ipl.append(ipt[dat_pos+dat_rpos])
                            print('一回判断-次项数','\nNumber & AfterNumber Symbol','\ndat_pos=',dat_pos,'\ndat_rpos=',dat_rpos,'\nipl=',ipl)
                            print('multsig_point=',multisig_point)
                            dat_pos=dat_pos+dat_rpos+1
                            dat_rpos=0
                            print('\nAfterNumber Symbol Reset','\ndat_pos=',dat_pos,'\ndat_rpos=',dat_rpos)
                        elif multisig_point==1:#小数点分项处理：有
                            ipl.append(float(ipt[dat_pos:(dat_pos+dat_rpos)]))
                            ipl.append(ipt[dat_pos+dat_rpos])
                            print('一回判断-次项数','\nNumber & AfterNumber Symbol','\ndat_pos=',dat_pos,'\ndat_rpos=',dat_rpos,'\nipl=',ipl)
                            print('multsig_point=',multisig_point)
                            dat_pos=dat_pos+dat_rpos+1
                            dat_rpos=0
                            print('\nAfterNumber Symbol Reset','\ndat_pos=',dat_pos,'\ndat_rpos=',dat_rpos)
                        else:#小数点分项处理：以防万一
                            sig_wrong=1
                            print('一回判断-次项数','\n',multisig_point)
                    else:
                        sig_wrong=1
                if dat_pos+dat_rpos+1>leng:#溢出判断
                    if sig_sym==0:#溢出之前没有遇到符号
                        if multisig_point==0:#小数点分项处理：无
                            ipl.append(int(ipt[dat_pos:(dat_pos+dat_rpos)]))
                            print('\nTillEnd Number','\ndat_pos=',dat_pos,'\ndat_rpos=',dat_rpos,'\nipl=',ipl)
                            print('multisig_point=',multisig_point)
                        elif multisig_point==1:#小数点分项处理：有
                            ipl.append(float(ipt[dat_pos:(dat_pos+dat_rpos)]))
                            print('\nTillEnd Number','\ndat_pos=',dat_pos,'\ndat_rpos=',dat_rpos,'\nipl=',ipl)
                            print('multisig_point=',multisig_point)
                        else:#小数点分项处理：以防万一
                            sig_wrong=1
                        sig_numfin=1
                        sig_fin=1
                        dat_pos=dat_pos+dat_rpos
                        dat_rpos=0
                    else:#溢出之前遇到了符号
                        sig_fin=1
                        dat_pos=dat_pos+dat_rpos
                        dat_rpos=1
                if multisig_point>1:#多小数点语法错误判断
                    sig_wrong=1
                    print('sig_wrong=',sig_wrong)
                    dat_rpos=dat_rpos-1
            elif belong(ipt[dat_pos+dat_rpos],sym)==1:#首项符
                ipl.append(ipt[dat_pos+dat_rpos])
                dat_pos=dat_pos+1
                print('\nSymbol','\ndat_pos=',dat_pos,'\ndat_rpos=',dat_rpos,'\nipl=',ipl)
            else:#首项错误
                sig_wrong=1
                print('sig_wrong=',sig_wrong)
            if sig_wrong==1:#错误登出：溢出小数点OK
                print('Not defined expression or illegal mathematic grammar.')
                print('\n错误登出值','\ndat_pos=',dat_pos,'\ndat_rpos=',dat_rpos,'\nipl=',ipl)
                print(ipt)
                print((dat_pos+dat_rpos-1)*' ','^')
                sig_fin=1'''
ektmathmode()
