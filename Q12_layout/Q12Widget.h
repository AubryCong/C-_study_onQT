#ifndef Q12WIDGET_H
#define Q12WIDGET_H

#include <QWidget>
#include <QComboBox>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

protected:
    void setupUI();   //ע�������ʼ��������ʵ�֣��ǳ��õĲο�����

protected slots:
    void onSubmit();

private:    //ֻ��������������Ҫ�õı����ŷ���˽�г�Ա�������棬�ö������Բ����ٶ���˽�г�Ա�����ˣ�ע��ѧϰ���ַ���������
    QComboBox ** m_scores;
    int m_nQuestionCount;
};

#endif // Q12WIDGET_H
