#include "formkelinci.h"
#include "ui_formkelinci.h"

formKelinci::formKelinci(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::formKelinci)
{
    ui->setupUi(this);
}

formKelinci::~formKelinci()
{
    delete ui;

    QSqlDatabase koneksi = QSqlDatabase::addDatabase("QODBC");
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

void formKelinci::on_pushButton_clicked()
{
    QString kelinciIdText = ui->kelinciIDLineEdit->text();
    QString namaKelinciText = ui->namaKelinciLineEdit->text();
    QString beratKelinciText = ui->beratKelinciLineEdit->text();
    QString genderKelinciText = ui->genderKelinciLineEdit->text();
    QString hargaKelinciText = ui->hargaKelinciLineEdit->text();
    QString rasKelinciText = ui->rasKelinciLineEdit->text();
    QString tglLahirText = ui->tanggalLahirEdit->text();
    QString lokasiText = ui->lokasiLineEdit->text();
    QString statusText = ui->statusLineEdit->text();

    // if (kelinciIdText.isEmpty() || namaKelinciText.isEmpty() || beratKelinciText.isEmpty() || genderKelinciText.isEmpty() ||
    //     hargaKelinciText.isEmpty() || rasKelinciText.isEmpty() || tglLahirText.isEmpty() || lokasiText.isEmpty() || statusText.isEmpty()) {
    //     qDebug() << "Error: One or more fields are empty!";
    //     return;
    // }

    // Convert date to correct format
    QDate tglLahir = QDate::fromString(tglLahirText, "d/M/yyyy");
    if (!tglLahir.isValid()) {
        qDebug() << "Error: Invalid date format!";
        qDebug() <<tglLahirText;
        qDebug() <<tglLahir;
        return;
    }

    QString tglLahirFormatted = tglLahir.toString("yyyy-MM-dd");

    QSqlQuery sql(koneksi);
    sql.prepare("INSERT INTO kelinci (kelinci_id, nama_kelinci, berat_kelinci, gender_kelinci, harga_kelinci, ras_kelinci, tgl_lahir, lokasi, status) "
                "VALUES (:kelinci_id, :nama_kelinci, :berat_kelinci, :gender_kelinci, :harga_kelinci, :ras_kelinci, :tgl_lahir, :lokasi, :status)");
    sql.bindValue(":kelinci_id", kelinciIdText.toInt());
    sql.bindValue(":nama_kelinci", namaKelinciText);
    sql.bindValue(":berat_kelinci", beratKelinciText);
    sql.bindValue(":gender_kelinci", genderKelinciText);
    sql.bindValue(":harga_kelinci", hargaKelinciText);
    sql.bindValue(":ras_kelinci", rasKelinciText);
    sql.bindValue(":tgl_lahir", tglLahirFormatted);
    sql.bindValue(":lokasi", lokasiText);
    sql.bindValue(":status", statusText);

    if (!sql.exec()) {
        qDebug() << "Error executing query:" << sql.lastError().text();
        qDebug() << sql.executedQuery();
    } else {
        qDebug() << "Insertion successful!";
    }
}



void formKelinci::on_pushButton_2_clicked()
{
    QString kelinciIdText = ui->kelinciIDLineEdit->text();
    QString namaKelinciText = ui->namaKelinciLineEdit->text();
    QString beratKelinciText = ui->beratKelinciLineEdit->text();
    QString genderKelinciText = ui->genderKelinciLineEdit->text();
    QString hargaKelinciText = ui->hargaKelinciLineEdit->text();
    QString rasKelinciText = ui->rasKelinciLineEdit->text();
    QString tglLahirText = ui->tanggalLahirEdit->text();
    QString lokasiText = ui->lokasiLineEdit->text();
    QString statusText = ui->statusLineEdit->text();

    // Uncomment for input validation
    // if (kelinciIdText.isEmpty() || namaKelinciText.isEmpty() || beratKelinciText.isEmpty() || genderKelinciText.isEmpty() ||
    //     hargaKelinciText.isEmpty() || rasKelinciText.isEmpty() || tglLahirText.isEmpty() || lokasiText.isEmpty() || statusText.isEmpty()) {
    //     qDebug() << "Error: One or more fields are empty!";
    //     return;
    // }

    // Convert date to correct format
    QDate tglLahir = QDate::fromString(tglLahirText, "d/M/yyyy");
    if (!tglLahir.isValid()) {
        qDebug() << "Error: Invalid date format!";
        qDebug() << "tglLahirText:" << tglLahirText;
        qDebug() << "tglLahir:" << tglLahir;
        return;
    }

    QString tglLahirFormatted = tglLahir.toString("yyyy-MM-dd");

    QSqlQuery sql(koneksi);
    sql.prepare("UPDATE kelinci SET nama_kelinci=:nama_kelinci, berat_kelinci=:berat_kelinci, gender_kelinci=:gender_kelinci, harga_kelinci=:harga_kelinci, ras_kelinci=:ras_kelinci, tgl_lahir=:tgl_lahir, lokasi=:lokasi, status=:status WHERE kelinci_id=:kelinci_id");
    sql.bindValue(":kelinci_id", kelinciIdText.toInt());
    sql.bindValue(":nama_kelinci", namaKelinciText);
    sql.bindValue(":berat_kelinci", beratKelinciText);
    sql.bindValue(":gender_kelinci", genderKelinciText);
    sql.bindValue(":harga_kelinci", hargaKelinciText);
    sql.bindValue(":ras_kelinci", rasKelinciText);
    sql.bindValue(":tgl_lahir", tglLahirFormatted);
    sql.bindValue(":lokasi", lokasiText);
    sql.bindValue(":status", statusText);

    if (!sql.exec()) {
        qDebug() << "Error executing query:" << sql.lastError().text();
        qDebug() << sql.executedQuery();
    } else {
        qDebug() << "Update successful!";
    }
}



void formKelinci::on_pushButton_3_clicked()
{
    QSqlQuery sql(koneksi);
    sql.prepare("DELETE FROM kelinci WHERE kelinci_id=:kelinci_id");
    sql.bindValue(":kelinci_id",ui->kelinciIDLineEdit->text().toInt());
    if (!sql.exec()) {
        qDebug() << "Error executing query:" << sql.lastError().text();
        qDebug()<<sql.executedQuery();
    } else {
        qDebug() << "Insertion successful!";
    }
}
