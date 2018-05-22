#include "loginscreen.h"
#include "ui_loginscreen.h"
#include <QPixmap>
#include <QDesktopWidget>
#include <QDebug>
#include "mainscreen.h"
//#include <QLineEdit>

LoginScreen::LoginScreen(QWidget *parent) :
QWidget(parent),
ui(new Ui::LoginScreen)
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

	QPixmap pixmap;
	pixmap.load (":/img/SAO_BG.jpg");

	pixmap = pixmap.scaled (width, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

	QPalette palette;
	palette.setBrush (QPalette::Window, pixmap);
	this->setPalette (palette);

	//QLineEdit *editPassword = new QLineEdit(ui->le_password);
	//editPassword->setEchoMode(QLineEdit::Password);
	}

LoginScreen::~LoginScreen()
	{
		delete ui;
	}

void LoginScreen::on_pb_Login_clicked()
{
		MainScreen *ms = new MainScreen ();
		ms->show ();
		this->close ();
}
