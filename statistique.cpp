#include "statistique.h"
#include "ui_statistique.h"
#include <QSqlQuery>
#include <QDate>

#include <QSqlQuery>

//#include <QtCharts>
#include "qcustomplot.h"
#include <QPixmap>

Statistique::Statistique(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Statistique)
{
    ui->setupUi(this);
}

Statistique::~Statistique()
{
    delete ui;
}
void Statistique::makplot()
{
ui->widget->setVisible(true);

ui->widget->clearPlottables();
// set dark background gradient:
QLinearGradient gradient(0, 0, 0,400);
gradient.setColorAt(0, QColor(90, 90, 90));
gradient.setColorAt(0.38, QColor(105, 105, 105));
gradient.setColorAt(1, QColor(70, 70, 70));
ui->widget->setBackground(QBrush(gradient));

// create empty bar chart objects:
QCPBars *sexe = new QCPBars(ui->widget->xAxis, ui->widget->yAxis);
sexe->setAntialiased(false);
sexe->setStackingGap(1);
// set names and colors:
sexe->setName("traitement par reclamation");
sexe->setPen(QPen(QColor(255,255,255).lighter(130)));
sexe->setBrush(QColor(0,0,127));


// stack bars on top of each other;
// prepare x axis with country labels:
QVector<double> ticks;
QVector<QString> labels;
ticks << 1 << 2 ;
labels << "oui" << "non";
QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
textTicker->addTicks(ticks, labels);
ui->widget->xAxis->setTicker(textTicker);
ui->widget->xAxis->setTickLabelRotation(60);
ui->widget->xAxis->setSubTicks(false);
ui->widget->xAxis->setTickLength(0, 4);
ui->widget->xAxis->setRange(0, 8);
ui->widget->xAxis->setBasePen(QPen(Qt::white));
ui->widget->xAxis->setTickPen(QPen(Qt::white));
ui->widget->xAxis->grid()->setVisible(true);
ui->widget->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
ui->widget->xAxis->setTickLabelColor(Qt::white);
ui->widget->xAxis->setLabelColor(Qt::white);

// prepare y axis:
ui->widget->yAxis->setRange(0,10);
ui->widget->yAxis->setPadding(5); // a bit more space to the left border
ui->widget->yAxis->setBasePen(QPen(Qt::white));
ui->widget->yAxis->setTickPen(QPen(Qt::white));
ui->widget->yAxis->setSubTickPen(QPen(Qt::white));
ui->widget->yAxis->grid()->setSubGridVisible(true);
ui->widget->yAxis->setTickLabelColor(Qt::white);
ui->widget->yAxis->setLabelColor(Qt::white);
ui->widget->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
ui->widget->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
 //
int h,f ;
h=f=0;
QSqlQuery *s;
s=new QSqlQuery();
s->prepare("select TRAITER	 from RECLAMATION ");
s->exec();
while(s->next())
{
    if(s->value(0).toString()=="oui")
        h++;
    if(s->value(0).toString()=="non")
        f++;
}
// Add data:
QVector<double> sexeData;
sexeData  << h << f ;
sexe->setData(ticks, sexeData);

// setup legend:
ui->widget->legend->setVisible(true);
ui->widget->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
ui->widget->legend->setBrush(QColor(255, 255, 255, 100));
ui->widget->legend->setBorderPen(Qt::NoPen);
QFont legendFont = font();
legendFont.setPointSize(10);
ui->widget->legend->setFont(legendFont);
ui->widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
ui->widget->replot();
}
