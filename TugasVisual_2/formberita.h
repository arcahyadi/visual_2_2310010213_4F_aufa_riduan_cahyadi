#ifndef FORMBERITA_H
#define FORMBERITA_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

namespace Ui {
class formBerita;
}

class formBerita : public QMainWindow
{
    Q_OBJECT

public:
    explicit formBerita(QWidget *parent = nullptr);
    ~formBerita();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::formBerita *ui;
    QSqlDatabase koneksi;
    QSqlQuery sql;
    QSqlRecord cari;
};

#endif // FORMBERITA_H
