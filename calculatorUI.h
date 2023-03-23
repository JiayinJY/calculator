#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QKeyEvent>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class CalculatorWindow : public QMainWindow
{
    Q_OBJECT

public:
    CalculatorWindow(QWidget *parent = nullptr);
    ~CalculatorWindow();

private:
    Ui::MainWindow *ui;
    void initUI();
    void initSignalSlots();

private slots:
    void clicked_key();
    void clicked_clear();
    void clicked_equ();


protected:
    void keyPressEvent(QKeyEvent *event);
};
#endif // MAINWINDOW_H
