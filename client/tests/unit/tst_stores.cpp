#include <QtTest/QtTest>

class tst_stores : public QObject
{
    Q_OBJECT
private slots:
    void testDummy() { QVERIFY(true); }
};

QTEST_APPLESS_MAIN(tst_stores)
#include "tst_stores.moc"