#pragma once
#include <QMainWindow>
class QListWidget;
class QTextEdit;

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
private:
    QListWidget *m_friendList;
    QTextEdit   *m_chatView;
    QTextEdit   *m_msgEdit;
};
