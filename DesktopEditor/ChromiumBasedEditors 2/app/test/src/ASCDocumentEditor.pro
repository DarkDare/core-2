QT  += core gui widgets printsupport

TEMPLATE = app
CONFIG += app_bundle

CONFIG -= debug_and_release debug_and_release_target

CONFIG(debug, debug|release) {
    DESTDIR = $$PWD/build/windows/Debug
} else {
    DESTDIR = $$PWD/build/windows/Release
}

win32:contains(QMAKE_TARGET.arch, x86_64):{
    PLATFORM_BUILD = win64
    message(windows64)
}
win32:!contains(QMAKE_TARGET.arch, x86_64):{
    PLATFORM_BUILD = win32
    message(windows32)
}

CONFIG(debug, debug|release) {
    PLATFORM_BUILD2 = $$PLATFORM_BUILD/debug
    message(debug)
} else {
    PLATFORM_BUILD2 = $$PLATFORM_BUILD
}

include($$PWD/AscDocumentEditor.pri)

SOURCES += \
    $$PWD/main.cpp

LIBS += -L$$PWD/../../cefbuilds/$$PLATFORM_BUILD -llibcef
LIBS += -L$$PWD/../../corebuilds/$$PLATFORM_BUILD2 -lascdocumentscore