QT -= gui

CONFIG += c++17 console
CONFIG -= app_bundle
#QT_CONFIG -= no-pkg-config
CONFIG  += link_pkgconfig
PKGCONFIG += opencv4
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0



SOURCES += \
        example/main.cpp \
        src/LKOFlow/LKOFlow.cpp \
        src/SuperResolution/FrameBuffer/FrameBuffer.cpp \
        src/SuperResolution/SuperResolutionBase.cpp \
        src/Utils/Utils.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    example/FrameSource/CaptureFrameSource.hpp \
    example/FrameSource/EmptyFrameSource.hpp \
    example/FrameSource/FrameSourceFactory.h \
    example/FrameSource/ImageListFrameSource.hpp \
    example/FrameSource/ImageListReader/ImageListReader.hpp \
    example/FrameSource/ImageListReader/ImageListReaderBase.hpp \
    example/FrameSource/VideoFrameSource.hpp \
    example/MultiFrameProcesser.hpp \
    include/FrameBuffer/FrameBuffer.h \
    include/FrameSource/FrameSource.h \
    include/LKOFlow/LKOFlow.h \
    include/SuperResolution/PropsStruct.h \
    include/SuperResolution/SuperResolutionBase.h \
    include/SuperResolution/SuperResolutionFactory.h \
    include/Utils/Utils.h


