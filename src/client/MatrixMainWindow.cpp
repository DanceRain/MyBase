#include "MatrixMainWindow.h"
#include "ui_MatrixMainWindow.h"
#include <QPropertyAnimation>
#include "Register.h"
#include "Login.h"
#include <memory>

using namespace::std;

MatrixMainWindow::MatrixMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MatrixMainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("Matrix"));
    this->setWindowFlag(Qt::FramelessWindowHint);

    /*删除Designer中多余的widget*/
    while(ui->stackedWidget->count())
    {
        ui->stackedWidget->removeWidget(ui->stackedWidget->widget(0));
    }


    initWidget();
    initConnect();
}

void MatrixMainWindow::initConnect()
{
    connect(ui->btShutdown, &QPushButton::clicked, this, &MatrixMainWindow::close);
    connect(ui->btMinimize, &QPushButton::clicked, this, &MatrixMainWindow::showMinimized);

}

void MatrixMainWindow::initWidget()
{
    Login* widgetLogin = new Login(this);
    Register* widgetRegister = new Register(this);

    ui->stackedWidget->addWidget(widgetLogin);
    ui->stackedWidget->addWidget(widgetRegister);
    ui->stackedWidget->setCurrentIndex(0);

    connect(widgetLogin, &Login::registerWindow, this, &MatrixMainWindow::on_btRegisterClicked);
    connect(widgetRegister, &Register::backLoginWindow, this, &MatrixMainWindow::on_btBackLoginClicked);
}

/*private slots*/
void MatrixMainWindow::on_btRegisterClicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MatrixMainWindow::on_btBackLoginClicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

/*protected*/
void MatrixMainWindow::mousePressEvent(QMouseEvent* e)
{
    last = e->globalPos();
}

void MatrixMainWindow::mouseMoveEvent(QMouseEvent* e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();

    last = e->globalPos();
    move(this->x()+dx, this->y()+dy);
}

void MatrixMainWindow::mouseReleaseEvent(QMouseEvent* e)
{

}


/*private*/
MatrixMainWindow::~MatrixMainWindow()
{
    delete ui;
}
