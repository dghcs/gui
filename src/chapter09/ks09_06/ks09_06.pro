include ($$(TRAINDEVHOME)/src/gui_base.pri)

TEMPLATE	= app
LANGUAGE	= C++

CONFIG		+= qt

QT			+= widgets

TEMPDIR		= $$TRAIN_OBJ_PATH/chapter09/ks09_06

DESTDIR     = $$TRAIN_BIN_PATH

INCLUDEPATH += $$TRAIN_INCLUDE_PATH/

TRANSLATIONS += $$TRAIN_SRC_PATH/translations/ks09_06.ts

#FORMS 		+= dialogbase.ui
				
HEADERS		+=  $$TRAIN_SRC_PATH/gui_base.pri \
				ks09_06.pro \
				textedit.h \
				mainwindow.h \
				splashscreen.h
				   
	
SOURCES    +=  main.cpp \
				textedit.cpp \
				mainwindow.cpp \
				splashscreen.cpp
				
RESOURCES	+= ks09_06.qrc
				
OBJECTS_DIR = $$TEMPDIR
MOC_DIR		= $$TEMPDIR/moc
UI_DIR		= $$TEMPDIR/ui

debug_and_release {
	CONFIG(debug, debug|release) {		
		LIBS += -lbasedll_d
		TARGET = ks09_06_d
	}
	CONFIG(release, debug|release) {			   
		LIBS += -lbasedll
		TARGET	= ks09_06
	}
} else {
	debug {		
		LIBS += -lbasedll_d
		TARGET	= ks09_06_d
	}
	release {
		LIBS += -lbasedll
		TARGET 	= ks09_06
	}
}