#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
// defining the action of New icon
void MainWindow::on_actionNew_triggered()
{
    //Clear the screen
        currentFile.clear();
        //Create a new text window
        ui->textEdit->setText(QString());
}
// defining the action of Open icon
void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open the File");
        QFile file(fileName);
        currentFile = fileName;
        if (!file.open(QIODevice::ReadOnly | QFile::Text))
        {
            QMessageBox::warning(this, "Warning", "Can NOT open file: " + file.errorString());
        }
        setWindowTitle(fileName);
        QTextStream in(&file);
        QString text = in.readAll();
        ui->textEdit->setText(text);
        file.close();
}
// defining the action of Save icon
void MainWindow::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save the File");
       QFile file(fileName);
       if (!file.open(QFile::WriteOnly | QFile::Text))
       {
           QMessageBox::warning(this, "Warning", "Can NOT save file: " + file.errorString());
       }
       currentFile = fileName;
       setWindowTitle(fileName);
       QTextStream out(&file);

       //Copy text in textEdit widget convert to plain text
       QString text = ui->textEdit->toPlainText();

       //Write to File then Close file
       out << text;
       file.close();
}
// defining the action of Exit icon
void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}
// defining the action of Copy icon
void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}
// defining the action of Paste icon
void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}
// defining the action of Undo icon
void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}
// defining the action of Redo icon
void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}
