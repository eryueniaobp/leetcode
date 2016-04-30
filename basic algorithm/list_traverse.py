def main(data):
    L = 0 
    cnt = len(data) 
    #lens will not change. the length of each data[i]
    lens = [ len(i) for i in data ]

    #current index of data[i], initial value =  0 
    inds = [ 0 for i in data ]
    while L>=0:
        if L < cnt:
            L +=1 
        else:
            cur_data = [ data[i][inds[i] ] for i in xrange(cnt) ] 
            print cur_data 
            #KEY-begin backtrace
            L -=1  
            while L>=0 and inds[L] == lens[L] -1 :
                inds[L] =  0
                L -=1 
            #KEY-end
            if L >=0:
                inds[L] +=1
    
if __name__ == '__main__':
    data =  [
        [1,2,3],
        [4,5],
        [6,7,8,9],
    ]
    main(data)
