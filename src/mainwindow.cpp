#include "mainwindow.h"

#include <QMenuBar>
#include <QPropertyAnimation>
#include <QtMath>

#include "Controller.h"
#include "creditcalc.h"
#include "graph.h"
#include "ui_mainwindow.h"
#include <QVector>

MainWindow::MainWindow(s21::Controller controller, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), controller_(controller) {
  ui->setupUi(this);

  inputXLineEdit = ui->lineEdit_x;
  inputXlineEdit_min = ui->lineEdit_x_min_graph;
  inputXlineEdit_max = ui->lineEdit_x_max_graph;
  inputYlineEdit_min = ui->lineEdit_y_min_graph;
  inputYlineEdit_max = ui->lineEdit_y_max_graph;

  expandCalculatorAction = new QAction(tr("Expand Calculator"), this);
  creditCalculatorAction = new QAction(tr("Credit Calculator"), this);

  fileMenu = menuBar()->addMenu(tr("&CALC"));
  fileMenu->addAction(expandCalculatorAction);
  fileMenu->addAction(creditCalculatorAction);

  QString menuBarStyle = "background-color: rgb(255, 255, 255);";
  menuBar()->setStyleSheet(menuBarStyle);

  connect(expandCalculatorAction, &QAction::triggered, this,
          &MainWindow::expandWindow);
  connect(creditCalculatorAction, &QAction::triggered, this,
          &MainWindow::CreditCalc);

  connect(ui->pushButton_zero, SIGNAL(clicked()), this, SLOT(add_lexems()));
  connect(ui->pushButton_x, SIGNAL(clicked()), this, SLOT(add_lexems()));
  connect(ui->pushButton_one, SIGNAL(clicked()), this, SLOT(add_lexems()));
  connect(ui->pushButton_two, SIGNAL(clicked()), this, SLOT(add_lexems()));
  connect(ui->pushButton_three, SIGNAL(clicked()), this, SLOT(add_lexems()));
  connect(ui->pushButton_four, SIGNAL(clicked()), this, SLOT(add_lexems()));
  connect(ui->pushButton_five, SIGNAL(clicked()), this, SLOT(add_lexems()));
  connect(ui->pushButton_six, SIGNAL(clicked()), this, SLOT(add_lexems()));
  connect(ui->pushButton_seven, SIGNAL(clicked()), this, SLOT(add_lexems()));
  connect(ui->pushButton_eight, SIGNAL(clicked()), this, SLOT(add_lexems()));
  connect(ui->pushButton_nine, SIGNAL(clicked()), this, SLOT(add_lexems()));
  connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(add_lexems()));
  connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(add_lexems()));
  connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(add_lexems()));
  connect(ui->pushButton_multi, SIGNAL(clicked()), this, SLOT(add_lexems()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(add_lexems()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(add_lexems()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(add_lexems()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(add_lexems()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(add_lexems()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(add_lexems()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(add_lexems()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(add_lexems()));
  connect(ui->pushButton_open_prnt, SIGNAL(clicked()), this,
          SLOT(add_lexems()));
  connect(ui->pushButton_close_prnt, SIGNAL(clicked()), this,
          SLOT(add_lexems()));
  connect(ui->pushButton_point, SIGNAL(clicked()), this, SLOT(add_lexems()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(add_lexems()));
  connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(add_lexems()));
  connect(ui->pushButton_ac, SIGNAL(clicked()), this, SLOT(clearText()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(add_lexems()));
  connect(ui->pushButton_res, SIGNAL(clicked()), this, SLOT(calc_result()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::expandWindow() {
  QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");

  if (width() == 791) {
    animation->setEndValue(QRect(geometry().x(), geometry().y(), 361, 360));
  } else {
    animation->setEndValue(QRect(geometry().x(), geometry().y(), 791, 360));
  }
  animation->setDuration(500);
  animation->setEasingCurve(QEasingCurve::InOutQuad);

  animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void MainWindow::CreditCalc() {
  creditcalc_ui = new class CreditCalc(controller_, this);
  creditcalc_ui->show();
}

void MainWindow::add_lexems() {
  QPushButton *button = static_cast<QPushButton *>(sender());

  QString current_text = ui->show_res->text();
  QString new_label;

  if (current_text == "0") {
    new_label = button->text();
  } else {
    new_label = current_text + button->text();
  }

  ui->show_res->setText(new_label);
}

void MainWindow::clearText() { ui->show_res->setText("0"); }

void MainWindow::calc_result() {
  std::string result;
  std::string temp_str;
  QString exec = ui->show_res->text();
  const std::string math_exp_str = exec.toStdString();
  QString xInput = inputXLineEdit->text();
  double xValue = xInput.toDouble();
  if (controller_.checkXStr(math_exp_str)) {
    temp_str = controller_.convertWithX(math_exp_str, xValue);
    result = controller_.equal(temp_str);
  } else
    result = controller_.equal(math_exp_str);
  QString str = QString::fromStdString(result.c_str());
  ui->show_res->setText(str);
}

void MainWindow::on_pushButton_graph_clicked() {
  QString ex = ui->show_res->text();
  std::string math_exp_str = ex.toStdString();

  QString xBegin = inputXlineEdit_min->text();
  double xValue_begin = xBegin.toDouble();

  QString xEnd = inputXlineEdit_max->text();
  double xValue_end = xEnd.toDouble();

  QString yBegin = inputYlineEdit_min->text();
  double yValue_begin = yBegin.toDouble();

  QString yEnd = inputYlineEdit_max->text();
  double yValue_end = yEnd.toDouble();

  graph_ui = new Graph(this);

  graph_ui->setXAxis(xValue_begin, xValue_end);
  graph_ui->setYAxis(yValue_begin, yValue_end);
  controller_.clearVectGraph();
  std::pair<std::vector<double>, std::vector<double>> a = controller_.graphPlot(xValue_begin, xValue_end, math_exp_str);
  QVector<double> b;
  for (const auto &value : a.first) {
    b.append(static_cast<double>(value));
  }

  QVector<double> c;
  for (const auto &value : a.second) {
    c.append(static_cast<double>(value));
  }
  graph_ui->plotGraph(b, c);

  graph_ui->show();
}
