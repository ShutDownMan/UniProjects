/********************************************************************************
** Form generated from reading UI file 'loginscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINSCREEN_H
#define UI_LOGINSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginScreen
{
public:
    QFrame *frame;
    QLabel *lb_User;
    QLabel *lb_password;
    QLineEdit *lineEdit;
    QLineEdit *le_password;
    QPushButton *pb_Login;

    void setupUi(QWidget *LoginScreen)
    {
        if (LoginScreen->objectName().isEmpty())
            LoginScreen->setObjectName(QStringLiteral("LoginScreen"));
        LoginScreen->resize(1284, 722);
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/unnamed.ico"), QSize(), QIcon::Normal, QIcon::Off);
        LoginScreen->setWindowIcon(icon);
        frame = new QFrame(LoginScreen);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(370, 440, 621, 51));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        lb_User = new QLabel(frame);
        lb_User->setObjectName(QStringLiteral("lb_User"));
        lb_User->setGeometry(QRect(0, 22, 47, 13));
        lb_password = new QLabel(frame);
        lb_password->setObjectName(QStringLiteral("lb_password"));
        lb_password->setGeometry(QRect(240, 22, 47, 13));
        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(50, 20, 171, 20));
        le_password = new QLineEdit(frame);
        le_password->setObjectName(QStringLiteral("le_password"));
        le_password->setGeometry(QRect(280, 20, 171, 20));
        le_password->setEchoMode(QLineEdit::Password);
        pb_Login = new QPushButton(frame);
        pb_Login->setObjectName(QStringLiteral("pb_Login"));
        pb_Login->setGeometry(QRect(490, 20, 75, 23));

        retranslateUi(LoginScreen);

        QMetaObject::connectSlotsByName(LoginScreen);
    } // setupUi

    void retranslateUi(QWidget *LoginScreen)
    {
        LoginScreen->setWindowTitle(QApplication::translate("LoginScreen", "S.A.O. (Sistema de Arquivamento de Of\303\255cios)", 0));
        lb_User->setText(QApplication::translate("LoginScreen", "Usu\303\241rio:", 0));
        lb_password->setText(QApplication::translate("LoginScreen", "Senha:", 0));
        pb_Login->setText(QApplication::translate("LoginScreen", "Entrar", 0));
    } // retranslateUi

};

namespace Ui {
    class LoginScreen: public Ui_LoginScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINSCREEN_H
