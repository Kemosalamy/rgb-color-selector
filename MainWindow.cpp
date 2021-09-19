#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QBrush>
#include <QClipboard>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      viewColor(0,0,0,255)
{
    ui->setupUi(this);

    QGraphicsScene* myScene = new QGraphicsScene();
    ui->colorViewer->setScene(myScene);
    ui->colorViewer->setBackgroundBrush(viewColor);

    ui->hexLabel->setTextInteractionFlags(Qt::TextSelectableByMouse);

    ui->colorViewer->setMinimumWidth(144);
    ui->copyButton->setMinimumWidth(80);
    ui->copyButton->setMinimumHeight(60);
    ui->redSlider->setMinimumWidth(300);
    ui->blueSlider->setMinimumWidth(300);
    ui->greenSlider->setMinimumWidth(300);

    ui->redSlider->setMinimum(0);
    ui->redSlider->setMaximum(255);
    ui->redSlider->setTickInterval(1);
    ui->redSlider->setSingleStep(1);
    ui->redSlider->setTickPosition(QSlider::TicksAbove);

    ui->greenSlider->setMinimum(0);
    ui->greenSlider->setMaximum(255);
    ui->greenSlider->setTickInterval(1);
    ui->greenSlider->setSingleStep(1);
    ui->greenSlider->setTickPosition(QSlider::TicksAbove);

    ui->blueSlider->setMinimum(0);
    ui->blueSlider->setMaximum(255);
    ui->blueSlider->setTickInterval(1);
    ui->blueSlider->setSingleStep(1);
    ui->blueSlider->setTickPosition(QSlider::TicksAbove);

    connect(ui->redSlider,&QSlider::valueChanged,this, &MainWindow::updateColor);
    connect(ui->greenSlider,&QSlider::valueChanged,this, &MainWindow::updateColor);
    connect(ui->blueSlider,&QSlider::valueChanged,this, &MainWindow::updateColor);
    connect(ui->copyButton,&QPushButton::clicked,this, &MainWindow::copyHexColor);
    connect(ui->stayOnTopButton,&QPushButton::clicked,this,&MainWindow::keepWindowOnTop);

}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::getHexString(int value){
    char hex_array[2];
    sprintf(hex_array, "%X", value);
    QString hex_string = hex_array;
    hex_string = QString(2-hex_string.size(),'0') + hex_string;
    return hex_string;
}


void MainWindow::updateColor(){

    viewColor.setRgb(ui->redSlider->value(),ui->greenSlider->value(),ui->blueSlider->value());
    ui->colorViewer->setBackgroundBrush(viewColor);

    QString redValueString = QString("%1").arg(ui->redSlider->value());
    redValueString = QString(3-redValueString.size(),'0') + redValueString;
    ui->redLabel->setText("R - " + redValueString);

    QString greenValueString = QString("%1").arg(ui->greenSlider->value());
    greenValueString = QString(3-greenValueString.size(),'0') + greenValueString;
    ui->greenLabel->setText("G - " + greenValueString);

    QString blueValueString = QString("%1").arg(ui->blueSlider->value());
    blueValueString = QString(3-blueValueString.size(),'0') + blueValueString;
    ui->blueLabel->setText("B - " + blueValueString);

    QString hex_color = "#" + getHexString(ui->redSlider->value())
            + getHexString(ui->greenSlider->value())
            + getHexString(ui->blueSlider->value());

    ui->hexLabel->setText(hex_color);

}

void MainWindow::copyHexColor(){
    QClipboard* clipboard = QApplication::clipboard();
    clipboard->setText(ui->hexLabel->text());
}

void MainWindow::keepWindowOnTop(){
    if(this->windowFlags()&Qt::WindowStaysOnTopHint) this->setWindowFlags(this->windowFlags()^Qt::WindowStaysOnTopHint);
    else this->setWindowFlags(Qt::WindowStaysOnTopHint);
    this->show();
}








