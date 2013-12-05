#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

class GLViewport;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void timeout();
    
private:
    Ui::MainWindow *ui;
    QTimer timer;
    GLViewport *widget;
};

#endif // MAINWINDOW_H
