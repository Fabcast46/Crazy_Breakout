#ifndef THREAD
#define THREAD

#include <QThread>
#include <QTcpSocket>
#include <QDebug>

class Thread : public QThread
{
    Q_OBJECT

public:
    explicit Thread(qintptr ID, QObject *parent = 0);
    void run();

signals:
    void error(QTcpSocket::SocketError socketerror);

public slots:
    void readyRead();
    void desconectado();

private:
    QTcpSocket *socket;
    qintptr socketDescriptor;
};
#endif // MYTHREAD
