#ifndef MYBUTTON_H
#define MYBUTTON_H
/**
 * @file
 * @brief implement the function of comment praise
 * @author MengYeqing
 * @date 2019/12/2
 * @note
 */
#include <QObject>
#include <QPushButton>
#include <QIcon>

class myButton : public QPushButton
{
    Q_OBJECT
signals:
    void click(int id, int labelId, int seq, QString productId, bool add);
protected:
    void mousePressEvent(QMouseEvent* event);
public:
    myButton(QWidget *parent=0, int id = 0, int labelId = 0, int seq = 0, QString productId = "");
    int id;
    int labelId;
    int seq;
    QString productId;

    bool isclicked;
};

#endif // MYBUTTON_H