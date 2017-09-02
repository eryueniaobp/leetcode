__author__ = 'baipeng'


import numpy as np


from graphviz import Digraph
class Node(object):
    def __init__(self, l =None , r=None ,v=0):
        self.r = r  #right
        self.l = l
        self.v = v #value


        self.ptag = -1  # tag to indicate parent .
        self.tag = 0    #   state machine variable .

    def __str__(self):
        return '{0}\n{1}\t{2}\n'.format(self.v ,self.l.v ,self.r.v  )


def parent(root, a, b):
    root.tag = 1
    stack = [root]

    hit = 0


    while len(stack) > 0 :
        cur = stack[-1]


        if cur.tag ==1:

            #color path
            if cur == a or cur == b :
                hit +=1
                if hit == 1:
                    for n in stack:
                        n.ptag = 1 if cur==a  else 2
                else:
                    other_tag = 2 if cur==a else 1
                    for i, n in enumerate(stack):
                        if n.ptag != other_tag:
                            return None if i < 1 else stack[i-1]


            cur.tag = 2
            if cur.l is not None:
                cur = cur.l
                cur.tag = 1
                stack.append( cur)
        elif cur.tag ==2:
            cur.tag = 3
            if cur.r is not None:
                cur = cur.r
                cur.tag = 1
                stack.append(cur)
        elif cur.tag == 3:

            # print cur.v
            stack.pop()




if __name__ ==  '__main__':
    nodes = [Node(v=1000)]

    i = 0

    dot = Digraph(comment='The Round Table')
    dot.node(str(i) , '1000')

    np.random.seed(1)
    cnt= 30
    ia,ib = np.random.randint(0 , cnt*2    , 2)
    for k in range(0,cnt):
        value = np.random.randint(1,100, 2)
        print value
        cur = nodes[i]
        left_c = Node(v=value[0])
        right_c = Node(v= value[1])

        cur.l,cur.r  = left_c ,right_c



        nodes.append(cur.l)


        nodes.append(cur.r)

        s = len(nodes)
        if s-2  == ia or s-2 == ib :
            print '-'* 10 , value[0]

            dot.node(str(s-2), str(value[0]),   color='blue',style='filled')
        else:
            dot.node(str(s-2), str(value[0]) )


        if s-1 == ia or s-1 == ib:
            print '-'* 10 , value[1]
            dot.node(str(s-1), str(value[1]),   color='blue',   style='filled')
        else:
            dot.node(str(s-1), str(value[1]))


        dot.edges( [
            (str(i) , str(s-2)  ) ,
             (str(i) , str(s-1))

        ])


        i+=1

    print '*' * 8  , len(nodes)
    root = nodes[0]
    print dot.source


    dot.render('binary_tree',view=True)

    print '-' * 8
    print parent(root , nodes[ia] , nodes[ib]  )


