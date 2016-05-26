#include "mainwindow.h"
#include "QDesktopServices"
void MainWindow::Print(){
    // JavaScript code for creating Google Maps page
    QString b = "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\">";
    QString b1 = "<html xmlns=\"http://www.w3.org/1999/xhtml\" xml:lang=\"ru\" lang=\"ru\"><head>";
    QString b2 = "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=windows-1251\"/>";
    QString b3 = "<meta http-equiv=\"Content-Language\" content=\"ru\"/>";
    QString b4 = "<title>Google Maps API v3</title><style type=\"text/css\">";
    QString b5 = "html { height: 100% }";
    QString b6 = "body { height: 100%; margin: 0px; padding: 0px }";
    QString b7 = "#map_canvas { height: 100% }";
    QString b8 = "</style></head><body onload=\"initialize()\"><div id=\"map_canvas\" style=\"width:100%; height:100%\"></div>";
    QString b9 = "<script type=\"text/javascript\" src=\"http://maps.google.com/maps/api/js?sensor=false\"></script><script type=\"text/javascript\">";
    QString b10 = "function initialize() {var latlng = new google.maps.LatLng(49.99, 36.23), myOptions = {zoom: 8, center: latlng, mapTypeId: google.maps.MapTypeId.ROADMAP};";
    QString b11 = "var map = new google.maps.Map(document.getElementById(\"map_canvas\"), myOptions); // Êîîðäèíàòû äëÿ ëèíèè";
    QString b12 = "var polylineCoords = [new google.maps.LatLng(59.95, 30.40), new google.maps.LatLng(59.95, 30.50), new google.maps.LatLng(45.05, 30.50)];";
    QString b13 = "var polyline = new google.maps.Polyline({path: polylineCoords, strokeColor: \"#FF0000\", strokeOpacity: 1.0, strokeWeight: 2 });";
    QString b14 = "polyline.setMap(map);}";
    QString b15 = "</script></body></html>";
    // Set points coordinates
    QString main_string="var polylineCoords = [";
    for(int i = 0;i<latitude1.count();i++){
        QString buf = "new google.maps.LatLng("+QString::number(latitude1[i])+", "+QString::number(longitude1[i])+"), ";
        if(i==latitude1.count()-1){
           buf=buf+"];";
        }
        main_string=main_string+buf;
    }
    
    b12=main_string;

    //Saving //
    QString FileSaving = QFileDialog::getSaveFileName(this,"Save html document for viewing plane trajectory","D:/","File html(*.html)");
    //qDebug()<<FileSaving;
    QFile file(FileSaving);
    if (FileSaving.isEmpty()){
        file.close();
    }else{
        if(!file.open(QIODevice::WriteOnly|QIODevice::Text)){
            QMessageBox::StandardButton Save;
            Save=QMessageBox::critical(this,"Îøèáêà","Îøèáêà ñîõðàíåíèÿ",QMessageBox::Ok);
            return;
        }
    }
    QTextStream save(&file);
    save << b << endl;
    save << b1 << endl;
    save << b2 << endl;
    save << b3 << endl;
    save << b4 << endl;
    save << b5 << endl;
    save << b6 << endl;
    save << b7 << endl;
    save << b8 << endl;
    save << b9 << endl;
    save << b10 << endl;
    save << b11 << endl;
    save << b12 << endl;
    save << b13 << endl;
    save << b14 << endl;
    save << b15 << endl;
    file.close();
    QDesktopServices::openUrl(QUrl("file:///"+FileSaving, QUrl::TolerantMode));
    }

