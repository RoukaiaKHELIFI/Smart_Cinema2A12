#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"employe.h"
#include"client.h"
#include"carte_fidelite.h"
#include"film.h"
#include"ticket.h"
#include <QMessageBox>
#include <QMediaPlayer>
#include "QTimer"
#include <QMainWindow>
#include<QIcon>
#include <QPropertyAnimation>
#include"salle.h"
#include"reservation.h"
#include <QFile>

#include "ui_mainwindow.h"
#include <QTextDocument>
#include <QMainWindow>
#include <QPixmap>
#include <QIcon>
#include<QPropertyAnimation>
//test
#include <QSqlTableModel>
#include "smtp.h"
#include <QRandomGenerator>
#include <QRandomGenerator64>
#include <QFileDialog>
#include <QRandomGenerator>
#include "random.h"
#include <QTranslator>
#include <QInputDialog>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
QString id_Reser="55012";
private slots:
    void on_AjouterClient_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_AjouterFilm_clicked();

    void on_ModifierFilm_clicked();

    void on_SupprimerFilm_clicked();

    void on_refresh_clicked();

    void on_recherche_cursorPositionChanged();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_Close_2_clicked();

    void on_returnF_clicked();

    void on_ajouterTicket_clicked();

    void on_ModifierTicket_clicked();

    void on_SupprimerTicket_clicked();

    void on_refreshT_clicked();

    void on_recherchecase_2_cursorPositionChanged();

    void on_Close_ticket_clicked();

    void on_returnTick_clicked();

    void on_Close_ticket_2_clicked();

    void on_AfficherFilmTable_activated(const QModelIndex &index);

    void on_AfficherTicketTable_activated(const QModelIndex &index);

    void on_ajouterClient_clicked();

    void on_modifierClient_clicked();

    void on_AfficherClient_activated();

    void on_SupprimerClient_clicked();

    void refraiche();

    void Afficher_Client_Table2();
    void Afficher_Carte_Table();
    void Afficher_Client_Table();
    void on_ajouter_carte_clicked();

    void on_filtrerClient_clicked();

    void on_recherchecase_3_cursorPositionChanged();

    void on_refresh_2_clicked();

    void on_closeClient_clicked();

    void on_SupprimerCarte_clicked();

    void on_modifier_carte_clicked();

    void on_refrech2_clicked();

    void on_AfficheCarteFidelite_2_activated();

    void on_AfficherClient2_activated();

    void on_recherchecase_4_cursorPositionChanged();

    void on_recherchecase_5_cursorPositionChanged();

    void on_close_2_clicked();

    void on_return_2_clicked();

    void on_return_ticket_clicked();

    void on_Return2_clicked();

    void on_triperso_2_clicked();

    void on_trier_clicked();

    void on_triperso_clicked();

    void on_trier_client_clicked();

    void on_triperso_3_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_13_clicked();

    void on_return_from_ajout_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_return_from_ajout_2_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_return_from_ajout_3_clicked();

    void on_pushButton_12_clicked();

    void on_affichage_salle_activated(const QModelIndex &index);

    void on_recherche_salle_cursorPositionChanged();

    void on_recherche_reservation_cursorPositionChanged();

    void on_pushButton_20_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_25_clicked();

    void on_return_from_ajout_4_clicked();


    void on_pushButton_27_clicked();

    void on_return_from_ajout_5_clicked();

    void on_pushButton_29_clicked();

    void on_return_from_ajout_6_clicked();

    void on_pushButton_28_clicked();

    void on_affichage_reservation_activated(const QModelIndex &index);

   void on_pushButton_23_clicked();

   void on_pushButton_32_clicked();

   void on_pushButton_31_clicked();

   void on_pushButton_33_clicked();

   void on_pushButton_34_clicked();

   void on_ajouter_res_clicked();



   void on_pushButton_24_clicked();


   void on_modif_res_clicked();



   void on_id_client_4_textChanged();

   void on_nb_personne_textChanged();


   void on_pushButton_26_clicked();

   void on_pushButton_35_clicked();

   void on_pushButton_36_clicked();


private:
    Ui::MainWindow *ui;
    client tmpc;
    carte_fidelite tmpf;
    QPropertyAnimation *animation;
    Film tmpF;
    Ticket empc;
    QPropertyAnimation *animation2;
    QPropertyAnimation *animation1;
    QMediaPlayer *musicConect=new QMediaPlayer;
    Salle Etmp;
    Reservation Etmp1;


};
#endif // MAINWINDOW_H
