#include <QtTest/QtTest>

class tst_core : public QObject
{
    Q_OBJECT

private slots:              // 测试函数
    void initTestCase() {}   // 可选：全局初始化
    void cleanupTestCase() {}
    void testExample() { QVERIFY(true); }
};

// 生成 main() 并自动完成 moc
QTEST_APPLESS_MAIN(tst_core)
#include "tst_core.moc"