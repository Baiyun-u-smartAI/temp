# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'one.ui'
#
# Created by: PyQt5 UI code generator 5.6
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *  
class Ui_Dialog(object):
    def setupUi(self, Dialog):
        Dialog.setObjectName("Dialog")
        Dialog.resize(605, 462)
        self.dial = QtWidgets.QDial(Dialog)
        self.dial.setGeometry(QtCore.QRect(180, 140, 191, 161))
        self.dial.setObjectName("dial")
        

        self.retranslateUi(Dialog)
        QtCore.QMetaObject.connectSlotsByName(Dialog)
        self.dial.valueChanged.connect(self.myfun)
        Dialog.show()
    def retranslateUi(self, Dialog):
        _translate = QtCore.QCoreApplication.translate
        Dialog.setWindowTitle(_translate("Dialog", "Dialog"))
    def myfun(self):
        print self.dial.value()
if __name__ == "__main__":
    import sys
    app = QApplication(sys.argv)
    widget = QWidget(None)
    Ui_Dialog().setupUi(widget)
    
    sys.exit(app.exec_())
    
    pass
    print "ok"
