#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "client.h"
#include "carte_fidelite.h"
#include<QIcon>
#include <QPropertyAnimation>
#include <QPixmap>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_AjouterClient_clicked();

    void on_closeClient_2_clicked();

    void on_ajouter_clicked();

    void Afficher_Client_Table();
    void on_AfficherClient_activated(const QModelIndex &index);

    void on_ModifierClient_2_clicked();

    void on_SupprimerClient_2_clicked();

    void on_ModifierClient_3_clicked();

    void on_modifier_clicked();

    void on_recherchecase_3_cursorPositionChanged(int arg1, int arg2);
    void refraiche();
    void Afficher_Client_Table2();
    void Afficher_Carte_Table();

    void on_AfficherClient2_activated(const QModelIndex &index);

    void on_recherchecase_4_cursorPositionChanged(int arg1, int arg2);

    void on_ajouter_carte_2_clicked();

    void on_refrech2_clicked();

    void on_refrech_clicked();

    void on_AfficheCarteFidelite_2_activated(const QModelIndex &index);

    void on_SupprimerCarte_2_clicked();

    void on_close_2_clicked();

    void on_close_b_clicked();

    void on_filtrer_2_clicked();

    void on_envoyer_mail_2_clicked();

private:
    Ui::MainWindow *ui;
    client tmpc;
    carte_fidelite tmpf;

    QPropertyAnimation *animation;

};
#endif // MAINWINDOW_H
