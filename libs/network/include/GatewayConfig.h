#pragma once
#include <QObject>
#include <QString>

#if defined(NETWORKLIB_STATIC)
#  define NETWORK_EXPORT
#elif defined(NETWORKLIB_BUILD)
#  define NETWORK_EXPORT Q_DECL_EXPORT
#else
#  define NETWORK_EXPORT Q_DECL_IMPORT
#endif

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
