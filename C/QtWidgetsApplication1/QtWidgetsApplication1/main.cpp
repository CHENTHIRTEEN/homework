#include "QtWidgetsApplication1.h"
#include <QtWidgets/QApplication>
#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QFile>
#include <QEventLoop>
#define URLSTR "https://authserver.nuist.edu.cn/authserver/login?service=http%3A%2F%2Fmy.nuist.edu.cn%2F"
#define FILE_NAME "D:/code.txt"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QUrl url(URLSTR);
    QNetworkAccessManager manager;
    QEventLoop loop;
    qDebug() << "Reading code from" << URLSTR;
    QNetworkReply* reply = manager.get(QNetworkRequest(url));
    QObject::connect(reply,&QNetworkReply::finished,&loop,&QEventLoop::quit);
    //开启子事件循环
    loop.exec();

    //将读到的信息写入文件
    QString code = reply->readAll();
    QFile file(FILE_NAME);
    file.open(QIODevice::WriteOnly);
    QTextStream out(&file);
    out << code << endl;
    file.close();
    qDebug() << "Finished, the code have written to " << FILE_NAME;
    QtWidgetsApplication1 w;
    w.show();
    return a.exec();
}
