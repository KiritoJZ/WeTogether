#include <QApplication>
#include "ui/login_widget.h"
#include "ui/main_window.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    LoginWidget lw;
    MainWindow mw;

    QObject::connect(&lw, &LoginWidget::loggedIn, &lw, [&]{
        lw.hide();
        mw.show();
    });

    lw.show();
    return a.exec();
}
