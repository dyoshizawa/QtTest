#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_pressed()
{
    ui->lineEdit->setText("push button");


    //
    //画像サイズを設定
    int width=100,height=50;
    //QImageクラスで画像を生成。フォーマットを32ビット画像にする。
    QImage image(width,height,QImage::Format_ARGB32);

    //ix, iyの2重ルーブで、全ての画素の色を設定する。
    for(int ix=0;ix<width;ix++)
    {
        for(int iy=0;iy<height;iy++)
        {
            //色の値を決める。0〜255の範囲内に収まるようにする。
            int red  =120*(1+sin(ix*0.5));
            int green=120*(1+cos(iy*0.5));
            int blue =120*(1+sin(iy*0.2));
            //透明度の設定
            int alpha=255;
            //Qtの色のクラスに色を設定する。
            QColor color;
            color.setRgb(red,green,blue,alpha);
            //座標(ix, iy)の画素の色を設定する。
            image.setPixelColor(ix,iy,color);
        }
    }
    //graphicsViewにScene_を設定。
    ui->graphicsView->setScene(&Scene_);
    //Scene_をクリア
    Scene_.clear();
    //Scene_に登録するpixmapを作成
    QPixmap pixmap=QPixmap::fromImage(image);
    //Scene_に画像を登録
    Scene_.addPixmap(pixmap);
}

void MainWindow::on_pushButton_2_clicked()
{
    QColor color(255, 0,0);
    ui->textEdit->setTextBackgroundColor(color);
    ui->textEdit->setText("push button");
}
