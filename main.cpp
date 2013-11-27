#include <QApplication>
#include "FlatTextDatabaseViewer.h"
 
int main(int argc, char *argv[])
 {
    QApplication app(argc, argv);
    FlatTextDatabaseViewer viewer;
    viewer.show();
    return app.exec();
}