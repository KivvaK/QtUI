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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGraphicsView *gvPlot;
    QVBoxLayout *verticalLayout;
    QPushButton *pbRUp;
    QSpacerItem *verticalSpacer;
    QPushButton *pbRDown;
    QGroupBox *gbSettings;
    QGridLayout *gridLayout;
    QDoubleSpinBox *dsbXShrink;
    QLabel *label_8;
    QLabel *label_9;
    QComboBox *cbxSurfaces;
    QLabel *label_2;
    QSpinBox *sbHorizonCount;
    QDoubleSpinBox *dsbZShrink;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_6;
    QDoubleSpinBox *dsbYDepth;
    QHBoxLayout *horizontalLayout;
    QPushButton *pbRLeft;
    QSpacerItem *horizontalSpacer;
    QPushButton *pbRRight;
    QPushButton *pbDraw;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(853, 551);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        gvPlot = new QGraphicsView(centralwidget);
        gvPlot->setObjectName("gvPlot");

        gridLayout_2->addWidget(gvPlot, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        pbRUp = new QPushButton(centralwidget);
        pbRUp->setObjectName("pbRUp");
        QFont font;
        font.setPointSize(14);
        pbRUp->setFont(font);

        verticalLayout->addWidget(pbRUp);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pbRDown = new QPushButton(centralwidget);
        pbRDown->setObjectName("pbRDown");
        pbRDown->setFont(font);

        verticalLayout->addWidget(pbRDown);


        gridLayout_2->addLayout(verticalLayout, 0, 1, 1, 1);

        gbSettings = new QGroupBox(centralwidget);
        gbSettings->setObjectName("gbSettings");
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(gbSettings->sizePolicy().hasHeightForWidth());
        gbSettings->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(10);
        gbSettings->setFont(font1);
        gridLayout = new QGridLayout(gbSettings);
        gridLayout->setObjectName("gridLayout");
        dsbXShrink = new QDoubleSpinBox(gbSettings);
        dsbXShrink->setObjectName("dsbXShrink");
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(dsbXShrink->sizePolicy().hasHeightForWidth());
        dsbXShrink->setSizePolicy(sizePolicy1);
        dsbXShrink->setFont(font1);
        dsbXShrink->setMinimum(-99.989999999999995);
        dsbXShrink->setValue(10.000000000000000);

        gridLayout->addWidget(dsbXShrink, 0, 1, 1, 3);

        label_8 = new QLabel(gbSettings);
        label_8->setObjectName("label_8");
        label_8->setFont(font1);

        gridLayout->addWidget(label_8, 2, 0, 1, 1);

        label_9 = new QLabel(gbSettings);
        label_9->setObjectName("label_9");

        gridLayout->addWidget(label_9, 5, 0, 1, 2);

        cbxSurfaces = new QComboBox(gbSettings);
        cbxSurfaces->addItem(QString());
        cbxSurfaces->addItem(QString());
        cbxSurfaces->addItem(QString());
        cbxSurfaces->setObjectName("cbxSurfaces");
        cbxSurfaces->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(cbxSurfaces, 6, 0, 1, 4);

        label_2 = new QLabel(gbSettings);
        label_2->setObjectName("label_2");
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);
        label_2->setFont(font1);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        sbHorizonCount = new QSpinBox(gbSettings);
        sbHorizonCount->setObjectName("sbHorizonCount");
        sbHorizonCount->setMaximum(300);
        sbHorizonCount->setValue(50);

        gridLayout->addWidget(sbHorizonCount, 5, 2, 1, 2);

        dsbZShrink = new QDoubleSpinBox(gbSettings);
        dsbZShrink->setObjectName("dsbZShrink");
        dsbZShrink->setFont(font1);
        dsbZShrink->setMinimum(-99.989999999999995);
        dsbZShrink->setValue(4.000000000000000);

        gridLayout->addWidget(dsbZShrink, 2, 1, 1, 3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 7, 0, 1, 4);

        label_6 = new QLabel(gbSettings);
        label_6->setObjectName("label_6");
        label_6->setFont(font1);

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

        dsbYDepth = new QDoubleSpinBox(gbSettings);
        dsbYDepth->setObjectName("dsbYDepth");
        dsbYDepth->setFont(font1);
        dsbYDepth->setMinimum(-99.989999999999995);
        dsbYDepth->setValue(6.000000000000000);

        gridLayout->addWidget(dsbYDepth, 3, 1, 1, 3);


        gridLayout_2->addWidget(gbSettings, 0, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pbRLeft = new QPushButton(centralwidget);
        pbRLeft->setObjectName("pbRLeft");
        pbRLeft->setFont(font);

        horizontalLayout->addWidget(pbRLeft);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pbRRight = new QPushButton(centralwidget);
        pbRRight->setObjectName("pbRRight");
        pbRRight->setFont(font);

        horizontalLayout->addWidget(pbRRight);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);

        pbDraw = new QPushButton(centralwidget);
        pbDraw->setObjectName("pbDraw");
        sizePolicy.setHeightForWidth(pbDraw->sizePolicy().hasHeightForWidth());
        pbDraw->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(pbDraw, 1, 1, 1, 2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 853, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\234\320\265\321\202\320\276\320\264 \320\277\320\273\320\260\320\262\320\260\321\216\321\211\320\265\320\263\320\276 \320\263\320\276\321\200\320\270\320\267\320\276\320\275\321\202\320\260", nullptr));
        pbRUp->setText(QCoreApplication::translate("MainWindow", "\342\206\221", nullptr));
#if QT_CONFIG(shortcut)
        pbRUp->setShortcut(QCoreApplication::translate("MainWindow", "Up", nullptr));
#endif // QT_CONFIG(shortcut)
        pbRDown->setText(QCoreApplication::translate("MainWindow", "\342\206\223", nullptr));
#if QT_CONFIG(shortcut)
        pbRDown->setShortcut(QCoreApplication::translate("MainWindow", "Down", nullptr));
#endif // QT_CONFIG(shortcut)
        gbSettings->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\277\320\276\321\201\321\202\321\200\320\276\320\265\320\275\320\270\321\217", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "zShrink", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\320\247\320\270\321\201\320\273\320\276 \320\277\320\273\320\276\321\201\320\272\320\276\321\201\321\202\320\265\320\271:", nullptr));
        cbxSurfaces->setItemText(0, QCoreApplication::translate("MainWindow", "\320\234\320\265\320\272\321\201\320\270\320\272\320\260\320\275\321\201\320\272\320\260\321\217 \321\210\320\273\321\217\320\277\320\260", nullptr));
        cbxSurfaces->setItemText(1, QCoreApplication::translate("MainWindow", "\320\232\320\260\321\200\320\264\320\270\320\275\320\260\320\273\321\214\320\275\321\213\320\271 \321\201\320\270\320\275\321\203\321\201", nullptr));
        cbxSurfaces->setItemText(2, QCoreApplication::translate("MainWindow", "\320\237\320\270\320\272\320\270", nullptr));

        label_2->setText(QCoreApplication::translate("MainWindow", "xShrink", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "yDepth", nullptr));
        pbRLeft->setText(QCoreApplication::translate("MainWindow", "\342\206\220", nullptr));
#if QT_CONFIG(shortcut)
        pbRLeft->setShortcut(QCoreApplication::translate("MainWindow", "Left", nullptr));
#endif // QT_CONFIG(shortcut)
        pbRRight->setText(QCoreApplication::translate("MainWindow", "\342\206\222", nullptr));
#if QT_CONFIG(shortcut)
        pbRRight->setShortcut(QCoreApplication::translate("MainWindow", "Right", nullptr));
#endif // QT_CONFIG(shortcut)
        pbDraw->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\200\320\270\321\201\320\276\320\262\320\260\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
