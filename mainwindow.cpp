#include "mainwindow.h"
#include "math.h"
#include <ctime>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Statistic display elements //
    // Labels
    l_way = new QLabel("Ñóììàðíàÿ äëèííà ìàðøðóòà ïîëåòà(êì):");
    lmid_speed = new QLabel("Ñðåäíÿÿ ñêîðîñòü ïîëåòà(êì/÷):");
    lmax_height = new QLabel("Ìàêñ. âûñîòà ïîëåòà(ì):");
    lmin_height = new QLabel("Ìèí. âûñîòà ïîëåòà(ì):");
    lmax_speed = new QLabel("Ìàêñ. ñêîðîñòü ïîëåòà(êì/÷):");
    lmin_speed = new QLabel("Ìèí. ñêîðîñòü ïîëåòà(êì/÷):");
    ltotal_time = new QLabel("Îáùåå âðåìÿ ïîëåòà(ìèí):");
    // Text Edits
    te_way = new QTextEdit;
    te_way->setMaximumHeight(25);
    te_mid_speed = new QTextEdit;
    te_mid_speed->setMaximumHeight(25);
    te_max_height = new QTextEdit;
    te_max_height->setMaximumHeight(25);
    te_min_height = new QTextEdit;
    te_min_height->setMaximumHeight(25);
    te_max_speed = new QTextEdit;
    te_max_speed->setMaximumHeight(25);
    te_min_speed = new QTextEdit;
    te_min_speed->setMaximumHeight(25);
    te_total_time = new QTextEdit;
    te_total_time->setMaximumHeight(25);
    //
    te_way->setReadOnly(true);
    te_mid_speed->setReadOnly(true);
    te_max_height->setReadOnly(true);
    te_min_height->setReadOnly(true);
    te_max_speed->setReadOnly(true);
    te_min_speed->setReadOnly(true);
    te_total_time->setReadOnly(true);
    // Buttons
    pbQuit = new QPushButton("Âûõîä");
    pbPrint = new QPushButton("Ïîêàçàòü òðàåêòîðèþ ïîëåòà");
    pbLoad = new QPushButton("Çàãðóçèòü äàííûå");
    pbSave = new QPushButton("Ñîõðàíèòü äàííûå äëÿ ãðàôèêîâ");
    pbStat = new QPushButton("Ïîêàçàòü ñòàòèñòèêó ïîëåòà");
    glMain = new QGridLayout;
    // Layouts for buttons
    VbLayout_First = new QHBoxLayout;
    VbLayout_Second = new QHBoxLayout;
    VbLayout_Third = new QHBoxLayout;
    // Layouts for statistic
    Layout_way = new QHBoxLayout;
    Layout_midspeed = new QHBoxLayout;
    Layout_max_h = new QHBoxLayout;
    Layout_min_h = new QHBoxLayout;
    Layout_max_speed = new QHBoxLayout;
    Layout_min_speed = new QHBoxLayout;
    Layout_time = new QHBoxLayout;
    //
    Layout_way->addWidget(l_way);
    Layout_way->addWidget(te_way);
    Layout_midspeed->addWidget(lmid_speed);
    Layout_midspeed->addWidget(te_mid_speed);
    Layout_max_h->addWidget(lmax_height);
    Layout_max_h->addWidget(te_max_height);
    Layout_min_h->addWidget(lmin_height);
    Layout_min_h->addWidget(te_min_height);
    Layout_max_speed->addWidget(lmax_speed);
    Layout_max_speed->addWidget(te_max_speed);
    Layout_min_speed->addWidget(lmin_speed);
    Layout_min_speed->addWidget(te_min_speed);
    Layout_time->addWidget(ltotal_time);
    Layout_time->addWidget(te_total_time);
    //
    wCenter = new QWidget;
    // Layouts //
    VbLayout_First->addWidget(pbLoad);
    VbLayout_First->addWidget(pbPrint);
    VbLayout_First->addStretch();
    ///
    VbLayout_Second->addWidget(pbSave);
    VbLayout_Second->addWidget(pbStat);
    VbLayout_Second->addStretch();
    ///
    VbLayout_Third->addWidget(pbQuit);
    VbLayout_Third->addStretch();
    ///
    glMain->addLayout(Layout_way,0,0);
    glMain->addLayout(Layout_midspeed,1,0);
    glMain->addLayout(Layout_max_h,2,0);
    glMain->addLayout(Layout_min_h,3,0);
    glMain->addLayout(Layout_max_speed,4,0);
    glMain->addLayout(Layout_min_speed,5,0);
    glMain->addLayout(Layout_time,6,0);
    glMain->addLayout(VbLayout_First,7,0);
    glMain->addLayout(VbLayout_Second,8,0);
    glMain->addLayout(VbLayout_Third,9,0);
    wCenter ->setLayout(glMain);  
    this ->setCentralWidget(wCenter);
    connect(pbLoad, SIGNAL(clicked()), this, SLOT(LoadFile()));
    connect(pbPrint, SIGNAL(clicked()), this, SLOT(Print()));
    connect(pbSave, SIGNAL(clicked()), this, SLOT(Save()));
    connect(pbQuit, SIGNAL(clicked()), this, SLOT(Quit()));
    connect(pbStat, SIGNAL(clicked()), this, SLOT(Statistic()));
    }
MainWindow::~MainWindow()
{
}
void MainWindow::Quit(){
    this->close();
}
