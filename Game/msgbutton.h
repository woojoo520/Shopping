#ifndef MSGBUTTON_H
#define MSGBUTTON_H

#include <QObject>
#include <QPushButton>
#include <QIcon>

class msgButton : public QPushButton
{
    Q_OBJECT
signals:
    void readXmsg(int id);
public slots:
    void changeIcon();
protected:

public:
    msgButton(QWidget *parent=0, int id=0, bool isread=false);
    int Id;
};

#endif // MSGBUTTON_H
