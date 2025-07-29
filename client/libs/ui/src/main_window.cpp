#include "ui/main_window.h"
#include "stores/friend_store.h"
#include <QVBoxLayout>
#include <QSplitter>
#include <QListWidget>
#include <QTextEdit>
#include <qjsonobject.h>

MainWindow::MainWindow(QWidget *p): QMainWindow(p) {
    setWindowTitle("QQ Demo");
    resize(900, 600);

    auto *split = new QSplitter(Qt::Horizontal, this);

    m_friendList = new QListWidget;
    m_chatView   = new QTextEdit; m_chatView->setReadOnly(true);
    m_msgEdit    = new QTextEdit;

    auto *left  = new QWidget;
    auto *right = new QWidget;
    auto *leftLay  = new QVBoxLayout(left);
    auto *rightLay = new QVBoxLayout(right);
    leftLay->addWidget(m_friendList);
    rightLay->addWidget(m_chatView);
    rightLay->addWidget(m_msgEdit);

    split->addWidget(left);
    split->addWidget(right);
    setCentralWidget(split);

    connect(&FriendStore::instance(), &FriendStore::friendsReady,
            this, [this](const QJsonArray &arr){
                m_friendList->clear();
                for (const auto &v : arr)
                    m_friendList->addItem(v.toObject()["name"].toString());
            });
    FriendStore::instance().refresh();   // 启动即拉好友
}
