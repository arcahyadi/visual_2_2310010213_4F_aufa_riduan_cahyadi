#include "formraskelinci.h"
#include "ui_formraskelinci.h"

formRasKelinci::formRasKelinci(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::formRasKelinci)
{
    ui->setupUi(this);

    koneksi = QSqlDatabase::addDatabase("QODBC");
    koneksi.setDatabaseName("visual_2");
    koneksi.setUserName("root");
    koneksi.setPassword("");

    if (koneksi.open()){
        qDebug()<<"Database terkoneksi";
        qDebug()<<koneksi.databaseName();
    }else{
        qDebug()<<koneksi.lastError().text();
    }
}

formRasKelinci::~formRasKelinci()
{
    delete ui;
}

void formRasKelinci::on_pushButton_clicked()
{
    QString rasIdText = ui->rasIDLineEdit->text();
    QString namaRasText = ui->namaRasLineEdit->text();
    QString ciriRasText = ui->ciriRasLineEdit->text();

    if (rasIdText.isEmpty() || namaRasText.isEmpty() || ciriRasText.isEmpty()) {
        qDebug() << "Error: One or more fields are empty!";
        return;
    } else {
        qDebug() << "Variable Terisi";
    }

    int rasId = rasIdText.toInt();

    QSqlQuery sql(koneksi);
    sql.prepare("INSERT INTO ras (ras_id, nama_ras, ciri_ras) "
                "VALUES (:ras_id, :nama_ras, :ciri_ras)");
    sql.bindValue(":ras_id", rasId);
    sql.bindValue(":nama_ras", namaRasText);
    sql.bindValue(":ciri_ras", ciriRasText);

    qDebug() << "Prepared query:" << sql.executedQuery();
    qDebug() << "Isi variable: ras_id=" << rasId
             << ", nama_ras=" << namaRasText
             << ", ciri_ras=" << ciriRasText;

    if (!sql.exec()) {
        qDebug() << "Error executing query:" << sql.lastError().text();
        qDebug() << sql.executedQuery();
    } else {
        qDebug() << "Insertion successful!";
    }

}

void formRasKelinci::on_pushButton_2_clicked()
{
    QString rasIdText = ui->rasIDLineEdit->text();
    QString namaRasText = ui->namaRasLineEdit->text();
    QString ciriRasText = ui->ciriRasLineEdit->text();

    if (rasIdText.isEmpty() || namaRasText.isEmpty() || ciriRasText.isEmpty()) {
        qDebug() << "Error: One or more fields are empty!";
        return;
    } else {
        qDebug() << "Variable Terisi";
    }

    int rasId = rasIdText.toInt();

    QSqlQuery sql(koneksi);
    sql.prepare("UPDATE ras SET nama_ras=:nama_ras, ciri_ras=:ciri_ras WHERE ras_id=:ras_id");
    sql.bindValue(":ras_id", rasId);
    sql.bindValue(":nama_ras", namaRasText);
    sql.bindValue(":ciri_ras", ciriRasText);

    qDebug() << "Prepared query:" << sql.executedQuery();
    qDebug() << "Isi variable: ras_id=" << rasId
             << ", nama_ras=" << namaRasText
             << ", ciri_ras=" << ciriRasText;

    if (!sql.exec()) {
        qDebug() << "Error executing query:" << sql.lastError().text();
        qDebug() << sql.executedQuery();
    } else {
        qDebug() << "Update successful!";
    }
}

void formRasKelinci::on_pushButton_3_clicked()
{
    QSqlQuery sql(koneksi);
    sql.prepare("DELETE FROM ras WHERE ras_id=:ras_id");
    sql.bindValue(":ras_id",ui->rasIDLineEdit->text().toInt());

    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Hapus";
    }else{
        qDebug()<<sql.lastError().text();
    }
}
