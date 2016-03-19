#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui
{
class Widget;
}

class DuPlot;

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    void inicializaVariables();
    void configuraGUI();
    void graficaFuncionCuadratica();

    Ui::Widget *ui;
    DuPlot *mFuncionCuadratica;
    double m_a, m_b, m_c;
};

#endif // WIDGET_H
