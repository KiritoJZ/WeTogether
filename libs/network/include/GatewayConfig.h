#pragma once
#include <QObject>
#include <QString>
#include <network_global.h>

class NETWORK_EXPORT GatewayConfig : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString baseUrl READ baseUrl NOTIFY baseUrlChanged)
public:
    explicit GatewayConfig(QObject *parent = nullptr);
    QString baseUrl() const;

    Q_INVOKABLE void reloadFromFile(const QString &path = "config.json");
signals:
    void baseUrlChanged();
private:
    QString m_baseUrl;
};
