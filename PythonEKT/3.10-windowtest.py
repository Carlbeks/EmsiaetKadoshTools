def spower(t):
    output=[];
    const=[];
    modulus=[];
    
    for i in range(t):
        c = 0;
        for j in range(i+1):
            c += (j+1)**t;
        const.append(c);

    for i in range(t):
        modulus.append([]);
        for j in range(t):
            modulus[i].append((i+1)**(t-j));
            
    output = modulus;
    for i in range(t):
        output[i].append(const[i]);
    print(output);
    return output;


def solveD(list_equation):
    output=[];
    for i in range(len(list_equation)):
        e = list_equation;
        for j in range(len(e)-1):
            pos_1 = 0;
            sig_moduj = 0;
            while sig_moduj == 0:
                if pos_1 >= len(e):
                    sig_moduj = 2;
                    print(' < Error >>> Found all modulus 0. >');
                    return 1;
                elif e[pos_1][i] == 0:
                    pos_1 += 1;
                else:
                    sig_moduj = 1;
                    
            target = []
            for temp1 in range(len(e[pos_1])):
                target.append(e[pos_1][temp1]);
            comp = e[pos_1][i];
            for k in range(len(e)): # wrong here
                e[pos_1][k] -= comp*target[k]/target[i];
            print(e)




solveD([[1,1,2],[1,-1,0]])
input(' > ENTER ONCE <  ')