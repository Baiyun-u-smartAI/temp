# -*- coding: UTF-8 -*-
import numpy as np
import matplotlib.pyplot as plt

class four_side(object):
    def __init__(self,x,y,a,numbers=100):
        pointlist=np.zeros((2,numbers*4))
        pointlist[0][0:numbers]=np.linspace(x-a/2.,x+a/2.,numbers)
        pointlist[1][0:numbers]=np.ones(numbers)*(y+a/2.)
        pointlist[0][numbers:2*numbers]=np.ones(numbers) * (x + a / 2.)
        pointlist[1][numbers:2*numbers]=np.linspace(y - a / 2., y + a / 2., numbers)
        pointlist[0][2*numbers:3*numbers] = np.linspace(x - a / 2., x + a / 2., numbers)
        pointlist[1][2*numbers:3*numbers] = np.ones(numbers) * (y - a / 2.)
        pointlist[0][3*numbers:4*numbers] = np.ones(numbers) * (x - a / 2.)
        pointlist[1][3*numbers:4*numbers] = np.linspace(y - a / 2., y + a / 2., numbers)
        self.pointlist=np.transpose(pointlist)

    @classmethod
    def rotate(cls,object,angle=np.random.random()*90):
        temp=np.transpose(object.pointlist)
        angle=angle/180.*np.pi
        temp[0],temp[1] = temp[0] * np.cos(angle) + temp[1] * np.sin(angle),-temp[0] * np.sin(angle) + temp[1] * np.cos(angle)

        object.pointlist=np.transpose(temp)
        return object


if __name__ =="__main__":
    plt.figure()
    a=four_side(1,2,3)
    a=four_side.rotate(a)
    a=a.pointlist
    plt.scatter(np.transpose(a)[0],np.transpose(a)[1])
    plt.show()
    # print np.random.random()