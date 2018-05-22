/********************************************************************************
** Form generated from reading UI file 'busca.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUSCA_H
#define UI_BUSCA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_busca
{
public:
    QPushButton *pb_cancelar;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QDateEdit *dateEdit;
    QLabel *label_4;
    QComboBox *comboBox;
    QLabel *label_5;
    QComboBox *comboBox_2;
    QLabel *label_6;
    QComboBox *comboBox_3;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *busca)
    {
        if (busca->objectName().isEmpty())
            busca->setObjectName(QStringLiteral("busca"));
        busca->setWindowModality(Qt::ApplicationModal);
        busca->resize(440, 287);
        QFont font;
        font.setPointSize(12);
        busca->setFont(font);
        pb_cancelar = new QPushButton(busca);
        pb_cancelar->setObjectName(QStringLiteral("pb_cancelar"));
        pb_cancelar->setGeometry(QRect(350, 250, 75, 23));
        QFont font1;
        font1.setPointSize(8);
        pb_cancelar->setFont(font1);
        label = new QLabel(busca);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 10, 321, 16));
        label->setFont(font1);
        label_2 = new QLabel(busca);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 50, 131, 16));
        label_2->setFont(font1);
        lineEdit = new QLineEdit(busca);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(110, 50, 61, 20));
        label_3 = new QLabel(busca);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(270, 53, 47, 13));
        label_3->setFont(font1);
        dateEdit = new QDateEdit(busca);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(310, 50, 110, 22));
        dateEdit->setFont(font1);
        label_4 = new QLabel(busca);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 92, 47, 13));
        label_4->setFont(font1);
        comboBox = new QComboBox(busca);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(50, 90, 371, 22));
        comboBox->setFont(font1);
        label_5 = new QLabel(busca);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 130, 131, 16));
        label_5->setFont(font1);
        comboBox_2 = new QComboBox(busca);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(110, 130, 311, 22));
        comboBox_2->setFont(font1);
        label_6 = new QLabel(busca);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 170, 141, 16));
        label_6->setFont(font1);
        comboBox_3 = new QComboBox(busca);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setGeometry(QRect(120, 170, 301, 22));
        comboBox_3->setFont(font1);
        checkBox = new QCheckBox(busca);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(330, 211, 101, 17));
        checkBox->setFont(font1);
        checkBox_2 = new QCheckBox(busca);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(90, 210, 111, 17));
        checkBox_2->setFont(font1);
        checkBox_3 = new QCheckBox(busca);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setGeometry(QRect(210, 210, 101, 17));
        checkBox_3->setFont(font1);
        pushButton_2 = new QPushButton(busca);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(100, 250, 75, 23));
        pushButton_2->setFont(font1);
        pushButton_3 = new QPushButton(busca);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(203, 250, 121, 23));
        pushButton_3->setFont(font1);

        retranslateUi(busca);

        QMetaObject::connectSlotsByName(busca);
    } // setupUi

    void retranslateUi(QWidget *busca)
    {
        busca->setWindowTitle(QApplication::translate("busca", "Buscar Of\303\255cio", 0));
        pb_cancelar->setText(QApplication::translate("busca", "Cancelar", 0));
        label->setText(QApplication::translate("busca", " Preencha uma ou mais op\303\247\303\265es de busca:", 0));
        label_2->setText(QApplication::translate("busca", "C\303\263digo do of\303\255cio:", 0));
        label_3->setText(QApplication::translate("busca", "Data:", 0));
        label_4->setText(QApplication::translate("busca", "Tipo:", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("busca", "Alvar\303\241", 0)
         << QApplication::translate("busca", "Comunica\303\247\303\243o", 0)
         << QApplication::translate("busca", "Jur\303\255dico", 0)
         << QApplication::translate("busca", "Patrim\303\264nio", 0)
         << QApplication::translate("busca", "Precat\303\263rio", 0)
         << QApplication::translate("busca", "Requerimento", 0)
         << QApplication::translate("busca", "Rogat\303\263ria", 0)
         << QApplication::translate("busca", "Outros", 0)
        );
        label_5->setText(QApplication::translate("busca", "Setor remetente:", 0));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("busca", "ACESC", 0)
         << QApplication::translate("busca", "Ag\303\252ncia do Trabalhador", 0)
         << QApplication::translate("busca", "Departamento de Recursos Humanos", 0)
         << QApplication::translate("busca", "Divis\303\243o de Desenvolvimento de Pessoal", 0)
         << QApplication::translate("busca", "Divis\303\243o de Folha, Registro e Cadastro", 0)
         << QApplication::translate("busca", "Divis\303\243o de Medicina e Seguran\303\247a do Trabalho", 0)
         << QApplication::translate("busca", "FUNDETEC", 0)
         << QApplication::translate("busca", "Guarda Patrimonial", 0)
         << QApplication::translate("busca", "Secretaria de A\303\247\303\243o Comunit\303\241ria", 0)
         << QApplication::translate("busca", "Secretaria de Administra\303\247\303\243o", 0)
         << QApplication::translate("busca", "Secretaria de Agricultura", 0)
         << QApplication::translate("busca", "Secretaria de Assist\303\252ncia Social", 0)
         << QApplication::translate("busca", "Secretaria de Assuntos Jur\303\255dicos", 0)
         << QApplication::translate("busca", "Secretaria de Cultura", 0)
         << QApplication::translate("busca", "Secretaria de Desenvolvimento Econ\303\264mico", 0)
         << QApplication::translate("busca", "Secretaria de Educa\303\247\303\243o", 0)
         << QApplication::translate("busca", "Secretaria de Esporte e Lazer", 0)
         << QApplication::translate("busca", "Secretaria de Finan\303\247as", 0)
         << QApplication::translate("busca", "Secretaria de Governo", 0)
         << QApplication::translate("busca", "Secretaria de Obras P\303\272blicas", 0)
         << QApplication::translate("busca", "Secretaria de Planejamento", 0)
         << QApplication::translate("busca", "Secretaria de Sa\303\272de", 0)
         << QApplication::translate("busca", "Secretaria do Meio Ambiente", 0)
        );
        label_6->setText(QApplication::translate("busca", "Setor destinat\303\241rio:", 0));
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("busca", "ACESC", 0)
         << QApplication::translate("busca", "Ag\303\252ncia do Trabalhador", 0)
         << QApplication::translate("busca", "Departamento de Recursos Humanos", 0)
         << QApplication::translate("busca", "Divis\303\243o de Desenvolvimento de Pessoal", 0)
         << QApplication::translate("busca", "Divis\303\243o de Folha, Registro e Cadastro", 0)
         << QApplication::translate("busca", "Divis\303\243o de Medicina e Seguran\303\247a do Trabalho", 0)
         << QApplication::translate("busca", "FUNDETEC", 0)
         << QApplication::translate("busca", "Guarda Patrimonial", 0)
         << QApplication::translate("busca", "Secretaria de A\303\247\303\243o Comunit\303\241ria", 0)
         << QApplication::translate("busca", "Secretaria de Administra\303\247\303\243o", 0)
         << QApplication::translate("busca", "Secretaria de Agricultura", 0)
         << QApplication::translate("busca", "Secretaria de Assist\303\252ncia Social", 0)
         << QApplication::translate("busca", "Secretaria de Assuntos Jur\303\255dicos", 0)
         << QApplication::translate("busca", "Secretaria de Cultura", 0)
         << QApplication::translate("busca", "Secretaria de Desenvolvimento Econ\303\264mico", 0)
         << QApplication::translate("busca", "Secretaria de Educa\303\247\303\243o", 0)
         << QApplication::translate("busca", "Secretaria de Esporte e Lazer", 0)
         << QApplication::translate("busca", "Secretaria de Finan\303\247as", 0)
         << QApplication::translate("busca", "Secretaria de Governo", 0)
         << QApplication::translate("busca", "Secretaria de Obras P\303\272blicas", 0)
         << QApplication::translate("busca", "Secretaria de Planejamento", 0)
         << QApplication::translate("busca", "Secretaria de Sa\303\272de", 0)
         << QApplication::translate("busca", "Secretaria do Meio Ambiente", 0)
        );
        checkBox->setText(QApplication::translate("busca", "Of\303\255cio resposta.", 0));
        checkBox_2->setText(QApplication::translate("busca", "Of\303\255cio pendente.", 0));
        checkBox_3->setText(QApplication::translate("busca", "Of\303\255cio conclu\303\255do.", 0));
        pushButton_2->setText(QApplication::translate("busca", "Buscar", 0));
        pushButton_3->setText(QApplication::translate("busca", "Limpar campos", 0));
    } // retranslateUi

};

namespace Ui {
    class busca: public Ui_busca {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUSCA_H
