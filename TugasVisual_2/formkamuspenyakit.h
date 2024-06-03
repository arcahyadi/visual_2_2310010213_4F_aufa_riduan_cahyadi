#ifndef FORMKAMUSPENYAKIT_H
#define FORMKAMUSPENYAKIT_H

#include <QMainWindow>

namespace Ui {
class formKamusPenyakit;
}

class formKamusPenyakit : public QMainWindow
{
    Q_OBJECT

public:
    explicit formKamusPenyakit(QWidget *parent = nullptr);
    ~formKamusPenyakit();

private:
    Ui::formKamusPenyakit *ui;
};

#endif // FORMKAMUSPENYAKIT_H
