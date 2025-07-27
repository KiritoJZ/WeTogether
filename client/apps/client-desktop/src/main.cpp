#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMessageBox::information(nullptr, "Hello", "Build OK!");
    return 0;
}