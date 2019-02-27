

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMainWindow>
class QDial;
class QAction;
class QWidget;
class QTextBrowser;
class QMenuBar;
class QMenu;
class QStatusBar;



class Window : public QMainWindow
{
    Q_OBJECT

public:
    Window();

private:
    QAction *action;
    QWidget *centralwidget;
    QDial *dial;
    QTextBrowser *textBrowser;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;
    int random_number;

public slots:
    void disable(int value);

};

#endif