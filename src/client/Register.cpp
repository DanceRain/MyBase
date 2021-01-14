#include "Register.h"
#include "ui_Register.h"
#include "MatrixMainWindow.h"

Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
}

/*public*/
Register::~Register()
{
    delete ui;
}

/*slots*/
void Register::on_btBack_clicked()
{
    emit backLoginWindow();
}

/*private*/
void Register::initConnect()
{
    connect(ui->btFinishRegister, &QPushButton::clicked, this, &Register::on_btBack_clicked);
}
