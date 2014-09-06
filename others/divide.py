def div(a,b): # a /b
    c = b
    ret = 0
    while a >= b :
        c = b
        i=1
        while a >= c :
            c = c <<1
            i = i<<1
        ret += (i>>1)
        a = a - (c>>1)
    return ret

print div(5,7)
print div(16,5)
print div(15,5)
print div(25,5)
print div(26,5)

    
