// pb_21_100.cpp
// Горбацевич Андрей
#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "dbmanager.cpp"

#include <QIODevice>
#include <QMessageBox>
#include <QString>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    ui->modeButtonGroup->setId(ui->mode1RadioButton, 1);
    ui->modeButtonGroup->setId(ui->mode2RadioButton, 2);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_execPushButton_clicked() {
    nuark::DBManager manager;

    QString out_text;
    QTextStream ost(&out_text, QIODevice::WriteOnly);
    ost << tr("Текстовый файл: ") << ui->textFileLineEdit->text() << "\n"
        << tr("Двоичный файл: ") << ui->binFileLineEdit->text() << "\n"
        << tr("Режим: ") << ui->modeButtonGroup->checkedId() << "\n";

    switch (ui->modeButtonGroup->checkedId()) {
        case 1:
            manager.first_mode(
                    ui->textFileLineEdit->text(),
                    ui->binFileLineEdit->text(),
                    ost
            );
            break;
        case 2:
            manager.second_mode(ui->binFileLineEdit->text(), ost);
            break;
        default:
            ost << "No way!\n";
    }

    ui->outTextEdit->setPlainText(out_text);
}
