#pragma once
#include <QObject>
#include <qqmlintegration.h>

#if defined(UI_LOGIN_STATIC)
#  define UI_LOGIN_EXPORT
#elif defined(UI_LOGIN_BUILD)
#  define UI_LOGIN_EXPORT Q_DECL_EXPORT
#else
#  define UI_LOGIN_EXPORT Q_DECL_IMPORT
#endif

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
