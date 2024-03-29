include ($$(TRAINDEVHOME)/src/gui_base.pri)

TEMPLATE	= app
LANGUAGE	= C++

QT			+= widgets

TEMPDIR		= $$TRAIN_OBJ_PATH/chapter13/ks13_01

DESTDIR     = $$TRAIN_BIN_PATH

INCLUDEPATH += $$TRAIN_INCLUDE_PATH/base/basedll

HEADERS		+=  $$TRAIN_SRC_PATH/gui_base.pri \
				ks13_01.pro \
				dialog.h \
				config.h \
				recvthread.h \
				sendthread.h
	
SOURCES    +=  main.cpp \
				dialog.cpp \
				config.cpp \
				recvthread.cpp \
				sendthread.cpp
				
FORMS		+= dialogbase.ui

OBJECTS_DIR = $$TEMPDIR
MOC_DIR		= $$TEMPDIR/moc
UI_DIR		= $$TEMPDIR/ui

debug_and_release {
	CONFIG(debug, debug|release) {
		LIBS   += -lbasedll_d   
		TARGET = ks13_01_d
	}
	CONFIG(release, debug|release) {			   
		LIBS   += -lbasedll				   
		TARGET	= ks13_01
	}
} else {
	debug {
		LIBS   += -lbasedll_d		
		TARGET	= ks13_01_d
	}
	release {			   
		LIBS   += -lbasedll		
		TARGET 	= ks13_01
	}
}