QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QMAKE_EXTRA_COMPILERS += nasm
NASMEXTRAFLAGS = -f elf64 -g -F dwarf
OTHER_FILES += $$NASM_SOURCES
nasm.output = ${QMAKE_FILE_BASE}.o
nasm.commands = nasm $$NASMEXTRAFLAGS -o ${QMAKE_FILE_BASE}.o ${QMAKE_FILE_NAME}
nasm.input = NASM_SOURCES

NASM_SOURCES += \
    test.asm \
    random.asm \
    determProb.asm


SOURCES += \
    DataBase.cpp \
    EtapaConf.cpp \
    Producto.cpp \
    ThreadEtapa.cpp \
    main.cpp \
    mainwindow.cpp \
    threadcontador.cpp \
    threadhistograma.cpp \
    threadproduccion.cpp \
    ventanaetapa.cpp \
    ventanahistograma.cpp \
    ventanaprincipal.cpp

HEADERS += \
    DataBase.h \
    EstadoProducto.h \
    EtapaConf.h \
    Includes.h \
    Producto.h \
    TemplateQueue.h \
    ThreadEtapa.h \
    mainwindow.h \
    threadcontador.h \
    threadhistograma.h \
    threadproduccion.h \
    ventanaetapa.h \
    ventanahistograma.h \
    ventanaprincipal.h

FORMS += \
    mainwindow.ui \
    ventanaetapa.ui \
    ventanahistograma.ui \
    ventanaprincipal.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    determProb.asm \
    random.asm \
    test.asm \
    timeWait.asm

RESOURCES += \
    Resources.qrc
