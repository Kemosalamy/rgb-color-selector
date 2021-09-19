#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString getHexString(int value);

public slots:
    void updateColor();
    void copyHexColor();
    void keepWindowOnTop();

private:
    Ui::MainWindow *ui;
    QColor viewColor;
};
#endif // MAINWINDOW_H
