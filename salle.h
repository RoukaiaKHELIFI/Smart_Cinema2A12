#ifndef SALLE_H
#define SALLE_H
#include<QSqlQuery>
#include <QSqlQueryModel>
#include<QString>

class Salle
{
public:
    Salle();
    Salle(int,int,int,int);
    int get_num_salle();
    int get_nb_chaise();
    int get_nb_baffles();
    int get_nb_ecrans();
bool ajouter();
QSqlQueryModel * afficher();
bool supprimer(int);
bool Update(int);
private:
int num_salle,nb_chaise,nb_baffles,nb_ecrans;

};

#endif // SALLE_H
