# -*- coding: utf-8 -*-
"""
import matplotlib.pyplot as plt
import pydicom
import numpy as np
from pydicom.data import get_testdata_files


# filename = get_testdata_files("1.dcm")[0]
ds = pydicom.dcmread("0002DCFC.dcm")

A=(ds.pixel_array+0.0)/(4096.)
B1= A[460:460+730]  # 长度730,y
B1=np.transpose(B1)[1260:1260+730]  # 长度730,x
B2=A[1250:1250+730]  # y
B2=np.transpose(B2)[1220:1220+730]  # x
B3=A[2000:2000+730]
B3=np.transpose(B3)[1310:1310+730]
B4=A[2730:2730+730]
B4=np.transpose(B4)[1300:1300+730]
plt.imshow(ds.pixel_array,cmap=plt.cm.bone)
# plt.imshow(np.transpose(B1),cmap=plt.cm.bone)
# plt.imshow(np.transpose(B2),cmap=plt.cm.bone)
# plt.imshow(np.transpose(B3),cmap=plt.cm.bone)
# plt.imshow(np.transpose(B4),cmap=plt.cm.bone)



plt.show()
print np.sum(B1),np.sum(B2),np.sum(B3),np.sum(B4)

"""
class MyClass(object):
    def __init__(self):
        self.data=0

def func(self):
    print "func"




if __name__=="__main__":
    MyClass.func = func
    a=MyClass()
    a.func()


