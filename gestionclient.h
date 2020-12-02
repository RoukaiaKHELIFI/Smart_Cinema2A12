#ifndef GESTIONCLIENT_H
#define GESTIONCLIENT_H
#include "smtp.h"
#include <QDialog>
#include "client.h"
#include "carte_fidelite.h"
#include<QIcon>
#include <QPropertyAnimation>
#include <QPixmap>
namespace Ui {
class GestionClient;
}

class GestionClient : public QDialog
{
    Q_OBJECT

public:
    explicit GestionClient(QWidget *parent = nullptr);
    ~GestionClient();

private slots:
    void on_ajouter_carte_clicked();

    void on_ajouterClient_clicked();

    void on_modifierClient_clicked();

    void on_SupprimerClient_clicked();

    void on_filtrerClient_clicked();

    void on_recherchecase_3_cursorPositionChanged(int arg1, int arg2);

    void on_refresh_clicked();

    void on_closeClient_clicked();

    void on_AfficherClient_activated(const QModelIndex &index);
    void refraiche();
    void Afficher_Client_Table2();
    void Afficher_Carte_Table();
    void Afficher_Client_Table();

    void on_SupprimerCarte_clicked();

    void on_modifier_carte_clicked();

    void on_refrech2_clicked();

    void on_AfficheCarteFidelite_2_activated(const QModelIndex &index);

    void on_AfficherClient2_activated(const QModelIndex &index);

    void on_recherchecase_4_cursorPositionChanged(int arg1, int arg2);

    void on_recherchecase_5_cursorPositionChanged(int arg1, int arg2);

    void on_close_2_clicked();

    void on_envoyer_mail_clicked();

private:
    Ui::GestionClient *ui;
    client tmpc;
    carte_fidelite tmpf;
    QPropertyAnimation *animation;
    void sendMail(QString subject , QString msg){
               Smtp* smtp = new Smtp("nasreddine.elmadhkour@esprit.tn","191JFT2263","smtp.gmail.com", 465);
               connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
               smtp->sendMail("nasreddine.elmadhkour@esprit.tn", "nasreddine1234@gmail.com" , subject,msg);}
       void mailSent(QString);

};

#endif // GESTIONCLIENT_H
