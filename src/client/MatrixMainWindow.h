#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPushButton>

namespace Ui {
class MatrixMainWindow;
}

class MatrixMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MatrixMainWindow(QWidget *parent = nullptr);
    ~MatrixMainWindow();
protected:
    void mousePressEvent(QMouseEvent* e);
    void mouseMoveEvent(QMouseEvent* e);
    void mouseReleaseEvent(QMouseEvent* e);

private slots:
    void on_btRegisterClicked();
    void on_btBackLoginClicked();

private:
    void initConnect();
    void initWidget();
    Ui::MatrixMainWindow *ui;
    QPoint last;
};

#endif // MAINWINDOW_H
