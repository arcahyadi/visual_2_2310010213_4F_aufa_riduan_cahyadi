#include "formkamuspenyakit.h"
#include "ui_formkamuspenyakit.h"

formKamusPenyakit::formKamusPenyakit(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::formKamusPenyakit)
{
    ui->setupUi(this);

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

formKamusPenyakit::~formKamusPenyakit()
{
    delete ui;
}

void formKamusPenyakit::on_pushButton_clicked()
{
    QSqlQuery sql(koneksi);
    sql.prepare("INSERT INTO kamus_penyakit (penyakit_id,nama_penyakit,obat,deskripsi)"
                "VALUES(:penyakit_id,:nama_penyakit,:obat,:deskripsi)");
    sql.bindValue(":penyakit_id",ui->penyakitIDLineEdit->text().toInt());
    sql.bindValue(":nama_penyakit",ui->namaPenyakitLineEdit->text());
    sql.bindValue(":obat",ui->obatLineEdit->text());
    sql.bindValue(":deskripsi",ui->deskripsiLineEdit->text());
    if (!sql.exec()) {
        qDebug() << "Error executing query:" << sql.lastError().text();
        qDebug()<<sql.executedQuery();
    } else {
        qDebug() << "Insertion successful!";
    }
}


void formKamusPenyakit::on_pushButton_2_clicked()
{
    QSqlQuery sql(koneksi);
    sql.prepare("UPDATE kamus_penyakit SET nama_penyakit=:nama_penyakit,obat=:obat, deskripsi=:deskripsi where penyakit_id=:penyakit_id ");
    sql.bindValue(":penyakit_id",ui->penyakitIDLineEdit->text().toInt());
    sql.bindValue(":nama_penyakit",ui->namaPenyakitLineEdit->text());
    sql.bindValue(":obat",ui->obatLineEdit->text());
    sql.bindValue(":deskripsi",ui->deskripsiLineEdit->text());
    if (sql.exec()){
        qDebug()<<"Data Berhasil Di ubah";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void formKamusPenyakit::on_pushButton_3_clicked()
{
    QSqlQuery sql(koneksi);
    sql.prepare("DELETE FROM kamus_penyakit WHERE penyakit_id=:penyakit_id");
    sql.bindValue(":penyakit_id",ui->penyakitIDLineEdit->text().toInt());

    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Hapus";
    }else{
        qDebug()<<sql.lastError().text();
    }
}

