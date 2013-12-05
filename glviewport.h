#ifndef GLVIEWPORT_H
#define GLVIEWPORT_H

#include <QtOpenGL/QGLWidget>

class GLViewport : public QGLWidget
{
public:
    GLViewport();
    void bust();
    void mousePressEvent(QMouseEvent *);
protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
private:
    unsigned bustCount;
};

#endif // GLVIEWPORT_H
