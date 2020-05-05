#include "mylayout.h"
#include "ui_mylayout.h"

#include <QFileDialog>

MyLayout::MyLayout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyLayout)
{
    ui->setupUi(this);
    ui->pushButton_2->setCheckable(true);
}

MyLayout::~MyLayout()
{
    delete ui;
}

void MyLayout::on_pushButton_clicked()
{
    QString fileName =
            QFileDialog::getOpenFileName(this,"打开文件","","图片文件(*.png *.jpg)");
    QImage * img=new QImage;
    if(fileName != ""){
        if(img->load(fileName)){
            //图片缩放以适应Label大小
            img->scaled(ui->label_15->size(),Qt::KeepAspectRatio);
            ui->label_15->setScaledContents(true);
            //显示图片在Label中
            ui->label_15->setPixmap(QPixmap::fromImage(*img));
        }
    }
}

void MyLayout::on_pushButton_2_toggled(bool checked)
{
    // 设置文本编辑器的显示和隐藏
    ui->splitter->setVisible(checked);
    ui->splitter_2->setVisible(checked);
    if(checked) {
        ui->pushButton_2->setText(tr("简洁模式"));
    }
    else {
        ui->pushButton_2->setText(tr("更多信息"));
    }
}
