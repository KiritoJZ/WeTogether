#pragma once
#include <QWidget>
class QLineEdit;
class LoginWidget : public QWidget {
    Q_OBJECT
public:
    explicit LoginWidget(QWidget *parent = nullptr);
signals:
    void loggedIn(const QString &nick);
private slots:
    void onLoginClicked();
private:
    QLineEdit *m_email, *m_pwd;
};
