#include "gestsponso.h"
#include "ui_gestsponso.h"
#include <QPrinter>
#include "gestpromotion.h"
#include <QPrintDialog>
#include <QPainter>
#include  "promotion.h"
#include <QMessageBox>
#include <QColor>
#include <QPalette>
#include "gestsponso.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QTableWidget>
#include <QPixmap>
gestsponso::gestsponso(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestsponso)
{
    ui->setupUi(this);
}

gestsponso::~gestsponso()
{
    delete ui;
}

void gestsponso::on_pushButton_clicked()
{
    int id=ui->id_s->text().toInt();
           QString nomfilm= ui->nomf_s->text();
            QString catfilm= ui->catf_s->text();
           int prix = ui->prix_s->text().toInt();

         Promotion p(id,nomfilm,catfilm,prix);
         bool test=p.ajouter();
         if(test)
       {ui->tabs->setModel(tmpp.afficher()); //refresh
       QMessageBox::information(nullptr, QObject::tr("Ajouter une Promotion"),
                         QObject::tr("Promotion ajoutée.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

       }
         else
             QMessageBox::critical(nullptr, QObject::tr("Ajouter une Promotion"),
                         QObject::tr("Erreur !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
}

/*void gestsponso::on_btn_rechercher_clicked()
{
    QString nomfilm = ui->nom_a_chercher->text();
        if(tmpsponso.verifierExnoms(nomfilm)==false)
        {QMessageBox::warning(this,"ERREUR","Promotion n'existe pas");}
        else
        ui->tabs->setModel(tmpsponso.recherche_nom(nomfilm));
}
*/
void gestsponso::on_btn_refresh_clicked()
{
    ui->tabs->setModel(tmpp.afficher());
}

void gestsponso::on_btn_tri_nom_clicked()
{
  ui->tabs->setModel(tmpp.trier());
}

void gestsponso::on_btn_tri_id_clicked()
{
ui->tabs->setModel(tmpp.trier1());}

void gestsponso::on_btn_pdf_clicked()
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
                  double xscale = double(ui->tabs->width() / 65);
                  double yscale = double(ui->tabs->height() / 65);
                  painter.scale(xscale, yscale);
                  ui->tabs->render(&painter);
                  painter.end();
              }
              else
              {
                  qWarning("failed to open file");
                 QMessageBox::warning(nullptr,QObject::tr("PDF echoue"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
              }
           }
}

void gestsponso::on_btn_modifier_clicked()
{
    int id=ui->id_a_modifier->text().toInt();

           QString nomfilm= ui->nv_nom->text();
            QString catfilm= ui->nv_cat->text();
           int prix= ui->nv_prix->text().toInt();


          Promotion p(id,nomfilm,catfilm,prix);
         bool test=p.modifier(id,nomfilm,catfilm,prix);
         if(test)
       {
             ui->tabs->setModel(tmpp.afficher());
       QMessageBox::information(nullptr, QObject::tr("Modifier une  Promotion"),
                         QObject::tr(" Promotion modifiée.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

       }
         else
             QMessageBox::critical(nullptr, QObject::tr("Modifier une  Promotion"),
                         QObject::tr("Erreur !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestsponso::on_btn_supprimer_clicked()
{
    QSqlQuery query;

            int id = ui->id_a_supprimer->text().toInt();

            query.prepare("delete from  promotion where id=:id");
            query.bindValue(":id", id);
            bool v =query.exec();
            if(v)
            {ui->tabs->setModel(tmpp.afficher());//refresh
                QMessageBox::information(nullptr, QObject::tr("Supprimer une  Promotion"),
                            QObject::tr(" Promotion supprimé.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

            }
            else
                QMessageBox::critical(nullptr, QObject::tr("Supprimer une  Promotion"),
                            QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestsponso::on_btn_rechercher_clicked()
{
    QString noms = ui->nom_a_chercher->text();
        if(tmpp.verifierExnoms(noms)==false)
        {QMessageBox::warning(this,"ERREUR","Promotion n'existe pas");}
        else
        ui->tabs->setModel(tmpp.recherche_nom(noms));
}

void gestsponso::on_pushButton_2_clicked()
{
    gestpromotion s;
    s.exec();
}
