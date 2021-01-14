#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_btLogin_clicked();
    void on_btRegister_clicked();

signals:
    void registerWindow();
    void userWindow();

private:
    void initConnect();
    Ui::Login *ui;
};

#endif // LOGIN_H
