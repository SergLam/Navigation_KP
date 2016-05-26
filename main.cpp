#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
QApplication a(argc, argv);
QTranslator qtHelpTranslator;
qtHelpTranslator.load("qt_help_ru",QLibraryInfo::location(QLibraryInfo::TranslationsPath));
a.installTranslator(&qtHelpTranslator);
QTranslator qtTranslator;
qtTranslator.load("qt_ru",QLibraryInfo::location(QLibraryInfo::TranslationsPath));
a.installTranslator(&qtTranslator);
QTextCodec::setCodecForLocale( QTextCodec::codecForName("ANSI"));
QTextCodec::setCodecForCStrings( QTextCodec::codecForLocale());
QTextCodec::setCodecForTr( QTextCodec::codecForLocale());
MainWindow w;
w.show();
return a.exec();

}



