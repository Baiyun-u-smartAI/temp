#include <QtWidgets>
#include "mainwindow.h"


Window::Window() {
    setWindowTitle("MainWindow");
    resize(287, 300);
    action = new QAction;
    action->setObjectName("action");
    centralwidget = new QWidget;
    centralwidget->setObjectName("centralwidget");

    dial = new QDial(centralwidget);
    dial->setObjectName("dial");
    dial->setGeometry(QRect(30, 10, 221, 221));
    connect(dial,SIGNAL(valueChanged(int)),SLOT(disable(int)));
    random_number = rand()%99+1;
    textBrowser = new QTextBrowser(centralwidget);
    textBrowser->setObjectName("textBrowser");
    textBrowser->setGeometry(QRect(10, 220, 256, 31));
    setCentralWidget(centralwidget);
    menubar = new QMenuBar;
    menubar->setObjectName("menubar");
    menubar->setGeometry(QRect(0, 0, 287, 23));
    menu = new QMenu(menubar);
    menu->setObjectName("menu");
    setMenuBar(menubar);
    statusbar = new QStatusBar;
    statusbar->setObjectName("statusbar");
    setStatusBar(statusbar);
    menubar->addAction(menu->menuAction());
    menu->addAction(action);
    setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
    action->setText(QApplication::translate("MainWindow", "\351\207\215\347\275\256", Q_NULLPTR));
    textBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
                                                               "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
                                                               "p, li { white-space: pre-wrap; }\n"
                                                               "</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
                                                               "<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">:|</span></p></body></html>", Q_NULLPTR));
    menu->setTitle(QApplication::translate("MainWindow", "\345\274\200\345\247\213", Q_NULLPTR));




}


void Window::disable(int value) {
    dial->setEnabled(false);


}






