#ifndef UI1_H
#define UI1_H

#include <QDialog>

namespace Ui {
class ui1;
}

class ui1 : public QDialog
{
    Q_OBJECT

public:
    explicit ui1(QWidget *parent = nullptr);
    ~ui1();

private slots:
    void on_pushButton_clicked();

    void on_hid2_customContextMenuRequested(const QPoint &pos);

    void on_gav_clicked();

private:
    Ui::ui1 *ui;
};

#endif // UI1_H
