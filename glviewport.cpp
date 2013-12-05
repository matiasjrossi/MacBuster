#include "glviewport.h"

#if defined(__APPLE__) || defined(MACOSX)
  #include <GLUT/glut.h>
#else
  #include <gl/glut.h>
#endif

#define min(A,B) (A>B ? B : A)
#define max(A,B) (A<B ? B : A)


GLViewport::GLViewport() :
    bustCount(0)
{
}

void GLViewport::paintGL()
{
    qglClearColor(Qt::black);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(0.9, 0.5, 0.0);
    glutWireTeapot(1.0);
    renderText(-1.0, -0.9, 0.0, QString("Count: %1").arg(bustCount));
}

void GLViewport::initializeGL()
{
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
}

void GLViewport::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    double hor = max(static_cast<double>(w)/static_cast<double>(h),1.0);
    double ver = max(static_cast<double>(h)/static_cast<double>(w),1.0);
    glOrtho(-hor, hor, -ver, ver, -2.0, 2.0);
}

void GLViewport::bust()
{
    QImage im(1440, 1000, QImage::Format_ARGB32);
    bindTexture(im);
    bustCount++;
    updateGL();
}

void GLViewport::mousePressEvent(QMouseEvent *)
{
    bust();
}
