#pragma once
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include "network_global.h"

class NETWORK_EXPORT HttpClient : public QObject {
    Q_OBJECT
public:
    explicit HttpClient(QObject *parent = nullptr);

    void post(const QString &url,
              const QJsonObject &payload,
              std::function<void(QJsonDocument)> onSuccess,
              std::function<void(QString)> onError);
private slots:
    void onFinished();
private:
    QNetworkAccessManager m_mgr;
};
