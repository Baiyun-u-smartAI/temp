# -*- coding: UTF-8 -*-
import numpy as np
import matplotlib.pyplot as plt
from matplotlib import cm
from mpl_toolkits.mplot3d import axes3d
p0=0.5*1000
l1=0.04
l0=0.1185
D=0.02
d=D-0.0544/1000
E2=1115*10**6
F=np.linspace(0,0.3,30)
x=np.linspace(0,0.1185,30)
F,x=np.meshgrid(F,x)
# for i in range(0,100):
#     for j in range(0,1000):
#         xta[i][j]=64*F[i]*x[j]*(l0+((p0+F[i]/(d*l1))*d**2)/(E2*(D**2-d**2)-(p0+F[i]/(d*l1))*(D**2+d**2)))/(E2*np.pi*(D**4-d**4))
xta=64*F*x*(l0+((p0+F/(d*l1))*d**2)/(E2*(D**2-d**2)-(p0+F/(d*l1))*(D**2+d**2)))/(E2*np.pi*(D**4-d**4))
fig = plt.figure()
ax = fig.gca(projection='3d')
ax.plot_surface(F, x, xta, rstride=1, cstride=1, cmap=cm.rainbow,
                       linewidth=3, antialiased=False)
plt.show()




