#include "morse.h"
#include "MorseWorker.h"
#include "./ui_morse.h"
#include <windows.h>
#include <QThread>

QString text, WPM, pitch;
float baseTime;
int basePitch;

morse::morse(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::morse)
{
    ui->setupUi(this);
}

morse::~morse()
{
    delete ui;
}

void morse::on_pushButton_clicked()
{
    text = ui->textEdit->toPlainText();
    WPM = ui->lineEdit->text();
    pitch = ui->lineEdit_2->text();
    baseTime = (((60 * 1000) / WPM.toFloat()) / 5) / 10;//WPM转为单位长度
    basePitch = pitch.toInt();
    // 创建 worker 和线程
    MorseWorker *worker = new MorseWorker(text, baseTime, basePitch);
    QThread *thread = new QThread;
    // 将 worker 移动到新线程
    worker->moveToThread(thread);
    // 连接信号和槽
    connect(thread, &QThread::started, worker, &MorseWorker::process);
    connect(worker, &MorseWorker::finished, thread, &QThread::quit);
    connect(worker, &MorseWorker::finished, worker, &MorseWorker::deleteLater);
    connect(thread, &QThread::finished, thread, &QThread::deleteLater);
    // 启动线程
    thread->start();
}

