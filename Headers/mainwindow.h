#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tracker.h"
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
    Tracker& getTracker() {return m_tracker;}

private slots:
    void Tick();

    void Create(){};

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
    Tracker m_tracker;
    QTimer* mp_timer;
    bool needToRefreshNames;
};

#endif // MAINWINDOW_H
