include ($$(TRAINDEVHOME)/src/gui_base.pri)

TEMPLATE	= app
LANGUAGE	= C++

CONFIG		+= qt
QT			+= widgets xml

TEMPDIR		= $$TRAIN_OBJ_PATH/chapter09/ks09_15

DESTDIR     = $$TRAIN_BIN_PATH

INCLUDEPATH += $$TRAIN_INCLUDE_PATH/

TRANSLATIONS += $$TRAIN_SRC_PATH/translations/ks09_15.ts

#FORMS 		+= dialogbase.ui
				
HEADERS		+=  $$TRAIN_SRC_PATH/gui_base.pri \
				ks09_15.pro \
				graphview.h \
				mainwindow.h \
				rectitem.h \
				ellipseitem.h
				   
	
SOURCES    +=  main.cpp \
				graphview.cpp \
				mainwindow.cpp \
				rectitem.cpp \
				ellipseitem.cpp
				
RESOURCES	+= ks09_15.qrc
				
OBJECTS_DIR = $$TEMPDIR
MOC_DIR		= $$TEMPDIR/moc
UI_DIR		= $$TEMPDIR/ui

debug_and_release {
	CONFIG(debug, debug|release) {		
		LIBS += -lbasedll_d
		TARGET = ks09_15_d
	}
	CONFIG(release, debug|release) {			   
		LIBS += -lbasedll
		TARGET	= ks09_15
	}
} else {
	debug {		
		LIBS += -lbasedll_d
		TARGET	= ks09_15_d
	}
	release {
		LIBS += -lbasedll
		TARGET 	= ks09_15
	}
}