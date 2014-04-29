include_directories(if inc)

set(FSM_HEADERS inc/MainWindow.h inc/HelpViewer.h inc/DocumentEditor.h
           inc/ViewStructureWidget.h inc/Menu.h)
set(FSM src/main.cpp src/MainWindow.cpp src/HelpViewer.cpp src/DocumentEditor.cpp 
           src/ViewStructureWidget.cpp src/Menu.cpp)
QT4_WRAP_CPP(structureddocument_HEADERS_MOC ${FSM})

