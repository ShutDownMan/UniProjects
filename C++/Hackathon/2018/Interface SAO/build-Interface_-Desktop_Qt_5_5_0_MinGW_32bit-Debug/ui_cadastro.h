/********************************************************************************
** Form generated from reading UI file 'cadastro.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CADASTRO_H
#define UI_CADASTRO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Cadastro
{
public:
    QFrame *frame;
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QDateEdit *dateEdit;
    QLabel *label_4;
    QComboBox *comboBox;
    QLabel *label_5;
    QComboBox *comboBox_2;
    QPushButton *pb_findOficio;
    QLabel *label_6;
    QTableView *tableView;
    QLabel *label_7;
    QComboBox *comboBox_3;
    QPushButton *pushButton_4;
    QLabel *label_8;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QCheckBox *checkBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Cadastro)
    {
        if (Cadastro->objectName().isEmpty())
            Cadastro->setObjectName(QStringLiteral("Cadastro"));
        Cadastro->setWindowModality(Qt::ApplicationModal);
        Cadastro->resize(442, 498);
        frame = new QFrame(Cadastro);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 10, 421, 441));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(100, 40, 51, 20));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 40, 81, 16));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 10, 181, 16));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(210, 40, 81, 16));
        dateEdit = new QDateEdit(frame);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(290, 40, 110, 22));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 80, 81, 16));
        comboBox = new QComboBox(frame);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(90, 80, 311, 22));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 130, 91, 16));
        comboBox_2 = new QComboBox(frame);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(110, 130, 291, 22));
        pb_findOficio = new QPushButton(frame);
        pb_findOficio->setObjectName(QStringLiteral("pb_findOficio"));
        pb_findOficio->setGeometry(QRect(170, 330, 121, 23));
        label_6 = new QLabel(frame);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 330, 151, 16));
        tableView = new QTableView(frame);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(10, 240, 391, 71));
        label_7 = new QLabel(frame);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 180, 121, 16));
        comboBox_3 = new QComboBox(frame);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setGeometry(QRect(150, 180, 251, 22));
        pushButton_4 = new QPushButton(frame);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(274, 210, 131, 23));
        label_8 = new QLabel(frame);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 370, 211, 16));
        radioButton = new QRadioButton(frame);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(220, 370, 82, 17));
        radioButton_2 = new QRadioButton(frame);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(270, 370, 82, 17));
        radioButton_2->setChecked(true);
        checkBox = new QCheckBox(frame);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(10, 410, 111, 17));
        checkBox->setChecked(true);
        pushButton = new QPushButton(Cadastro);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(340, 460, 75, 23));
        pushButton_2 = new QPushButton(Cadastro);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, 460, 75, 23));

        retranslateUi(Cadastro);

        QMetaObject::connectSlotsByName(Cadastro);
    } // setupUi

    void retranslateUi(QWidget *Cadastro)
    {
        Cadastro->setWindowTitle(QApplication::translate("Cadastro", "Cadastrar Of\303\255cio", 0));
        label->setText(QApplication::translate("Cadastro", "C\303\263digo do of\303\255cio:", 0));
        label_2->setText(QApplication::translate("Cadastro", "Entre com as informa\303\247\303\265es do of\303\255cio:", 0));
        label_3->setText(QApplication::translate("Cadastro", "Data do of\303\255cio:", 0));
        label_4->setText(QApplication::translate("Cadastro", "Tipo do of\303\255cio:", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Cadastro", "Alvar\303\241", 0)
         << QApplication::translate("Cadastro", "Comunica\303\247\303\243o", 0)
         << QApplication::translate("Cadastro", "Jur\303\255dico", 0)
         << QApplication::translate("Cadastro", "Patroc\303\255nio", 0)
         << QApplication::translate("Cadastro", "Precat\303\263rio", 0)
         << QApplication::translate("Cadastro", "Requerimento", 0)
         << QApplication::translate("Cadastro", "Rogat\303\263ria", 0)
         << QApplication::translate("Cadastro", "Solicita\303\247\303\243o", 0)
         << QApplication::translate("Cadastro", "Outros", 0)
        );
        label_5->setText(QApplication::translate("Cadastro", "Setor remetente:", 0));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("Cadastro", "ACESC", 0)
         << QApplication::translate("Cadastro", "Ag\303\252ncia do Trabalhador", 0)
         << QApplication::translate("Cadastro", "Departamento de Recursos Humanos", 0)
         << QApplication::translate("Cadastro", "Divis\303\243o de Desenvolvimento de Pessoal", 0)
         << QApplication::translate("Cadastro", "Divis\303\243o de Folha, Registro e Cadastro", 0)
         << QApplication::translate("Cadastro", "Divis\303\243o de Medicina e Seguran\303\247a do Trabalho", 0)
         << QApplication::translate("Cadastro", "FUNDETEC", 0)
         << QApplication::translate("Cadastro", "Guarda Patrimonial", 0)
         << QApplication::translate("Cadastro", "Secretaria de A\303\247\303\243o Comunit\303\241ria", 0)
         << QApplication::translate("Cadastro", "Secretaria de Administra\303\247\303\243o", 0)
         << QApplication::translate("Cadastro", "Secretaria de Agricultura", 0)
         << QApplication::translate("Cadastro", "Secretaria de Assist\303\252ncia Social", 0)
         << QApplication::translate("Cadastro", "Secretaria de Assuntos Jur\303\255dicos", 0)
         << QApplication::translate("Cadastro", "Secretaria de Cultura", 0)
         << QApplication::translate("Cadastro", "Secretaria de Desenvolvimento Econ\303\264mico", 0)
         << QApplication::translate("Cadastro", "Secretaria de Educa\303\247\303\243o", 0)
         << QApplication::translate("Cadastro", "Secretaria de Esporte e Lazer", 0)
         << QApplication::translate("Cadastro", "Secretaria de Finan\303\247as", 0)
         << QApplication::translate("Cadastro", "Secretaria de Governo", 0)
         << QApplication::translate("Cadastro", "Secretaria de Obras P\303\272blicas", 0)
         << QApplication::translate("Cadastro", "Secretaria de Planejamento", 0)
         << QApplication::translate("Cadastro", "Secretaria de Sa\303\272de", 0)
         << QApplication::translate("Cadastro", "Secretaria do Meio Ambiente", 0)
        );
        pb_findOficio->setText(QApplication::translate("Cadastro", "Procurar arquivo", 0));
        label_6->setText(QApplication::translate("Cadastro", "Selecionar o of\303\255cio digitalizado:", 0));
        label_7->setText(QApplication::translate("Cadastro", "Setor(es) destinat\303\241rio(s):", 0));
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("Cadastro", "ACESC", 0)
         << QApplication::translate("Cadastro", "Ag\303\252ncia do Trabalhador", 0)
         << QApplication::translate("Cadastro", "Departamento de Recursos Humanos", 0)
         << QApplication::translate("Cadastro", "Divis\303\243o de Desenvolvimento de Pessoal", 0)
         << QApplication::translate("Cadastro", "Divis\303\243o de Folha, Registro e Cadastro", 0)
         << QApplication::translate("Cadastro", "Divis\303\243o de Medicina e Seguran\303\247a do Trabalho", 0)
         << QApplication::translate("Cadastro", "FUNDETEC", 0)
         << QApplication::translate("Cadastro", "Guarda Patrimonial", 0)
         << QApplication::translate("Cadastro", "Secretaria de A\303\247\303\243o Comunit\303\241ria", 0)
         << QApplication::translate("Cadastro", "Secretaria de Administra\303\247\303\243o", 0)
         << QApplication::translate("Cadastro", "Secretaria de Agricultura", 0)
         << QApplication::translate("Cadastro", "Secretaria de Assist\303\252ncia Social", 0)
         << QApplication::translate("Cadastro", "Secretaria de Assuntos Jur\303\255dicos", 0)
         << QApplication::translate("Cadastro", "Secretaria de Cultura", 0)
         << QApplication::translate("Cadastro", "Secretaria de Desenvolvimento Econ\303\264mico", 0)
         << QApplication::translate("Cadastro", "Secretaria de Educa\303\247\303\243o", 0)
         << QApplication::translate("Cadastro", "Secretaria de Esporte e Lazer", 0)
         << QApplication::translate("Cadastro", "Secretaria de Finan\303\247as", 0)
         << QApplication::translate("Cadastro", "Secretaria de Governo", 0)
         << QApplication::translate("Cadastro", "Secretaria de Obras P\303\272blicas", 0)
         << QApplication::translate("Cadastro", "Secretaria de Planejamento", 0)
         << QApplication::translate("Cadastro", "Secretaria de Sa\303\272de", 0)
         << QApplication::translate("Cadastro", "Secretaria do Meio Ambiente", 0)
        );
        pushButton_4->setText(QApplication::translate("Cadastro", "Adicionar setor", 0));
        label_8->setText(QApplication::translate("Cadastro", "Este of\303\255cio \303\251 uma resposta \303\240 outro of\303\255cio?", 0));
        radioButton->setText(QApplication::translate("Cadastro", "Sim", 0));
        radioButton_2->setText(QApplication::translate("Cadastro", "N\303\243o", 0));
        checkBox->setText(QApplication::translate("Cadastro", "Of\303\255cio pendente.", 0));
        pushButton->setText(QApplication::translate("Cadastro", "Cancelar", 0));
        pushButton_2->setText(QApplication::translate("Cadastro", "Cadastrar", 0));
    } // retranslateUi

};

namespace Ui {
    class Cadastro: public Ui_Cadastro {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CADASTRO_H
