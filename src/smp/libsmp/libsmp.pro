# Определение проекта
PROJECTNAME=libsmp

# Глобальные настройки
include(../../global.pri)

# Тип проекта
TEMPLATE = lib

# Имя собираемого модуля
TARGET = smp$${POST}

# Опции сборки
include(../../options.pri)

# Настройки QT
QT += core

# Подключаемые библиотеки

include(../../log4app.pri)

LIBS += -lconfigmanager$${POST}

libsmp_includedir = $$top_includedir/libsmp
INCLUDEPATH += $$top_includedir
# Экспортируемые заголовочные файлы
libheaders.path = $$top_installdir/$$root_prefix_dev/include/$${PROJECTNAME}/
libheaders.files =                                                  \
    $$libsmp_includedir/global.h\
    $$libsmp_includedir/model/nodeinterface.h \
    $$libsmp_includedir/model/prefixtree.h \
    $$libsmp_includedir/model/prefixnode.h \
    $$libsmp_includedir/model/modelinterface.h \
    $$libsmp_includedir/model/modelmain.h \
    $$libsmp_includedir/controller/controllerinterface.h

# Заголовочные файлы
HEADERS  += $${libheaders.files} \
    ../../include/libsmp/controller/controllermain.h



# Исходники
SOURCES += \
    model/prefixtree.cpp \
    model/prefixnode.cpp \
    model/modelmain.cpp \
    ../../include/libsmp/controller/controllermain.cpp