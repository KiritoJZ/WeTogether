#pragma once
#include <QNetworkReply>
#include <QJsonObject>

class ApiClient : public QObject {
    Q_OBJECT
public:
    explicit ApiClient(QObject *parent = nullptr);

    void login(const QString &email, const QString &pwd);
    void fetchFriends(const QString &token);

signals:
    void loginOK(const QString &token, const QJsonObject &user);
    void loginFailed(const QString &msg);
    void friendsReady(const QJsonArray &list);

private:
    QNetworkAccessManager *m_mgr;
};
