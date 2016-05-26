#include "mainwindow.h"
void MainWindow::Statistic(){

    float avgSpeed=0;
    float max_h =height1[0];
    float min_h =height1[0];
    float max_speed=speed[0];
    float min_speed=speed[0];
    for(int i=0;i<speed.count();i++){
        avgSpeed+=speed[i];
        if(max_h<height1[i]){
           max_h =height1[i] ;
        }
        if(min_h>height1[i]){
           min_h=height1[i] ;
        }
        if(max_speed<speed[i]){
            max_speed=speed[i];
        }
        if(min_speed>speed[i]){
           min_speed=speed[i] ;
        }
    }
    avgSpeed=avgSpeed/speed.count();
    double time_of_flight = (hours[hours.count()-1]-hours[0])*3600+(minutes[minutes.count()-1]-minutes[0])*60+(seconds[seconds.count()-1]-seconds[0]);
    te_way->setText(QString::number(distance[distance.count()-1]));
    te_mid_speed->setText(QString::number(avgSpeed));
    te_max_height->setText(QString::number(max_h));
    te_min_height->setText(QString::number(min_h));
    te_max_speed->setText(QString::number(max_speed));
    te_min_speed->setText(QString::number(min_speed));
    te_total_time->setText(QString::number(time_of_flight/60));
}

