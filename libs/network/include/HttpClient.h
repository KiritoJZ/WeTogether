#pragma once
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

#if defined(NETWORKLIB_STATIC)
#  define NETWORK_EXPORT
#elif defined(NETWORKLIB_BUILD)
#  define NETWORK_EXPORT Q_DECL_EXPORT
#else
#  define NETWORK_EXPORT Q_DECL_IMPORT
#endif

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
