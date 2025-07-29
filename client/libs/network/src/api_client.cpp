#include "network/api_client.h"
#include <QNetworkRequest>
#include <QJsonDocument>
#include <qjsonarray.h>

static const QString BASE = "http://localhost:8080";

ApiClient::ApiClient(QObject *p): QObject(p), m_mgr(new QNetworkAccessManager(this)) {}

void ApiClient::login(const QString &email, const QString &pwd) {
    QNetworkRequest req(QUrl(BASE + "/login"));
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject body{{"email", email}, {"password", pwd}};
    auto reply = m_mgr->post(req, QJsonDocument(body).toJson());
    connect(reply, &QNetworkReply::finished, this, [reply, this]{
        auto doc = QJsonDocument::fromJson(reply->readAll());
        if (reply->error() == QNetworkReply::NoError && doc["code"].toInt() == 0) {
            emit loginOK(doc["token"].toString(), doc["user"].toObject());
        } else {
            emit loginFailed(doc["msg"].toString());
        }
        reply->deleteLater();
    });
}

void ApiClient::fetchFriends(const QString &token) {
    QNetworkRequest req(QUrl(BASE + "/user/friends"));
    req.setRawHeader("Authorization", token.toUtf8());
    auto reply = m_mgr->get(req);
    connect(reply, &QNetworkReply::finished, this, [reply, this]{
        auto doc = QJsonDocument::fromJson(reply->readAll());
        if (reply->error() == QNetworkReply::NoError && doc.isArray())
            emit friendsReady(doc.array());
        reply->deleteLater();
    });
}
