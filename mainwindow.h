#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtGui>
class MainWindow : public QMainWindow{
    Q_OBJECT
protected:
    // Массивы для обработки входных данных //
    QVector <QString> text;
    QVector <QString> text_filtrated;
    // Массивы для хранения "сырых" значений //
    QVector <QString> time;
    QVector <QString> latitude;
    QVector <QString> longitude;
    QVector <QString> height;
    // Масиивы для хранения численных значений //
    QVector <int> hours;
    QVector <int> minutes;
    QVector <int> seconds;
    QVector <int> time_difference;
    QVector <float> latitude1;
    QVector <float> longitude1;
    QVector <float> height1;
    QVector <float> distance;
    QVector <float> speed;
    QVector <double> course;
    ///// Элементы интерфейса /////
    QLabel *l_way, *lmid_speed, *lmax_height, *lmin_height, *lmax_speed, *lmin_speed, *ltotal_time;
    QTextEdit *te_way, *te_mid_speed, *te_max_height, *te_min_height, *te_max_speed, *te_min_speed, *te_total_time;
    QPushButton *pbQuit, *pbLoad, *pbPrint, *pbSave, *pbStat;
    QGridLayout *glMain;
    QWidget *wCenter;
    QHBoxLayout *VbLayout_First, *VbLayout_Second, *VbLayout_Third;
    QHBoxLayout *Layout_way, *Layout_midspeed, *Layout_max_h, *Layout_min_h, *Layout_max_speed, *Layout_min_speed, *Layout_time;
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void Calcutate();
public slots:
   void LoadFile();  
   void Print();
   void Save();
   void Quit();
   void Statistic();
};
#endif // MAINWINDOW_H
