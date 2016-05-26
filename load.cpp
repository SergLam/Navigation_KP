#include "mainwindow.h"
#include "math.h"
void MainWindow::LoadFile(){
    QString FileLoading = QFileDialog::getOpenFileName(this,"Load input file(GPGGA)","D:/","File txt(*.txt)");
    QFile file(FileLoading);
    QTextStream fin(&file);
    if (FileLoading.isEmpty()){
        file.close();
    }else{
        if(!file.open(QIODevice::ReadOnly|
                      QIODevice::Text)){
            QMessageBox::StandardButton Load;
            Load=QMessageBox::critical(this,"Error","Error_opening_file",QMessageBox::Ok);
            return;
        }
    }
pbLoad->setDisabled(true);

while(1){
  QString buf = fin.readLine();
  if(buf==""){
     break;
  }
  text.append(buf);
}
file.close();

int count_of_GPGGA = 0;
for(int i=0;i<text.count();i++){
    if(!text[i].contains("GPGGA")){
        text[i].clear();
    }
    if(text[i].contains("GPGGA")){
       count_of_GPGGA=count_of_GPGGA+1;
    }
}

if (count_of_GPGGA==0){
    QMessageBox::StandardButton war;
    war=QMessageBox::critical(this,"Incorrect input data!",QMessageBox::Ok);
    if(war == QMessageBox::Ok){
       Quit();
   }
}

for(int i=0;i<text.count();i++){
    if(text[i]!=""){
        text_filtrated.append(text[i]);
    }
}
text.resize(1);
text.squeeze();

for(int i=0;i<text_filtrated.count();i++){
    QStringList buf = text_filtrated[i].split("GPGGA,");
    QString buff = buf.takeLast();
    QStringList splitted = buff.split(",");

    if(splitted[5]!="0"){
        time.append(splitted[0]);
        latitude.append(splitted[1]);
        longitude.append(splitted[3]);
        height.append(splitted[8]);
    }
}

for(int i=0;i<time.count();i++){
    QStringList buf = time[i].split(".");
    buf.removeLast();
    QString buffer = buf.join("");
    QStringList buff = buffer.split("");
    buff.removeAll("");
    if(buff[0]=="0"){
      buff.removeAt(0);
    }
    QString hour = buff[0];
    hours.append(hour.toInt());
    QString min = buff[1]+buff[2];
    minutes.append(min.toInt());
    QString sec = buff[3]+buff[4];
    seconds.append(sec.toInt());
}

for(int i=0;i<latitude.count();i++){
    QString buf = latitude[i];
    latitude1.append(buf.toFloat()/100);
}

for(int i=0;i<longitude.count();i++){
    QString buf = longitude[i];
    longitude1.append(buf.toFloat()/100);
}

for(int i=0;i<height.count();i++){
    QString buf = height[i];
    float buff = buf.toFloat();
    if(buff<0){
      buff=fabs(buff);
    }
    height1.append(buff);
}
Calcutate();
}

