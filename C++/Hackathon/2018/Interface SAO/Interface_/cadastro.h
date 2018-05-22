#ifndef CADASTRO_H
#define CADASTRO_H

#include <QWidget>

namespace Ui {
	class Cadastro;
	}

class Cadastro : public QWidget
{
	Q_OBJECT

public:
	explicit Cadastro(QWidget *parent = 0);
	~Cadastro();

private slots:
	void on_pushButton_clicked();

	void on_pb_findOficio_clicked();

private:
	Ui::Cadastro *ui;
};

#endif // CADASTRO_H
