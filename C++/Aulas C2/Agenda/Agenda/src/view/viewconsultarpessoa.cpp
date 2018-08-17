#include "viewconsultarpessoa.h"
#include "ui_viewconsultarpessoa.h"

ViewConsultarPessoa::ViewConsultarPessoa(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ViewConsultarPessoa)
{
    ui->setupUi(this);
}

ViewConsultarPessoa::~ViewConsultarPessoa()
{
    delete ui;
}
