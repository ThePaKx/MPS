/********************************************************************************
** Form generated from reading UI file 'showresultwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWRESULTWINDOW_H
#define UI_SHOWRESULTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShowResultWindow
{
public:
    QAction *actionsave;
    QAction *actionsaveAs;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTableWidget *preresWidget;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ShowResultWindow)
    {
        if (ShowResultWindow->objectName().isEmpty())
            ShowResultWindow->setObjectName(QString::fromUtf8("ShowResultWindow"));
        ShowResultWindow->resize(400, 600);
        actionsave = new QAction(ShowResultWindow);
        actionsave->setObjectName(QString::fromUtf8("actionsave"));
        actionsaveAs = new QAction(ShowResultWindow);
        actionsaveAs->setObjectName(QString::fromUtf8("actionsaveAs"));
        centralwidget = new QWidget(ShowResultWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        preresWidget = new QTableWidget(centralwidget);
        if (preresWidget->columnCount() < 2)
            preresWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        preresWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        preresWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        preresWidget->setObjectName(QString::fromUtf8("preresWidget"));

        verticalLayout->addWidget(preresWidget);

        ShowResultWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ShowResultWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 400, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        ShowResultWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ShowResultWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ShowResultWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(actionsave);
        menu->addAction(actionsaveAs);

        retranslateUi(ShowResultWindow);

        QMetaObject::connectSlotsByName(ShowResultWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ShowResultWindow)
    {
        ShowResultWindow->setWindowTitle(QApplication::translate("ShowResultWindow", "MainWindow", nullptr));
        actionsave->setText(QApplication::translate("ShowResultWindow", "\344\277\235\345\255\230", nullptr));
#ifndef QT_NO_SHORTCUT
        actionsave->setShortcut(QApplication::translate("ShowResultWindow", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionsaveAs->setText(QApplication::translate("ShowResultWindow", "\345\217\246\345\255\230\344\270\272", nullptr));
#ifndef QT_NO_SHORTCUT
        actionsaveAs->setShortcut(QApplication::translate("ShowResultWindow", "Ctrl+A", nullptr));
#endif // QT_NO_SHORTCUT
        QTableWidgetItem *___qtablewidgetitem = preresWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ShowResultWindow", "\345\205\211\350\260\261\346\226\207\344\273\266\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = preresWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ShowResultWindow", "\345\210\206\347\261\273\347\273\223\346\236\234", nullptr));
        menu->setTitle(QApplication::translate("ShowResultWindow", "\344\277\235\345\255\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShowResultWindow: public Ui_ShowResultWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWRESULTWINDOW_H
