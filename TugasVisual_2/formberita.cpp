#include "formberita.h"
#include "ui_formberita.h"

formBerita::formBerita(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::formBerita)
{
    ui->setupUi(this);

    koneksi = QSqlDatabase::addDatabase("QODBC");
    koneksi.setDatabaseName("visual_2");
    koneksi.setUserName("root");
    koneksi.setPassword("");

    if (koneksi.open()){
        qDebug()<<"Database terkoneksi";
    }else{
        qDebug()<<koneksi.lastError().text();
    }
}

formBerita::~formBerita()
{
    delete ui;
}

void formBerita::on_pushButton_clicked()
{
    // QSqlQuery sql(koneksi);
    // if (!sql.exec("INSERT INTO berita (berita_id, nama_berita, isi_berita, jenis_berita)"
    //             "VALUE('100142','anwar','BJM','Hewan')")){
    //     qDebug()<<sql.lastError().text();
    // }else{
    //     qDebug()<<"Data Berhasil Disimpan";
    // }

    QString beritaIdText = ui->iDberitaLineEdit->text();
    QString namaBeritaText = ui->namaBeritaLineEdit->text();
    QString isiBeritaText = ui->isiBeritaLineEdit->text();
    QString jenisBeritaText = ui->jenisBeritaLineEdit->text();

    if (beritaIdText.isEmpty() || namaBeritaText.isEmpty() || isiBeritaText.isEmpty() || jenisBeritaText.isEmpty()) {
        qDebug() << "Error: One or more fields are empty!";
        return;
    } else {
        qDebug() << "Variable Terisi";
    }

    int beritaId = beritaIdText.toInt();

    QSqlQuery sql(koneksi);
    sql.prepare("INSERT INTO berita (berita_id, nama_berita, isi_berita, jenis_berita)"
                "VALUE(:berita_id, :nama_berita, :isi_berita, :jenis_berita)");
    sql.bindValue(":berita_id", beritaId);
    sql.bindValue(":nama_berita", namaBeritaText);
    sql.bindValue(":isi_berita", isiBeritaText);
    sql.bindValue(":jenis_berita", jenisBeritaText);

    // qDebug() << "Prepared query:" << sql.executedQuery();
    qDebug() << "Isi variable: berita_id=" << beritaId
             << ", nama_berita=" << namaBeritaText
             << ", isi_berita=" << isiBeritaText
             << ", jenis_berita=" << jenisBeritaText;

    if (!sql.exec()) {
        qDebug() << "Error executing query:" << sql.lastError().text();
        qDebug() << sql.executedQuery();
        qDebug() << koneksi.databaseName();
    } else {
        qDebug() << "Insertion successful!";
    }

}


void formBerita::on_pushButton_2_clicked()
{
    QSqlQuery sql(koneksi);
    sql.prepare("UPDATE berita SET nama_berita=:nama_berita,isi_berita=:isi_berita, jenis_berita=:jenis_berita where berita_id=:berita_id ");
    sql.bindValue(":berita_id",ui->iDberitaLineEdit->text().toInt());
    sql.bindValue(":nama_berita",ui->namaBeritaLineEdit->text());
    sql.bindValue(":isi_berita",ui->isiBeritaLineEdit->text());
    sql.bindValue(":jenis_berita",ui->jenisBeritaLineEdit->text());
    if (sql.exec()){
        qDebug()<<"Data Berhasil Di ubah";
    }else{
        qDebug()<<sql.lastError().text();
        qDebug()<<sql.executedQuery();
    }
}


void formBerita::on_pushButton_3_clicked()
{
    QSqlQuery sql(koneksi);
    sql.prepare("DELETE FROM berita WHERE berita_id=:berita_id");
    sql.bindValue(":berita_id",ui->iDberitaLineEdit->text().toInt());

    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Hapus";
    }else{
        qDebug()<<sql.lastError().text();
    }
}

