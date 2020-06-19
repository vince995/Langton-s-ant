#ifndef QANTRULESWIDGET_H
#define QANTRULESWIDGET_H

#include <QWidget>
#include <QtWidgets>

class QAntRulesWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QAntRulesWidget(QWidget *parent = nullptr);
    QColor getColor();
    int getRule();

signals:
    int closeRequested();

public slots:
    void setColor();
    void setRule();

private:
    int rule;
    QColor color;
    QPushButton *colorButton;
    QPushButton *ruleButton;
};

#endif // QANTRULESWIDGET_H
