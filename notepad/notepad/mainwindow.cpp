#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QClipboard>
#include <QTextDocument>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    ui->actionNew->setIcon(QIcon("ui/assets/new.png"));
//    ui->actionOpen->setIcon(QIcon("assets/open.png"));
//    ui->actionSave->setIcon(QIcon("assets/save.png"));
//    ui->actionSave_as->setIcon(QIcon("assets/save_as.png"));
//    ui->actionExit->setIcon(QIcon("assets/exit.png"));
//    ui->actionCopy->setIcon(QIcon("assets/copy.png"));
//    ui->actionPaste->setIcon(QIcon("assets/paste.png"));
//    ui->actionFind->setIcon(QIcon("assets/find.png"));
//    ui->actionReplace->setIcon(QIcon("assets/replace.png"));
//    ui->actionAbout_Notepad->setIcon(QIcon("assets/about.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupIconPath()
{
    ui->actionNew->setIcon(QIcon("assets/new.png"));
    ui->actionOpen->setIcon(QIcon("assets/open.png"));
    ui->actionSave->setIcon(QIcon("assets/save.png"));
    ui->actionSave_as->setIcon(QIcon("assets/save_as.png"));
    ui->actionExit->setIcon(QIcon("assets/exit.png"));
    ui->actionCopy->setIcon(QIcon("assets/copy.png"));
    ui->actionPaste->setIcon(QIcon("assets/paste.png"));
    ui->actionFind->setIcon(QIcon("assets/find.png"));
    ui->actionReplace->setIcon(QIcon("assets/replace.png"));
    ui->actionAbout_Notepad->setIcon(QIcon("assets/about.png"));
}

void MainWindow::on_actionNew_triggered()
{
    ui->textEdit->setText("");
}

void MainWindow::on_actionOpen_triggered()
{
    MainWindow::isOpened = true;
    // QString = filename = QFileDialog::
    MainWindow::currentFileOpening = QFileDialog::getOpenFileName(this, "Open the file");

    QFile file(currentFileOpening);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    setWindowTitle(currentFileOpening);

    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
}

void MainWindow::on_actionSave_triggered()
{
    QString fileName = MainWindow::currentFileOpening;

    if (fileName.isEmpty()) {
        fileName = QFileDialog::getSaveFileName(this, "Save the file");
        MainWindow::currentFileOpening = fileName;
    }

    QFile file(fileName);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    setWindowTitle(fileName);

    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();
}

void MainWindow::on_actionSave_as_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save the file");

    QFile file(fileName);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    setWindowTitle(fileName);

    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;

    MainWindow::currentFileOpening = fileName;

    file.close();
}


void MainWindow::on_actionExit_triggered()
{
    qApp->exit();
}


void MainWindow::on_actionCopy_triggered()
{
    QClipboard *clipboard = QGuiApplication::clipboard();
    QString text = ui->textEdit->toPlainText();

    clipboard->setText(text);
}


void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}


void MainWindow::on_actionFind_triggered()
{

}

void MainWindow::on_actionReplace_triggered()
{

}

void MainWindow::on_actionAbout_Notepad_triggered()
{

}
