#include "mainwindow.h"

#include <QStatusBar>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {

  // getting current directory and files from where
  currentDir_ = new QDir(QDir::homePath());
  const QStringList names = currentDir_->entryList(
    QDir::Dirs | QDir::Files, QDir::DirsFirst | QDir::Name | QDir::IgnoreCase
  );

  // show files  
  filesList_ = new QListWidget(this);
  filesList_->addItems(names);
  setCentralWidget(filesList_);
  connect(filesList_, &QListWidget::itemDoubleClicked, this, 
    [this](QListWidgetItem *item){
      statusBar()->showMessage(item->text(), 2000);
  });


  // path line 
  menuBar_ = new QWidget(this);
  setMenuWidget(menuBar_);
  QHBoxLayout *menuBarPanel = new QHBoxLayout(menuBar_);
  menuBar_->setLayout(menuBarPanel);
  pathLine_ = new QLineEdit(this);
  pathLine_->setFocusPolicy(Qt::ClickFocus);
  pathLine_->setText(currentDir_->absolutePath());
  menuBarPanel->addWidget(pathLine_);


}