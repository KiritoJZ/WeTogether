#include "include/GatewayConfig.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

GatewayConfig::GatewayConfig(QObject *parent) : QObject(parent) {
    m_baseUrl="http://127.0.0.1:8080";
    reloadFromFile();
}
QString GatewayConfig::baseUrl() const { return m_baseUrl; }

void GatewayConfig::reloadFromFile(const QString &path) {
    QFile f(path);
    if (!f.open(QIODevice::ReadOnly)) return;
    auto obj = QJsonDocument::fromJson(f.readAll()).object();
    QString newUrl = obj.value("baseUrl").toString();
    if (newUrl != m_baseUrl) {
        m_baseUrl = newUrl;
        emit baseUrlChanged();
    }
}
