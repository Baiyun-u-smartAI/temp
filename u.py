
number = input("输入").split(' ')
# number= ['1', '3.4', '90']

# number_list = [float(i) for i in number]
number_list = []
for i in number:
    number_list.append(float(i))

    
# number_list = list(map(int,number))

print(number_list)
print(type(number))



number_list.sort()

print("排序后的数字列表为：%s" % number_list)
