#encoding=utf-8
from typing import List


class Solution:
    def addOperators(self, num: str, target: int) -> List[str]:
        """
        2 + 3 * 4 + 5

        2345
        +*+

        2 12 5
        + *
        2 60
        +
        62


        """
        ret = []

        def lt(op1, op2):
            if op2 == '*' and op1 != '*':
                return True
            return False

        def calc(num_stack, op_stack, next_op):
            num_stack = num_stack.copy()
            op_stack = op_stack.copy()
            while num_stack and op_stack and not lt(op_stack[-1], next_op):
                op = op_stack.pop()
                y = num_stack.pop()
                x = num_stack.pop()
                if op == '+':
                    num_stack.append(x + y)
                elif op == '-':
                    num_stack.append(x - y)
                else:
                    num_stack.append(x * y)
            return num_stack, op_stack

        def do(num, num_stack, op_stack, formula):
            # print(formula)
            # if len(num) == 0:
            #     op_stack.pop()
            #     ns, ops = calc(num_stack, op_stack, '+')
            #     if ns[-1] == target:
            #         ret.append(formula[:-1])
            for i in range(len(num)):
                if num[0] == '0' and i > 0 :
                    break
                cur = int(num[:i + 1])

                cur_s = num[:i+1]
                num_stack.append(cur)


                if num[i+1:] == '':

                    ns, ops = calc(num_stack, op_stack, '+')
                    if ns[-1] == target:
                        ret.append(formula + cur_s)
                else:
                    ns, ops = calc(num_stack, op_stack, '+')  # calc
                    do(num[i + 1:], ns, ops + ['+'], formula + cur_s + '+')

                    do(num[i + 1:], ns, ops + ['-'], formula + cur_s + '-')

                    ns, ops = calc(num_stack, op_stack, '*')  # calc

                    do(num[i + 1:], ns, ops + ['*'], formula + cur_s + '*')

                num_stack.pop()

            pass

        do(num, [], [], '')
        return ret



sol = Solution()
ret = sol.addOperators("2147483648", -2147483648)
print(ret)
