#include "formberita.h"
#include "ui_formberita.h"

formBerita::formBerita(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::formBerita)
{
    ui->setupUi(this);

    QSqlDatabase Koneksi = QSqlDatabase::addDatabase("QODBC");
    Koneksi.setDatabaseName("visual_2");
    Koneksi.setUserName("root");
    Koneksi.setPassword("");

    if (Koneksi.open()){
        qDebug()<<"Database terkoneksi";
        qDebug()<<Koneksi.databaseName();
    }else{
        qDebug()<<Koneksi.lastError().text();
    }
}

formBerita::~formBerita()
{
    delete ui;
}

void formBerita::on_pushButton_clicked()
{

    QSqlQuery sql(Koneksi);
    sql.prepare("INSERT INTO berita (berita_id,nama_berita,isi_berita,jenis_berita)"
                "VALUES(:berita_id,:nama_berita,:isi_berita,:jenis_berita)");
    sql.bindValue(":berita_id",ui->iDberitaLineEdit->text().toInt());
    sql.bindValue(":nama_berita",ui->namaBeritaLineEdit->text());
    sql.bindValue(":isi_berita",ui->isiBeritaLineEdit->text());
    sql.bindValue(":jenis_berita",ui->jenisBeritaLineEdit->text());
    if (!sql.exec()) {
        qDebug() << "Error executing query:" << sql.lastError().text();
        qDebug()<<sql.executedQuery();
    } else {
        qDebug() << "Insertion successful!";
    }

}


void formBerita::on_pushButton_2_clicked()
{
    QSqlQuery sql(Koneksi);
    sql.prepare("UPDATE berita SET nama_berita=:nama_berita,isi_berita:=isi_berita, jenis_berita:=jenis_berita, where berita_id=:berita_id ");
    sql.bindValue(":berita_id",ui->iDberitaLineEdit->text().toInt());
    sql.bindValue(":nama_berita",ui->namaBeritaLineEdit->text());
    sql.bindValue(":isi_berita",ui->isiBeritaLineEdit->text());
    sql.bindValue(":jenis_berita",ui->jenisBeritaLineEdit->text());
    if (sql.exec()){
        qDebug()<<"Data Berhasil Di ubah";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void formBerita::on_pushButton_3_clicked()
{
    QSqlQuery sql(Koneksi);
    sql.prepare("DELETE FROM berita WHERE berita_id=:berita_id");
    sql.bindValue(":berita_id",ui->iDberitaLineEdit->text().toInt());

    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Hapus";
    }else{
        qDebug()<<sql.lastError().text();
    }
}

