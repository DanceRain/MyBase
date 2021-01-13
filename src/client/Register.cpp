#include "Register.h"
#include "ui_Register.h"
#include "Login.h"

Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
}

Register::~Register()
{
    delete ui;
}

void Register::on_btBack_clicked()
{
    this->hide();
    static_cast<Login*>(this->parent())->show();
}
