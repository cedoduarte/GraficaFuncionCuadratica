#ifndef PARAMETROSFORM_H
#define PARAMETROSFORM_H

#include <QWidget>

namespace Ui
{
class ParametrosForm;
}

class QDoubleSpinBox;

class ParametrosForm : public QWidget
{
    Q_OBJECT
public:
    enum COEFICIENTE
    {
        A, B, C
    };

    explicit ParametrosForm(QWidget *parent = nullptr);
    ~ParametrosForm();
signals:
    void cambio(COEFICIENTE, double);
private slots:
    void on_AdoubleSpinBox_valueChanged(double a);
    void on_BdoubleSpinBox_valueChanged(double b);
    void on_CdoubleSpinBox_valueChanged(double c);
private:
    void configuraDoubleSpinBox(QDoubleSpinBox *spinner) const;

    Ui::ParametrosForm *ui;
};

#endif // PARAMETROSFORM_H
