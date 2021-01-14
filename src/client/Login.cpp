#include "Login.h"
#include "ui_Login.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

/*private*/
void Login::initConnect()
{
    connect(ui->btRegister, &QPushButton::clicked, this, &Login::on_btRegister_clicked);
}

/*public*/
Login::~Login()
{
    delete ui;
}

void Login::on_btLogin_clicked()
{
}

void Login::on_btRegister_clicked()
{
    emit registerWindow();
}
