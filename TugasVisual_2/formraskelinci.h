#ifndef FORMRASKELINCI_H
#define FORMRASKELINCI_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

namespace Ui {
class formRasKelinci;
}

class formRasKelinci : public QMainWindow
{
    Q_OBJECT

public:
    explicit formRasKelinci(QWidget *parent = nullptr);
    ~formRasKelinci();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::formRasKelinci *ui;
    QSqlDatabase koneksi;
};

#endif // FORMRASKELINCI_H
