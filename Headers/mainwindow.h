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

public slots:
    void Tick();

    void CreateActivity(const QString i_name);

    void StartActivity();

    void PauseActivity();

    void RestartActivity();

    void RemoveActivity();

    void FinishActivity();

    void on_AddButton_clicked();

    void on_actionSave_triggered();

    void on_actionLoad_triggered();

private:
    Ui::MainWindow *ui;
private:
    Tracker m_tracker;
    QTimer* mp_timer;
    bool needToRefreshNames;
    bool needToRefreshStatuses;
};

#endif // MAINWINDOW_H
