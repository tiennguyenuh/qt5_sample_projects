#include "myquickview.h"

#include <QDebug>

MyQuickView::MyQuickView(QWindow *parent) :
    QQuickView(parent)
{
    connect(this, SIGNAL(afterRendering()), this, SLOT(afterRendering()));
    rendered = false;
    elapsedTimer.start();
}


void MyQuickView::afterRendering()
{
    if(!rendered) {
        rendered = true;
    }

}
