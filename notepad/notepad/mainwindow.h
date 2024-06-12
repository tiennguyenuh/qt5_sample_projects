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

private slots:
    void setupIconPath();
    void on_actionNew_triggered();

    void on_actionSave_triggered();

    void on_actionSave_as_triggered();

    void on_actionOpen_triggered();

    void on_actionExit_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionFind_triggered();

    void on_actionReplace_triggered();

    void on_actionAbout_Notepad_triggered();

private:
    Ui::MainWindow *ui;
    bool isOpened;
    QString currentFileOpening;
};
#endif // MAINWINDOW_H
