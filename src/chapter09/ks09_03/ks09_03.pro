include ($$(TRAINDEVHOME)/src/gui_base.pri)

TEMPLATE	= app
LANGUAGE	= C++

CONFIG		+= qt

QT			+= widgets

TEMPDIR		= $$TRAIN_OBJ_PATH/chapter09/ks09_03

DESTDIR     = $$TRAIN_BIN_PATH

INCLUDEPATH += $$TRAIN_INCLUDE_PATH/

TRANSLATIONS += $$TRAIN_SRC_PATH/translations/ks09_03.ts

#FORMS 		+= dialogbase.ui
				
HEADERS		+=  $$TRAIN_SRC_PATH/gui_base.pri \
				ks09_03.pro \
				textedit.h \
				mainwindow.h
				   
	
SOURCES    +=  main.cpp \
				textedit.cpp \
				mainwindow.cpp
				
RESOURCES	+= ks09_03.qrc
				
OBJECTS_DIR = $$TEMPDIR
MOC_DIR		= $$TEMPDIR/moc
UI_DIR		= $$TEMPDIR/ui

debug_and_release {
	CONFIG(debug, debug|release) {		
		LIBS += -lbasedll_d
		TARGET = ks09_03_d
	}
	CONFIG(release, debug|release) {			   
		LIBS += -lbasedll
		TARGET	= ks09_03
	}
} else {
	debug {		
		LIBS += -lbasedll_d
		TARGET	= ks09_03_d
	}
	release {
		LIBS += -lbasedll
		TARGET 	= ks09_03
	}
}