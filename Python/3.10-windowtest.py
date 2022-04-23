def a():
    def b():
        print('b')
    def c():
        print('c')
    def d():
        print(b(),c())
