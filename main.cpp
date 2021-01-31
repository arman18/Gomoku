#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <Uibridge.h>
#include <QQmlContext>
#include <QtQuick>


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    Uibridge *m_Uibridge = new Uibridge();
    engine.rootContext()->setContextProperty("uiBridge", m_Uibridge);
    engine.rootContext()->setContextProperty("Length", int(25));
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    //const url (QUrl(QStringLiteral("qrc:/main.qml")));



    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();

}

/*QObject* rof = engine.rootObjects().first();

    QVariant firstArg("Arg++");
    QVariant retValue;

    QMetaObject::invokeMethod(rof,"myQmlFunction",Q_RETURN_ARG(QVariant,retValue),Q_ARG(QVariant,firstArg));

    qDebug() << retValue ;*/
