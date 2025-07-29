#include "stores/login_store.h"
#include "network/api_client.h"

LoginStore &LoginStore::instance() { static LoginStore s; return s; }
LoginStore::LoginStore(QObject *p) : QObject(p) {}

void LoginStore::login(const QString &email, const QString &pwd) {
    auto *api = new ApiClient(this);
    connect(api, &ApiClient::loginOK, this, [=, this](const QString &tok, const QJsonObject &user){
        m_token = tok;
        emit loginOK(tok, user["name"].toString());
        api->deleteLater();
    });
    connect(api, &ApiClient::loginFailed, this, [=, this](const QString &msg){
        emit loginFailed(msg);
        api->deleteLater();
    });
    api->login(email, pwd);
}
