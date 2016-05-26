#include "mainwindow.h"
#include "math.h"
void MainWindow::LoadFile(){
    QString FileLoading = QFileDialog::getOpenFileName(this,"Загрузить исходные данные","D:/","File txt(*.txt)");
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

// Считывание всех строк из текстового документа
while(1){
  QString buf = fin.readLine();
  if(buf==""){
     break;
  }
  text.append(buf);
}
file.close();
// Конец считывания
// Фильтрация строк
// Проверка на корректность данных
int count_of_GPGGA = 0;
for(int i=0;i<text.count();i++){
    if(!text[i].contains("GPGGA")){
        text[i].clear();
    }
    if(text[i].contains("GPGGA")){
       count_of_GPGGA=count_of_GPGGA+1;
    }
}
// Если GPGGA - не обнаружено - ошибка и закрытие приложения
if (count_of_GPGGA==0){
    QMessageBox::StandardButton war;
    war=QMessageBox::critical(this,"Ошибка!","Некорректное содержание \n входного файла!",QMessageBox::Ok);
    if(war == QMessageBox::Ok){
       Quit();
   }
}
// Массив только чистых строк
for(int i=0;i<text.count();i++){
    if(text[i]!=""){
        text_filtrated.append(text[i]);
    }
}
text.resize(1);
text.squeeze();
// Начало извлечения данных
for(int i=0;i<text_filtrated.count();i++){
    QStringList buf = text_filtrated[i].split("GPGGA,");
    QString buff = buf.takeLast();
    QStringList splitted = buff.split(",");
    // Фильтрация "ложных" строк (0 - плохой сигнал)
    // Занесение данных в массив для дальнейшей обработки
    if(splitted[5]!="0"){
        time.append(splitted[0]);
        latitude.append(splitted[1]);
        longitude.append(splitted[3]);
        height.append(splitted[8]);
    }
}

// Сортировка времени по часам, минутам, секундам
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
// Перевод широты из строки в число
for(int i=0;i<latitude.count();i++){
    QString buf = latitude[i];
    latitude1.append(buf.toFloat()/100);
}
// Перевод долготы из строки в число
for(int i=0;i<longitude.count();i++){
    QString buf = longitude[i];
    longitude1.append(buf.toFloat()/100);
}
// Перевод высоты из строки в число
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

