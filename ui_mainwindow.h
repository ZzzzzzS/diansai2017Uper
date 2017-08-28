/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_4;
    QTabWidget *tabWidget;
    QWidget *DirectionTab;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *LeftButton;
    QVBoxLayout *verticalLayout;
    QPushButton *UpButton;
    QPushButton *DownButton;
    QPushButton *RightButton;
    QWidget *AimTab;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *Button1;
    QPushButton *Button2;
    QPushButton *Button3;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *Button4;
    QPushButton *Button5;
    QPushButton *Button6;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *Button7;
    QPushButton *Button8;
    QPushButton *Button9;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *DebugButton;
    QPushButton *PowerButton;
    QPushButton *ConfigButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(425, 589);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light"));
        font.setPointSize(18);
        MainWindow->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_5 = new QGridLayout(centralWidget);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        gridLayout_4 = new QGridLayout(groupBox);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        tabWidget = new QTabWidget(groupBox);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        DirectionTab = new QWidget();
        DirectionTab->setObjectName(QStringLiteral("DirectionTab"));
        gridLayout_2 = new QGridLayout(DirectionTab);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        LeftButton = new QPushButton(DirectionTab);
        LeftButton->setObjectName(QStringLiteral("LeftButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Ignored);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(LeftButton->sizePolicy().hasHeightForWidth());
        LeftButton->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(LeftButton);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        UpButton = new QPushButton(DirectionTab);
        UpButton->setObjectName(QStringLiteral("UpButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(UpButton->sizePolicy().hasHeightForWidth());
        UpButton->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(UpButton);

        DownButton = new QPushButton(DirectionTab);
        DownButton->setObjectName(QStringLiteral("DownButton"));
        sizePolicy2.setHeightForWidth(DownButton->sizePolicy().hasHeightForWidth());
        DownButton->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(DownButton);


        horizontalLayout_2->addLayout(verticalLayout);

        RightButton = new QPushButton(DirectionTab);
        RightButton->setObjectName(QStringLiteral("RightButton"));
        sizePolicy1.setHeightForWidth(RightButton->sizePolicy().hasHeightForWidth());
        RightButton->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(RightButton);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        tabWidget->addTab(DirectionTab, QString());
        AimTab = new QWidget();
        AimTab->setObjectName(QStringLiteral("AimTab"));
        gridLayout_3 = new QGridLayout(AimTab);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        Button1 = new QPushButton(AimTab);
        Button1->setObjectName(QStringLiteral("Button1"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(Button1->sizePolicy().hasHeightForWidth());
        Button1->setSizePolicy(sizePolicy3);

        horizontalLayout_3->addWidget(Button1);

        Button2 = new QPushButton(AimTab);
        Button2->setObjectName(QStringLiteral("Button2"));
        sizePolicy3.setHeightForWidth(Button2->sizePolicy().hasHeightForWidth());
        Button2->setSizePolicy(sizePolicy3);

        horizontalLayout_3->addWidget(Button2);

        Button3 = new QPushButton(AimTab);
        Button3->setObjectName(QStringLiteral("Button3"));
        sizePolicy3.setHeightForWidth(Button3->sizePolicy().hasHeightForWidth());
        Button3->setSizePolicy(sizePolicy3);

        horizontalLayout_3->addWidget(Button3);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        Button4 = new QPushButton(AimTab);
        Button4->setObjectName(QStringLiteral("Button4"));
        sizePolicy3.setHeightForWidth(Button4->sizePolicy().hasHeightForWidth());
        Button4->setSizePolicy(sizePolicy3);

        horizontalLayout_4->addWidget(Button4);

        Button5 = new QPushButton(AimTab);
        Button5->setObjectName(QStringLiteral("Button5"));
        sizePolicy3.setHeightForWidth(Button5->sizePolicy().hasHeightForWidth());
        Button5->setSizePolicy(sizePolicy3);

        horizontalLayout_4->addWidget(Button5);

        Button6 = new QPushButton(AimTab);
        Button6->setObjectName(QStringLiteral("Button6"));
        sizePolicy3.setHeightForWidth(Button6->sizePolicy().hasHeightForWidth());
        Button6->setSizePolicy(sizePolicy3);

        horizontalLayout_4->addWidget(Button6);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        Button7 = new QPushButton(AimTab);
        Button7->setObjectName(QStringLiteral("Button7"));
        sizePolicy3.setHeightForWidth(Button7->sizePolicy().hasHeightForWidth());
        Button7->setSizePolicy(sizePolicy3);

        horizontalLayout_5->addWidget(Button7);

        Button8 = new QPushButton(AimTab);
        Button8->setObjectName(QStringLiteral("Button8"));
        sizePolicy3.setHeightForWidth(Button8->sizePolicy().hasHeightForWidth());
        Button8->setSizePolicy(sizePolicy3);

        horizontalLayout_5->addWidget(Button8);

        Button9 = new QPushButton(AimTab);
        Button9->setObjectName(QStringLiteral("Button9"));
        sizePolicy3.setHeightForWidth(Button9->sizePolicy().hasHeightForWidth());
        Button9->setSizePolicy(sizePolicy3);

        horizontalLayout_5->addWidget(Button9);


        verticalLayout_2->addLayout(horizontalLayout_5);


        gridLayout_3->addLayout(verticalLayout_2, 0, 0, 1, 1);

        tabWidget->addTab(AimTab, QString());

        gridLayout_4->addWidget(tabWidget, 0, 0, 1, 1);


        gridLayout_5->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy4);
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        DebugButton = new QPushButton(groupBox_2);
        DebugButton->setObjectName(QStringLiteral("DebugButton"));

        horizontalLayout->addWidget(DebugButton);

        PowerButton = new QPushButton(groupBox_2);
        PowerButton->setObjectName(QStringLiteral("PowerButton"));

        horizontalLayout->addWidget(PowerButton);

        ConfigButton = new QPushButton(groupBox_2);
        ConfigButton->setObjectName(QStringLiteral("ConfigButton"));

        horizontalLayout->addWidget(ConfigButton);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        gridLayout_5->addWidget(groupBox_2, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "\346\216\247\345\210\266", Q_NULLPTR));
        LeftButton->setText(QApplication::translate("MainWindow", "\343\200\212", Q_NULLPTR));
        UpButton->setText(QApplication::translate("MainWindow", "\357\270\275", Q_NULLPTR));
        DownButton->setText(QApplication::translate("MainWindow", "\357\270\276", Q_NULLPTR));
        RightButton->setText(QApplication::translate("MainWindow", "\343\200\213", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(DirectionTab), QApplication::translate("MainWindow", "\346\226\271\345\220\221\346\216\247\345\210\266", Q_NULLPTR));
        Button1->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        Button2->setText(QApplication::translate("MainWindow", "2", Q_NULLPTR));
        Button3->setText(QApplication::translate("MainWindow", "3", Q_NULLPTR));
        Button4->setText(QApplication::translate("MainWindow", "4", Q_NULLPTR));
        Button5->setText(QApplication::translate("MainWindow", "5", Q_NULLPTR));
        Button6->setText(QApplication::translate("MainWindow", "6", Q_NULLPTR));
        Button7->setText(QApplication::translate("MainWindow", "7", Q_NULLPTR));
        Button8->setText(QApplication::translate("MainWindow", "8", Q_NULLPTR));
        Button9->setText(QApplication::translate("MainWindow", "9", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(AimTab), QApplication::translate("MainWindow", "\347\233\256\346\240\207\347\202\271\346\216\247\345\210\266", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\351\205\215\347\275\256", Q_NULLPTR));
        DebugButton->setText(QApplication::translate("MainWindow", "\345\217\202\346\225\260\350\260\203\350\257\225", Q_NULLPTR));
        PowerButton->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", Q_NULLPTR));
        ConfigButton->setText(QApplication::translate("MainWindow", "\344\270\262\345\217\243\350\256\276\347\275\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
