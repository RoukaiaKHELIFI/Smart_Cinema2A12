#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "film.h"
#include "connection.h"
#include "QMessageBox"
#include "ticket.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    connection c;
    c.createconnect();
    ui->setupUi(this);
    setWindowIcon(QIcon("C:/Users/asus/Desktop/icon_film.png"));

    QPixmap bkgnd("C:/Users/asus/Desktop/bg.png");
            bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
            QPalette palette;
            palette.setBrush(QPalette::Background, bkgnd);
            this->setPalette(palette);



    ui->AfficherFilmTable->setModel(tmpc.afficher_film());
      ui->AfficherFilmTable->resizeColumnsToContents();
      ui->AfficherFilmTable->resizeRowsToContents();
      ui->AfficherFilmTable->setSelectionBehavior(QAbstractItemView::SelectRows);
      ui->AfficherFilmTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed,QHeaderView::Stretch);
      ui->AfficherFilmTable->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    ui->AfficherTicketTable->setModel(empc.afficher_ticket());

    ui->AfficherTicketTable->resizeColumnsToContents();
    ui->AfficherTicketTable->resizeRowsToContents();
    ui->AfficherTicketTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->AfficherTicketTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed,QHeaderView::Stretch);
    ui->AfficherTicketTable->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_AjouterFilm_clicked()
{
    Film f(ui->id_film->text().toInt(),ui->nom_film->text(),ui->realisateur->text(),
                       ui->nationalite->currentText(),ui->date_sortie->date(),ui->disponibilite->date(),
                       ui->categorie->currentText());
               f.ajouter_film();

               ui->AfficherFilmTable->setModel(tmpc.afficher_film());



               ui->id_film->setText("");
               ui->nom_film->setText("");
               ui->realisateur->setText("");
               ui->nationalite->setCurrentText("");
             //  ui->date_sortie->setDate();
             //  ui->disponibilite->setDate();
               ui->categorie->setCurrentText("");
}

void MainWindow::on_SupprimerFilm_clicked()
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


                 ui->id_film->setText("");
                 ui->nom_film->setText("");
                 ui->realisateur->setText("");
                 ui->nationalite->setCurrentText("");
               //  ui->date_sortie->setDate();
               //  ui->disponibilite->setDate();
                 ui->categorie->setCurrentText("");
}

void MainWindow::on_Close_2_clicked()
{
    close();
}

void MainWindow::on_Close_ticket_clicked()
{
    close();
}



void MainWindow::on_ajouterTicket_clicked()
{
    Ticket t(ui->id_ticket->text().toInt(),ui->Id_film_ticket->text(),ui->prix_ticket->text(),
                       ui->salles->currentText(),ui->paiment->currentText());
              t.ajouter_ticket();

               ui->AfficherTicketTable->setModel(empc.afficher_ticket());


               ui->id_ticket->setText("");
               ui->Id_film_ticket->setText("");
               ui->prix_ticket->setText("");
               ui->salles->setCurrentText("");
               ui->paiment->setCurrentText("");


}




void MainWindow::on_SupprimerTicket_clicked()
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

void MainWindow::on_ModifierFilm_clicked()
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

                   if (tmpCl->modifier_film()){


                           ui->AfficherFilmTable->setModel(tmpc.afficher_film());

                           //AfficherFilmTable();

                   }break;
               case QMessageBox::Cancel:

                   break;
               default:
                   // should never be reached
                   break;
             }


             ui->id_film->setText("");
             ui->nom_film->setText("");
             ui->realisateur->setText("");
             ui->nationalite->setCurrentText("");
           //  ui->date_sortie->setDate();
           //  ui->disponibilite->setDate();
             ui->categorie->setCurrentText("");


}

void MainWindow::on_RefreshFilm_clicked()
{
        ui->id_film->setText("");
        ui->nom_film->setText("");
        ui->realisateur->setText("");
        ui->nationalite->setCurrentText("");
      //  ui->date_sortie->setDate();
      //  ui->disponibilite->setDate();
        ui->categorie->setCurrentText("");
}

void MainWindow::on_RefreshTicket_clicked()
{
    ui->id_ticket->setText("");
    ui->Id_film_ticket->setText("");
    ui->prix_ticket->setText("");
    ui->salles->setCurrentText("");
    ui->paiment->setCurrentText("");
}

void MainWindow::on_ModifierTicket_clicked()
{
    QString idt=ui->Id_film_ticket->text();
    Ticket *tmpCl=new Ticket();
    tmpCl->setid_ticket(ui->id_ticket->text().toInt());
    tmpCl->setid_film(ui->Id_film_ticket->text());
    tmpCl->setprix(ui->prix_ticket->text());
    tmpCl->setsalle(ui->salles->currentText());
    tmpCl->settype_paiment(ui->paiment->currentText());


        QString str = " Vous voulez vraiment modifier le ticket ayant le id :"+ ui->id_ticket->text();
             int ret = QMessageBox::question(this, tr("modification"),str,QMessageBox::Ok|QMessageBox::Cancel);
             switch (ret) {
               case QMessageBox::Ok:

                   if (tmpCl->modifier_ticket()){


                           ui->AfficherTicketTable->setModel(empc.afficher_ticket());


                   }break;
               case QMessageBox::Cancel:

                   break;
               default:
                   // should never be reached
                   break;
             }
             ui->id_ticket->setText("");
             ui->Id_film_ticket->setText("");
             ui->prix_ticket->setText("");
             ui->salles->setCurrentText("");
             ui->paiment->setCurrentText("");
}
