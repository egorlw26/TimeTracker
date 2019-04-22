#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tracker.h"
#include "thread"
#include "chrono"
#include "QtCore"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Tracker& getTracker() {return tracker;}

private slots:
    void Tick();

    void on_AddButton_clicked();

    void on_StopButton_clicked();

    void on_StartButton_clicked();

    void on_Finish_Button_clicked();

    void on_RemoveButton_clicked();

    void on_actionSave_triggered();

    void on_actionLoad_triggered();

private:
    Ui::MainWindow *ui;
private:
    Tracker tracker;
    QTimer *timer;
    bool needToRefreshNames;
};

#endif // MAINWINDOW_H
