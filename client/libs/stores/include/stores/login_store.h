#pragma once
#include <QObject>

class LoginStore : public QObject {
    Q_OBJECT
public:
    static LoginStore &instance();
    QString token() const { return m_token; }

public slots:
    void login(const QString &email, const QString &pwd);

signals:
    void loginOK(const QString &token, const QString &nick);
    void loginFailed(const QString &msg);

private:
    explicit LoginStore(QObject *parent = nullptr);
    QString m_token;
};
