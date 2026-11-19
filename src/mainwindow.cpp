#include "mainwindow.h"

#include <QStatusBar>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {


  filesList_ = new QListWidget;
  setCentralWidget(filesList_);

  // path line 
  menuBar_ = new QWidget(this);
  setMenuWidget(menuBar_);
  QHBoxLayout *menuBarPanel = new QHBoxLayout(menuBar_);
  menuBar_->setLayout(menuBarPanel);
  pathLine_ = new QLineEdit(this);
  pathLine_->setFocusPolicy(Qt::ClickFocus);
  menuBarPanel->addWidget(pathLine_);

  connect(filesList_, &QListWidget::itemActivated, this,
  [this](QListWidgetItem* item) {
    if (item->text() == "..") {
      QDir parent = currentDir_;
      if (parent.cdUp())
        openDirectory(parent.absolutePath());
      return;
    }
    const QString path = currentDir_.filePath(item->text());
    if (QFileInfo(path).isDir())
      openDirectory(path);
  });
  connect(pathLine_, &QLineEdit::returnPressed, this, 
    [this] {
      openDirectory(pathLine_->text());
  });
  openDirectory(QDir::homePath());
}

void MainWindow::openDirectory(const QString& path) {
    if(path.isEmpty()) {
      return;
    }
    const QString input = QDir::fromNativeSeparators(path);
    QString absolutePath = (QDir::isAbsolutePath(input) ? input : currentDir_.absoluteFilePath(input));

    if(!QDir(absolutePath).exists()) {
      statusBar()->showMessage(tr("Не удалось открыть папку"), 3000);
      return;
    }
    
    absolutePath = QDir::cleanPath(absolutePath);
    currentDir_ = QDir(absolutePath);
    pathLine_->setText(currentDir_.absolutePath());
    
    // getting file names from dir
    const QStringList names = currentDir_.entryList(
      QDir::Dirs | QDir::Files | QDir::NoDot, QDir::DirsFirst | QDir::Name | QDir::IgnoreCase 
    );
    filesList_->clear();
    filesList_->addItems(names);
    
  }