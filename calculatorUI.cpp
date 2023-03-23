#include "ui_mainwindow.h"
#include "calculatorUI.h"
#include "eval.h"

CalculatorWindow::CalculatorWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initUI();
    initSignalSlots();
}

CalculatorWindow::~CalculatorWindow()
{
    delete ui;
}

void CalculatorWindow::initUI()
{
    QFont textEditFont("Microsoft Yahei", 25, 75);
    ui->label_down->setFont(textEditFont);
    ui->label_down->setAlignment(Qt::AlignRight);
    ui->label_up->setAlignment(Qt::AlignRight);
    setWindowTitle("Jiayin's Calculator");
    ui->label_down->setText("0");
}

void CalculatorWindow::initSignalSlots()
{
    connect(ui->btn_0,SIGNAL(clicked()),this,SLOT(clicked_key()));
    connect(ui->btn_1,SIGNAL(clicked()),this,SLOT(clicked_key()));
    connect(ui->btn_2,SIGNAL(clicked()),this,SLOT(clicked_key()));
    connect(ui->btn_3,SIGNAL(clicked()),this,SLOT(clicked_key()));
    connect(ui->btn_4,SIGNAL(clicked()),this,SLOT(clicked_key()));
    connect(ui->btn_5,SIGNAL(clicked()),this,SLOT(clicked_key()));
    connect(ui->btn_6,SIGNAL(clicked()),this,SLOT(clicked_key()));
    connect(ui->btn_7,SIGNAL(clicked()),this,SLOT(clicked_key()));
    connect(ui->btn_8,SIGNAL(clicked()),this,SLOT(clicked_key()));
    connect(ui->btn_9,SIGNAL(clicked()),this,SLOT(clicked_key()));
    connect(ui->btn_dot,SIGNAL(clicked()),this,SLOT(clicked_key()));
    connect(ui->btn_left,SIGNAL(clicked()),this,SLOT(clicked_key()));
    connect(ui->btn_right,SIGNAL(clicked()),this,SLOT(clicked_key()));
    connect(ui->btn_add,SIGNAL(clicked()),this,SLOT(clicked_key()));
    connect(ui->btn_sub,SIGNAL(clicked()),this,SLOT(clicked_key()));
    connect(ui->btn_mul,SIGNAL(clicked()),this,SLOT(clicked_key()));
    connect(ui->btn_div,SIGNAL(clicked()),this,SLOT(clicked_key()));
    connect(ui->btn_clear,SIGNAL(clicked()),this,SLOT(clicked_clear()));
    connect(ui->btn_equ,SIGNAL(clicked()),this,SLOT(clicked_equ()));
}

void CalculatorWindow::clicked_key()
{
    QPushButton *button = (QPushButton *)sender();
    ui->label_down->setText(button->text());
    ui->label_up->setText(ui->label_up->text() + button->text());
}

void CalculatorWindow::clicked_clear()
{
    ui->label_down->setText("0");
    ui->label_up->clear();
}

void CalculatorWindow::clicked_equ()
{
    ui->label_up->setText(ui->label_up->text() + "=");
    double result = Eval(ui->label_up->text().toStdString());
    ui->label_down->setText(QString::number(result));
}

void CalculatorWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_0:
            emit ui->btn_0->clicked();
            break;
        case Qt::Key_1:
            emit ui->btn_1->clicked();
            break;
        case Qt::Key_2:
            emit ui->btn_2->clicked();
            break;
        case Qt::Key_3:
            emit ui->btn_3->clicked();
            break;
        case Qt::Key_4:
            emit ui->btn_4->clicked();
            break;
        case Qt::Key_5:
            emit ui->btn_5->clicked();
            break;
        case Qt::Key_6:
            emit ui->btn_6->clicked();
            break;
        case Qt::Key_7:
            emit ui->btn_7->clicked();
            break;
        case Qt::Key_8:
            emit ui->btn_8->clicked();
            break;
        case Qt::Key_9:
            emit ui->btn_9->clicked();
            break;

        case Qt::Key_Plus:
            emit ui->btn_add->clicked();
            break;
        case Qt::Key_Minus:
            emit ui->btn_sub->clicked();
            break;
        case Qt::Key_Asterisk:
            emit ui->btn_mul->clicked();
            break;
        case Qt::Key_Slash:
            emit ui->btn_div->clicked();
            break;
        case Qt::Key_Period:
            emit ui->btn_dot->clicked();
            break;
        case Qt::Key_Delete:
            emit ui->btn_clear->clicked();
            break;
        case Qt::Key_ParenLeft:
            emit ui->btn_left->clicked();
            break;
        case Qt::Key_ParenRight:
            emit ui->btn_right->clicked();
            break;
        case Qt::Key_Enter:
        case Qt::Key_Equal:
            emit ui->btn_equ->clicked();
            break;

        default:
            break;
    }
}

