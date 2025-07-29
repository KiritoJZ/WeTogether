#include "ui/login_widget.h"
#include "stores/login_store.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QLineEdit>

LoginWidget::LoginWidget(QWidget *p): QWidget(p) {
    m_email = new QLineEdit; m_email->setPlaceholderText("Email");
    m_pwd   = new QLineEdit; m_pwd->setEchoMode(QLineEdit::Password);
    m_pwd->setPlaceholderText("Password");
    auto *btn = new QPushButton("Login");
    auto *lay = new QVBoxLayout(this);
    lay->addWidget(m_email);
    lay->addWidget(m_pwd);
    lay->addWidget(btn);

    connect(btn, &QPushButton::clicked, this, &LoginWidget::onLoginClicked);

    auto &store = LoginStore::instance();
    connect(&store, &LoginStore::loginOK, this,
            [=, this](const QString &, const QString &nick){ emit loggedIn(nick); });
    connect(&store, &LoginStore::loginFailed, this,
            [](const QString &m){ QMessageBox::critical(nullptr, "Login", m); });
}

void LoginWidget::onLoginClicked() {
    LoginStore::instance().login(m_email->text(), m_pwd->text());
}
