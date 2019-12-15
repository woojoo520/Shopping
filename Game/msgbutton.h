#ifndef MSGBUTTON_H
#define MSGBUTTON_H

/**
 * @file
 * @brief show the read and unread order message to the user
 * @author MengYeqing
 * @date 2019/12/01
 * @note
 */
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
