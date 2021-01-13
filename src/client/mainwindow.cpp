#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <buttonhoverwatcher.h>
#include <QPropertyAnimation>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("Matrix"));
    this->setWindowFlag(Qt::FramelessWindowHint);
    init();
}

void MainWindow::init()
{
    connect(ui->btShutdown, &QPushButton::clicked, this, &MainWindow::closeWindow);
    connect(ui->btMinimize, &QPushButton::clicked, this, &QMainWindow::showMinimized);
}

void MainWindow::closeWindow()
{

    QPropertyAnimation *animation = new QPropertyAnimation(this,"windowOpacity");
    animation->setDuration(1000);
    animation->setStartValue(0.5);
    animation->setEndValue(0);
    animation->setEasingCurve(QEasingCurve::Linear);


    animation->start();

    connect(animation,SIGNAL(finished()),this,SLOT(close()));
}


void MainWindow::mousePressEvent(QMouseEvent* e)
{
    last = e->globalPos();
}

void MainWindow::mouseMoveEvent(QMouseEvent* e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();

    last = e->globalPos();
    move(this->x()+dx, this->y()+dy);
}

void MainWindow::mouseReleaseEvent(QMouseEvent* e)
{
}

MainWindow::~MainWindow()
{
    delete ui;
}
