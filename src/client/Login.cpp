#include "Login.h"
#include "ui_Login.h"
#include <QPropertyAnimation>
#include "Register.h"

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("Matrix"));
    this->setWindowFlag(Qt::FramelessWindowHint);
    init();
}

void Login::init()
{
    connect(ui->btShutdown, &QPushButton::clicked, this, &Login::close);
    connect(ui->btMinimize, &QPushButton::clicked, this, &Login::showMinimized);
    connect(ui->btRegister, &QPushButton::clicked, this, &Login::openRegisterWindow);
}

/*private slots*/
void Login::closeWindow()
{

}

void Login::openRegisterWindow()
{
    Register window(this);
    this->hide();
    window.show();
}

/*protected*/
void Login::mousePressEvent(QMouseEvent* e)
{
    last = e->globalPos();
}

void Login::mouseMoveEvent(QMouseEvent* e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();

    last = e->globalPos();
    move(this->x()+dx, this->y()+dy);
}

void Login::mouseReleaseEvent(QMouseEvent* e)
{
}

Login::~Login()
{
    delete ui;
}
