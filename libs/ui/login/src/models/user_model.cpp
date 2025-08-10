#include "user_model.h"

UserModel::UserModel(QObject *parent) : QObject(parent) {}

QString UserModel::avatar() const { return m_avatar; }
void UserModel::setAvatar(const QString &path)
{
    if (m_avatar != path) {
        m_avatar = path;
        emit avatarChanged();
    }
}
