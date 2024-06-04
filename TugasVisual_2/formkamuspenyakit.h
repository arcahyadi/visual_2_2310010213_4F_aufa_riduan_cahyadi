#ifndef FORMKAMUSPENYAKIT_H
#define FORMKAMUSPENYAKIT_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

namespace Ui {
class formKamusPenyakit;
}

class formKamusPenyakit : public QMainWindow
{
    Q_OBJECT

public:
    explicit formKamusPenyakit(QWidget *parent = nullptr);
    ~formKamusPenyakit();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::formKamusPenyakit *ui;
    QSqlDatabase koneksi;
};

#endif // FORMKAMUSPENYAKIT_H
