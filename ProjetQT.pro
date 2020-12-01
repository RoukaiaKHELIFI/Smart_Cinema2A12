QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    authentification.cpp \
    carte_fidelite.cpp \
    client.cpp \
    connexion.cpp \
    dialog.cpp \
    employe.cpp \
    film.cpp \
    gestion_film.cpp \
    main.cpp \
    mainwindow.cpp \
    ticket.cpp

HEADERS += \
    authentification.h \
    carte_fidelite.h \
    client.h \
    connexion.h \
    dialog.h \
    employe.h \
    film.h \
    gestion_film.h \
    mainwindow.h \
    qcustomplot.h \
    ticket.h

FORMS += \
    authentification.ui \
    dialog.ui \
    gestion_film.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
