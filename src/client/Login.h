#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPushButton>


namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT
public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
protected:
    void mousePressEvent(QMouseEvent* e);
    void mouseMoveEvent(QMouseEvent* e);
    void mouseReleaseEvent(QMouseEvent* e);

private slots:
    void closeWindow();
    void openRegisterWindow();

private:
    void init();
    Ui::Login *ui;
    QPoint last;
};

#endif // MAINWINDOW_H
