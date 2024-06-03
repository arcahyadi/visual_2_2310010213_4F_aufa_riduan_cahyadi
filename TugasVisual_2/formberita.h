#ifndef FORMBERITA_H
#define FORMBERITA_H

#include <QMainWindow>

namespace Ui {
class formBerita;
}

class formBerita : public QMainWindow
{
    Q_OBJECT

public:
    explicit formBerita(QWidget *parent = nullptr);
    ~formBerita();

private:
    Ui::formBerita *ui;
};

#endif // FORMBERITA_H
