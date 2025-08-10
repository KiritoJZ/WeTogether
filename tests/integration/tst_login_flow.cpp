#include <QtTest/QtTest>

class tst_login_flow : public QObject
{
    Q_OBJECT
private slots:
    void testDummy() { QVERIFY(true); }
};

QTEST_APPLESS_MAIN(tst_login_flow)
#include "tst_login_flow.moc"