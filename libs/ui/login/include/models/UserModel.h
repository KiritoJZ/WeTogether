#pragma once
#include <QObject>
#include <qqmlintegration.h>
#include "ui_login_global.h"
class UI_LOGIN_EXPORT UserModel : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QString avatar READ avatar WRITE setAvatar NOTIFY avatarChanged)
public:
    explicit UserModel(QObject *parent = nullptr);

    QString avatar() const;
    void setAvatar(const QString &path);

signals:
    void avatarChanged();
private:
    QString m_avatar = ":/qt/qml/Login/resources/avatar.png";
};
