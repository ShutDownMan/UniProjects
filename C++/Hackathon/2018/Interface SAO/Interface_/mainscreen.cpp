#include "mainscreen.h"
#include "ui_mainscreen.h"
#include <QDesktopWidget>
#include <QDebug>
//#include "cadastro.h"
#include <QStandardItemModel>

MainScreen::MainScreen(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::MainScreen)
	{
		ui->setupUi(this);
		QSize availableSize = qApp->desktop()->availableGeometry().size();
		int width = availableSize.width();
		int height = availableSize.height();
		qDebug() << "Available dimensions " << width << "x" << height;
		width *= 0.94; // 90% of the screen size
		height *= 0.94; // 90% of the screen size
		qDebug() << "Computed dimensions " << width << "x" << height;
		QSize newSize( width, height );

	setGeometry
	(
	QStyle::alignedRect
	(
	Qt::LeftToRight,
	Qt::AlignCenter,
	newSize,
	qApp->desktop()->availableGeometry()
	)
	);

	ui->Tabela->setAlternatingRowColors (true);
	ui->Tabela->setStyleSheet ("alternate-background-color: cyan; background-color: white;");
	ui->Tabela->setEditTriggers (QAbstractItemView::NoEditTriggers);

	connect(ui->pb_Cadastro, SIGNAL(click()), this, SLOT(on_pb_Cadastro_clicked()));
	connect(ui->pb_BuscarOficio, SIGNAL(click()), this, SLOT (on_pb_BuscarOficio_clicked ();));

	}

MainScreen::~MainScreen()
	{
		delete ui;
	}


void MainScreen::on_pb_Cadastro_clicked()
{
		novoCadastro = new Cadastro ();
		novoCadastro->show ();
		novoCadastro->setAttribute (Qt::WA_DeleteOnClose);
}

void MainScreen::on_pb_BuscarOficio_clicked()
{
		novaBusca = new busca ();
		novaBusca->show ();
		novaBusca->setAttribute (Qt::WA_DeleteOnClose);
}

void MainScreen::on_pb_Logoff_clicked()
{
		this->close ();
	lg =  new LoginScreen ();
	lg->show ();
}
