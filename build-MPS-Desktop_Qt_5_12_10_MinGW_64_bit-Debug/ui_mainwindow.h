/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>
#include <qchartview.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *openSpec;
    QAction *openReal;
    QAction *actionSNV;
    QAction *actionMSC;
    QAction *actionFD;
    QAction *actionSD;
    QAction *actionAUG;
    QAction *actionNormalize;
    QAction *actionloadSVCModel;
    QAction *actionsave;
    QAction *actionsaveAs;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QSplitter *splitter;
    QChartView *widget;
    QTableWidget *showCTableWidget;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *loadModelMenu;
    QMenu *menu_3;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1000, 800);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        openSpec = new QAction(MainWindow);
        openSpec->setObjectName(QString::fromUtf8("openSpec"));
        openReal = new QAction(MainWindow);
        openReal->setObjectName(QString::fromUtf8("openReal"));
        actionSNV = new QAction(MainWindow);
        actionSNV->setObjectName(QString::fromUtf8("actionSNV"));
        actionMSC = new QAction(MainWindow);
        actionMSC->setObjectName(QString::fromUtf8("actionMSC"));
        actionFD = new QAction(MainWindow);
        actionFD->setObjectName(QString::fromUtf8("actionFD"));
        actionSD = new QAction(MainWindow);
        actionSD->setObjectName(QString::fromUtf8("actionSD"));
        actionAUG = new QAction(MainWindow);
        actionAUG->setObjectName(QString::fromUtf8("actionAUG"));
        actionNormalize = new QAction(MainWindow);
        actionNormalize->setObjectName(QString::fromUtf8("actionNormalize"));
        actionloadSVCModel = new QAction(MainWindow);
        actionloadSVCModel->setObjectName(QString::fromUtf8("actionloadSVCModel"));
        actionsave = new QAction(MainWindow);
        actionsave->setObjectName(QString::fromUtf8("actionsave"));
        actionsaveAs = new QAction(MainWindow);
        actionsaveAs->setObjectName(QString::fromUtf8("actionsaveAs"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        sizePolicy.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy);
        splitter->setOrientation(Qt::Vertical);
        widget = new QChartView(splitter);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(40);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        splitter->addWidget(widget);
        showCTableWidget = new QTableWidget(splitter);
        if (showCTableWidget->columnCount() < 1)
            showCTableWidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        showCTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        showCTableWidget->setObjectName(QString::fromUtf8("showCTableWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(1);
        sizePolicy2.setHeightForWidth(showCTableWidget->sizePolicy().hasHeightForWidth());
        showCTableWidget->setSizePolicy(sizePolicy2);
        splitter->addWidget(showCTableWidget);

        gridLayout_2->addWidget(splitter, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1000, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        loadModelMenu = new QMenu(menubar);
        loadModelMenu->setObjectName(QString::fromUtf8("loadModelMenu"));
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(loadModelMenu->menuAction());
        menubar->addAction(menu_3->menuAction());
        menu->addAction(openSpec);
        menu->addAction(openReal);
        menu_2->addAction(actionSNV);
        menu_2->addAction(actionMSC);
        menu_2->addAction(actionFD);
        menu_2->addAction(actionSD);
        menu_2->addAction(actionNormalize);
        menu_2->addAction(actionAUG);
        loadModelMenu->addAction(actionloadSVCModel);
        menu_3->addAction(actionsave);
        menu_3->addAction(actionsaveAs);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MPS", nullptr));
        openSpec->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\351\242\204\346\265\213\345\205\211\350\260\261", nullptr));
        openReal->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\351\242\204\346\265\213\347\234\237\345\256\236\345\210\206\347\261\273\345\200\274 ", nullptr));
        actionSNV->setText(QApplication::translate("MainWindow", "SNV", nullptr));
        actionMSC->setText(QApplication::translate("MainWindow", "MSC", nullptr));
        actionFD->setText(QApplication::translate("MainWindow", "FD", nullptr));
        actionSD->setText(QApplication::translate("MainWindow", "SD", nullptr));
        actionAUG->setText(QApplication::translate("MainWindow", "AUG", nullptr));
        actionNormalize->setText(QApplication::translate("MainWindow", "Normalize", nullptr));
        actionloadSVCModel->setText(QApplication::translate("MainWindow", "\345\212\240\350\275\275SVM\346\250\241\345\236\213", nullptr));
        actionsave->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
#ifndef QT_NO_SHORTCUT
        actionsave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionsaveAs->setText(QApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272", nullptr));
#ifndef QT_NO_SHORTCUT
        actionsaveAs->setShortcut(QApplication::translate("MainWindow", "Ctrl+A", nullptr));
#endif // QT_NO_SHORTCUT
        QTableWidgetItem *___qtablewidgetitem = showCTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\345\210\206\347\261\273\346\225\260\346\215\256", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        menu_2->setTitle(QApplication::translate("MainWindow", "\351\242\204\345\244\204\347\220\206", nullptr));
        loadModelMenu->setTitle(QApplication::translate("MainWindow", "\345\257\274\345\205\245\346\250\241\345\236\213", nullptr));
        menu_3->setTitle(QApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
