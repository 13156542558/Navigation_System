/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QToolBox *toolBox;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *inputx_2;
    QLineEdit *inputy_2;
    QLineEdit *coordinate_1;
    QLineEdit *coordinate_2;
    QLineEdit *nearest_res;
    QLineEdit *nearest_gas;
    QVBoxLayout *verticalLayout_7;
    QToolButton *toolButton_7;
    QToolButton *toolButton_6;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QListView *listView_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *shortpt;
    QPushButton *pushButton;
    QWidget *page_4;
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *verticalLayout;
    QLineEdit *inputx;
    QLineEdit *inputy;
    QPushButton *nearpt;
    QVBoxLayout *verticalLayout_8;
    QLabel *label;
    QListView *listView;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QToolButton *toolButton_4;
    QToolButton *toolButton_5;
    QToolButton *toolButton;
    QVBoxLayout *verticalLayout_11;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_peak;
    QPushButton *pushButton_non;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *cancel;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(929, 868);
        MainWindow->setMaximumSize(QSize(1024, 1024));
        MainWindow->setStyleSheet(QString::fromUtf8("#MainWindow{border-image: url(:/images/back_img.jpg);}"));
        MainWindow->setIconSize(QSize(1024, 1024));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        toolBox = new QToolBox(centralwidget);
        toolBox->setObjectName("toolBox");
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolBox->sizePolicy().hasHeightForWidth());
        toolBox->setSizePolicy(sizePolicy);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        page_3->setGeometry(QRect(0, 0, 231, 676));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(page_3->sizePolicy().hasHeightForWidth());
        page_3->setSizePolicy(sizePolicy1);
        page_3->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_9 = new QVBoxLayout(page_3);
        verticalLayout_9->setObjectName("verticalLayout_9");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        inputx_2 = new QLineEdit(page_3);
        inputx_2->setObjectName("inputx_2");
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(inputx_2->sizePolicy().hasHeightForWidth());
        inputx_2->setSizePolicy(sizePolicy2);
        inputx_2->setMinimumSize(QSize(100, 20));
        inputx_2->setMaximumSize(QSize(300, 20));
        inputx_2->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(inputx_2);

        inputy_2 = new QLineEdit(page_3);
        inputy_2->setObjectName("inputy_2");
        inputy_2->setMinimumSize(QSize(100, 20));
        inputy_2->setMaximumSize(QSize(300, 20));
        inputy_2->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(inputy_2);

        coordinate_1 = new QLineEdit(page_3);
        coordinate_1->setObjectName("coordinate_1");
        coordinate_1->setMinimumSize(QSize(100, 20));
        coordinate_1->setMaximumSize(QSize(300, 20));
        coordinate_1->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(coordinate_1);

        coordinate_2 = new QLineEdit(page_3);
        coordinate_2->setObjectName("coordinate_2");
        coordinate_2->setMinimumSize(QSize(100, 20));
        coordinate_2->setMaximumSize(QSize(300, 20));
        coordinate_2->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(coordinate_2);

        nearest_res = new QLineEdit(page_3);
        nearest_res->setObjectName("nearest_res");
        nearest_res->setMinimumSize(QSize(100, 20));
        nearest_res->setMaximumSize(QSize(300, 20));
        nearest_res->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(nearest_res);

        nearest_gas = new QLineEdit(page_3);
        nearest_gas->setObjectName("nearest_gas");
        nearest_gas->setMaximumSize(QSize(300, 20));
        nearest_gas->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(nearest_gas);


        verticalLayout_9->addLayout(verticalLayout_3);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setContentsMargins(0, 0, -1, -1);
        toolButton_7 = new QToolButton(page_3);
        toolButton_7->setObjectName("toolButton_7");
        sizePolicy2.setHeightForWidth(toolButton_7->sizePolicy().hasHeightForWidth());
        toolButton_7->setSizePolicy(sizePolicy2);
        toolButton_7->setMinimumSize(QSize(100, 20));
        toolButton_7->setMaximumSize(QSize(300, 20));

        verticalLayout_7->addWidget(toolButton_7);

        toolButton_6 = new QToolButton(page_3);
        toolButton_6->setObjectName("toolButton_6");
        sizePolicy2.setHeightForWidth(toolButton_6->sizePolicy().hasHeightForWidth());
        toolButton_6->setSizePolicy(sizePolicy2);
        toolButton_6->setMinimumSize(QSize(100, 20));
        toolButton_6->setMaximumSize(QSize(300, 20));

        verticalLayout_7->addWidget(toolButton_6);


        verticalLayout_9->addLayout(verticalLayout_7);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_3 = new QLabel(page_3);
        label_3->setObjectName("label_3");
        label_3->setMinimumSize(QSize(150, 15));
        label_3->setMaximumSize(QSize(2000, 20));
        label_3->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        verticalLayout_4->addWidget(label_3);

        listView_2 = new QListView(page_3);
        listView_2->setObjectName("listView_2");
        listView_2->setMaximumSize(QSize(300, 680));

        verticalLayout_4->addWidget(listView_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(-1, 0, -1, -1);
        shortpt = new QPushButton(page_3);
        shortpt->setObjectName("shortpt");
        sizePolicy2.setHeightForWidth(shortpt->sizePolicy().hasHeightForWidth());
        shortpt->setSizePolicy(sizePolicy2);
        shortpt->setMinimumSize(QSize(100, 20));
        shortpt->setMaximumSize(QSize(250, 20));

        horizontalLayout_3->addWidget(shortpt);

        pushButton = new QPushButton(page_3);
        pushButton->setObjectName("pushButton");
        sizePolicy2.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy2);
        pushButton->setMinimumSize(QSize(100, 20));
        pushButton->setMaximumSize(QSize(250, 20));

        horizontalLayout_3->addWidget(pushButton);


        verticalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout_4);


        verticalLayout_9->addLayout(verticalLayout_2);

        toolBox->addItem(page_3, QString::fromUtf8("\345\234\260\347\202\271\345\256\232\347\202\271\345\257\274\350\210\252"));
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        page_4->setGeometry(QRect(0, 0, 231, 676));
        verticalLayout_10 = new QVBoxLayout(page_4);
        verticalLayout_10->setObjectName("verticalLayout_10");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, -1, -1, -1);
        inputx = new QLineEdit(page_4);
        inputx->setObjectName("inputx");
        inputx->setMinimumSize(QSize(100, 20));
        inputx->setMaximumSize(QSize(300, 20));
        inputx->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(inputx);

        inputy = new QLineEdit(page_4);
        inputy->setObjectName("inputy");
        sizePolicy2.setHeightForWidth(inputy->sizePolicy().hasHeightForWidth());
        inputy->setSizePolicy(sizePolicy2);
        inputy->setMinimumSize(QSize(100, 20));
        inputy->setMaximumSize(QSize(300, 20));
        inputy->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(inputy);

        nearpt = new QPushButton(page_4);
        nearpt->setObjectName("nearpt");
        nearpt->setMinimumSize(QSize(100, 20));
        nearpt->setMaximumSize(QSize(300, 20));

        verticalLayout->addWidget(nearpt);


        verticalLayout_10->addLayout(verticalLayout);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        label = new QLabel(page_4);
        label->setObjectName("label");
        label->setTextFormat(Qt::AutoText);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(label);

        listView = new QListView(page_4);
        listView->setObjectName("listView");
        listView->setEnabled(true);
        listView->setMaximumSize(QSize(300, 680));
        listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listView->setSpacing(0);
        listView->setModelColumn(0);
        listView->setWordWrap(false);

        verticalLayout_8->addWidget(listView);


        verticalLayout_10->addLayout(verticalLayout_8);

        toolBox->addItem(page_4, QString::fromUtf8("\345\257\273\346\211\276\351\231\204\350\277\221100\344\270\252\347\202\271"));

        gridLayout->addWidget(toolBox, 0, 1, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setSizeConstraint(QLayout::SetMaximumSize);
        horizontalSpacer = new QSpacerItem(680, 680, QSizePolicy::Fixed, QSizePolicy::Minimum);

        verticalLayout_5->addItem(horizontalSpacer);


        gridLayout->addLayout(verticalLayout_5, 0, 0, 2, 1);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(-1, -1, -1, 20);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(150, 30));
        label_2->setMaximumSize(QSize(16777215, 10));
        QFont font;
        font.setPointSize(20);
        label_2->setFont(font);
        label_2->setTextFormat(Qt::AutoText);
        label_2->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        verticalLayout_6->addWidget(label_2);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_6->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        toolButton_2 = new QToolButton(centralwidget);
        toolButton_2->setObjectName("toolButton_2");
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(toolButton_2->sizePolicy().hasHeightForWidth());
        toolButton_2->setSizePolicy(sizePolicy3);
        toolButton_2->setMinimumSize(QSize(0, 30));
        toolButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 127, 0);"));

        horizontalLayout->addWidget(toolButton_2);

        toolButton_3 = new QToolButton(centralwidget);
        toolButton_3->setObjectName("toolButton_3");
        sizePolicy3.setHeightForWidth(toolButton_3->sizePolicy().hasHeightForWidth());
        toolButton_3->setSizePolicy(sizePolicy3);
        toolButton_3->setMinimumSize(QSize(0, 30));
        toolButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 0);"));

        horizontalLayout->addWidget(toolButton_3);

        toolButton_4 = new QToolButton(centralwidget);
        toolButton_4->setObjectName("toolButton_4");
        sizePolicy3.setHeightForWidth(toolButton_4->sizePolicy().hasHeightForWidth());
        toolButton_4->setSizePolicy(sizePolicy3);
        toolButton_4->setMinimumSize(QSize(0, 30));
        toolButton_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 0);"));

        horizontalLayout->addWidget(toolButton_4);

        toolButton_5 = new QToolButton(centralwidget);
        toolButton_5->setObjectName("toolButton_5");
        sizePolicy3.setHeightForWidth(toolButton_5->sizePolicy().hasHeightForWidth());
        toolButton_5->setSizePolicy(sizePolicy3);
        toolButton_5->setMinimumSize(QSize(0, 30));
        toolButton_5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));

        horizontalLayout->addWidget(toolButton_5);

        toolButton = new QToolButton(centralwidget);
        toolButton->setObjectName("toolButton");
        sizePolicy3.setHeightForWidth(toolButton->sizePolicy().hasHeightForWidth());
        toolButton->setSizePolicy(sizePolicy3);
        toolButton->setMinimumSize(QSize(0, 30));
        toolButton->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 0, 0);\n"
""));

        horizontalLayout->addWidget(toolButton);


        verticalLayout_6->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout_6, 3, 0, 1, 1);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName("verticalLayout_11");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pushButton_peak = new QPushButton(centralwidget);
        pushButton_peak->setObjectName("pushButton_peak");
        pushButton_peak->setMinimumSize(QSize(0, 25));
        pushButton_peak->setMaximumSize(QSize(16777215, 25));
        QFont font1;
        font1.setPointSize(10);
        pushButton_peak->setFont(font1);

        horizontalLayout_2->addWidget(pushButton_peak);

        pushButton_non = new QPushButton(centralwidget);
        pushButton_non->setObjectName("pushButton_non");
        pushButton_non->setMinimumSize(QSize(0, 25));
        pushButton_non->setMaximumSize(QSize(16777215, 25));
        pushButton_non->setFont(font1);

        horizontalLayout_2->addWidget(pushButton_non);


        verticalLayout_11->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        cancel = new QPushButton(centralwidget);
        cancel->setObjectName("cancel");
        cancel->setMinimumSize(QSize(100, 40));
        cancel->setMaximumSize(QSize(150, 40));
        cancel->setFont(font1);

        horizontalLayout_4->addWidget(cancel);


        verticalLayout_11->addLayout(horizontalLayout_4);


        gridLayout->addLayout(verticalLayout_11, 3, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 929, 17));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        toolBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\345\256\232\347\202\271\345\257\274\350\210\252\347\263\273\347\273\237", nullptr));
        inputx_2->setPlaceholderText(QCoreApplication::translate("MainWindow", "\347\254\254\344\270\200\344\270\252\347\202\271\346\240\207\345\217\267(1-10000)", nullptr));
        inputy_2->setPlaceholderText(QCoreApplication::translate("MainWindow", "\347\254\254\344\272\214\344\270\252\347\202\271\346\240\207\345\217\267(1-10000)", nullptr));
        coordinate_1->setPlaceholderText(QCoreApplication::translate("MainWindow", "\347\254\254\344\270\200\344\270\252\347\202\271\347\232\204\345\235\220\346\240\207", nullptr));
        coordinate_2->setPlaceholderText(QCoreApplication::translate("MainWindow", "\347\254\254\344\272\214\344\270\252\347\202\271\347\232\204\345\235\220\346\240\207", nullptr));
        nearest_res->setPlaceholderText(QCoreApplication::translate("MainWindow", "\346\234\200\350\277\221\347\232\204\351\244\220\351\246\206", nullptr));
        nearest_gas->setText(QString());
        nearest_gas->setPlaceholderText(QCoreApplication::translate("MainWindow", "\346\234\200\350\277\221\347\232\204\345\212\240\346\262\271\347\253\231", nullptr));
        toolButton_7->setText(QCoreApplication::translate("MainWindow", "\346\227\266\351\227\264\357\274\232", nullptr));
        toolButton_6->setText(QCoreApplication::translate("MainWindow", "\350\267\235\347\246\273\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\346\211\200\347\273\217\350\277\207\347\232\204\347\202\271", nullptr));
        shortpt->setText(QCoreApplication::translate("MainWindow", "\350\267\235\347\246\273\346\234\200\347\237\255\350\267\257", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\346\227\266\351\227\264\346\234\200\347\237\255\350\267\257", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_3), QCoreApplication::translate("MainWindow", "\345\234\260\347\202\271\345\256\232\347\202\271\345\257\274\350\210\252", nullptr));
        inputx->setPlaceholderText(QCoreApplication::translate("MainWindow", "x\345\235\220\346\240\207(0-32767)", nullptr));
        inputy->setPlaceholderText(QCoreApplication::translate("MainWindow", "y\345\235\220\346\240\207(0-32767)", nullptr));
        nearpt->setText(QCoreApplication::translate("MainWindow", "\346\234\200\350\277\221100\344\270\252\347\202\271(\345\217\263\351\224\256\345\217\214\345\207\273)", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\346\234\200\350\277\221100\344\270\252\347\202\271\346\240\207\345\217\267", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_4), QCoreApplication::translate("MainWindow", "\345\257\273\346\211\276\351\231\204\350\277\221100\344\270\252\347\202\271", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\351\201\223\350\267\257\347\212\266\345\206\265", nullptr));
        toolButton_2->setText(QCoreApplication::translate("MainWindow", "<50%", nullptr));
        toolButton_3->setText(QCoreApplication::translate("MainWindow", "50%-80%", nullptr));
        toolButton_4->setText(QCoreApplication::translate("MainWindow", "80%-100%", nullptr));
        toolButton_5->setText(QCoreApplication::translate("MainWindow", "100%-150%", nullptr));
        toolButton->setText(QCoreApplication::translate("MainWindow", ">150%", nullptr));
        pushButton_peak->setText(QCoreApplication::translate("MainWindow", "Peak", nullptr));
        pushButton_non->setText(QCoreApplication::translate("MainWindow", "Non-Peak", nullptr));
        cancel->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
