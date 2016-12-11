

def main():
    vs = [ -0.03 for i in range(10)]

    cur_val = 1
    invest =  1

    addup = 0

    iter = 0
    for v  in vs:
        cur_val = cur_val + cur_val * v

        # cur_val + addup * 1.03 = invest +addup

        addup = (invest - 1.03*cur_val)/0.03
        print iter, v, addup
        iter +=1

        invest += addup
        cur_val += addup


if __name__ == '__main__':
    main()
