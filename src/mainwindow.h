#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QMenuBar>
#include <QLineEdit>

#include <QString>
#include <QListWidget>

#include <QDir>

class MainWindow : public QMainWindow {

 public:
  explicit MainWindow(QWidget* parent=nullptr);


 private:
  QWidget* central_;
  QWidget* menuBar_;
  QLineEdit* pathLine_;

  QDir *currentDir_;
  QListWidget* filesList_;
  
};


#endif // MAINWINDOW_H