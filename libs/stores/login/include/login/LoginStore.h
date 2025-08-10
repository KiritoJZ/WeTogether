#pragma once
#include <QObject>
#include "GatewayConfig.h"
#include "HttpClient.h"
#include "stores_login_globa.h"

class STORES_LOGIN_EXPORT LoginStore : public QObject {
    Q_OBJECT
    Q_PROPERTY(bool busy READ busy NOTIFY busyChanged)
    Q_PROPERTY(QString error READ error NOTIFY errorChanged)
    Q_PROPERTY(bool loggedIn READ loggedIn NOTIFY loggedInChanged)
public:
    explicit LoginStore(QObject *parent = nullptr);

    Q_INVOKABLE void login(const QString &user, const QString &pass);
    bool busy() const;
    QString error() const;
    bool loggedIn() const;

signals:
    void busyChanged();
    void errorChanged();
    void loggedInChanged();
    void loginSuccess(const QVariantMap &data);
private:
    HttpClient m_http;
    GatewayConfig m_gc;
    bool m_busy = false;
    QString m_error;
    bool m_loggedIn = false;
};
