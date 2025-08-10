#pragma once
#include <QObject>
#include <qqmlintegration.h>
#include "login/login_store.h"

#if defined(UI_LOGIN_STATIC)
#  define UI_LOGIN_EXPORT
#elif defined(UI_LOGIN_BUILD)
#  define UI_LOGIN_EXPORT Q_DECL_EXPORT
#else
#  define UI_LOGIN_EXPORT Q_DECL_IMPORT
#endif

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
