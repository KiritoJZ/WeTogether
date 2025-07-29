#pragma once
#include <QObject>
#include <QJsonArray>

class FriendStore : public QObject {
    Q_OBJECT
public:
    static FriendStore &instance();
public slots:
    void refresh();               // 从网络拉取
signals:
    void friendsReady(const QJsonArray &list);
private:
    explicit FriendStore(QObject *p = nullptr);
};
