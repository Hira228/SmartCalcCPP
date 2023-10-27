#include "graph.h"

#include "qcustomplot.h"
#include "ui_graph.h"

Graph::Graph(QWidget *parent) : QDialog(parent), ui(new Ui::Graph) {
  ui->setupUi(this);
}

Graph::~Graph() { delete ui; }

void Graph::setXAxis(double x_min, double x_max) {
  ui->widget->xAxis->setRange(x_min, x_max);
}

void Graph::setYAxis(double y_min, double y_max) {
  ui->widget->yAxis->setRange(y_min, y_max);
}

void Graph::plotGraph(QVector<double> x, QVector<double> y) {
  ui->widget->addGraph();
  ui->widget->graph(0)->addData(x, y);
  ui->widget->replot();
}
