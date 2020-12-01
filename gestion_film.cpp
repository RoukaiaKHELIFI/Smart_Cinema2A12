#include "gestion_film.h"
#include "ui_gestion_film.h"
#include "carte_fidelite.h"
#include "film.h"

#include "QMessageBox"
#include "ticket.h"

gestion_film::gestion_film(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_film)
{
    ui->setupUi(this);
    setWindowIcon(QIcon("C:/Users/asus/Desktop/icon_film.png"));

        QPixmap bkgnd("C:/Users/asus/Desktop/bg.png");
            bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
            QPalette palette;
           // palette.setBrush(QPalette::Background, bkgnd);
           // this->setPalette(palette);

        ui->AfficherFilmTable->setModel(tmpc.afficher_film());
        ui->AfficherTicketTable->setModel(empc.afficher_ticket());
}

gestion_film::~gestion_film()
{
    delete ui;
}


void gestion_film::on_AjouterFilm_clicked()
{
    Film f(ui->id_film->text().toInt(),ui->nom_film->text(),ui->realisateur->text(),
                       ui->nationalite->currentText(),ui->date_sortie->date(),ui->disponibilite->date(),
                       ui->categorie->currentText());
               f.ajouter_film();

               ui->AfficherFilmTable->setModel(tmpc.afficher_film());
}











void gestion_film::on_ModifierFilm_clicked()
{
    QString idf=ui->id_film->text();
    Film *tmpCl=new Film();
    tmpCl->setid_film(ui->id_film->text().toInt());
    tmpCl->setnom_film(ui->nom_film->text());
    tmpCl->setrealisateur(ui->realisateur->text());
    tmpCl->setnationalite(ui->nationalite->currentText());
    tmpCl->setdate_sortie(ui->date_sortie->date());
    tmpCl->setdisponibilite(ui->disponibilite->date());
    tmpCl->setcategories(ui->categorie->currentText());


        QString str = " Vous voulez vraiment modifier le film ayant le id :"+ ui->id_film->text();
             int ret = QMessageBox::question(this, tr("modification"),str,QMessageBox::Ok|QMessageBox::Cancel);
             switch (ret) {
               case QMessageBox::Ok:

                   //  tmpCl->setid_film(ui->id_film->text().toInt());

                   if (tmpCl->modifier_film()){

                           ui->AfficherFilmTable->setModel(tmpc.afficher_film());

                           //Afficher_Film_Table();

                   }break;
               case QMessageBox::Cancel:

                   break;
               default:
                   // should never be reached
                   break;
             }
}

void gestion_film::on_SupprimerFilm_clicked()
{
    QItemSelectionModel *select=ui->AfficherFilmTable->selectionModel();
        QString idd=select->selectedRows(0).value(0).data().toString();
        Film *tmpCl=new Film();

            QString str = " Vous voulez vraiment supprimer \n le film  ayant le id :"+ ui->id_film->text();
                 int ret = QMessageBox::question(this, tr("suppression"),str,QMessageBox::Ok|QMessageBox::Cancel);
                 switch (ret) {
                   case QMessageBox::Ok:

                      tmpCl->setid_film(ui->id_film->text().toInt());
                       if (tmpCl->supprimer_film()){

                               ui->AfficherFilmTable->setModel(tmpc.afficher_film());
                       }break;
                   case QMessageBox::Cancel:

                       break;
                   default:
                       // should never be reached
                       break;
                 }

}

void gestion_film::on_Close_2_clicked()
{
    close();
}

void gestion_film::on_Close_ticket_clicked()
{
    close();
}

void gestion_film::on_ajouterTicket_clicked()
{
    Ticket t(ui->id_ticket->text().toInt(),ui->Id_film_ticket->text(),ui->prix_ticket->text(),
                       ui->salles->currentText(),ui->paiment->currentText(),ui->id_cleint->text().toInt());
              t.ajouter_ticket();

              carte_fidelite c(ui->id_cleint->text().toInt(),0,0);
              int nb=c.recupere_nbfilm(ui->id_cleint->text().toInt());
              int nbf=c.recupere_nbpoint(ui->id_cleint->text().toInt());
              QString str = " Vous voulez vraiment supprimer \n ticket  ayant le id :"+ QString::number(nb)+"   "+ QString::number(nbf);
              QMessageBox::information(this, tr("suppression"),str,QMessageBox::Ok|QMessageBox::Cancel);

              c.modifier_cartefidelite();

               nb=c.recupere_nbfilm(ui->id_cleint->text().toInt());
               nbf=c.recupere_nbpoint(ui->id_cleint->text().toInt());
              QString str2 = " Vous voulez vraiment supprimer \n ticket  ayant le id :"+ QString::number(nb)+"   "+ QString::number(nbf);
              QMessageBox::information(this, tr("suppression"),str2,QMessageBox::Ok|QMessageBox::Cancel);


               ui->AfficherTicketTable->setModel(empc.afficher_ticket());

}

void gestion_film::on_SupprimerTicket_clicked()
{
    QItemSelectionModel *select=ui->AfficherTicketTable->selectionModel();
        QString idd=select->selectedRows(0).value(0).data().toString();
        Ticket *tmpCl=new Ticket();

            QString str = " Vous voulez vraiment supprimer \n ticket  ayant le id :"+ ui->id_ticket->text();
                 int ret = QMessageBox::question(this, tr("suppression"),str,QMessageBox::Ok|QMessageBox::Cancel);
                 switch (ret) {
                   case QMessageBox::Ok:

                      tmpCl->setid_ticket(ui->id_ticket->text().toInt());
                       if (tmpCl->supprimer_ticket()){

                               ui->AfficherTicketTable->setModel(empc.afficher_ticket());
                       }break;
                   case QMessageBox::Cancel:

                       break;
                   default:
                       // should never be reached
                       break;
                 }
}

void gestion_film::on_ModifierTicket_2_clicked()
{
    carte_fidelite c(34,0,0);
    int nb=c.recupere_nbfilm(ui->id_cleint->text().toInt());
    int nbf=c.recupere_nbpoint(ui->id_cleint->text().toInt());
    QString str = " Vous voulez vraiment supprimer \n ticket  ayant le id :"+ QString::number(nb)+"   "+ QString::number(nbf);
    QMessageBox::information(this, tr("suppression"),str,QMessageBox::Ok|QMessageBox::Cancel);
    c.modifier_cartefidelite();
}
