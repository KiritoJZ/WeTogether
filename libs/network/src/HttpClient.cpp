#include "include/HttpClient.h"
#include <QNetworkRequest>
#include <QJsonDocument>

HttpClient::HttpClient(QObject *parent) : QObject(parent) {}

void HttpClient::post(const QString &url,
                      const QJsonObject &payload,
                      std::function<void(QJsonDocument)> onSuccess,
                      std::function<void(QString)> onError) {
    QNetworkRequest req((QUrl(url)));
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray body = QJsonDocument(payload).toJson();
    QNetworkReply *reply = m_mgr.post(req, body);
    connect(reply, &QNetworkReply::finished, this, [=]() mutable {
        reply->deleteLater();
        if (reply->error() != QNetworkReply::NoError) {
            onError(reply->errorString());
            return;
        }
        QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
        onSuccess(doc);
    });
}
void HttpClient::onFinished() {
    // 实现内容
}
