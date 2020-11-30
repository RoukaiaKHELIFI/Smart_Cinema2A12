#include "mainwindow.h"
#include "authentification.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include "carte_fidelite.h"

#include "QMessageBox"
#include "mainwindow.h"
#include <QString>
#include <QMessageBox>
#include "connexion.h"
#include "dialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->AfficherClient->setModel(tmpc.afficher_client());
    ui->AfficheCarteFidelite_2->setModel(tmpf.afficher_cartefidelite());
    ui->AfficherClient2->setModel(tmpc.afficher_client());
    Afficher_Client_Table();
    Afficher_Client_Table2();
    Afficher_Carte_Table();
    ui->id_carte->setVisible(false);
    ui->id_client->setVisible(false);
    ui->cin_client_ajouter->setValidator(new QIntValidator(0,99999999,this));
    ui->telephone_ajouter->setValidator(new QIntValidator(0,99999999,this));
    ui->AfficherClient->setModel(tmpc.afficher_client());
    setWindowIcon(QIcon("C:/Users/sinda/Desktop/projet 2a/popcornicon"));
    QPixmap pixel ("C:/Users/sinda/Desktop/projet 2a/popcornicon");
    ui->icon_2->setPixmap(pixel.scaled(200,100,Qt::KeepAspectRatio));
    int w= ui->icon_2->width();
    int h=ui->icon_2->height();

    animation=new QPropertyAnimation(ui->icon_2,"geometry");
    animation->setDuration(1999);
    animation->setStartValue(ui->icon_2->geometry());
    animation->setEndValue(QRect(1180,20,w,h));
    animation->setLoopCount(-1);
    animation->start();


    ui->id_client_2->setVisible(false);
    ui->cin_client_ajouter_2->setEnabled(false);
    ui->nom_ajouter_2->setEnabled(false);
    ui->prenom_ajouter_2->setEnabled(false);
    ui->telephone_ajouter_2->setEnabled(false);
    ui->adresse_ajouter_2->setEnabled(false);
    ui->mail_ajouter_2->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_AjouterClient_clicked()
{

}

void MainWindow::on_closeClient_2_clicked()
{
  close();
}

void MainWindow::on_ajouter_clicked()
{
    client c(ui->cin_client_ajouter->text().toInt(),ui->nom_ajouter->text(),ui->prenom_ajouter->text(),ui->dateNaissance_ajouter->date(),
             ui->telephone_ajouter->text().toInt(),ui->fontion_ajouter->currentText(),ui->adresse_ajouter->text()
             ,QDate::currentDate(),ui->mail_ajouter->text(),ui->genre_ajouter->currentText(),ui->etatcivil_ajouter->currentText());

    if (c.controle_saisie() == "")
    {

   QString str = " Vous voulez vraiment ajouter ce client:" ;
            int ret = QMessageBox::question(this, tr("enregistrement"),str,QMessageBox::Ok|QMessageBox::Cancel);

            switch (ret) {
              case QMessageBox::Ok:
            { if(c.getCin()==0 )//SI ELEVE
                {
                   if(! c.existe_client_tel() )
                       {     c.ajouter_client();
                          ui->AfficherClient->setModel(tmpc.afficher_client());
                          refraiche();
                       }
                   else
                       {
                          QMessageBox::critical(this,tr("erreure")," num tel existe !!");
                       }

                }
              else//mehouch eleve
                {
                    if (! c.existe_client_cin() && ! c.existe_client_tel() )
                    {
                        c.ajouter_client();
                        ui->AfficherClient->setModel(tmpc.afficher_client());
                        refraiche();
                    }
                    else
                    {
                        QMessageBox::critical(this,"/n erreure","/n cin exite ou num tel existe !!");
                    }
                }
            }
                     break;
              case QMessageBox::Cancel:

                  break;
              default:
                  // should never be reached
                  break;

            }}
    else {
        QMessageBox::critical(this,"erreure",c.controle_saisie());
    }

}



//selection de toute une ligne
void MainWindow::Afficher_Client_Table(){
   ui->AfficherClient->resizeColumnsToContents();
   ui->AfficherClient->resizeRowsToContents();
   ui->AfficherClient->setSelectionBehavior(QAbstractItemView::SelectRows);
   ui->AfficherClient->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed,QHeaderView::Stretch);
   ui->AfficherClient->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
}

void MainWindow::Afficher_Carte_Table(){
   ui->AfficheCarteFidelite_2->resizeColumnsToContents();
   ui->AfficheCarteFidelite_2->resizeRowsToContents();
   ui->AfficheCarteFidelite_2->setSelectionBehavior(QAbstractItemView::SelectRows);
   ui->AfficheCarteFidelite_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed,QHeaderView::Stretch);
   ui->AfficheCarteFidelite_2->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
}

void MainWindow::Afficher_Client_Table2(){
   ui->AfficherClient2->resizeColumnsToContents();
   ui->AfficherClient2->resizeRowsToContents();
   ui->AfficherClient2->setSelectionBehavior(QAbstractItemView::SelectRows);
   ui->AfficherClient2->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed,QHeaderView::Stretch);
   ui->AfficherClient2->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
}
void MainWindow::on_AfficherClient_activated(const QModelIndex &index)
{
    QString l=ui->AfficherClient->selectionModel()->selectedIndexes().at(0).data().toString();
    ui->id_client->setText(l);

    l=ui->AfficherClient->selectionModel()->selectedIndexes().at(1).data().toString();
    ui->cin_client_ajouter->setText(l);

    l=ui->AfficherClient->selectionModel()->selectedIndexes().at(2).data().toString();
    ui->nom_ajouter->setText(l);

    l=ui->AfficherClient->selectionModel()->selectedIndexes().at(3).data().toString();
    ui->prenom_ajouter->setText(l);

    l=ui->AfficherClient->selectionModel()->selectedIndexes().at(4).data().toString();
  //ui->dateNaissance->setDate(l);//->setDate("dd-mm-yyyy");

    l=ui->AfficherClient->selectionModel()->selectedIndexes().at(5).data().toString();
    ui->telephone_ajouter->setText(l);

    l=ui->AfficherClient->selectionModel()->selectedIndexes().at(6).data().toString();
    if(l=="Eleve")
    {ui->fontion_ajouter->setCurrentIndex(1);}
    else
    {  if(l=="Etudiant(e)")
     ui->fontion_ajouter->setCurrentIndex(2);
        else
        {  if(l=="Employe(e)")
         ui->fontion_ajouter->setCurrentIndex(3);
            else
            {  if(l=="Retraite(e)")
             ui->fontion_ajouter->setCurrentIndex(4);
                else
                {  if(l=="Chomeur(e)")
                 ui->fontion_ajouter->setCurrentIndex(5);
        }}}}

    l=ui->AfficherClient->selectionModel()->selectedIndexes().at(7).data().toString();
    ui->adresse_ajouter->setText(l);

    //l=ui->AfficherClientTable->selectionModel()->selectedIndexes().at(8).data().toString();
    //ui->datecreation->setText(l);

    l=ui->AfficherClient->selectionModel()->selectedIndexes().at(9).data().toString();
    ui->mail_ajouter->setText(l);

    l=ui->AfficherClient->selectionModel()->selectedIndexes().at(10).data().toString();
    if(l=="Femme")
    {ui->genre_ajouter->setCurrentIndex(1);}
    else
    {  if(l=="Homme")
     ui->genre_ajouter->setCurrentIndex(2); }


    l=ui->AfficherClient->selectionModel()->selectedIndexes().at(11).data().toString();
    if(l=="Marie(e)")
    {ui->etatcivil_ajouter->setCurrentIndex(2);}
    else
    {  if(l=="celibataire")
     ui->etatcivil_ajouter->setCurrentIndex(1); }
}

void MainWindow::on_ModifierClient_2_clicked()
{
    QString idd=ui->id_client->text();
    client *tmpCl=new client();
    tmpCl->setId(ui->id_client->text().toInt());
    tmpCl->setCin(ui->cin_client_ajouter->text().toInt());
    tmpCl->setNom(ui->nom_ajouter->text());
    tmpCl->setPrenom(ui->prenom_ajouter->text());
    tmpCl->setDate_naissance(ui->dateNaissance_ajouter->date());
    tmpCl->setNumTel(ui->telephone_ajouter->text().toInt());
    tmpCl->setFonction(ui->fontion_ajouter->currentText());
    tmpCl->setAdresse(ui->adresse_ajouter->text());
    tmpCl->setMail_client(ui->mail_ajouter->text());
    tmpCl->setGenre(ui->genre_ajouter->currentText());
    tmpCl->setEtat_civil(ui->etatcivil_ajouter->currentText());
    if (idd=="")
    { QMessageBox::information(this,"non existe"," id n'existe pas");}
    else
       {if (tmpCl->controle_saisie() == "")//pas de message
        {
        QString str = " Vous voulez vraiment modifier le client ayant le id :"+ ui->id_client->text();
             int ret = QMessageBox::question(this, tr("modification"),str,QMessageBox::Ok|QMessageBox::Cancel);
             switch (ret) {
               case QMessageBox::Ok:
                   if (tmpCl->modifier_client()){

                           ui->AfficherClient->setModel(tmpc.afficher_client());
                           Afficher_Client_Table();
                           refraiche();
                   }break;
               case QMessageBox::Cancel:

                   break;
               default:
                   // should never be reached
                   break;
             }
       }
        else
        {
            QMessageBox::information(this,"erreure",tmpCl->controle_saisie());
        }

    }
    refraiche();
}

void MainWindow::on_SupprimerClient_2_clicked()
{
    QString idd=ui->id_client->text();
    client *tmpCl=new client();
    if (idd=="")
    { QMessageBox::information(this,"non existe","id n'existe pas");}
    else
       {
        QString str = " Vous voulez vraiment supprimer \n l client ayant le id :"+ ui->id_client->text();
             int ret = QMessageBox::question(this, tr("suppression"),str,QMessageBox::Ok|QMessageBox::Cancel);
             switch (ret) {
               case QMessageBox::Ok:

                  tmpCl->setId(ui->id_client->text().toInt());
                   if (tmpCl->supprimer_client()){

                           ui->AfficherClient->setModel(tmpc.afficher_client());
                           Afficher_Client_Table();
                           refraiche();
                   }break;
               case QMessageBox::Cancel:

                   break;
               default:
                   // should never be reached
                   break;
             }
       }
    refraiche();
}

void MainWindow::on_ModifierClient_3_clicked()
{
    QString idd=ui->id_client->text();
    client *tmpCl=new client();
    tmpCl->setId(ui->id_client->text().toInt());
    tmpCl->setCin(ui->cin_client_ajouter->text().toInt());
    tmpCl->setNom(ui->nom_ajouter->text());
    tmpCl->setPrenom(ui->prenom_ajouter->text());
    tmpCl->setDate_naissance(ui->dateNaissance_ajouter->date());
    tmpCl->setNumTel(ui->telephone_ajouter->text().toInt());
    tmpCl->setFonction(ui->fontion_ajouter->currentText());
    tmpCl->setAdresse(ui->adresse_ajouter->text());
    tmpCl->setMail_client(ui->mail_ajouter->text());
    tmpCl->setGenre(ui->genre_ajouter->currentText());
    tmpCl->setEtat_civil(ui->etatcivil_ajouter->currentText());
    if (idd=="")
    { QMessageBox::information(this,"non existe"," id n'existe pas");}
    else
       {if (tmpCl->controle_saisie() == "")//pas de message
        {
        QString str = " Vous voulez vraiment modifier le client ayant le id :"+ ui->id_client->text();
             int ret = QMessageBox::question(this, tr("modification"),str,QMessageBox::Ok|QMessageBox::Cancel);
             switch (ret) {
               case QMessageBox::Ok:
                   if (tmpCl->modifier_client()){

                           ui->AfficherClient->setModel(tmpc.afficher_client());
                           Afficher_Client_Table();
                           refraiche();
                   }break;
               case QMessageBox::Cancel:

                   break;
               default:
                   // should never be reached
                   break;
             }
       }
        else
        {
            QMessageBox::information(this,"erreure",tmpCl->controle_saisie());
        }

    }
    refraiche();
}

void MainWindow::on_modifier_clicked()
{
    QString idd=ui->id_client->text();
    client *tmpCl=new client();
    tmpCl->setId(ui->id_client->text().toInt());
    tmpCl->setCin(ui->cin_client_ajouter->text().toInt());
    tmpCl->setNom(ui->nom_ajouter->text());
    tmpCl->setPrenom(ui->prenom_ajouter->text());
    tmpCl->setDate_naissance(ui->dateNaissance_ajouter->date());
    tmpCl->setNumTel(ui->telephone_ajouter->text().toInt());
    tmpCl->setFonction(ui->fontion_ajouter->currentText());
    tmpCl->setAdresse(ui->adresse_ajouter->text());
    tmpCl->setMail_client(ui->mail_ajouter->text());
    tmpCl->setGenre(ui->genre_ajouter->currentText());
    tmpCl->setEtat_civil(ui->etatcivil_ajouter->currentText());
    if (idd=="")
    { QMessageBox::information(this,"non existe"," id n'existe pas");}
    else
       {if (tmpCl->controle_saisie() == "")//pas de message
        {
        QString str = " Vous voulez vraiment modifier le client ayant le id :"+ ui->id_client->text();
             int ret = QMessageBox::question(this, tr("modification"),str,QMessageBox::Ok|QMessageBox::Cancel);
             switch (ret) {
               case QMessageBox::Ok:

                   if (tmpCl->modifier_client()){

                           ui->AfficherClient->setModel(tmpc.afficher_client());
                           Afficher_Client_Table();
                           refraiche();
                   }break;
               case QMessageBox::Cancel:

                   break;
               default:
                   // should never be reached
                   break;
             }
       }
        else
        {
            QMessageBox::information(this,"erreure",tmpCl->controle_saisie());
        }

    }
    refraiche();
}

void MainWindow::on_recherchecase_3_cursorPositionChanged(int arg1, int arg2)
{
    client v;
    ui->AfficherClient->setModel(v.rechercher_existe(ui->recherchecase_3->text()));
    Afficher_Client_Table();
}


void MainWindow::refraiche()
{
    ui->id_client->setText("");
    ui->cin_client_ajouter->setText("");
    ui->genre_ajouter->setCurrentIndex(0);
    ui->nom_ajouter->setText("");
    ui->prenom_ajouter->setText("");
    ui->etatcivil_ajouter->setCurrentIndex(0);
    ui->telephone_ajouter->setText("");
    ui->mail_ajouter->setText("");
    ui->fontion_ajouter->setCurrentIndex(0);
    ui->adresse_ajouter->setText("");
    ui->id_client_2->setText("");
    ui->cin_client_ajouter_2->setText("");
    ui->nom_ajouter_2->setText("");
    ui->prenom_ajouter_2->setText("");
    ui->telephone_ajouter_2->setText("");
    ui->adresse_ajouter_2->setText("");
    ui->mail_ajouter_2->setText("");
    ui->AfficherClient->setModel(tmpc.afficher_client());
    ui->AfficheCarteFidelite_2->setModel(tmpf.afficher_cartefidelite());
    ui->AfficherClient2->setModel(tmpc.afficher_client());
    Afficher_Client_Table();
    Afficher_Client_Table2();
    Afficher_Carte_Table();
}

void MainWindow::on_AfficherClient2_activated(const QModelIndex &index)
{
    QString l=ui->AfficherClient2->selectionModel()->selectedIndexes().at(0).data().toString();
    ui->id_client_2->setText(l);

    l=ui->AfficherClient2->selectionModel()->selectedIndexes().at(1).data().toString();
    ui->cin_client_ajouter_2->setText(l);

    l=ui->AfficherClient2->selectionModel()->selectedIndexes().at(2).data().toString();
    ui->nom_ajouter_2->setText(l);

    l=ui->AfficherClient2->selectionModel()->selectedIndexes().at(3).data().toString();
    ui->prenom_ajouter_2->setText(l);

    l=ui->AfficherClient2->selectionModel()->selectedIndexes().at(5).data().toString();
    ui->telephone_ajouter_2->setText(l);



    l=ui->AfficherClient2->selectionModel()->selectedIndexes().at(7).data().toString();
    ui->adresse_ajouter_2->setText(l);

   l=ui->AfficherClient2->selectionModel()->selectedIndexes().at(9).data().toString();
    ui->mail_ajouter_2->setText(l);


}

void MainWindow::on_recherchecase_4_cursorPositionChanged(int arg1, int arg2)
{
    client v;
    ui->AfficherClient2->setModel(v.rechercher_existe(ui->recherchecase_4->text()));
    Afficher_Client_Table2();
}

void MainWindow::on_ajouter_carte_2_clicked()
{
    QString idd=ui->id_client_2->text();

    if (idd=="")
    { QMessageBox::information(this,"non existe","selectionner le client");}
    else{
    carte_fidelite c(ui->id_client_2->text().toInt(),QDate::currentDate(),100,0);

   QString str = " Vous voulez vraiment ajouter ce carte fidelite:" ;
            int ret = QMessageBox::question(this, tr("enregistrement"),str,QMessageBox::Ok|QMessageBox::Cancel);

            switch (ret) {
              case QMessageBox::Ok:
            {
               if(! c.existe_carte() )
                   {    c.ajouter_cartefidelite();
                   ui->AfficheCarteFidelite_2->setModel(tmpf.afficher_cartefidelite());
                   refraiche();
                   }
               else
                   {
                      QMessageBox::critical(this,tr("erreure")," carte fidelite existe !!");
                   }

            }
                     break;
              case QMessageBox::Cancel:

                  break;
              default:
                  // should never be reached
                  break;

            }
}

}

void MainWindow::on_refrech2_clicked()
{
    refraiche();
}

void MainWindow::on_refrech_clicked()
{
    refraiche();
}

void MainWindow::on_AfficheCarteFidelite_2_activated(const QModelIndex &index)
{
    QString l=ui->AfficheCarteFidelite_2->selectionModel()->selectedIndexes().at(0).data().toString();
    ui->id_carte->setText(l);

}



void MainWindow::on_SupprimerCarte_2_clicked()
{
    QString idd=ui->id_carte->text();
    carte_fidelite *tmpcf=new carte_fidelite();
    if (idd=="")
    { QMessageBox::information(this,"non existe","id n'existe pas");}
    else
       {
        QString str = " Vous voulez vraiment supprimer \n l carte ayant le id :"+ ui->id_carte->text();
             int ret = QMessageBox::question(this, tr("suppression"),str,QMessageBox::Ok|QMessageBox::Cancel);
             switch (ret) {
               case QMessageBox::Ok:

                  tmpcf->setId_carte(ui->id_carte->text().toInt());
                   if (tmpcf->supprimer_cartefidelite()){

                           ui->AfficheCarteFidelite_2->setModel(tmpf.afficher_cartefidelite());
                           Afficher_Carte_Table();
                           refraiche();
                   }break;
               case QMessageBox::Cancel:

                   break;
               default:
                   // should never be reached
                   break;
             }
       }
    refraiche();

}

void MainWindow::on_close_2_clicked()
{
    close();
}

void MainWindow::on_close_b_clicked()
{
    close();
}

void MainWindow::on_filtrer_2_clicked()
{

   if (ui->genre_filtre->currentText() == "" & ui->fonction_filtre->currentText() == "" & ui->Etat_civil_filtre->currentText() == "")
   {
       QMessageBox::information(this,"erreure"," aucune valeur saisi");

   }else{
    client v;
    ui->AfficherClient->setModel(v.filtre(ui->genre_filtre->currentText(),ui->fonction_filtre->currentText(),ui->Etat_civil_filtre->currentText()));
    Afficher_Client_Table();}

}

void MainWindow::on_envoyer_mail_2_clicked()
{

}
