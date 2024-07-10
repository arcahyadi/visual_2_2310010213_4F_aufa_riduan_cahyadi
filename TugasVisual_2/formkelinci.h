#ifndef FORMKELINCI_H
#define FORMKELINCI_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

namespace Ui {
class formKelinci;
}

class formKelinci : public QMainWindow
{
    Q_OBJECT

public:
    explicit formKelinci(QWidget *parent = nullptr);
    ~formKelinci();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::formKelinci *ui;
    QSqlDatabase koneksi;
};

#endif // FORMKELINCI_H
