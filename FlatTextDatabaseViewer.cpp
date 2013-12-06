
#include <QtGui>
#include "FlatTextDatabaseViewer.h"
#include "FlatTextDatabase.h"
#include <QStringList>

FlatTextDatabaseViewer::FlatTextDatabaseViewer(QWidget *parent)
    : QWidget(parent)
 {
     FlatTextDatabase* instance = FlatTextDatabase::getInstance();

     QString fileName = QFileDialog::getOpenFileName(this);
     if (!fileName.isEmpty())
     {
        instance->readRecord(fileName.toStdString());
     }

 	setWindowTitle(tr("FlatTextDatabaseViewer"));
    resize(400, 200);
    tableWidget = new QTableWidget(this);
    QStringList labels;
     labels << "OrderID" << "owner" <<"amount";
    
     std::vector<order> data = instance->getData();
    tableWidget->setColumnCount(3);
    tableWidget->setHorizontalHeaderLabels(labels);
    
     for (unsigned i =0; i< data.size(); ++i) {
         int newRow = tableWidget->rowCount();
         
         tableWidget->insertRow(newRow);
         
         QTableWidgetItem *item1 = new QTableWidgetItem;
         item1->setText(QString::number(data[i].orderID));
         tableWidget->setItem(newRow, 0, item1);
         QTableWidgetItem *item2 = new QTableWidgetItem;
         item2->setText(QString(data[i].owner));
         tableWidget->setItem(newRow, 1, item2);
         QTableWidgetItem *item3 = new QTableWidgetItem;
         item3->setText(QString::number(data[i].amount));
        tableWidget->setItem(newRow,2, item3);
                        
     }
    
    

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(tableWidget, 0,0);
    setLayout(mainLayout);
}