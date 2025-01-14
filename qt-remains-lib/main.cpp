#include <QCoreApplication>
#include <QPushButton>
#include <QPainter>
#include <QThread>
#include <QPropertyAnimation>
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <QTableView>
#include <QStandardItemModel>
#include <QtTest/QtTest>
#include <QSslSocket>
#include <QTimer>
#include <QLabel>
#include <QIcon>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QDebug>
#include <QApplication>  // Use QApplication for GUI

// 1. Qt Graphics & Drawing
void testGraphics() {
    qDebug() << "Running Graphics Test...";
    QPixmap pixmap(100, 100);
    pixmap.fill(Qt::white);
    QPainter painter(&pixmap);
    painter.setBrush(Qt::blue);
    painter.drawRect(10, 10, 80, 80);
    painter.end();
    pixmap.save("test_graphics.png");
    qDebug() << "Graphics test completed, file saved.";
}

// 2. Qt Multithreading
void testMultithreading() {
    qDebug() << "Running Multithreading Test...";
    QThread *thread = new QThread();
    QObject::connect(thread, &QThread::started, []() {
        qDebug() << "Thread started";
    });
    thread->start();
    thread->wait();
    delete thread;
    qDebug() << "Multithreading test completed.";
}

// 3. Qt Animations
void testAnimation(QWidget *widget) {
    qDebug() << "Running Animation Test...";
    widget->show();  // Ensure the widget is shown
    QPropertyAnimation *animation = new QPropertyAnimation(widget, "geometry");
    animation->setDuration(1000);
    animation->setStartValue(QRect(0, 0, 100, 100));
    animation->setEndValue(QRect(200, 200, 100, 100));
    animation->start();
    qDebug() << "Animation test completed.";
}

// 4. Qt Localization & Internationalization
void testLocalization() {
    qDebug() << "Running Localization Test...";
    QDateTime date = QDateTime::currentDateTime();
    qDebug() << "Current Date and Time: " << date.toString();
    qDebug() << "Localization test completed.";
}

// 5. Qt UI Testing (Automated UI Testing with QTestLib)
class TestButton : public QObject {
    Q_OBJECT

private slots:
    void testButtonClick() {
        qDebug() << "Running UI Test...";
        QPushButton button("Click Me");
        QVERIFY(button.text() == "Click Me");
        QTest::mouseClick(&button, Qt::LeftButton);
        QVERIFY(button.isEnabled());
        qDebug() << "UI Test completed.";
    }
};

// 6. Qt File Handling
void testFileHandling() {
    qDebug() << "Running File Handling Test...";
    QFile file("test.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << "Hello, Qt!";
        file.close();
        qDebug() << "File written successfully.";
    } else {
        qDebug() << "Failed to open file.";
    }
}

// 7. Qt Model/View Architecture
void testModelView() {
    qDebug() << "Running Model/View Test...";
    QStandardItemModel *model = new QStandardItemModel(2, 2);
    model->setItem(0, 0, new QStandardItem("Item 1"));
    model->setItem(0, 1, new QStandardItem("Item 2"));
    model->setItem(1, 0, new QStandardItem("Item 3"));
    model->setItem(1, 1, new QStandardItem("Item 4"));
    QTableView *view = new QTableView();
    view->setModel(model);
    view->show();
    qDebug() << "Model/View Test completed.";
}

// 8. Qt SSL/TLS Network Security
void testNetworkSecurity() {
    qDebug() << "Running Network Security Test...";
    QSslSocket sslSocket;
    sslSocket.connectToHostEncrypted("www.example.com", 443);
    if (sslSocket.waitForEncrypted()) {
        qDebug() << "SSL connection established.";
    } else {
        qDebug() << "SSL connection failed.";
    }
    qDebug() << "Network Security Test completed.";
}

// 9. Qt Resource Management
void testResourceManagement() {
    qDebug() << "Running Resource Management Test...";
    QIcon icon(":/images/icon.png");
    qDebug() << "Icon loaded:" << !icon.isNull();
    qDebug() << "Resource Management Test completed.";
}

// 10. Qt Event Handling
void testEventHandling() {
    qDebug() << "Running Event Handling Test...";
    QLabel *label = new QLabel("Hello, Qt!");
    label->setWindowTitle("Qt Event Test");
    label->show();
    QTest::keyClick(label, Qt::Key_Escape);
    qDebug() << "Event Handling Test completed.";
}

// 11. Qt Crash Handling
void testCrashHandling() {
    qDebug() << "Running Crash Handling Test...";
    QCoreApplication::setOrganizationName("TestOrg");
    QCoreApplication::setOrganizationDomain("test.org");
    qFatal("Test crash!");
}

// Main function to run tests
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);  // Use QApplication for GUI

    // Run each test and log its completion
    testGraphics();

    QWidget widget;
    testAnimation(&widget);

    testLocalization();

    // UI Testing with QTestLib
    TestButton buttonTest;
    QTest::qExec(&buttonTest);

    testFileHandling();

    testModelView();

    // Network security test (SSL/TLS)
    testNetworkSecurity();

    testResourceManagement();

    testEventHandling();

    testCrashHandling();

    return app.exec();
}

#include "main.moc"

