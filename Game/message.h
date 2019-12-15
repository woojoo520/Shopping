#ifndef MESSAGE_H
#define MESSAGE_H
/**
 * @file 
 * @brief doing nothing?
 * @author MengYeqing
 * @date 2019/12/01
 * @note
 */

#include <QDialog>

namespace Ui {
class Message;
}

class Message : public QDialog
{
    Q_OBJECT

public:
    explicit Message(QWidget *parent = 0);
    ~Message();

private:
    Ui::Message *ui;
};

#endif // MESSAGE_H
