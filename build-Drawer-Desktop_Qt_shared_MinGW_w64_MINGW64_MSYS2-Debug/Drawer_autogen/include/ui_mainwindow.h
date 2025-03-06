/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mousegraphicsview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *lblWidthHeader;
    QHBoxLayout *horizontalLayout;
    QLabel *lblWidth;
    QLabel *lblWidthPix;
    QCheckBox *cbxAnimatedFloodFill;
    QSpacerItem *verticalSpacer;
    QPushButton *pbClear;
    MouseGraphicsView *gvDrawer;
    QLabel *lblInstructions;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1021, 632);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        lblWidthHeader = new QLabel(centralwidget);
        lblWidthHeader->setObjectName("lblWidthHeader");
        QFont font;
        font.setPointSize(16);
        lblWidthHeader->setFont(font);

        verticalLayout->addWidget(lblWidthHeader);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        lblWidth = new QLabel(centralwidget);
        lblWidth->setObjectName("lblWidth");
        lblWidth->setFont(font);
        lblWidth->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(lblWidth);

        lblWidthPix = new QLabel(centralwidget);
        lblWidthPix->setObjectName("lblWidthPix");
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lblWidthPix->sizePolicy().hasHeightForWidth());
        lblWidthPix->setSizePolicy(sizePolicy);
        lblWidthPix->setFont(font);
        lblWidthPix->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(lblWidthPix);


        verticalLayout->addLayout(horizontalLayout);

        cbxAnimatedFloodFill = new QCheckBox(centralwidget);
        cbxAnimatedFloodFill->setObjectName("cbxAnimatedFloodFill");
        QFont font1;
        font1.setPointSize(14);
        cbxAnimatedFloodFill->setFont(font1);
        cbxAnimatedFloodFill->setTristate(false);

        verticalLayout->addWidget(cbxAnimatedFloodFill);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pbClear = new QPushButton(centralwidget);
        pbClear->setObjectName("pbClear");
        pbClear->setFont(font);

        verticalLayout->addWidget(pbClear);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        gvDrawer = new MouseGraphicsView(centralwidget);
        gvDrawer->setObjectName("gvDrawer");

        gridLayout->addWidget(gvDrawer, 0, 0, 1, 1);

        lblInstructions = new QLabel(centralwidget);
        lblInstructions->setObjectName("lblInstructions");
        lblInstructions->setFont(font1);
        lblInstructions->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lblInstructions, 1, 0, 1, 2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1021, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lblWidthHeader->setText(QCoreApplication::translate("MainWindow", "\320\242\320\276\320\273\321\211\320\270\320\275\320\260 \320\277\320\265\321\200\320\260:", nullptr));
        lblWidth->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        lblWidthPix->setText(QCoreApplication::translate("MainWindow", "\320\277\320\270\320\272\321\201", nullptr));
        cbxAnimatedFloodFill->setText(QCoreApplication::translate("MainWindow", "\320\220\320\275\320\270\320\274\320\260\321\206\320\270\321\217 \320\267\320\260\320\273\320\270\320\262\320\272\320\270", nullptr));
        pbClear->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        lblInstructions->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\320\240\320\270\321\201\320\276\320\262\320\260\320\275\320\270\320\265 \320\272\321\203\321\200\321\201\320\276\321\200\320\276\320\274 \320\274\321\213\321\210\320\270. \320\230\320\267\320\274\320\265\320\275\320\265\320\275\320\270\320\265 \321\202\320\276\320\273\321\211\320\270\320\275\321\213 \320\273\320\270\320\275\320\270\320\270 - \320\272\320\276\320\273\321\221\321\201\320\270\320\272\320\276\320\274 \320\274\321\213\321\210\320\270.</p><p>\320\227\320\260\320\273\320\270\320\262\320\272\320\260 - \320\277\321\200\320\260\320\262\320\260\321\217 \320\272\320\275\320\276\320\277\320\272\320\260 \320\274\321\213\321\210\320\270.</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
