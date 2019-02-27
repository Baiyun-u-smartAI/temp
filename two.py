# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'two.ui'
#
# Created by: PyQt5 UI code generator 5.6
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *


# 给QtWidgets定义keypress事件函数
class spinBox(QtWidgets.QSpinBox):
    def keyPressEvent(self, event):
        print "hey dude, your press key on me"


class Ui_Dialog(QMainWindow):
    def __init__(self, parent=None):
        QMainWindow.__init__(self, parent=parent)
        self.setupUi(self)
    def setupUi(self, Dialog):
        Dialog.setObjectName("Dialog")
        Dialog.resize(605, 462)
        self.dial = QtWidgets.QDial(Dialog)
        self.dial.setGeometry(QtCore.QRect(140, 30, 191, 161))
        self.dial.setProperty("value", 0)
        self.dial.setObjectName("dial")
        # 启用已经定义好的QtWidgets.QSpinBox类
        self.spinBox = spinBox(Dialog)

        self.spinBox.setGeometry(QtCore.QRect(240, 250, 61, 31))
        self.spinBox.setObjectName("spinBox")

        # self.retranslateUi(Dialog)
        QtCore.QMetaObject.connectSlotsByName(Dialog)

        self.dial.valueChanged.connect(lambda value: self.fun(value))
        #self.spinBox.valueChanged.connect(lambda value: self.fun(value))
        self.spinBox.setRange(20,200)
        self.spinBox.setSingleStep(10)
        self.spinBox.setWrapping(True)



        Dialog.show()
    # def retranslateUi(self, Dialog):
    #     _translate = QtCore.QCoreApplication.translate
    #     Dialog.setWindowTitle(_translate("Dialog", "Dialog"))


    def fun(self,value):
        if value*1.5<99:
            self.dial.valueChanged.disconnect()
            self.dial.setValue(value*1.5)
            self.dial.valueChanged.connect(lambda value: self.fun(value))
        else:
            self.dial.valueChanged.disconnect()
            self.dial.setValue(value*0.5)
            self.dial.valueChanged.connect(lambda value: self.fun(value))
    def keyPressEvent(self, e):
            if e.key() == Qt.Key_F5:
                print "ok"
                self.dial.valueChanged.disconnect()
            elif e.key()==Qt.Key_F6:
                self.dial.valueChanged.connect(lambda value: self.fun(value))

if __name__ == "__main__":
            import sys
            app = QApplication(sys.argv)
            w = Ui_Dialog()
            w.show()
            sys.exit(app.exec_())

            pass
