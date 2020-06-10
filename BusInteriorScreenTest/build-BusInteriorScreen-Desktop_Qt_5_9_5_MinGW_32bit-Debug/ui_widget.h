/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *widgetSerial;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacerSerial3;
    QLabel *labelSerialName;
    QSpacerItem *horizontalSpacerSerial5;
    QComboBox *comboBoxSerialCom;
    QSpacerItem *horizontalSpacerSerial1;
    QComboBox *comboBoxSerialBaundRate;
    QSpacerItem *horizontalSpacerSerial2;
    QPushButton *pushButtonSerialSwitch;
    QSpacerItem *horizontalSpacerSerial4;
    QPushButton *pushButtonSerialSend;
    QSpacerItem *horizontalSpacerSerial6;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBoxBusInteriorDevice;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButtonFrontScreen;
    QRadioButton *radioButtonBackScreen;
    QRadioButton *radioButtonFrontRoad;
    QRadioButton *radioButtonSideRoad;
    QRadioButton *radioButtonBackRoad;
    QRadioButton *radioButtonFrontSection;
    QRadioButton *radioButtonBackSection;
    QRadioButton *radioButtonStopAnnouncer;
    QGroupBox *groupBoxFrontScreen;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radioButtonFrontScreenSelfCheck;
    QRadioButton *radioButtonFrontScreenSetTime;
    QRadioButton *radioButtonFrontScreenSetStopName;
    QRadioButton *radioButtonFrontScreenSetFirstLast;
    QRadioButton *radioButtonFrontScreenSetPropagandaLanguage;
    QRadioButton *radioButtonFrontScreenPlayStopName;
    QRadioButton *radioButtonFrontScreenPlayNumProLanguage;
    QRadioButton *radioButtonFrontScreenPlayItemProLanguage;
    QGroupBox *groupBoxBackScreen;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *radioButtonBackScreenSelfCheck;
    QRadioButton *radioButtonBackScreenSetTime;
    QRadioButton *radioButtonBackScreenSetStopName;
    QRadioButton *radioButtonBackScreenSetFirstLast;
    QRadioButton *radioButtonBackScreenSetPropagandaLanguage;
    QRadioButton *radioButtonBackScreenPlayStopName;
    QRadioButton *radioButtonBackScreenPlayNumProLanguage;
    QRadioButton *radioButtonBackScreenPlayItemProLanguage;
    QTextEdit *textEditTxRxDataDisplay;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(657, 470);
        widgetSerial = new QWidget(Widget);
        widgetSerial->setObjectName(QStringLiteral("widgetSerial"));
        widgetSerial->setGeometry(QRect(10, 10, 421, 41));
        horizontalLayout = new QHBoxLayout(widgetSerial);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacerSerial3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacerSerial3);

        labelSerialName = new QLabel(widgetSerial);
        labelSerialName->setObjectName(QStringLiteral("labelSerialName"));

        horizontalLayout->addWidget(labelSerialName);

        horizontalSpacerSerial5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacerSerial5);

        comboBoxSerialCom = new QComboBox(widgetSerial);
        comboBoxSerialCom->setObjectName(QStringLiteral("comboBoxSerialCom"));

        horizontalLayout->addWidget(comboBoxSerialCom);

        horizontalSpacerSerial1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacerSerial1);

        comboBoxSerialBaundRate = new QComboBox(widgetSerial);
        comboBoxSerialBaundRate->setObjectName(QStringLiteral("comboBoxSerialBaundRate"));

        horizontalLayout->addWidget(comboBoxSerialBaundRate);

        horizontalSpacerSerial2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacerSerial2);

        pushButtonSerialSwitch = new QPushButton(widgetSerial);
        pushButtonSerialSwitch->setObjectName(QStringLiteral("pushButtonSerialSwitch"));

        horizontalLayout->addWidget(pushButtonSerialSwitch);

        horizontalSpacerSerial4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacerSerial4);

        pushButtonSerialSend = new QPushButton(widgetSerial);
        pushButtonSerialSend->setObjectName(QStringLiteral("pushButtonSerialSend"));

        horizontalLayout->addWidget(pushButtonSerialSend);

        horizontalSpacerSerial6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacerSerial6);

        widget = new QWidget(Widget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 60, 291, 211));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        groupBoxBusInteriorDevice = new QGroupBox(widget);
        groupBoxBusInteriorDevice->setObjectName(QStringLiteral("groupBoxBusInteriorDevice"));
        verticalLayout = new QVBoxLayout(groupBoxBusInteriorDevice);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        radioButtonFrontScreen = new QRadioButton(groupBoxBusInteriorDevice);
        radioButtonFrontScreen->setObjectName(QStringLiteral("radioButtonFrontScreen"));

        verticalLayout->addWidget(radioButtonFrontScreen);

        radioButtonBackScreen = new QRadioButton(groupBoxBusInteriorDevice);
        radioButtonBackScreen->setObjectName(QStringLiteral("radioButtonBackScreen"));

        verticalLayout->addWidget(radioButtonBackScreen);

        radioButtonFrontRoad = new QRadioButton(groupBoxBusInteriorDevice);
        radioButtonFrontRoad->setObjectName(QStringLiteral("radioButtonFrontRoad"));

        verticalLayout->addWidget(radioButtonFrontRoad);

        radioButtonSideRoad = new QRadioButton(groupBoxBusInteriorDevice);
        radioButtonSideRoad->setObjectName(QStringLiteral("radioButtonSideRoad"));

        verticalLayout->addWidget(radioButtonSideRoad);

        radioButtonBackRoad = new QRadioButton(groupBoxBusInteriorDevice);
        radioButtonBackRoad->setObjectName(QStringLiteral("radioButtonBackRoad"));

        verticalLayout->addWidget(radioButtonBackRoad);

        radioButtonFrontSection = new QRadioButton(groupBoxBusInteriorDevice);
        radioButtonFrontSection->setObjectName(QStringLiteral("radioButtonFrontSection"));

        verticalLayout->addWidget(radioButtonFrontSection);

        radioButtonBackSection = new QRadioButton(groupBoxBusInteriorDevice);
        radioButtonBackSection->setObjectName(QStringLiteral("radioButtonBackSection"));

        verticalLayout->addWidget(radioButtonBackSection);

        radioButtonStopAnnouncer = new QRadioButton(groupBoxBusInteriorDevice);
        radioButtonStopAnnouncer->setObjectName(QStringLiteral("radioButtonStopAnnouncer"));

        verticalLayout->addWidget(radioButtonStopAnnouncer);


        horizontalLayout_2->addWidget(groupBoxBusInteriorDevice);

        groupBoxFrontScreen = new QGroupBox(widget);
        groupBoxFrontScreen->setObjectName(QStringLiteral("groupBoxFrontScreen"));
        verticalLayout_2 = new QVBoxLayout(groupBoxFrontScreen);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        radioButtonFrontScreenSelfCheck = new QRadioButton(groupBoxFrontScreen);
        radioButtonFrontScreenSelfCheck->setObjectName(QStringLiteral("radioButtonFrontScreenSelfCheck"));

        verticalLayout_2->addWidget(radioButtonFrontScreenSelfCheck);

        radioButtonFrontScreenSetTime = new QRadioButton(groupBoxFrontScreen);
        radioButtonFrontScreenSetTime->setObjectName(QStringLiteral("radioButtonFrontScreenSetTime"));

        verticalLayout_2->addWidget(radioButtonFrontScreenSetTime);

        radioButtonFrontScreenSetStopName = new QRadioButton(groupBoxFrontScreen);
        radioButtonFrontScreenSetStopName->setObjectName(QStringLiteral("radioButtonFrontScreenSetStopName"));

        verticalLayout_2->addWidget(radioButtonFrontScreenSetStopName);

        radioButtonFrontScreenSetFirstLast = new QRadioButton(groupBoxFrontScreen);
        radioButtonFrontScreenSetFirstLast->setObjectName(QStringLiteral("radioButtonFrontScreenSetFirstLast"));

        verticalLayout_2->addWidget(radioButtonFrontScreenSetFirstLast);

        radioButtonFrontScreenSetPropagandaLanguage = new QRadioButton(groupBoxFrontScreen);
        radioButtonFrontScreenSetPropagandaLanguage->setObjectName(QStringLiteral("radioButtonFrontScreenSetPropagandaLanguage"));

        verticalLayout_2->addWidget(radioButtonFrontScreenSetPropagandaLanguage);

        radioButtonFrontScreenPlayStopName = new QRadioButton(groupBoxFrontScreen);
        radioButtonFrontScreenPlayStopName->setObjectName(QStringLiteral("radioButtonFrontScreenPlayStopName"));

        verticalLayout_2->addWidget(radioButtonFrontScreenPlayStopName);

        radioButtonFrontScreenPlayNumProLanguage = new QRadioButton(groupBoxFrontScreen);
        radioButtonFrontScreenPlayNumProLanguage->setObjectName(QStringLiteral("radioButtonFrontScreenPlayNumProLanguage"));

        verticalLayout_2->addWidget(radioButtonFrontScreenPlayNumProLanguage);

        radioButtonFrontScreenPlayItemProLanguage = new QRadioButton(groupBoxFrontScreen);
        radioButtonFrontScreenPlayItemProLanguage->setObjectName(QStringLiteral("radioButtonFrontScreenPlayItemProLanguage"));

        verticalLayout_2->addWidget(radioButtonFrontScreenPlayItemProLanguage);


        horizontalLayout_2->addWidget(groupBoxFrontScreen);

        groupBoxBackScreen = new QGroupBox(widget);
        groupBoxBackScreen->setObjectName(QStringLiteral("groupBoxBackScreen"));
        verticalLayout_3 = new QVBoxLayout(groupBoxBackScreen);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        radioButtonBackScreenSelfCheck = new QRadioButton(groupBoxBackScreen);
        radioButtonBackScreenSelfCheck->setObjectName(QStringLiteral("radioButtonBackScreenSelfCheck"));

        verticalLayout_3->addWidget(radioButtonBackScreenSelfCheck);

        radioButtonBackScreenSetTime = new QRadioButton(groupBoxBackScreen);
        radioButtonBackScreenSetTime->setObjectName(QStringLiteral("radioButtonBackScreenSetTime"));

        verticalLayout_3->addWidget(radioButtonBackScreenSetTime);

        radioButtonBackScreenSetStopName = new QRadioButton(groupBoxBackScreen);
        radioButtonBackScreenSetStopName->setObjectName(QStringLiteral("radioButtonBackScreenSetStopName"));

        verticalLayout_3->addWidget(radioButtonBackScreenSetStopName);

        radioButtonBackScreenSetFirstLast = new QRadioButton(groupBoxBackScreen);
        radioButtonBackScreenSetFirstLast->setObjectName(QStringLiteral("radioButtonBackScreenSetFirstLast"));

        verticalLayout_3->addWidget(radioButtonBackScreenSetFirstLast);

        radioButtonBackScreenSetPropagandaLanguage = new QRadioButton(groupBoxBackScreen);
        radioButtonBackScreenSetPropagandaLanguage->setObjectName(QStringLiteral("radioButtonBackScreenSetPropagandaLanguage"));

        verticalLayout_3->addWidget(radioButtonBackScreenSetPropagandaLanguage);

        radioButtonBackScreenPlayStopName = new QRadioButton(groupBoxBackScreen);
        radioButtonBackScreenPlayStopName->setObjectName(QStringLiteral("radioButtonBackScreenPlayStopName"));

        verticalLayout_3->addWidget(radioButtonBackScreenPlayStopName);

        radioButtonBackScreenPlayNumProLanguage = new QRadioButton(groupBoxBackScreen);
        radioButtonBackScreenPlayNumProLanguage->setObjectName(QStringLiteral("radioButtonBackScreenPlayNumProLanguage"));

        verticalLayout_3->addWidget(radioButtonBackScreenPlayNumProLanguage);

        radioButtonBackScreenPlayItemProLanguage = new QRadioButton(groupBoxBackScreen);
        radioButtonBackScreenPlayItemProLanguage->setObjectName(QStringLiteral("radioButtonBackScreenPlayItemProLanguage"));

        verticalLayout_3->addWidget(radioButtonBackScreenPlayItemProLanguage);


        horizontalLayout_2->addWidget(groupBoxBackScreen);

        textEditTxRxDataDisplay = new QTextEdit(Widget);
        textEditTxRxDataDisplay->setObjectName(QStringLiteral("textEditTxRxDataDisplay"));
        textEditTxRxDataDisplay->setGeometry(QRect(10, 280, 601, 181));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        labelSerialName->setText(QApplication::translate("Widget", "\344\270\262\345\217\243\345\220\215\345\255\227\357\274\232", Q_NULLPTR));
        pushButtonSerialSwitch->setText(QApplication::translate("Widget", "\346\211\223\345\274\200\344\270\262\345\217\243", Q_NULLPTR));
        pushButtonSerialSend->setText(QApplication::translate("Widget", "\345\217\221\351\200\201\346\225\260\346\215\256", Q_NULLPTR));
        groupBoxBusInteriorDevice->setTitle(QApplication::translate("Widget", "\350\275\246\345\206\205\350\256\276\345\244\207", Q_NULLPTR));
        radioButtonFrontScreen->setText(QApplication::translate("Widget", "\345\211\215\345\206\205\345\261\217", Q_NULLPTR));
        radioButtonBackScreen->setText(QApplication::translate("Widget", "\345\220\216\345\206\205\345\261\217", Q_NULLPTR));
        radioButtonFrontRoad->setText(QApplication::translate("Widget", "\345\211\215\350\267\257\347\211\214", Q_NULLPTR));
        radioButtonSideRoad->setText(QApplication::translate("Widget", "\344\276\247\350\267\257\347\211\214", Q_NULLPTR));
        radioButtonBackRoad->setText(QApplication::translate("Widget", "\345\220\216\350\267\257\347\211\214", Q_NULLPTR));
        radioButtonFrontSection->setText(QApplication::translate("Widget", "\345\211\215\347\253\231\350\212\202\347\211\214", Q_NULLPTR));
        radioButtonBackSection->setText(QApplication::translate("Widget", "\345\220\216\347\253\231\350\212\202\347\211\214", Q_NULLPTR));
        radioButtonStopAnnouncer->setText(QApplication::translate("Widget", "\346\212\245\347\253\231\345\231\250", Q_NULLPTR));
        groupBoxFrontScreen->setTitle(QApplication::translate("Widget", "\345\211\215\345\206\205\345\261\217\345\212\237\350\203\275", Q_NULLPTR));
        radioButtonFrontScreenSelfCheck->setText(QApplication::translate("Widget", "\350\207\252\346\243\200\345\212\237\350\203\275", Q_NULLPTR));
        radioButtonFrontScreenSetTime->setText(QApplication::translate("Widget", "\346\227\266\351\227\264\350\256\276\347\275\256", Q_NULLPTR));
        radioButtonFrontScreenSetStopName->setText(QApplication::translate("Widget", "\347\253\231\345\220\215\350\256\276\347\275\256", Q_NULLPTR));
        radioButtonFrontScreenSetFirstLast->setText(QApplication::translate("Widget", "\351\246\226\346\234\253\345\217\245\350\256\276\347\275\256", Q_NULLPTR));
        radioButtonFrontScreenSetPropagandaLanguage->setText(QApplication::translate("Widget", "\345\256\243\344\274\240\347\224\250\350\257\255\350\256\276\347\275\256", Q_NULLPTR));
        radioButtonFrontScreenPlayStopName->setText(QApplication::translate("Widget", "\347\253\231\345\220\215\346\222\255\346\224\276", Q_NULLPTR));
        radioButtonFrontScreenPlayNumProLanguage->setText(QApplication::translate("Widget", "\345\256\243\344\274\240\347\224\250\350\257\255\346\214\211\345\272\217\345\217\267\346\222\255\346\224\276", Q_NULLPTR));
        radioButtonFrontScreenPlayItemProLanguage->setText(QApplication::translate("Widget", "\345\256\243\344\274\240\347\224\250\350\257\255\346\214\211\345\206\205\345\256\271\346\222\255\346\224\276", Q_NULLPTR));
        groupBoxBackScreen->setTitle(QApplication::translate("Widget", "\345\220\216\345\206\205\345\261\217\345\212\237\350\203\275", Q_NULLPTR));
        radioButtonBackScreenSelfCheck->setText(QApplication::translate("Widget", "\350\207\252\346\243\200\345\212\237\350\203\275", Q_NULLPTR));
        radioButtonBackScreenSetTime->setText(QApplication::translate("Widget", "\346\227\266\351\227\264\350\256\276\347\275\256", Q_NULLPTR));
        radioButtonBackScreenSetStopName->setText(QApplication::translate("Widget", "\347\253\231\345\220\215\350\256\276\347\275\256", Q_NULLPTR));
        radioButtonBackScreenSetFirstLast->setText(QApplication::translate("Widget", "\351\246\226\346\234\253\345\217\245\350\256\276\347\275\256", Q_NULLPTR));
        radioButtonBackScreenSetPropagandaLanguage->setText(QApplication::translate("Widget", "\345\256\243\344\274\240\347\224\250\350\257\255\350\256\276\347\275\256", Q_NULLPTR));
        radioButtonBackScreenPlayStopName->setText(QApplication::translate("Widget", "\347\253\231\345\220\215\346\222\255\346\224\276", Q_NULLPTR));
        radioButtonBackScreenPlayNumProLanguage->setText(QApplication::translate("Widget", "\345\256\243\344\274\240\347\224\250\350\257\255\346\214\211\345\272\217\345\217\267\346\222\255\346\224\276", Q_NULLPTR));
        radioButtonBackScreenPlayItemProLanguage->setText(QApplication::translate("Widget", "\345\256\243\344\274\240\347\224\250\350\257\255\346\214\211\345\206\205\345\256\271\346\222\255\346\224\276", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
