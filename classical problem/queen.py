__author__ = 'coder'
import matplotlib.pyplot as plt
import numpy as np
"""
output: 92
"""
board = np.array([-1] * 8)
Y =  range(8)

Y.reverse()
Y = np.array(Y)

def checkValid(level , pos ):
    if level == 0:
        return True

    for i in range(level):
        pi = board[i]

        if pi == pos : return False  #vertical conflict

        if abs(i - level ) == abs (  pi - pos) : return False  # diagonal
    return True
def draw(board):


    plt.plot ( board + 0.5  , Y + 0.5  , 'bo' , ms = 35  )
    plt.grid(True)
    plt.xticks( range(-1,9) )
    plt.yticks(range(-1,9))
    plt.axis([-1,8,-1,8])
    plt.show()
    print board
def queen(level=0):

    if level == 8:
        draw(board)
        return 1
    sum =  0
    for i in range(8):
        if checkValid(level , i ):
            board[level] = i
            sum += queen(level + 1 )
        else:
            pass

    board[level] = -1
    # print level ,sum
    return sum



if __name__ == '__main__':
    ret = queen()
    print ret
