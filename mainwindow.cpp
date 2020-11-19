#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include "dialog.h"
#include "QMessageBox"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "connection.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    connection c;
     c.createconnect();
     ui->setupUi(this);
     ui->AfficherClientTable->setModel(tmpc.afficher_client());
     Afficher_Client_Table();
     ui->id_client_select->setVisible(false);
     ui->cin_client->setValidator(new QIntValidator(0,99999999,this));
     ui->telephone->setValidator(new QIntValidator(0,99999999,this));

     setWindowIcon(QIcon("C:/Users/sinda/Desktop/projet 2a/popcornicon"));
QPixmap pixel ("C:/Users/sinda/Desktop/projet 2a/popcornicon");
ui->icon->setPixmap(pixel.scaled(200,100,Qt::KeepAspectRatio));
     int w= ui->icon->width();
     int h=ui->icon->height();

     animation=new QPropertyAnimation(ui->icon,"geometry");
     animation->setDuration(1999);
     animation->setStartValue(ui->icon->geometry());
     animation->setEndValue(QRect(1200,20,w,h));
     animation->setLoopCount(-1);
     animation->start();


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_close_clicked()
{
    close();
}

void MainWindow::on_closeClient_clicked()
{
    close();
}

void MainWindow::on_AjouterClient_clicked()
{
    client c(ui->cin_client->text().toInt(),ui->nom->text(),ui->prenom->text(),ui->dateNaissance->date(),
             ui->telephone->text().toInt(),ui->fontion->currentText(),ui->adresse->text()
             ,QDate::currentDate(),ui->mail->text(),ui->genre->currentText(),ui->etatcivil->currentText());

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
                          ui->AfficherClientTable->setModel(tmpc.afficher_client());
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
                        ui->AfficherClientTable->setModel(tmpc.afficher_client());
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
   ui->AfficherClientTable->resizeColumnsToContents();
   ui->AfficherClientTable->resizeRowsToContents();
   ui->AfficherClientTable->setSelectionBehavior(QAbstractItemView::SelectRows);
   ui->AfficherClientTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed,QHeaderView::Stretch);
   ui->AfficherClientTable->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
}

void MainWindow::on_AfficherClientTable_activated()
{
    QString l=ui->AfficherClientTable->selectionModel()->selectedIndexes().at(0).data().toString();
    ui->id_client_select->setText(l);

    l=ui->AfficherClientTable->selectionModel()->selectedIndexes().at(1).data().toString();
    ui->cin_client->setText(l);

    l=ui->AfficherClientTable->selectionModel()->selectedIndexes().at(2).data().toString();
    ui->nom->setText(l);

    l=ui->AfficherClientTable->selectionModel()->selectedIndexes().at(3).data().toString();
    ui->prenom->setText(l);

    l=ui->AfficherClientTable->selectionModel()->selectedIndexes().at(4).data().toString();
  //ui->dateNaissance->setDate(l);//->setDate("dd-mm-yyyy");

    l=ui->AfficherClientTable->selectionModel()->selectedIndexes().at(5).data().toString();
    ui->telephone->setText(l);

    l=ui->AfficherClientTable->selectionModel()->selectedIndexes().at(6).data().toString();
    if(l=="Eleve")
    {ui->fontion->setCurrentIndex(1);}
    else
    {  if(l=="Etudiant(e)")
     ui->fontion->setCurrentIndex(2);
        else
        {  if(l=="Employe(e)")
         ui->fontion->setCurrentIndex(3);
            else
            {  if(l=="Retraite(e)")
             ui->fontion->setCurrentIndex(4);
                else
                {  if(l=="Chomeur(e)")
                 ui->fontion->setCurrentIndex(5);
        }}}}

    l=ui->AfficherClientTable->selectionModel()->selectedIndexes().at(7).data().toString();
    ui->adresse->setText(l);

    //l=ui->AfficherClientTable->selectionModel()->selectedIndexes().at(8).data().toString();
    //ui->datecreation->setText(l);

    l=ui->AfficherClientTable->selectionModel()->selectedIndexes().at(9).data().toString();
    ui->mail->setText(l);

    l=ui->AfficherClientTable->selectionModel()->selectedIndexes().at(10).data().toString();
    if(l=="Femme")
    {ui->genre->setCurrentIndex(1);}
    else
    {  if(l=="Homme")
     ui->genre->setCurrentIndex(2); }


    l=ui->AfficherClientTable->selectionModel()->selectedIndexes().at(11).data().toString();
    if(l=="Marie(e)")
    {ui->etatcivil->setCurrentIndex(2);}
    else
    {  if(l=="celibataire")
     ui->etatcivil->setCurrentIndex(1); }


}



void MainWindow::on_SupprimerClient_clicked()
{
    QString idd=ui->id_client_select->text();
    client *tmpCl=new client();
    if (idd=="")
    { QMessageBox::information(this,"non existe","id n'existe pas");}
    else
       {
        QString str = " Vous voulez vraiment supprimer \n l client ayant le id :"+ ui->id_client_select->text();
             int ret = QMessageBox::question(this, tr("suppression"),str,QMessageBox::Ok|QMessageBox::Cancel);
             switch (ret) {
               case QMessageBox::Ok:

                  tmpCl->setId(ui->id_client_select->text().toInt());
                   if (tmpCl->supprimer_client()){

                           ui->AfficherClientTable->setModel(tmpc.afficher_client());
                           Afficher_Client_Table();
                   }break;
               case QMessageBox::Cancel:

                   break;
               default:
                   // should never be reached
                   break;
             }
       }
}


void MainWindow::on_ModifierClient_clicked()
{

    QString idd=ui->id_client_select->text();
    client *tmpCl=new client();
    tmpCl->setId(ui->id_client_select->text().toInt());
    tmpCl->setCin(ui->cin_client->text().toInt());
    tmpCl->setNom(ui->nom->text());
    tmpCl->setPrenom(ui->prenom->text());
    tmpCl->setDate_naissance(ui->dateNaissance->date());
    tmpCl->setNumTel(ui->telephone->text().toInt());
    tmpCl->setFonction(ui->fontion->currentText());
    tmpCl->setAdresse(ui->adresse->text());
    tmpCl->setMail_client(ui->mail->text());
    tmpCl->setGenre(ui->genre->currentText());
    tmpCl->setEtat_civil(ui->etatcivil->currentText());
    if (idd=="")
    { QMessageBox::information(this,"non existe"," id n'existe pas");}
    else
       {if (tmpCl->controle_saisie() == "")//pas de message
        {
        QString str = " Vous voulez vraiment modifier le client ayant le id :"+ ui->id_client_select->text();
             int ret = QMessageBox::question(this, tr("suppression"),str,QMessageBox::Ok|QMessageBox::Cancel);
             switch (ret) {
               case QMessageBox::Ok:
                   if (tmpCl->modifier_client()){

                           ui->AfficherClientTable->setModel(tmpc.afficher_client());
                           Afficher_Client_Table();
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

}
