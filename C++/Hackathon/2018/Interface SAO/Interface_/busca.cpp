#include "busca.h"
#include "ui_busca.h"

busca::busca(QWidget *parent) :
QWidget(parent),
ui(new Ui::busca)
	{
		ui->setupUi(this);
	}

busca::~busca()
	{
		delete ui;
	}

void busca::on_pb_cancelar_clicked()
{
		this->close ();
}
