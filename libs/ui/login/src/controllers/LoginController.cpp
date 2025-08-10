#include "LoginController.h"
#include <QRegularExpression>

LoginController::LoginController(QObject *parent)
    : QObject(parent)
{
    connect(&m_store, &LoginStore::errorChanged, this, [this] {
        if (!m_store.error().isEmpty())
            emit error(m_store.error());
    });
    connect(&m_store, &LoginStore::loginSuccess,
            this, &LoginController::success);
}

void LoginController::login(const QString &u, const QString &p)
{
    m_store.login(u, p);
}

bool LoginController::checkInput(const QString &u, const QString &p)
{
    // 账号：手机 11 位 或 邮箱
    static QRegularExpression userRe(R"(^(1[3-9]\d{9}|[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,})$)");
    // 密码：8-16 位，至少两种字符
    static QRegularExpression pwdRe(R"(^[A-Za-z0-9!@#$%^&*()\-_=+\\\[\]{}|;:'",.<>/?]{8,16}$)");

    return userRe.match(u).hasMatch() && pwdRe.match(p).hasMatch();
}
