#include "cadastro.h"
#include "ui_cadastro.h"
#include <QFileDialog>
#include <QString>

Cadastro::Cadastro(QWidget *parent) :
QWidget(parent),
ui(new Ui::Cadastro)
	{
		ui->setupUi(this);
	}

Cadastro::~Cadastro()
	{
		delete ui;
	}

void Cadastro::on_pushButton_clicked()
{
		this->close ();
}

void Cadastro::on_pb_findOficio_clicked()
{
		QString fileName = QFileDialog::getOpenFileName(this,
		tr("Selecionar ofício"), "/home/", tr("Image Files (*.png *.jpg *.bmp)"));
}
