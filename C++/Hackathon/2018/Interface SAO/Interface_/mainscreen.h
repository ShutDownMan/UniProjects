#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <QMainWindow>
#include "cadastro.h"
#include "busca.h"
#include "loginscreen.h"

namespace Ui {
	class MainScreen;
	}

class MainScreen : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainScreen(QWidget *parent = 0);
	~MainScreen();

private slots:
	void on_pb_Cadastro_clicked();

	void on_pb_BuscarOficio_clicked();

	void on_pb_Logoff_clicked();

private:
	Ui::MainScreen *ui;
	Cadastro *novoCadastro;
	busca *novaBusca;
	LoginScreen *lg;
};

#endif // MAINSCREEN_H
