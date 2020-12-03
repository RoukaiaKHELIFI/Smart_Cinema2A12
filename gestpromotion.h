#ifndef GESTPROMOTION_H
#define GESTPROMOTION_H

#include <QDialog>
#include "sponsorisation.h"
namespace Ui {
class gestpromotion;
}

class gestpromotion : public QDialog
{
    Q_OBJECT

public:
    explicit gestpromotion(QWidget *parent = nullptr);
    ~gestpromotion();

private slots:
    void on_btn_ajouters_clicked();

    void on_btn_supprimers_clicked();

    void on_btn_modifiers_clicked();

    void on_btn_pdfs_clicked();

    void on_tn_tri_noms_clicked();

    void on_btn_tri_num_s_clicked();

    void on_tn_refreshs_clicked();

    void on_btn_cherchers_clicked();

private:
    Ui::gestpromotion *ui;
    Sponsorisation tmpsp;
};

#endif // GESTPROMOTION_H
