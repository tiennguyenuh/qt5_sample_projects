#ifndef MYQUICKVIEW_H
#define MYQUICKVIEW_H

#include <QtQuick/QQuickView>
#include <QTime>

class MyQuickView : public QQuickView
{
    Q_OBJECT
public:
    explicit MyQuickView(QWindow *parent = 0);

private:
    bool rendered;
    QTime elapsedTimer;

    
signals:
    
public slots:
    void afterRendering();
    
};

#endif // MYQUICKVIEW_H
