#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <number.h>

#include <QQuickView>
#include <QQmlContext>
#include <QQmlEngine>
#include <QCoreApplication>
#include <QVariantList>
#include <QStringList>

int main(int argc, char *argv[])
{

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QVariantList listHex;
    QVariantList listDec;
    QVariantList listOct;
    QVariantList listBin;


    qmlRegisterType<Number>("ToDo",1,0,"Number");

    Number* number = new Number();
    number->castToDecimal(DEC_RADIX_TYPE);
    number->setNumber();
    int a = number->getIndexHex();
    qDebug("das: %d",a);
    int* arrHex = number->getHexNumberToShow();
    int* arrDec = number->getDecNumberToShow();
    int* arrOct = number->getOctNumberToShow();
    int* arrBin = number->getBinNumberToShow();
    for(int i = 0; i<100; i++){
        listHex.append(arrHex[i]);
        listDec.append(arrDec[i]);
        listOct.append(arrOct[i]);
        listBin.append(arrBin[i]);
    }

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    QObject* root = engine.rootObjects().first();
    root->setProperty("numberHex", listHex);
    root->setProperty("numberDec", listDec);
    root->setProperty("numberOct",listOct);
    root->setProperty("numberBin",listBin);

    return app.exec();
}
