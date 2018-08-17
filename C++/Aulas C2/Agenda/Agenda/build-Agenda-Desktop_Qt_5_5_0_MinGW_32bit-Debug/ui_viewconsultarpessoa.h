/********************************************************************************
** Form generated from reading UI file 'viewconsultarpessoa.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWCONSULTARPESSOA_H
#define UI_VIEWCONSULTARPESSOA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ViewConsultarPessoa
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLabel *label_4;
    QDateEdit *dateEdit;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton;
    QVBoxLayout *verticalLayout;

    void setupUi(QWidget *ViewConsultarPessoa)
    {
        if (ViewConsultarPessoa->objectName().isEmpty())
            ViewConsultarPessoa->setObjectName(QStringLiteral("ViewConsultarPessoa"));
        ViewConsultarPessoa->resize(872, 565);
        horizontalLayoutWidget = new QWidget(ViewConsultarPessoa);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 20, 491, 221));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEdit = new QLineEdit(horizontalLayoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);

        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        lineEdit_2 = new QLineEdit(horizontalLayoutWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_2);

        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(horizontalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        dateEdit = new QDateEdit(horizontalLayoutWidget);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, dateEdit);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        radioButton_2 = new QRadioButton(horizontalLayoutWidget);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        horizontalLayout_2->addWidget(radioButton_2);

        radioButton = new QRadioButton(horizontalLayoutWidget);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        horizontalLayout_2->addWidget(radioButton);


        formLayout->setLayout(4, QFormLayout::FieldRole, horizontalLayout_2);


        horizontalLayout->addLayout(formLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));

        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(ViewConsultarPessoa);

        QMetaObject::connectSlotsByName(ViewConsultarPessoa);
    } // setupUi

    void retranslateUi(QWidget *ViewConsultarPessoa)
    {
        ViewConsultarPessoa->setWindowTitle(QApplication::translate("ViewConsultarPessoa", "Form", 0));
        label->setText(QApplication::translate("ViewConsultarPessoa", "Nome:", 0));
        label_2->setText(QApplication::translate("ViewConsultarPessoa", "CPF:", 0));
        label_3->setText(QApplication::translate("ViewConsultarPessoa", "Data de nascimento:", 0));
        label_4->setText(QApplication::translate("ViewConsultarPessoa", "Sexo:", 0));
        radioButton_2->setText(QApplication::translate("ViewConsultarPessoa", "Masculino", 0));
        radioButton->setText(QApplication::translate("ViewConsultarPessoa", "Feminino", 0));
    } // retranslateUi

};

namespace Ui {
    class ViewConsultarPessoa: public Ui_ViewConsultarPessoa {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWCONSULTARPESSOA_H
