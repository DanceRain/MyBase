#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QWidget>

namespace Ui {
class Register;
}

class Register : public QWidget
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

private slots:
    void on_btBack_clicked();

signals:
    void backLoginWindow();

private:
    void initConnect();
    Ui::Register *ui;
};

#endif // TITLEBAR_H
