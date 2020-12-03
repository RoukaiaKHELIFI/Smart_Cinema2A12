#include "gestpromotion.h"
#include "ui_gestpromotion.h"
#include "sponsorisation.h"
#include <QMessageBox>
#include <QMessageBox>
#include <QColor>
#include <QPalette>
#include "gestsponso.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QTableWidget>
#include <QPixmap>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
gestpromotion::gestpromotion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestpromotion)
{
    ui->setupUi(this);
}

gestpromotion::~gestpromotion()
{
    delete ui;
}

void gestpromotion::on_btn_ajouters_clicked()
{
    int num=ui->num->text().toInt();
           QString nom= ui->nom_s->text();
            QString type= ui->type_s->text();
          QString methode= ui->methode_s->text();

         Sponsorisation p(num,nom,type,methode);
         bool test=p.ajouter();
         if(test)
       {ui->tableView->setModel(tmpsp.afficher()); //refresh
       QMessageBox::information(nullptr, QObject::tr("Ajouter une Sponsorisation"),
                         QObject::tr("Sponsorisation ajoutée.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

       }
         else
             QMessageBox::critical(nullptr, QObject::tr("Ajouter une Sponsorisation"),
                         QObject::tr("Erreur !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestpromotion::on_btn_supprimers_clicked()
{
    QSqlQuery query;

            int num = ui->id_a_supprimer_s->text().toInt();

            query.prepare("delete from  sponsorisation where num=:num");
            query.bindValue(":num", num);
            bool v =query.exec();
            if(v)
            {ui->tableView->setModel(tmpsp.afficher());//refresh
                QMessageBox::information(nullptr, QObject::tr("Supprimer une  Sponsorisation"),
                            QObject::tr(" Sponsorisation supprimé.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

            }
            else
                QMessageBox::critical(nullptr, QObject::tr("Supprimer une  Sponsorisation"),
                            QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestpromotion::on_btn_modifiers_clicked()
{
    int id=ui->id_a_modifiers->text().toInt();


           QString nom= ui->nv_noms->text();
            QString type= ui->nv_types->text();
           QString methode= ui->nv_methodes->text();


         Sponsorisation p(id,nom,type,methode);
         bool test=p.modifier(id,nom,type,methode);
         if(test)
       {
             ui->tableView->setModel(tmpsp.afficher());
       QMessageBox::information(nullptr, QObject::tr("Modifier une  Sponsorisation"),
                         QObject::tr(" Sponsorisation modifiée.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

       }
         else
             QMessageBox::critical(nullptr, QObject::tr("Modifier une  Sponsorisation"),
                         QObject::tr("Erreur !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestpromotion::on_btn_pdfs_clicked()
{
    QPrinter *printer = new QPrinter(QPrinter::HighResolution);
               printer->setOutputFormat(QPrinter::NativeFormat);
               printer->setPageSize(QPrinter::A4);
               printer->setOrientation(QPrinter::Portrait);
               printer->setFullPage(true);


           QPrintDialog *printDialog = new QPrintDialog(printer,this);
           printDialog->setWindowTitle("Impression PDF");
           if(printDialog->exec())
           {
              QPainter painter;
              if(painter.begin(printer))
              {
                  double xscale = double(ui->tableView->width() / 65);
                  double yscale = double(ui->tableView->height() / 65);
                  painter.scale(xscale, yscale);
                  ui->tableView->render(&painter);
                  painter.end();
              }
              else
              {
                  qWarning("failed to open file");
                 QMessageBox::warning(nullptr,QObject::tr("PDF echoue"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
              }
           }
}

void gestpromotion::on_tn_tri_noms_clicked()
{
ui->tableView->setModel(tmpsp.trier());
}

void gestpromotion::on_btn_tri_num_s_clicked()
{
ui->tableView->setModel(tmpsp.trier1());
}

void gestpromotion::on_tn_refreshs_clicked()
{
   ui->tableView->setModel(tmpsp.afficher());
}

void gestpromotion::on_btn_cherchers_clicked()
{
    QString noms = ui->nom_a_chercherp->text();
        if(tmpsp.verifierExnoms(noms)==false)
        {QMessageBox::warning(this,"ERREUR","Sponsorisation n'existe pas");}
        else
        ui->tableView->setModel(tmpsp.recherche_nom(noms));
}
