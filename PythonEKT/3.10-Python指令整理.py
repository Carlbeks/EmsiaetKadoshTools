'''

#import tkinter
#win=tkinter.Tk()
#win.title("Test")
#win.mainloop()


#import tkinter as task; root = task.Tk()
#root.title("Test")
#root.update()
#b = task.Button(root, text='This is just a buttom!!!!!!!!!!!!!!!!!!!!!!!!!')
#b.pack()
#root.update()
#root.geometry('1000x500')
#root.mainloop()


# 3.1.1数字\
    1+1  # 简单计算器
    1-1
    1*1
    1/1
    1**2  # 乘方
    n = 1  # 定义变量n
    1//2  # 除法取整
    5%2  # 取余数
    n + _  # 下划线是上一次的输出
    round(n,m)  # n是有关变量，m是取小数位数
    int()  # 变换元素为常量
    float()  # 变换元素为浮点数

# 3.1.2字符串\''
    # 引号判定脱离
        >>> 'spam eggs'  # single quotes
        'spam eggs'

        >>> 'doesn\'t'  # use \' to escape the single quote...
        "doesn't"

        >>> "doesn't"  # ...or use double quotes instead
        "doesn't"

        >>> '"Yes," they said.'
        '"Yes," they said.'

        >>> "\"Yes,\" they said."
        '"Yes," they said.'

        >>> '"Isn\'t," they said.'
        '"Isn\'t," they said.'

        >>> print('"Isn\'t," they said.')
        "Isn't," they said.

    # print()指令：r与\n指示
        >>> s = 'First line.\nSecond line.'  # \n指示输出换行
        >>> s  # 没有print()指令，\n会被直接输出
        'First line.\nSecond line.'
        >>> print(s)  # print()指令中，\n表示换行
        First line.
        Second line.

        >>> print('C:\some\name')  # \n指示输出换行
        C:\some
        ame
        >>> print(r'C:\some\name')  # r表示拒绝判断\n
        C:\some\name

    # 输出字符串的运算
        >>> # 3 times 'un', followed by 'ium'
        >>> 3 * 'un' + 'ium'
        'unununium'
        >>> 'Py' 'thon'
        'Python'

        # 定义全引用
            >>> prefix = 'Py'
            >>> prefix 'thon'  # 直接叠加不识别
                File "<stdin>", line 1
                prefix 'thon'
                            ^
            SyntaxError: invalid syntax

            >>> ('un' * 3) 'ium' # 
              File "<stdin>", line 1
                ('un' * 3) 'ium'
                               ^
            SyntaxError: invalid syntax

    # 字母选取
        >>> word = 'Python'
        >>> word[0]  # 0位（初位）
        'P'
        >>> word[5]  # 5位（第6个）
        'n'
        >>> word[-1]  # 末位
        'n'
        >>> word[-2]  # 倒数第二位
        'o'
        >>> word[-6]
        'P'
        # 冒号范围选取：一律冒号左边的包含，即冒号左边一位包含，右边一位不包含
            >>> word[:2]   # 从开始位到第2位（不包含）
            'Py'
            >>> word[4:]   # 从4位到末位（包含）
            'on'
            >>> word[-2:]  # 从倒数第二位到末位（包含）
            'on'

            >>> word[:2] + word[2:]
            'Python'
            >>> word[:4] + word[4:]
            'Python'
        # 如果取字母超过限制则会错误
            >>> word[42]  # the word only has 6 characters
            Traceback (most recent call last):
              File "<stdin>", line 1, in <module>
            IndexError: string index out of range

        # 但是范围超过不会出错误，输出比较有趣
            >>> word[4:42]
            'on'
            >>> word[42:]
            ''
    # 不可以只改一个字母
        >>> word[0] = 'J'
        Traceback (most recent call last):
          File "<stdin>", line 1, in <module>
        TypeError: 'str' object does not support item assignment
        >>> word[2:] = 'py'
        Traceback (most recent call last):
          File "<stdin>", line 1, in <module>
        TypeError: 'str' object does not support item assignment
        # 但是你可以创建一个新的
            >>> 'J' + word[1:]
            'Jython'
            >>> word[:2] + 'py'
            'Pypy'

    # 字母长度
        >>> s = 'supercalifragilisticexpialidocious'
        >>> len(s)
        34

# 3.1.3列表（集合）运算\[]
    >>> squares = [1, 4, 9, 16, 25]
    >>> squares
    [1, 4, 9, 16, 25]
    
    >>> squares[0]  # 元素有排序，可以读取特定位置的元素
    1
    >>> squares[-1]
    25
    >>> squares[-3:]  # 范围选中输出，输出为列表格式
    [9, 16, 25]

    >>> squares[:]  # 相当于复制一遍
    [1, 4, 9, 16, 25]

    # 列表可以加减运算！
        >>> squares + [36, 49, 64, 81, 100]
        [1, 4, 9, 16, 25, 36, 49, 64, 81, 100]

    # 列表可以单个元素修改！
        >>> cubes = [1, 8, 27, 65, 125]  # something's wrong here
        >>> 4 ** 3  # the cube of 4 is 64, not 65!
        64
        >>> cubes[3] = 64  # replace the wrong value
        >>> cubes
        [1, 8, 27, 64, 125]

    # 在列表结尾往后添加元素
        >>> cubes.append(216)  # add the cube of 6
        >>> cubes.append(7 ** 3)  # and the cube of 7
        >>> cubes
        [1, 8, 27, 64, 125, 216, 343]

        >>> letters = ['a', 'b', 'c', 'd', 'e', 'f', 'g']
        >>> letters
        ['a', 'b', 'c', 'd', 'e', 'f', 'g']

        >>> letters[2:5] = ['C', 'D', 'E']  # 替换一部分
        >>> letters
        ['a', 'b', 'C', 'D', 'E', 'f', 'g']

        >>> letters[2:5] = []  # 替换为空，也就是删除
        >>> letters
        ['a', 'b', 'f', 'g']

        >>> letters[:] = []  # 所有替换为空，也就是将列表变为空列表
        >>> letters
        []

    # 计算所有元素个数
        >>> letters = ['a', 'b', 'c', 'd']
        >>> len(letters)
        4

    # 列表套娃
        >>> a = ['a', 'b', 'c']
        >>> n = [1, 2, 3]
        >>> x = [a, n]          # a、n两个列表套娃进x列表
        >>> x
        [['a', 'b', 'c'], [1, 2, 3]]
        >>> x[0]  # x列表中的0位
        ['a', 'b', 'c']
        >>> x[0][1]  # [x列表中的0位]中的1位
        'b'

# 5.1,2-更多列表
    list.append() # 向后添加项
    list.extend() # 向后添加可迭代的对象中所有对象（比如一个列表，就是把新列表中的每一项加到原列表里）
    list.insert(pos,target) # 在pos的位置插入target。也就是将target放到列表的pos位，并将所有原来pos位及以后的项往后移。
    list.remove(tar) # 将列表中第一个值等于tar的项移除，如果没有匹配，程序会报错。
    list.pop(【可选i】) # 将列表中指定位置的值删除并返回。
    list.clear() # 清空列表
    ???   list.index(x[, start[, end]])
    list.count(tar) # 返回在list中值x一共出现了多少次
    ???   list.sort(*, key=None, reverse=False)
    list.reverse() # 颠倒列表
    list.copy() # 这是一个列表的副本，相当于list[:]

    一个绞尽脑汁的汇总：
        >>> fruits = ['orange', 'apple', 'pear', 'banana', 'kiwi', 'apple', 'banana']
        >>> fruits.count('apple')
        2
        >>> fruits.count('tangerine')
        0
        >>> fruits.index('banana')
        3
        >>> fruits.index('banana', 4)  # Find next banana starting a position 4
        6
        >>> fruits.reverse()
        >>> fruits
        ['banana', 'apple', 'kiwi', 'banana', 'pear', 'apple', 'orange']
        >>> fruits.append('grape')
        >>> fruits
        ['banana', 'apple', 'kiwi', 'banana', 'pear', 'apple', 'orange', 'grape']
        >>> fruits.sort()
        >>> fruits
        ['apple', 'apple', 'banana', 'banana', 'grape', 'kiwi', 'orange', 'pear']
        >>> fruits.pop()
        'pear'
    
    # deque 排队互动
        >>> from collections import deque
        >>> queue = deque(["Eric", "John", "Michael"])
        >>> queue.append("Terry")           # Terry arrives
        >>> queue.append("Graham")          # Graham arrives
        >>> queue.popleft()                 # The first to arrive now leaves
        'Eric'
        >>> queue.popleft()                 # The second to arrive now leaves
        'John'
        >>> queue                           # Remaining queue in order of arrival
        deque(['Michael', 'Terry', 'Graham'])

    # 创建有一定规则的列表时：
        >>> squares = []
        >>> for x in range(10):
        ...     squares.append(x**2)
        ...
        >>> squares
        [0, 1, 4, 9, 16, 25, 36, 49, 64, 81]
        # 等效于：
        squares = list(map(lambda x: x**2, range(10)))
        # 还能这么干：
        squares = [x**2 for x in range(10)]                                            #################################### for 的新用法
    # for 和 if 的新的阳间用法
        >>> [(x, y) for x in [1,2,3] for y in [3,1,4] if x != y]
        [(1, 3), (1, 4), (2, 3), (2, 1), (2, 4), (3, 1), (3, 4)]
        # 等效于：
        >>> combs = []
        >>> for x in [1,2,3]:
        ...     for y in [3,1,4]:
        ...         if x != y:
        ...             combs.append((x, y))
        ...
        >>> combs
        [(1, 3), (1, 4), (2, 3), (2, 1), (2, 4), (3, 1), (3, 4)]
    又是一个离谱的绞尽脑汁
        >>> vec = [-4, -2, 0, 2, 4]
        >>> # create a new list with the values doubled
        >>> [x*2 for x in vec]
        [-8, -4, 0, 4, 8]
        >>> # filter the list to exclude negative numbers
        >>> [x for x in vec if x >= 0]
        [0, 2, 4]
        >>> # apply a function to all the elements
        >>> [abs(x) for x in vec]
        [4, 2, 0, 2, 4]
        >>> # call a method on each element
        >>> freshfruit = ['  banana', '  loganberry ', 'passion fruit  ']
        >>> [weapon.strip() for weapon in freshfruit]
        ['banana', 'loganberry', 'passion fruit']
        >>> # create a list of 2-tuples like (number, square)
        >>> [(x, x**2) for x in range(6)]
        [(0, 0), (1, 1), (2, 4), (3, 9), (4, 16), (5, 25)]
        >>> # the tuple must be parenthesized, otherwise an error is raised
        >>> [x, x**2 for x in range(6)]
          File "<stdin>", line 1, in <module>
            [x, x**2 for x in range(6)]
                       ^
        SyntaxError: invalid syntax
        >>> # flatten a list using a listcomp with two 'for'
        >>> vec = [[1,2,3], [4,5,6], [7,8,9]]
        >>> [num for elem in vec for num in elem]
        [1, 2, 3, 4, 5, 6, 7, 8, 9]


    # 列表套列表的神奇运算
        >>> matrix = [
        ...     [1, 2, 3, 4],
        ...     [5, 6, 7, 8],
        ...     [9, 10, 11, 12],
        ... ]


        >>> [[row[i] for row in matrix] for i in range(4)] #（母列表中：子列表是：对于matrix中的每一个row：对于该row中的每一个第i位）
        [[1, 5, 9], [2, 6, 10], [3, 7, 11], [4, 8, 12]]


        # 等效于：        
            transposed = []
            for i in range(4):
                transposed.append([row[i] for row in matrix])

            transposed
            [[1, 5, 9], [2, 6, 10], [3, 7, 11], [4, 8, 12]]

        # 也等效于：
            transposed = []
            for i in range(4):
                # the following 3 lines implement the nested listcomp
                transposed_row = []
                for row in matrix:
                    transposed_row.append(row[i])
                transposed.append(transposed_row)

            transposed
            [[1, 5, 9], [2, 6, 10], [3, 7, 11], [4, 8, 12]]

        # 不知道什么意思：
        >>> list(zip(*matrix))
        [(1, 5, 9), (2, 6, 10), (3, 7, 11), (4, 8, 12)]

    更多列表指令：
        del list[] # 删除list中第多少位；甚至可以用来删除变量整体

# 5.3-元组和序列
    #
        >>> t = 12345, 54321, 'hello!'
        >>> t[0]
        12345
        >>> t
        (12345, 54321, 'hello!')
        >>> # 元组可以被嵌套：
        ... u = t, (1, 2, 3, 4, 5)
        >>> u
        ((12345, 54321, 'hello!'), (1, 2, 3, 4, 5))
        >>> # 元组不可变：
        ... t[0] = 88888
        Traceback (most recent call last):
          File "<stdin>", line 1, in <module>
        TypeError: 'tuple' object does not support item assignment
        >>> # 元组中的内容可变
        ... v = ([1, 2, 3], [3, 2, 1])
        >>> v
        ([1, 2, 3], [3, 2, 1])
    # 声明元组的办法：
        >>> empty = ()
        >>> singleton = 'hello',    # <-- note trailing comma
        >>> len(empty)
        0
        >>> len(singleton)
        1
        >>> singleton
        ('hello',)
    
    #用数组进行分别赋值：
        x, y, z = t

# 5.4-集合
    # 基本上同数学集合。
    # 创建集合：
        a={1,2}
        a=set()
        # 但是注意：
            a={}
        # 会创建一个字典。
    # 集合判定与算法
        >>> 1 in a
        True
        >>> 3 in a
        False
        b={1,3}
        
        # 差集 交集 交集 双向补集
        >>> a = set('abracadabra')
        >>> b = set('alacazam')
        >>> a                                  # unique letters in a
        {'a', 'r', 'b', 'c', 'd'}
        >>> a - b                              # letters in a but not in b
        {'r', 'd', 'b'}
        >>> a | b                              # letters in a or b or both
        {'a', 'c', 'r', 'd', 'b', 'm', 'z', 'l'}
        >>> a & b                              # letters in both a and b
        {'a', 'c'}
        >>> a ^ b                              # letters in a or b but not both
        {'r', 'd', 'b', 'm', 'z', 'l'}

        # 集合也可以用解释法定义
        >>> a = {x for x in 'abracadabra' if x not in 'abc'}
        >>> a
        {'r', 'd'}

# 5.5-字典*未解释完成
    Another useful data type built into Python is the dictionary (see Mapping Types — dict). Dictionaries are sometimes found in other languages as “associative memories” or “associative arrays”. Unlike sequences, which are indexed by a range of numbers, dictionaries are indexed by keys, which can be any immutable type; strings and numbers can always be keys. Tuples can be used as keys if they contain only strings, numbers, or tuples; if a tuple contains any mutable object either directly or indirectly, it cannot be used as a key. You can’t use lists as keys, since lists can be modified in place using index assignments, slice assignments, or methods like append() and extend().
    It is best to think of a dictionary as a set of key: value pairs, with the requirement that the keys are unique (within one dictionary). A pair of braces creates an empty dictionary: {}. Placing a comma-separated list of key:value pairs within the braces adds initial key:value pairs to the dictionary; this is also the way dictionaries are written on output.
    The main operations on a dictionary are storing a value with some key and extracting the value given the key. It is also possible to delete a key:value pair with del. If you store using a key that is already in use, the old value associated with that key is forgotten. It is an error to extract a value using a non-existent key.
    Performing list(d) on a dictionary returns a list of all the keys used in the dictionary, in insertion order (if you want it sorted, just use sorted(d) instead). To check whether a single key is in the dictionary, use the in keyword.
    Here is a small example using a dictionary:

        >>> tel = {'jack': 4098, 'sape': 4139}
        >>> tel['guido'] = 4127
        >>> tel
        {'jack': 4098, 'sape': 4139, 'guido': 4127}
        >>> tel['jack']
        4098
        >>> del tel['sape']
        >>> tel['irv'] = 4127
        >>> tel
        {'jack': 4098, 'guido': 4127, 'irv': 4127}
        >>> list(tel)
        ['jack', 'guido', 'irv']
        >>> sorted(tel)
        ['guido', 'irv', 'jack']
        >>> 'guido' in tel
        True
        >>> 'jack' not in tel
        False

    The dict() constructor builds dictionaries directly from sequences of key-value pairs:

        >>> dict([('sape', 4139), ('guido', 4127), ('jack', 4098)])
        {'sape': 4139, 'guido': 4127, 'jack': 4098}

    In addition, dict comprehensions can be used to create dictionaries from arbitrary key and value expressions:

        >>> {x: x**2 for x in (2, 4, 6)}
        {2: 4, 4: 16, 6: 36}

    When the keys are simple strings, it is sometimes easier to specify pairs using keyword arguments:

        >>> dict(sape=4139, guido=4127, jack=4098)
        {'sape': 4139, 'guido': 4127, 'jack': 4098}

    # 与循环的互动

        >>> knights = {'gallahad': 'the pure', 'robin': 'the brave'}
        >>> for k, v in knights.items():
        ...     print(k, v)
        ...
        gallahad the pure
        robin the brave

    # 在序列中循环时，可以使用enumerate()函数同时检索位置索引和相应的值。
        >>> for i, v in enumerate(['tic', 'tac', 'toe']):
        ...     print(i, v)
        ...
        0 tic
        1 tac
        2 toe

    # 要同时循环两个或多个序列，可以将这些条目与zip()函数配对。
        >>> questions = ['name', 'quest', 'favorite color']
        >>> answers = ['lancelot', 'the holy grail', 'blue']
        >>> for q, a in zip(questions, answers):
        ...     print('What is your {0}?  It is {1}.'.format(q, a))
        ...
        What is your name?  It is lancelot.
        What is your quest?  It is the holy grail.
        What is your favorite color?  It is blue.
        
    # 如果想要反向循环，可以用reverse()套住正循环的表达
        >>> for i in reversed(range(1, 10, 2)):
        ...     print(i)
        ...
        9
        7
        5
        3
        1

    # 也可以整理一下。要避免重复，可以sorted(set(basket))。
        >>> basket = ['apple', 'orange', 'apple', 'pear', 'orange', 'banana']
        >>> for i in sorted(basket):
        ...     print(i)
        ...
        apple
        apple
        banana
        orange
        orange
        pear

    # 有时，当你循环浏览一个列表时，很容易改变它；然而，创建一个新列表通常更简单、更安全。
        >>> import math
        >>> raw_data = [56.2, float('NaN'), 51.7, 55.3, 52.5, float('NaN'), 47.8]
        >>> filtered_data = []
        >>> for value in raw_data:
        ...     if not math.isnan(value):
        ...         filtered_data.append(value)
        ...
        >>> filtered_data
        [56.2, 51.7, 55.3, 52.5, 47.8]


# 5.8-比较
    (1, 2, 3)              < (1, 2, 4)
    [1, 2, 3]              < [1, 2, 4]
    'ABC' < 'C' < 'Pascal' < 'Python'
    (1, 2, 3, 4)           < (1, 2, 4)
    (1, 2)                 < (1, 2, -1)
    (1, 2, 3)             == (1.0, 2.0, 3.0)
    (1, 2, ('aa', 'ab'))   < (1, 2, ('abc', 'a'), 4)



#-----------------------程序指令----------------------------#

# 3.2编程第一步
    #While循环
    >>> # Fibonacci series（斐波那契数列）:
    ... # the sum of two elements defines the next
    ... a, b = 0, 1
    >>> while a < 10:
    ...     print(a)
    ...     a, b = b, a+b
    ...
    0
    1
    1
    2
    3
    5
    8

    # print()指令：字符连接和end
        >>> i = 256*256
        >>> print('The value of i is', i)
        The value of i is 65536

        >>> a, b = 0, 1
        >>> while a < 1000:
        ...     print(a, end=',')
        ...     a, b = b, a+b
        ...
        0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,

# 4.1-if指令
    # if, elif, else顺带int和input
    >>> x = int(input("Please enter an integer: "))
    Please enter an integer: 42
    >>> if x < 0:
    ...     x = 0
    ...     print('Negative changed to zero')
    ... elif x == 0:  # 由于else: #\n# if ... :太长，所以省略为elif
    ...     print('Zero')
    ... elif x == 1:
    ...     print('Single')
    ... else:
    ...     print('More')
    ...
    More

# 4.2-for指令
    # Python中的for语句与C或Pascal中的for语句有点不同。
    # Python的for语句并不是总是迭代一个算术数列（如Pascal），
    # 也不是让用户能够定义迭代步骤和停止条件（如C），
    # 而是按照它们在序列中出现的顺序迭代任何序列的项（列表或字符串）。
        >>> # Measure some strings:
        ... words = ['cat', 'window', 'defenestrate']
        >>> for w in words:
        ...     print(w, len(w))
        ...
        cat 3
        window 6
        defenestrate 12
    #------#
        # Create a sample collection
        users = {'Hans': 'active', 'Éléonore': 'inactive', '景太郎': 'active'}
        # Strategy:  Iterate over a copy
        for user, status in users.copy().items():
        if status == 'inactive':
        del users[user]
        # Strategy:  Create a new collection
        active_users = {}
        for user, status in users.items():
            if status == 'active':
                active_users[user] = status

# 4.3-range()指令（大概是列举？）
    >>> for i in range(5):  # （列举i=从1到5的各项？）
    ...     print(i)
    ...
    0
    1
    2
    3
    4

    # list(range(a,b,c))：在[a,b)以c的步长列举
        >>> list(range(5, 10))
        [5, 6, 7, 8, 9]

        >>> list(range(0, 10, 3))
        [0, 3, 6, 9]

        >>> list(range(-10, -100, -30))
        [-10, -40, -70]

    # （列举i=从1到5的各项？）
        >>> a = ['Mary', 'had', 'a', 'little', 'lamb']
        >>> for i in range(len(a)):
        ...     print(i, a[i])
        ...
        0 Mary
        1 had
        2 a
        3 little
        4 lamb

    # 一件非常离谱的事情
        >>> range(10)
        range(0, 10)

    # 顺带：和sum()指令的互动
        >>> sum(range(4))  # 0 + 1 + 2 + 3
        6

# 4.4-break与coninue指令
    # 跳出循环或迭代
        >>> for n in range(2, 10):
        ...     for x in range(2, n):
        ...         if n % x == 0:
        ...             print(n, 'equals', x, '*', n//x)
        ...             break
        ...     else:
        ...         # loop fell through without finding a factor
        ...         print(n, 'is a prime number')
        ...
        2 is a prime number
        3 is a prime number
        4 equals 2 * 2
        5 is a prime number
        6 equals 2 * 3
        7 is a prime number
        8 equals 2 * 4
        9 equals 3 * 3
    # 继续下一次循环或迭代
        >>> for num in range(2, 10):
        ...     if num % 2 == 0:
        ...         print("Found an even number", num)
        ...         continue
        ...     print("Found an odd number", num)
        ...
        Found an even number 2
        Found an odd number 3
        Found an even number 4
        Found an odd number 5
        Found an even number 6
        Found an odd number 7
        Found an even number 8
        Found an odd number 9

# 4.5-pass指令
    # 当程序上不需要运行什么但是语法上确需要填充的时候用这个东西，本身没有作用。
        >>> while True:
            pass  # Busy-wait for keyboard interrupt (Ctrl+C)

        >>> class MyEmptyClass:
            pass
    # 测试新程序时作为函数或条件体的占位符。
    # 便于在更抽象的层次上思考。pass处被忽略：
        >>> def initlog(*args):
            pass   # Remember to implement this!
        
# 4.6-match

    def http_error(status):
    match status:
        case 400:
            return "Bad request"
        case 404:
            return "Not found"
        case 418:
            return "I'm a teapot"
        case _:
            return "Something's wrong with the internet"


    # 也可以用|表示或者
    case 401 | 403 | 404:
        return "Not allowed"

    # point is an (x, y) tuple（“点”是一个形如(x,y)的数组）
    match point:
        case (0, 0):
            print("Origin")
        case (0, y):
            print(f"Y={y}")
        case (x, 0):
            print(f"X={x}")
        case (x, y):
            print(f"X={x}, Y={y}")
        case _:
            raise ValueError("Not a point")


    # 应用class的时候
    class Point:
        x: int
        y: int

    def where_is(point):
        match point:
            case Point(x=0, y=0):
                print("Origin")
            case Point(x=0, y=y):
                print(f"Y={y}")
            case Point(x=x, y=0):
                print(f"X={x}")
            case Point():
                print("Somewhere else")
            case _: # 下划线意思实际上就是else
                print("Not a point")

    match points:# 貌似什么都可以match，下面是match一个列表
        case []:
            print("No points")
        case [Point(0, 0)]:
            print("The origin")
        case [Point(x, y)]:
            print(f"Single point {x}, {y}")
        case [Point(0, y1), Point(0, y2)]:
            print(f"Two on the Y axis at {y1}, {y2}")
        case _:
            print("Something else")

    match point:
        case Point(x, y) if x == y:
            print(f"Y=X at {x}")
        case Point(x, y):
            print(f"Not on the diagonal")

        case (Point(x1, y1), Point(x2, y2) as p2): ...# 输入x2y2作为p2


    class Color(Enum):# match与class的互动：一个实例##########################################################
        RED = 'red'
        GREEN = 'green'
        BLUE = 'blue'

    color = Color(input("Enter your choice of 'red', 'blue' or 'green': "))

    match color:
        case Color.RED:
            print("I see red!")
        case Color.GREEN:
            print("Grass is green")
        case Color.BLUE:
            print("I'm feeling the blues :(")

# 4.7-def
    # 谁都会的def
        变量的全局性和局部性。
        可以这么干:
            def alpha():
                ... ...
            a=alpha
        此时a和alpha都可以作为函数名。
    # 函数输入默认值
        i = 5
        def f(arg=i):
            print(arg)
        i = 6
        f()
            # 将会输出5而不是6。也就是函数默认值定下来了以后就是定下来了，再改变量也不行
        def f(a, L=[]):
            L.append(a)
            return L

        print(f(1))
        print(f(2))
        print(f(3))
            # 默认值只计算一次。如果默认值是列表、字典、大多数类的实例，会产生不同。上例是叠加。
        def f(a, L=None):
            if L is None:
                L = []
            L.append(a)
            print(L)
            # 然而这么干可以把叠加效果去除。























        '''