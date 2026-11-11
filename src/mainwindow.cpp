#include "mainwindow.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  setWindowTitle("Explorer");
  resize(900, 600);

  // Основной контейнер с содержимым
  auto *central = new QWidget(this);
  setCentralWidget(central);

  auto *layout = new QVBoxLayout(central);

  auto addressBar = new QLineEdit(central);
  addressBar->setPlaceholderText("");
  
  auto *placeholder = new QLabel("Содержимое папки", central);

  placeholder->setAlignment(Qt::AlignCenter);

  layout->addWidget(addressBar);
  layout->addWidget(placeholder,1);
}