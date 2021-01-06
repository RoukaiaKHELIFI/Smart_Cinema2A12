#ifndef CAPTEUR_MOUVEMENT_H
#define CAPTEUR_MOUVEMENT_H
#include<QtSerialPort/QtSerialPort>
#include<QtSerialPort/QSerialPortInfo>

class capteur_mouvement
{
public:
    capteur_mouvement();
    int connect_capteur();
    int close_Capteur();

    QByteArray read_from_capteur();
    QSerialPort* getserial();
    QString get_capteur_port_name();
    int write_to_arduino(QByteArray); //envoie des données à arduino
    /***********************/
private :
    QSerialPort *serial;
    static const quint16 arduino_uno_vendor_id=9025;
    static const quint16 arduino_uno_producy_id=67;
    QString arduino_port_name;
    bool arduino_is_available;
    QByteArray data;
};

#endif // CAPTEUR_MOUVEMENT_H




