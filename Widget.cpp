#include "Widget.h"
#include "ui_Widget.h"
#include "ParametrosForm.h"
#include "DuPlot.h"
#include <QVBoxLayout>
#include <QMenu>
#include <QDebug>

#define XMIN -10.0
#define XMAX +10.0
#define YMIN -10.0
#define YMAX +10.0

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    inicializaVariables();
    configuraGUI();
    graficaFuncionCuadratica();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::inicializaVariables()
{
    m_a = 1.0;
    m_b = 0.0;
    m_c = 0.0;
    mFuncionCuadratica = new DuPlot(ui->customPlot, this);
}

void Widget::configuraGUI()
{
    auto vbox = new QVBoxLayout;
    auto menu = new QMenu(this);
    auto parametrosForm = new ParametrosForm(this);
    vbox->addWidget(parametrosForm);
    menu->setLayout(vbox);
    ui->parametrosPushButton->setMenu(menu);

    ui->customPlot->xAxis->setRange(XMIN, XMAX);
    ui->customPlot->yAxis->setRange(YMIN, YMAX);

    connect(parametrosForm, &ParametrosForm::cambio,
            [&](ParametrosForm::COEFICIENTE c, double valor)
    {
        switch (c) {
        case ParametrosForm::A:
            m_a = valor;
            break;
        case ParametrosForm::B:
            m_b = valor;
            break;
        case ParametrosForm::C:
            m_c = valor;
            break;
        }
        mFuncionCuadratica->removeGraph();
        graficaFuncionCuadratica();
        ui->customPlot->replot();
    });
}

void Widget::graficaFuncionCuadratica()
{
    QVector<double> x, y;
    for (double iX = XMIN; iX < XMAX; iX += 0.1) {
        x << iX;
        y << m_a*pow(iX, 2.0)+m_b*iX+m_c;
    }
    mFuncionCuadratica->setX(x);
    mFuncionCuadratica->setY(y);
    mFuncionCuadratica->drawGraph();
}
