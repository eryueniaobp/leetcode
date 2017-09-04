#encoding=utf-8
import matplotlib.pyplot as plt
import  numpy as np


mat = [ [0]*9 for i in range(9) ]

square_map = {

}
def check_row(row,col,val):
    for i in range(col):
        if mat[row][i] == val:
            return False
    return True

def check_col(row,col,val):
    for i in range(row):
        if mat[i][col] == val:
            return False
    return True
def build_square():
    for i in range(9):
        square_map[i] = []
    for i in range(9 * 9 ):
        r , l = i/9 , i%9

        square_id = r / 3 * 3 + l / 3


        square_map[square_id].append(i)



    print square_map

def check_square(row,col,val):
    square_id  = row /3  *  3 + col /3

    target = row * 9 + col
    for k in square_map[square_id]:
        if k >= target: break

        kr,kl = k/9 , k%9

        if mat[kr][kl] == val: return False

    return True


def plot(mat):
    for r in range(9):
        for l in range(9):

            x = l + 0.5
            y = 8-r +0.5

            plt.text(x, y , mat[r][l])
    plt.axis([0,10,0,10])
    plt.grid(True)
    plt.xticks( range(10))
    plt.yticks(range(10))
    plt.show()

def check(row,col, val):

    return check_row(row,col,val) and check_col(row,col,val) and check_square(row,col,val)
def solve(level= 0):
    """
    求出所有可行的局面
    :return: number
    """
    build_square()
    solcnt = 0
    k = 0

    while k >= 0 and k < 9*9  :
        #当前放第几个
        # while k >=0 and  k < 9 * 9:
        r , l =  k/9 , k % 9

        pre_v =  mat[r][l]
        alive = False
        for i in range(pre_v+1 ,10): # 1 -9
            if check(r, l , i):
                mat[r][l] = i
                alive = True
                break
            else:
                pass
        if alive == False: # backtrace
            mat[r][l] = 0 #backtrace .
            k -= 1
        else:
            k += 1

        if k == 9 *9:
            # find one solution
            # print mat
            # plot(mat)
            # print '==' * 20
            solcnt +=1
            k -= 1
    return solcnt







if __name__ == '__main__':

    print  solve()
