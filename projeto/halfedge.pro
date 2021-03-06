# #####################################################################
# raytrace qmake
# #####################################################################
QT += core
QT += widgets

# app indica ao qmake que estamos montando uma aplicacão
TEMPLATE = app

# Diretórios onde estarão outros arquivos do projeto
DEPENDPATH += src
INCLUDEPATH += .
INCLUDEPATH += src

# Pasta onde os arquivos temporarios de compilacao ficaram armazenados
OBJECTS_DIR = tmp
MOC_DIR = tmp
RCC_DIR = tmp

# Diretorio onde os arquivos executaveis serao gerados
DESTDIR = bin

# Indica ao qmake que vamos utilizar a biblioteca qt
# com os modulos core e gui (que sao os que utilizaremos)
CONFIG += qt

# Indica se deve criar um makefile com suporte aos simbolos de debug ou nao
CONFIG += debug

# CONFIG += release
# #DEFINES += QT_NO_DEBUG_OUTPUT
# #DEFINES += QT_NO_WARNING_OUTPUT
# Habilitando os warnings do compilador no makefile.
CONFIG += warn_on

# Se estivermos em uma plataforma Windows
win32 { 
    # Se estiver em modo debug, incluimos as bibliotecas de console para podermos
    # utilizar funcoes de debug como a qDebug():
    # http://doc.qtsoftware.com/4.5/qtglobal.html#qDebug
    debug:CONFIG += console
    
    # Então configura de acordo.
    CONFIG += windows
}

# # Windows common build here
# Se estivermos em ambiente unix
unix:CONFIG += x11

# Nome do executavel criado
TARGET = halfedge

# # ADICIONEM OS ARQUIVOS AQUI ##
# Arquivos .h
HEADERS += \
    src/MainWindow.h \
    src/halfedge.h \
    src/point.h \
    src/vertex.h \
    src/face.h \
    src/io.h \
    src/halfedgewidget.h

# Arquivos .cpp
SOURCES += \
    src/MainWindow.cpp \
    src/halfedge.cpp \
    src/point.cpp \
    src/main.cpp \
    src/vertex.cpp \
    src/face.cpp \
    src/io.cpp \
    src/halfedgewidget.cpp

# Arquivos dos resources (imagens por exemplo)
RESOURCES += halfedge.qrc
