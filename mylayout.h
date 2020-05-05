#ifndef MYLAYOUT_H
#define MYLAYOUT_H

#include <QDialog>

namespace Ui {
class MyLayout;
}

class MyLayout : public QDialog
{
    Q_OBJECT

public:
    explicit MyLayout(QWidget *parent = nullptr);
    ~MyLayout();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_toggled(bool checked);

private:
    Ui::MyLayout *ui;
};

#endif // MYLAYOUT_H
