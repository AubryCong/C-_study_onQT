#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QThread>
#include <QPointer>

class SecondFirer : public QObject //�����������߳��й�������ʵ����������ͳ������������ʵ�ֵ���ʱ�Ĵ����߼�
{                                   //ʵ������ʱ���Դ�����Ҫ���߳���ʵ�ֵĴ����߼�
    Q_OBJECT
public:
    SecondFirer(int seconds) : m_nSeconds(seconds){}

signals:
    void secondLeft(int sec, unsigned int id);
public slots:
    void onTimeout();
private:
    int m_nSeconds;
};

class CountThread : public QThread  //ʹ���̱߳���̳�QThread
{
public:
    CountThread(QWidget * receiver);  //������ͨ���̶߳���Ĺ��캯���������̶߳����ָ��
    ~CountThread();

protected:
    void run();  //�߳���ʵ�ֵ��߼���Ҫ��run()������ʵ��

private:
    QPointer<QWidget> m_receiver;  //����ָ�뱣��Widget��ʵ�����������QObjectָ��ָ��Ķ�������ʱ��õ�֪ͨ���й�NULL
};                                 //����������isNull()�����ж��Ƿ���Է��������еĶ����ָ��

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void onSecondLeft(int sec, unsigned int id);

private:
    QLabel * m_label;
};

#endif // WIDGET_H
