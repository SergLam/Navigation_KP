#include "mainwindow.h"
void MainWindow::Save(){
    QString FileSaving = QFileDialog::getSaveFileName(this,"Save data for plots building","D:/","File CSV(*.csv)");
    QFile file(FileSaving);
    if (FileSaving.isEmpty()){
        file.close();
    }else{
        if(!file.open(QIODevice::WriteOnly|QIODevice::Text)){
            QMessageBox::StandardButton Save;
            Save=QMessageBox::critical(this,"Error","File not opened",QMessageBox::Ok);
            return;
        }
    }
    QTextStream save(&file);
    save<<QObject::tr("latitude(°);longitude(°);Height(m);passed way(km);Flight time(hh,mm,ss);Speed(km/h);true course(°)\n");
    for(int i=0; i<speed.count(); i++){
        QString b = QString("%1").arg(latitude1[i], 0, 'g', 8);
        b.replace(".",",");
        save << b << ";";
        QString c = QString("%1").arg(longitude1[i], 0, 'g', 8);
        c.replace(".",",");
        save << c << ";";
        QString d = QString("%1").arg(height1[i], 0, 'g', 8);
        d.replace(".",",");
        save << d << ";";
        QString e = QString("%1").arg(distance[i], 0, 'g', 8);
        e.replace(".",",");
        save << e << ";";
        QString f = time[i];
        f.replace(".",",");
        save << f << ";";
        QString g = QString("%1").arg(speed[i], 0, 'g', 8);
        g.replace(".",",");
        save << g << ";";
        QString h = QString("%1").arg(course[i], 0, 'g', 8);
        h.replace(".",",");
        save << h << ";"<<endl;
    }
    file.close();
}


