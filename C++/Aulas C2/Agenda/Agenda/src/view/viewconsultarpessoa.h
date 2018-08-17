#ifndef VIEWCONSULTARPESSOA_H
#define VIEWCONSULTARPESSOA_H

#include <QWidget>

namespace Ui {
class ViewConsultarPessoa;
}

class ViewConsultarPessoa : public QWidget
{
    Q_OBJECT

public:
    explicit ViewConsultarPessoa(QWidget *parent = 0);
    ~ViewConsultarPessoa();

private:
    Ui::ViewConsultarPessoa *ui;
};

#endif // VIEWCONSULTARPESSOA_H
