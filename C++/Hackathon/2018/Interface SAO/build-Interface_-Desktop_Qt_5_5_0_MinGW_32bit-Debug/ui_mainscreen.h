/********************************************************************************
** Form generated from reading UI file 'mainscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSCREEN_H
#define UI_MAINSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainScreen
{
public:
    QAction *actionLogoff;
    QAction *actionSair;
    QAction *actionCadastrar_of_cio;
    QAction *actionBuscar_Of_cio_s;
    QAction *actionOf_cio_s_Pendente_s;
    QAction *actionTrocar_senha;
    QAction *actionTrocar_email;
    QAction *actionEditar_dados_pessoais;
    QWidget *centralwidget;
    QFrame *frame;
    QPushButton *pb_Cadastro;
    QPushButton *pb_BuscarOficio;
    QPushButton *pb_Pendentes;
    QPushButton *pb_Sair;
    QPushButton *pb_Logoff;
    QTableView *Tabela;
    QMenuBar *menubar;
    QMenu *menuSistema;
    QMenu *menuOf_cios;
    QMenu *menuUsu_rio;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainScreen)
    {
        if (MainScreen->objectName().isEmpty())
            MainScreen->setObjectName(QStringLiteral("MainScreen"));
        MainScreen->setWindowModality(Qt::NonModal);
        MainScreen->resize(1284, 722);
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/unnamed.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainScreen->setWindowIcon(icon);
        actionLogoff = new QAction(MainScreen);
        actionLogoff->setObjectName(QStringLiteral("actionLogoff"));
        actionSair = new QAction(MainScreen);
        actionSair->setObjectName(QStringLiteral("actionSair"));
        actionCadastrar_of_cio = new QAction(MainScreen);
        actionCadastrar_of_cio->setObjectName(QStringLiteral("actionCadastrar_of_cio"));
        actionBuscar_Of_cio_s = new QAction(MainScreen);
        actionBuscar_Of_cio_s->setObjectName(QStringLiteral("actionBuscar_Of_cio_s"));
        actionOf_cio_s_Pendente_s = new QAction(MainScreen);
        actionOf_cio_s_Pendente_s->setObjectName(QStringLiteral("actionOf_cio_s_Pendente_s"));
        actionTrocar_senha = new QAction(MainScreen);
        actionTrocar_senha->setObjectName(QStringLiteral("actionTrocar_senha"));
        actionTrocar_email = new QAction(MainScreen);
        actionTrocar_email->setObjectName(QStringLiteral("actionTrocar_email"));
        actionEditar_dados_pessoais = new QAction(MainScreen);
        actionEditar_dados_pessoais->setObjectName(QStringLiteral("actionEditar_dados_pessoais"));
        centralwidget = new QWidget(MainScreen);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(20, 10, 1251, 80));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pb_Cadastro = new QPushButton(frame);
        pb_Cadastro->setObjectName(QStringLiteral("pb_Cadastro"));
        pb_Cadastro->setGeometry(QRect(0, 12, 131, 51));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/add.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pb_Cadastro->setIcon(icon1);
        pb_Cadastro->setIconSize(QSize(32, 32));
        pb_BuscarOficio = new QPushButton(frame);
        pb_BuscarOficio->setObjectName(QStringLiteral("pb_BuscarOficio"));
        pb_BuscarOficio->setGeometry(QRect(160, 12, 121, 51));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/img/search.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pb_BuscarOficio->setIcon(icon2);
        pb_BuscarOficio->setIconSize(QSize(32, 32));
        pb_Pendentes = new QPushButton(frame);
        pb_Pendentes->setObjectName(QStringLiteral("pb_Pendentes"));
        pb_Pendentes->setGeometry(QRect(310, 12, 161, 51));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/img/pendente.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pb_Pendentes->setIcon(icon3);
        pb_Pendentes->setIconSize(QSize(32, 32));
        pb_Sair = new QPushButton(frame);
        pb_Sair->setObjectName(QStringLiteral("pb_Sair"));
        pb_Sair->setGeometry(QRect(1170, 12, 75, 51));
        pb_Logoff = new QPushButton(frame);
        pb_Logoff->setObjectName(QStringLiteral("pb_Logoff"));
        pb_Logoff->setGeometry(QRect(1080, 10, 75, 51));
        Tabela = new QTableView(centralwidget);
        Tabela->setObjectName(QStringLiteral("Tabela"));
        Tabela->setGeometry(QRect(19, 100, 1241, 550));
        MainScreen->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainScreen);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1284, 21));
        menuSistema = new QMenu(menubar);
        menuSistema->setObjectName(QStringLiteral("menuSistema"));
        menuOf_cios = new QMenu(menubar);
        menuOf_cios->setObjectName(QStringLiteral("menuOf_cios"));
        menuUsu_rio = new QMenu(menubar);
        menuUsu_rio->setObjectName(QStringLiteral("menuUsu_rio"));
        MainScreen->setMenuBar(menubar);
        statusbar = new QStatusBar(MainScreen);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainScreen->setStatusBar(statusbar);

        menubar->addAction(menuSistema->menuAction());
        menubar->addAction(menuOf_cios->menuAction());
        menubar->addAction(menuUsu_rio->menuAction());
        menuSistema->addAction(actionLogoff);
        menuSistema->addSeparator();
        menuSistema->addAction(actionSair);
        menuOf_cios->addAction(actionCadastrar_of_cio);
        menuOf_cios->addAction(actionBuscar_Of_cio_s);
        menuOf_cios->addAction(actionOf_cio_s_Pendente_s);
        menuUsu_rio->addAction(actionTrocar_senha);
        menuUsu_rio->addAction(actionTrocar_email);
        menuUsu_rio->addAction(actionEditar_dados_pessoais);

        retranslateUi(MainScreen);

        QMetaObject::connectSlotsByName(MainScreen);
    } // setupUi

    void retranslateUi(QMainWindow *MainScreen)
    {
        MainScreen->setWindowTitle(QApplication::translate("MainScreen", "MainWindow", 0));
        actionLogoff->setText(QApplication::translate("MainScreen", "Logoff", 0));
        actionSair->setText(QApplication::translate("MainScreen", "Sair", 0));
        actionCadastrar_of_cio->setText(QApplication::translate("MainScreen", "Cadastrar Of\303\255cio", 0));
        actionBuscar_Of_cio_s->setText(QApplication::translate("MainScreen", "Buscar Of\303\255cio(s)", 0));
        actionOf_cio_s_Pendente_s->setText(QApplication::translate("MainScreen", "Of\303\255cio(s) Pendente(s)", 0));
        actionTrocar_senha->setText(QApplication::translate("MainScreen", "Trocar senha", 0));
        actionTrocar_email->setText(QApplication::translate("MainScreen", "Trocar email", 0));
        actionEditar_dados_pessoais->setText(QApplication::translate("MainScreen", "Editar dados pessoais", 0));
        pb_Cadastro->setText(QApplication::translate("MainScreen", "Cadastrar Of\303\255cio", 0));
        pb_BuscarOficio->setText(QApplication::translate("MainScreen", "Buscar Of\303\255cio", 0));
        pb_Pendentes->setText(QApplication::translate("MainScreen", "Of\303\255cio(s) Pendente(s)", 0));
        pb_Sair->setText(QApplication::translate("MainScreen", "Sair", 0));
        pb_Logoff->setText(QApplication::translate("MainScreen", "Logoff", 0));
        menuSistema->setTitle(QApplication::translate("MainScreen", "Sistema", 0));
        menuOf_cios->setTitle(QApplication::translate("MainScreen", "Of\303\255cios", 0));
        menuUsu_rio->setTitle(QApplication::translate("MainScreen", "Usu\303\241rio", 0));
    } // retranslateUi

};

namespace Ui {
    class MainScreen: public Ui_MainScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSCREEN_H
