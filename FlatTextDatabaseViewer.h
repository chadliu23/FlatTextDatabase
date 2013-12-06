#ifndef FALTTEXTDATABASEVIEWER_H
#define FALTTEXTDATABASEVIEWER_H
 
#include <QWidget>
 class QTableWidget;
class FlatTextDatabaseViewer : public QWidget
 {
    Q_OBJECT
 
public:
    FlatTextDatabaseViewer(QWidget *parent = 0);
 
protected:
    //void paintEvent(QPaintEvent *event);
    QTableWidget *tableWidget;
};
 
#endif