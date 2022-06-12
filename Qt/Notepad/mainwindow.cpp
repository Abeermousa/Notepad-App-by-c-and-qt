#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QFile>
#include<QFileDialog>
#include<QTextStream>
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit); //to remove space from each side in textedit
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
file_path_="";
ui->textEdit->setText("");
}


void MainWindow::on_actionOpen_triggered()
{
    //decler qString varible which will use save the file name
  QString file_name=QFileDialog::getOpenFileName(this,"open the file");
  QFile file(file_name); //decler object of qfile
  file_path_=file_name;
  if(!file.open(QFile::ReadOnly|QFile::Text)){

  //will check if this file is open or not and thenmake two flags readonly and second text file
      //if is file not open then we just show some message(include QMessage)
      QMessageBox::warning(this,"..","file not open");
      return;
     }
  QTextStream in(&file);
  QString text=in.readAll();
  ui->textEdit->setText(text);
  file.close();
}


void MainWindow::on_actionSave_triggered()
{


  QFile file(file_path_); //decler object of qfile
  if(!file.open(QFile::WriteOnly|QFile::Text)){

  //will check if this file is open or not and thenmake two flags readonly and second text file
      //if is file not open then we just show some message(include QMessage)
      QMessageBox::warning(this,"..","file not open");
      return;
     }
  QTextStream out(&file);
  QString text=ui->textEdit->toPlainText();
  out<<text;
  file.flush();
  file.close();
}


void MainWindow::on_actionSave_as_triggered()
{
    //decler qString varible which will use save the file name
  QString file_name=QFileDialog::getSaveFileName(this,"open the file");
  QFile file(file_name); //decler object of qfile
  file_path_=file_name;
  if(!file.open(QFile::WriteOnly|QFile::Text)){

  //will check if this file is open or not and thenmake two flags readonly and second text file
      //if is file not open then we just show some message(include QMessage)
      QMessageBox::warning(this,"..","file not open");
      return;
     }
  QTextStream out(&file);
  QString text=ui->textEdit->toPlainText();
  out<<text;
  file.flush();
  file.close();
}


void MainWindow::on_actionCut_triggered()
{
ui->textEdit->cut();
}


void MainWindow::on_actionCopy_triggered()
{
ui->textEdit->copy();
}


void MainWindow::on_actionRedo_triggered()
{
ui->textEdit->redo();
}


void MainWindow::on_actionUndo_triggered()
{
ui->textEdit->undo();
}


void MainWindow::on_actionAboutNotepad_triggered()
{
    QString about_text;
    about_text="Auther: somebody\n";
    about_text += "Date: 20/8/2022\n";
    about_text += "(C) Notepad (R)\n";
    QMessageBox::about(this,"About Notpad",about_text);
}


void MainWindow::on_actionpaste_triggered()
{
    ui->textEdit->paste();
}

