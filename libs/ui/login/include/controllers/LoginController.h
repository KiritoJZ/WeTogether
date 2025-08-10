#pragma once
#include <QObject>
#include <qqmlintegration.h>
#include "ui_login_global.h"
#include "login/LoginStore.h"

class UI_LOGIN_EXPORT LoginController : public QObject
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit LoginController(QObject *parent = nullptr);
    Q_INVOKABLE void login(const QString &u, const QString &p); 
    Q_INVOKABLE bool checkInput(const QString &u, const QString &p);
signals:
    void success(const QVariantMap &data);
    void error(const QString &msg);
private:
    LoginStore m_store;
};
