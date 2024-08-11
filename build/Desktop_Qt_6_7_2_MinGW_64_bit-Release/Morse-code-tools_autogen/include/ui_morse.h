/********************************************************************************
** Form generated from reading UI file 'morse.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MORSE_H
#define UI_MORSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_morse
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTextEdit *textEdit;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QLabel *label_4;

    void setupUi(QWidget *morse)
    {
        if (morse->objectName().isEmpty())
            morse->setObjectName("morse");
        morse->resize(800, 600);
        layoutWidget = new QWidget(morse);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(80, 60, 664, 481));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft YaHei UI")});
        font.setPointSize(14);
        label->setFont(font);

        verticalLayout->addWidget(label);

        textEdit = new QTextEdit(layoutWidget);
        textEdit->setObjectName("textEdit");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI")});
        font1.setPointSize(14);
        textEdit->setFont(font1);

        verticalLayout->addWidget(textEdit);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName("lineEdit");

        verticalLayout->addWidget(lineEdit);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        verticalLayout->addWidget(label_3);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName("lineEdit_2");

        verticalLayout->addWidget(lineEdit_2);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setFont(font);

        verticalLayout->addWidget(pushButton);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Microsoft YaHei UI")});
        font2.setPointSize(8);
        label_4->setFont(font2);

        verticalLayout->addWidget(label_4);


        retranslateUi(morse);

        QMetaObject::connectSlotsByName(morse);
    } // setupUi

    void retranslateUi(QWidget *morse)
    {
        morse->setWindowTitle(QCoreApplication::translate("morse", "morse", nullptr));
        label->setText(QCoreApplication::translate("morse", "\350\257\267\350\276\223\345\205\245\346\226\207\345\255\227\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("morse", "\351\200\237\345\272\246\357\274\210WPM\357\274\211\357\274\232", nullptr));
        lineEdit->setText(QCoreApplication::translate("morse", "20", nullptr));
        label_3->setText(QCoreApplication::translate("morse", "\351\237\263\350\260\203\357\274\210Hz\357\274\211\357\274\232", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("morse", "600", nullptr));
        pushButton->setText(QCoreApplication::translate("morse", "\347\241\256\345\256\232", nullptr));
        label_4->setText(QCoreApplication::translate("morse", "Version 1.1 By lijiaxuan 2024.08.11 https://www.yuanshen.dev/ https://github.com/lijiaxuan1811/Morse-Code-Tools", nullptr));
    } // retranslateUi

};

namespace Ui {
    class morse: public Ui_morse {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MORSE_H
