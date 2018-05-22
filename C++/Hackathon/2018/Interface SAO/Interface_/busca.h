#ifndef BUSCA_H
#define BUSCA_H

#include <QWidget>

namespace Ui {
	class busca;
	}

class busca : public QWidget
{
	Q_OBJECT

public:
	explicit busca(QWidget *parent = 0);
	~busca();

private slots:
	void on_pb_cancelar_clicked();

private:
	Ui::busca *ui;
};

#endif // BUSCA_H
