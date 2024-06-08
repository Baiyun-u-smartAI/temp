import numpy as np

n = 0
#从1到78循环
for x in range(1, 19*4+2):
    for y in range(x+1, 19*4+3):
        # 创建一个长度为19*4+2的数组，值从1到76
        a = np.arange(1, 19*4+2+1).astype(np.int8)
        # 从数组中删除x和y
        a = np.delete(a, np.where(a==x))
        a = np.delete(a, np.where(a==y))
        # print(a)
        gCount = 0 # 找到等差数列的组个数
        d = 1 # 找公差等于1的
        fail = False
        while len(a) != 0 and not fail:
            nCount = 1 # 找到一组等差数列里的个数
            temp0 = a[0] # 定义第一个数
            # 删除a[0]
            a = np.delete(a, 0)
            while nCount <4:

                # 查找a[0]+(nCount)*d是否在a中
                if temp0+nCount*d in a:
                    # 找到了
                    # 删除a中的temp0+(nCount)*d
                    a = np.delete(a, np.where(a==temp0+(nCount)*d))
                    nCount += 1 # 找到的个数加1
                    
                else:
                    # 没找到
                    fail = True
                    break

            
        if not fail:
            n+=1
            print(f'x={x}, y={y}, d={d}')
            continue
        else:
            # 创建一个长度为19*4+2的数组，值从1到76
            a = np.arange(1, 19*4+2+1).astype(np.int8)
            # 从数组中删除x和y
            a = np.delete(a, np.where(a==x))
            a = np.delete(a, np.where(a==y))
            gCount = 0 # 找到等差数列的组个数
            d = 19 # 找公差等于1的
            found = False
            fail = False
            while len(a) != 0 and not fail:
                nCount = 1 # 找到一组等差数列里的个数
                temp0 = a[0] # 定义第一个数
                # 删除a[0]
                a = np.delete(a, 0)
                while nCount <4:
                    if temp0+nCount*d in a:
                        # 找到了
                        # 删除a中的temp0+(nCount)*d
                        a = np.delete(a, np.where(a==temp0+(nCount)*d))
                        nCount += 1 # 找到的个数加1
                        
                    else:
                        fail = True
                        break

            if not fail:
                n+=1
                print(f'x={x}, y={y}, d={d}')

# 计算78里面选2个的组合数
all = 78*77/2
print(f'总共有{n}组，占比{n/all*100}%')
