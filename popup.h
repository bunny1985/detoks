#ifndef POPUP_H
#define POPUP_H

#include <QWidget>
#include <QDesktopWidget>
#include <QRect>
#include <QTimer>

namespace Ui {
    class popup;
}

class popup : public QWidget {
    Q_OBJECT
public:

    popup(QWidget *parent = 0);
    void execute(QString msg);
    ~popup();

protected:

    void changeEvent(QEvent *e);

private:
    Ui::popup *ui;
    QTimer *timer;
    double op;
    bool showed;
     bool opened;

private slots:
     void tick();
};

#endif // POPUP_H
