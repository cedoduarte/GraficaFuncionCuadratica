#include "DuPlot.h"
#include "qcustomplot.h"

DuPlot::DuPlot(QCustomPlot *customPlot, QObject *parent)
    : QObject(parent)
{   
    mCustomPlot = customPlot;
}

void DuPlot::drawGraph()
{
    mGraph = mCustomPlot->addGraph();
    mGraph->setData(mX, mY);
}

void DuPlot::removeGraph()
{
    mCustomPlot->removeGraph(mGraph);
}
