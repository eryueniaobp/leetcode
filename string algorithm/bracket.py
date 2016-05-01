
def is_match(str):
    stack = []
    i = 0 
    for c in str:
        if c == '{':
            stack.append(c)
        else:
            #stack[-1]: get the last element of the array
            if len(stack) >0 and stack[-1] == '{':
                stack.pop()
            else:
                return False

    if  len(stack) > 0: 
        return False
    else:
        return True
    
def main():
    str= '{{{}}}{{}}'
    print is_match(str) #True

    str= '{{{}}}{{}}{'
    print is_match(str) #False

    str = '{}}}'
    print is_match(str) #False
if __name__ == '__main__':
    main()
