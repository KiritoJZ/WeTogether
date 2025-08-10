#include "login/login_store.h"
#include <qjsondocument.h>
#include <qjsonobject.h>

LoginStore::LoginStore(QObject *parent) : QObject(parent), m_http(this) {}

bool LoginStore::busy() const { return m_busy; }
QString LoginStore::error() const { return m_error; }
bool LoginStore::loggedIn() const { return m_loggedIn; }

void LoginStore::login(const QString &user, const QString &pass) {
    if (m_busy) return;
    m_busy = true;
    emit busyChanged();
    m_error.clear();
    emit errorChanged();

    QJsonObject payload{{"identifier", user}, {"password", pass}};
    QString url = m_gc.baseUrl() + "/api/auth";

    m_http.post(url, payload,
                [=, this](QJsonDocument doc) {
                    // 这里根据后端实际字段判断成功
                    bool ok = doc.object().value("code").toInt() == 1000;
                    if (ok) {
                        m_loggedIn = true;
                        emit loggedInChanged();
                        emit loginSuccess(doc.object().toVariantMap());
                    } else {
                        m_error = doc.object().value("msg").toString();
                        emit errorChanged();
                    }
                    m_busy = false;
                    emit busyChanged();
                },
                [=, this](QString err) {
                    m_error = err;
                    emit errorChanged();
                    m_busy = false;
                    emit busyChanged();
                });
}

