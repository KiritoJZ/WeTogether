#include <QGuiApplication>
#include <QDirIterator>
#include <QDebug>
#include <QQmlApplicationEngine>
#include <QQuickStyle>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQuickStyle::setStyle("Basic");

    QQmlApplicationEngine engine;

    QString qmlStagePath = QCoreApplication::applicationDirPath()
                           + "/../qml";
    engine.addImportPath(qmlStagePath);

    engine.loadFromModule("Main", "Main");

    qDebug() << engine.importPathList();

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
