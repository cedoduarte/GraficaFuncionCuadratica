#include "ParametrosForm.h"
#include "ui_ParametrosForm.h"

ParametrosForm::ParametrosForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ParametrosForm)
{
    ui->setupUi(this);
    configuraDoubleSpinBox(ui->AdoubleSpinBox);
    configuraDoubleSpinBox(ui->BdoubleSpinBox);
    configuraDoubleSpinBox(ui->CdoubleSpinBox);
}

ParametrosForm::~ParametrosForm()
{
    delete ui;
}

void ParametrosForm::on_AdoubleSpinBox_valueChanged(double a)
{
    emit cambio(A, a);
}

void ParametrosForm::on_BdoubleSpinBox_valueChanged(double b)
{
    emit cambio(B, b);
}

void ParametrosForm::on_CdoubleSpinBox_valueChanged(double c)
{
    emit cambio(C, c);
}

void ParametrosForm::configuraDoubleSpinBox(QDoubleSpinBox *spinner) const
{
    const double valor = +999999999999.999;
    spinner->setMaximum(valor);
    spinner->setMinimum(-valor);
}
