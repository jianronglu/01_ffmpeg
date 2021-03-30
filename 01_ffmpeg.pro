QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    receiver.cpp \
    sender.cpp

HEADERS += \
    mainwindow.h \
    receiver.h \
    sender.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


win32 {
    INCLUDEPATH += F:/Dev/ffmpeg-4.3.2_3/include
    LIBS += -LF:/Dev/ffmpeg-4.3.2/lib \
            -lavcodec \
            -lavdevice \
            -lavfilter \
            -lavformat \
            -lavutil \
            -lpostproc \
            -lswscale \
            -lswresample
}

# mac
macx {
    FFMPEG_HOME = /usr/local/Cellar/ffmpeg/4.3.2_3
    INCLUDEPATH += $${FFMPEG_HOME}/include
    LIBS += -L$${FFMPEG_HOME}/lib \
            -lavcodec \
            -lavdevice \
            -lavfilter \
            -lavformat \
            -lavutil \
            -lpostproc \
            -lswscale \
            -lswresample \
            -lavresample
}
