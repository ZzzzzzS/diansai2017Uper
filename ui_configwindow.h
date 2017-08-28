/********************************************************************************
** Form generated from reading UI file 'configwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGWINDOW_H
#define UI_CONFIGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ConfigWindow
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QComboBox *COMBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *SpeedBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *DataBox;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QComboBox *ChackBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QComboBox *StopBox;
    QPushButton *PowerButton;
    QPushButton *SaveButton;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_8;
    QCheckBox *HEXBox;
    QCheckBox *CleanBox;
    QVBoxLayout *verticalLayout_5;
    QTextEdit *ReceiveAera;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *SendAera;
    QPushButton *SendButton;

    void setupUi(QDialog *ConfigWindow)
    {
        if (ConfigWindow->objectName().isEmpty())
            ConfigWindow->setObjectName(QStringLiteral("ConfigWindow"));
        ConfigWindow->resize(391, 603);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light"));
        font.setPointSize(14);
        ConfigWindow->setFont(font);
        gridLayout_3 = new QGridLayout(ConfigWindow);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        groupBox = new QGroupBox(ConfigWindow);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(0, 250));
        groupBox->setMaximumSize(QSize(16777215, 16777215));
        groupBox->setFont(font);
        groupBox->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(label_3);

        COMBox = new QComboBox(groupBox);
        COMBox->setObjectName(QStringLiteral("COMBox"));
        sizePolicy.setHeightForWidth(COMBox->sizePolicy().hasHeightForWidth());
        COMBox->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(COMBox);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label_2);

        SpeedBox = new QComboBox(groupBox);
        SpeedBox->setObjectName(QStringLiteral("SpeedBox"));
        sizePolicy.setHeightForWidth(SpeedBox->sizePolicy().hasHeightForWidth());
        SpeedBox->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(SpeedBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label);

        DataBox = new QComboBox(groupBox);
        DataBox->setObjectName(QStringLiteral("DataBox"));
        sizePolicy.setHeightForWidth(DataBox->sizePolicy().hasHeightForWidth());
        DataBox->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(DataBox);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_6->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(label_4);

        ChackBox = new QComboBox(groupBox);
        ChackBox->setObjectName(QStringLiteral("ChackBox"));
        sizePolicy.setHeightForWidth(ChackBox->sizePolicy().hasHeightForWidth());
        ChackBox->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(ChackBox);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(label_5);

        StopBox = new QComboBox(groupBox);
        StopBox->setObjectName(QStringLiteral("StopBox"));
        sizePolicy.setHeightForWidth(StopBox->sizePolicy().hasHeightForWidth());
        StopBox->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(StopBox);


        verticalLayout_2->addLayout(horizontalLayout_5);


        verticalLayout_3->addLayout(verticalLayout_2);

        PowerButton = new QPushButton(groupBox);
        PowerButton->setObjectName(QStringLiteral("PowerButton"));
        sizePolicy.setHeightForWidth(PowerButton->sizePolicy().hasHeightForWidth());
        PowerButton->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(PowerButton);


        horizontalLayout_6->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout_6);

        SaveButton = new QPushButton(groupBox);
        SaveButton->setObjectName(QStringLiteral("SaveButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(SaveButton->sizePolicy().hasHeightForWidth());
        SaveButton->setSizePolicy(sizePolicy1);

        verticalLayout_4->addWidget(SaveButton);


        gridLayout->addLayout(verticalLayout_4, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(ConfigWindow);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        groupBox_2->setMaximumSize(QSize(16777215, 1677215));
        groupBox_2->setFont(font);
        groupBox_2->setStyleSheet(QStringLiteral(""));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        HEXBox = new QCheckBox(groupBox_2);
        HEXBox->setObjectName(QStringLiteral("HEXBox"));
        sizePolicy1.setHeightForWidth(HEXBox->sizePolicy().hasHeightForWidth());
        HEXBox->setSizePolicy(sizePolicy1);
        HEXBox->setFont(font);
        HEXBox->setChecked(true);

        horizontalLayout_8->addWidget(HEXBox);

        CleanBox = new QCheckBox(groupBox_2);
        CleanBox->setObjectName(QStringLiteral("CleanBox"));
        sizePolicy1.setHeightForWidth(CleanBox->sizePolicy().hasHeightForWidth());
        CleanBox->setSizePolicy(sizePolicy1);
        CleanBox->setFont(font);
        CleanBox->setTabletTracking(false);
        CleanBox->setChecked(true);

        horizontalLayout_8->addWidget(CleanBox);


        verticalLayout_6->addLayout(horizontalLayout_8);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        ReceiveAera = new QTextEdit(groupBox_2);
        ReceiveAera->setObjectName(QStringLiteral("ReceiveAera"));
        sizePolicy.setHeightForWidth(ReceiveAera->sizePolicy().hasHeightForWidth());
        ReceiveAera->setSizePolicy(sizePolicy);
        ReceiveAera->setReadOnly(true);

        verticalLayout_5->addWidget(ReceiveAera);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        SendAera = new QLineEdit(groupBox_2);
        SendAera->setObjectName(QStringLiteral("SendAera"));
        sizePolicy.setHeightForWidth(SendAera->sizePolicy().hasHeightForWidth());
        SendAera->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(SendAera);

        SendButton = new QPushButton(groupBox_2);
        SendButton->setObjectName(QStringLiteral("SendButton"));
        sizePolicy.setHeightForWidth(SendButton->sizePolicy().hasHeightForWidth());
        SendButton->setSizePolicy(sizePolicy);
        SendButton->setFont(font);

        horizontalLayout_7->addWidget(SendButton);


        verticalLayout_5->addLayout(horizontalLayout_7);


        verticalLayout_6->addLayout(verticalLayout_5);


        gridLayout_2->addLayout(verticalLayout_6, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 1, 0, 1, 1);


        retranslateUi(ConfigWindow);

        SaveButton->setDefault(true);
        SendButton->setDefault(true);


        QMetaObject::connectSlotsByName(ConfigWindow);
    } // setupUi

    void retranslateUi(QDialog *ConfigWindow)
    {
        ConfigWindow->setWindowTitle(QApplication::translate("ConfigWindow", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("ConfigWindow", "\351\205\215\347\275\256", Q_NULLPTR));
        label_3->setText(QApplication::translate("ConfigWindow", "\347\253\257\345\217\243   ", Q_NULLPTR));
        label_2->setText(QApplication::translate("ConfigWindow", "\346\263\242\347\211\271\347\216\207", Q_NULLPTR));
        SpeedBox->clear();
        SpeedBox->insertItems(0, QStringList()
         << QApplication::translate("ConfigWindow", "9600", Q_NULLPTR)
         << QApplication::translate("ConfigWindow", "19200", Q_NULLPTR)
         << QApplication::translate("ConfigWindow", "38400", Q_NULLPTR)
         << QApplication::translate("ConfigWindow", "57600", Q_NULLPTR)
         << QApplication::translate("ConfigWindow", "115200", Q_NULLPTR)
        );
        label->setText(QApplication::translate("ConfigWindow", "\346\225\260\346\215\256\344\275\215", Q_NULLPTR));
        DataBox->clear();
        DataBox->insertItems(0, QStringList()
         << QApplication::translate("ConfigWindow", "8", Q_NULLPTR)
         << QApplication::translate("ConfigWindow", "7", Q_NULLPTR)
         << QApplication::translate("ConfigWindow", "6", Q_NULLPTR)
         << QApplication::translate("ConfigWindow", "5", Q_NULLPTR)
        );
        label_4->setText(QApplication::translate("ConfigWindow", "\346\240\241\351\252\214\344\275\215", Q_NULLPTR));
        ChackBox->clear();
        ChackBox->insertItems(0, QStringList()
         << QApplication::translate("ConfigWindow", "\346\227\240", Q_NULLPTR)
         << QApplication::translate("ConfigWindow", "\345\245\207\346\225\210\351\252\214", Q_NULLPTR)
         << QApplication::translate("ConfigWindow", "\345\201\266\346\225\210\351\252\214", Q_NULLPTR)
        );
        label_5->setText(QApplication::translate("ConfigWindow", "\345\201\234\346\255\242\344\275\215", Q_NULLPTR));
        StopBox->clear();
        StopBox->insertItems(0, QStringList()
         << QApplication::translate("ConfigWindow", "1", Q_NULLPTR)
         << QApplication::translate("ConfigWindow", "2", Q_NULLPTR)
        );
        PowerButton->setText(QApplication::translate("ConfigWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", Q_NULLPTR));
        SaveButton->setText(QApplication::translate("ConfigWindow", "\344\277\235\345\255\230\350\256\276\347\275\256", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("ConfigWindow", "\345\205\274\345\256\271\346\200\247\346\265\213\350\257\225", Q_NULLPTR));
        HEXBox->setText(QApplication::translate("ConfigWindow", "HEX\346\230\276\347\244\272", Q_NULLPTR));
        CleanBox->setText(QApplication::translate("ConfigWindow", "\350\207\252\345\212\250\346\270\205\351\231\244\345\217\221\351\200\201\345\214\272", Q_NULLPTR));
        ReceiveAera->setHtml(QApplication::translate("ConfigWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
        SendButton->setText(QApplication::translate("ConfigWindow", "\345\217\221\351\200\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ConfigWindow: public Ui_ConfigWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGWINDOW_H
