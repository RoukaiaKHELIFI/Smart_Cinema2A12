QT       += core gui multimedia sql network charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    carte_fidelite.cpp \
    client.cpp \
    connexion.cpp \
    employe.cpp \
    film.cpp \
    main.cpp \
    mainwindow.cpp \
    reservation.cpp \
    salle.cpp \
    smtp.cpp \
    ticket.cpp

HEADERS += \
    carte_fidelite.h \
    client.h \
    connexion.h \
    employe.h \
    film.h \
    mainwindow.h \
    random.h \
    reservation.h \
    salle.h \
    smtp.h \
    ticket.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    source.qrc
